/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/localization/msf/local_integ/localization_integ_impl.h"

#include "cyber/cyber.h"
#include "modules/common/util/perf_util.h"
#include "modules/localization/msf/common/util/frame_transform.h"

namespace apollo {
namespace localization {
namespace msf {

using common::Status;

LocalizationIntegImpl::LocalizationIntegImpl()
    : republish_process_(new MeasureRepublishProcess()),
      integ_process_(new LocalizationIntegProcess()),
      gnss_process_(new LocalizationGnssProcess()),
      lidar_process_(new LocalizationLidarProcess()),
      is_use_gnss_bestpose_(true),
      imu_altitude_from_lidar_localization_(0.0),
      imu_altitude_from_lidar_localization_available_(false),
      enable_lidar_localization_(true),
      gnss_antenna_extrinsic_(Eigen::Affine3d::Identity()) {}

LocalizationIntegImpl::~LocalizationIntegImpl() {
  delete republish_process_;
  delete lidar_process_;
  delete gnss_process_;
  delete integ_process_;
}

Status LocalizationIntegImpl::Init(const LocalizationIntegParam& params) {
  enable_lidar_localization_ = params.enable_lidar_localization;
  if (params.enable_lidar_localization) {
    auto state = lidar_process_->Init(params);
    if (!state.ok()) {
      return state;
    }
  }

  auto state = republish_process_->Init(params);
  if (!state.ok()) {
    return state;
  }

  state = integ_process_->Init(params);
  if (!state.ok()) {
    return state;
  }

  if (params.gnss_mode == static_cast<int>(GnssMode::SELF)) {
    state = gnss_process_->Init(params);
    is_use_gnss_bestpose_ = false;
    if (!state.ok()) {
      return state;
    }
  } else {
    is_use_gnss_bestpose_ = true;
  }

  if (params.is_using_raw_gnsspos) {
    gnss_antenna_extrinsic_.translation()(0) =
        params.imu_to_ant_offset.offset_x;
    gnss_antenna_extrinsic_.translation()(1) =
        params.imu_to_ant_offset.offset_y;
    gnss_antenna_extrinsic_.translation()(2) =
        params.imu_to_ant_offset.offset_z;
  } else {
    gnss_antenna_extrinsic_ = Eigen::Affine3d::Identity();
  }
  AINFO << "gnss and imu lever arm: "
        << gnss_antenna_extrinsic_.translation()(0) << " "
        << gnss_antenna_extrinsic_.translation()(1) << " "
        << gnss_antenna_extrinsic_.translation()(2);

  expert_.Init(params);

  return Status::OK();
}

void LocalizationIntegImpl::PcdProcess(const LidarFrame& lidar_frame) {
  PcdProcessImpl(lidar_frame);
}

void LocalizationIntegImpl::PcdProcessImpl(const LidarFrame& pcd_data) {
  // lidar -> republish -> integ
  lidar_process_->PcdProcess(pcd_data);

  int state = 0;
  LocalizationEstimate lidar_localization;

  state = lidar_process_->GetResult(&lidar_localization);

  expert_.AddLidarLocalization(lidar_localization);

  MeasureData lidar_measure;
  if (state == 2) {  // only state OK republish lidar msg
    republish_process_->LidarLocalProcess(lidar_localization, &lidar_measure);
    integ_process_->MeasureDataProcess(lidar_measure);

    imu_altitude_from_lidar_localization_ =
        lidar_localization.pose.position.z;
    imu_altitude_from_lidar_localization_available_ = true;
  }

  lastest_lidar_localization_ =
      LocalizationResult(LocalizationMeasureState(state), lidar_localization);
}

void LocalizationIntegImpl::RawImuProcessRfu(const ImuData& imu_data) {
  ImuProcessImpl(imu_data);
}

void LocalizationIntegImpl::ImuProcessImpl(const ImuData& imu_data) {
  // imu -> lidar
  // imu -> integ -> republish -> lidar -> publish

  // start_time = boost::posix_time::microsec_clock::local_time();
  if (enable_lidar_localization_) {
    lidar_process_->RawImuProcess(imu_data);
  }
  integ_process_->RawImuProcess(imu_data);

  expert_.AddImu(imu_data);

  // integ
  IntegState state;
  LocalizationEstimate integ_localization;
  integ_process_->GetResult(&state, &integ_localization);
  ImuData corrected_imu;
  integ_process_->GetCorrectedImu(&corrected_imu);
  InertialParameter earth_param;
  integ_process_->GetEarthParameter(&earth_param);
  // check msf running status and set msf_status in integ_localization

  LocalizationIntegStatus integ_status;
  expert_.AddFusionLocalization(integ_localization);
  expert_.GetFusionStatus(&integ_localization.msfstatus,
                          &integ_localization.sensorstatus,
                          &integ_status);

  apollo::localization::Pose* posepb_loc = &integ_localization.pose;

  if (imu_altitude_from_lidar_localization_available_) {
    apollo::common::PointENU* position = &posepb_loc->position;
    position->z=imu_altitude_from_lidar_localization_;
  }

  // set linear acceleration
  Eigen::Vector3d orig_acceleration(corrected_imu.fb[0], corrected_imu.fb[1],
                                    corrected_imu.fb[2]);
  const apollo::common::Quaternion& orientation =
      integ_localization.pose.orientation;
  Eigen::Quaternion<double> quaternion(orientation.qw, orientation.qx,
                                       orientation.qy, orientation.qz);
  Eigen::Vector3d vec_acceleration =
      static_cast<Eigen::Vector3d>(quaternion * orig_acceleration);

  // Remove gravity.
  vec_acceleration(2) -= earth_param.g;

  apollo::common::Point3D* linear_acceleration =
      &posepb_loc->linearacceleration;
  linear_acceleration->x=vec_acceleration(0);
  linear_acceleration->y=vec_acceleration(1);
  linear_acceleration->z=vec_acceleration(2);

  Eigen::Vector3d vec_acceleration_vrf =
      quaternion.inverse() * vec_acceleration;

  apollo::common::Point3D* linear_acceleration_vrf =
      &posepb_loc->linearaccelerationvrf;
  linear_acceleration_vrf->x=vec_acceleration_vrf(0);
  linear_acceleration_vrf->y=vec_acceleration_vrf(1);
  linear_acceleration_vrf->z=vec_acceleration_vrf(2);

  // set angular velocity
  Eigen::Vector3d orig_angular_velocity(
      corrected_imu.wibb[0], corrected_imu.wibb[1], corrected_imu.wibb[2]);
  Eigen::Vector3d vec_angular_velocity = static_cast<Eigen::Vector3d>(
      quaternion.toRotationMatrix() * orig_angular_velocity);
  apollo::common::Point3D* angular_velocity =
      &posepb_loc->angularvelocity;
  angular_velocity->x=vec_angular_velocity(0);
  angular_velocity->y=vec_angular_velocity(1);
  angular_velocity->z=vec_angular_velocity(2);

  apollo::common::Point3D* angular_velocity_vrf =
      &posepb_loc->angularvelocityvrf;
  angular_velocity_vrf->x=corrected_imu.wibb[0];
  angular_velocity_vrf->y=corrected_imu.wibb[1];
  angular_velocity_vrf->z=corrected_imu.wibb[2];

  lastest_integ_localization_ =
      LocalizationResult(LocalizationMeasureState(static_cast<int>(state)),
                         integ_localization, integ_status);

  InsPva integ_sins_pva;
  double covariance[9][9];
  integ_process_->GetResult(&state, &integ_sins_pva, covariance);

  // update republish
  republish_process_->IntegPvaProcess(integ_sins_pva);

  if (state != IntegState::NOT_INIT) {
    // pass result of integration localization to lidar process module
    if (enable_lidar_localization_ && state != IntegState::NOT_STABLE) {
      lidar_process_->IntegPvaProcess(integ_sins_pva);
    }

    if (!is_use_gnss_bestpose_) {
      // pass localization result to gnss process module
      gnss_process_->IntegSinsPvaProcess(integ_sins_pva, covariance);
    }
  }
}

void LocalizationIntegImpl::RawObservationProcess(
    const drivers::gnss::EpochObservation& raw_obs_msg) {
  if (is_use_gnss_bestpose_) {
    return;
  }

  RawObservationProcessImpl(raw_obs_msg);
}

void LocalizationIntegImpl::RawEphemerisProcess(
    const drivers::gnss::GnssEphemeris& gnss_orbit_msg) {
  if (is_use_gnss_bestpose_) {
    return;
  }

  RawEphemerisProcessImpl(gnss_orbit_msg);
}

void LocalizationIntegImpl::GnssBestPoseProcess(
    const drivers::gnss::GnssBestPose& bestgnsspos_msg) {
  if (!is_use_gnss_bestpose_) {
    return;
  }

  GnssBestPoseProcessImpl(bestgnsspos_msg);
}

void LocalizationIntegImpl::RawObservationProcessImpl(
    const drivers::gnss::EpochObservation& raw_obs_msg) {
  gnss_process_->RawObservationProcess(raw_obs_msg);

  MeasureData gnss_measure;
  LocalizationMeasureState state = gnss_process_->GetResult(&gnss_measure);

  MeasureData measure;
  if (state == LocalizationMeasureState::OK ||
      state == LocalizationMeasureState::VALID) {
    republish_process_->GnssLocalProcess(gnss_measure, &measure);
    integ_process_->MeasureDataProcess(measure);
  }

  LocalizationEstimate gnss_localization;
  TransferGnssMeasureToLocalization(measure, &gnss_localization);

  lastest_gnss_localization_ = LocalizationResult(state, gnss_localization);
}

void LocalizationIntegImpl::RawEphemerisProcessImpl(
    const drivers::gnss::GnssEphemeris& gnss_orbit_msg) {
  gnss_process_->RawEphemerisProcess(gnss_orbit_msg);
}

void LocalizationIntegImpl::GnssBestPoseProcessImpl(
    const drivers::gnss::GnssBestPose& bestgnsspos_msg) {
  MeasureData measure;
  if (republish_process_->NovatelBestgnssposProcess(bestgnsspos_msg,
                                                    &measure)) {
    integ_process_->MeasureDataProcess(measure);

    expert_.AddGnssBestPose(bestgnsspos_msg, measure);
    LocalizationEstimate gnss_localization;
    TransferGnssMeasureToLocalization(measure, &gnss_localization);
    expert_.GetGnssStatus(&gnss_localization.msfstatus);

    lastest_gnss_localization_ =
        LocalizationResult(LocalizationMeasureState::OK, gnss_localization);
  }
}

void LocalizationIntegImpl::GnssHeadingProcess(
    const drivers::gnss::Heading& gnssheading_msg) {
  GnssHeadingProcessImpl(gnssheading_msg);
}

void LocalizationIntegImpl::GnssHeadingProcessImpl(
    const drivers::gnss::Heading& gnssheading_msg) {
  MeasureData measure;
  int heading_status = 0;
  if (republish_process_->GnssHeadingProcess(gnssheading_msg, &measure,
                                             &heading_status)) {
    integ_process_->MeasureDataProcess(measure);
  }
}

void LocalizationIntegImpl::TransferGnssMeasureToLocalization(
    const MeasureData& measure, LocalizationEstimate* localization) {
  CHECK_NOTNULL(localization);

  apollo::common::Header* headerpb = &localization->apolloheader;
  apollo::localization::Pose* posepb = &localization->pose;

  double timestamp = measure.time;
  localization->measurementtime=timestamp;
  headerpb->timestampsec=timestamp;

  UTMCoor utm_xy;
  FrameTransform::LatlonToUtmXY(measure.gnss_pos.longitude,
                                measure.gnss_pos.latitude, &utm_xy);

  apollo::common::PointENU* position = &posepb->position;
  position->x=utm_xy.x;
  position->y=utm_xy.y;
  position->z=measure.gnss_pos.height;

  apollo::common::Quaternion* quaternion = &posepb->orientation;
  quaternion->qx=0.0;
  quaternion->qy=0.0;
  quaternion->qz=0.0;
  quaternion->qw=1.0;

  apollo::localization::Uncertainty* uncertainty =
      &localization->uncertainty;

  apollo::common::Point3D* position_std_dev =
      &uncertainty->positionstddev;
  position_std_dev->x=-1.0;
  position_std_dev->y=-1.0;
  position_std_dev->z=-1.0;

  if (measure.is_have_variance) {
    position_std_dev->x=measure.variance[0][0];
    position_std_dev->y=measure.variance[1][1];
    position_std_dev->z=measure.variance[2][2];
  }

  apollo::common::Point3D* orientation_std_dev =
      &uncertainty->orientationstddev;
  orientation_std_dev->x=-1.0;
  orientation_std_dev->y=-1.0;
  orientation_std_dev->z=-1.0;
}

const LocalizationResult& LocalizationIntegImpl::GetLastestLidarLocalization()
    const {
  return lastest_lidar_localization_;
}

const LocalizationResult& LocalizationIntegImpl::GetLastestIntegLocalization()
    const {
  return lastest_integ_localization_;
}

const LocalizationResult& LocalizationIntegImpl::GetLastestGnssLocalization()
    const {
  return lastest_gnss_localization_;
}

}  // namespace msf
}  // namespace localization
}  // namespace apollo
