/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

/**
 * @file preprocessor_submodule.cc
 */

#include "modules/control/submodules/preprocessor_submodule.h"

#include <string>

#include "cyber/time/clock.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/control/common/control_gflags.h"

namespace apollo
{
  namespace control
  {

    using apollo::common::ErrorCode;
    using apollo::common::Status;
    using apollo::common::VehicleStateProvider;
    using apollo::cyber::Clock;
    using apollo::localization::LocalizationEstimate;

    PreprocessorSubmodule::PreprocessorSubmodule() : cyber::Component("PreprocessorSubmodule") {}

    PreprocessorSubmodule::~PreprocessorSubmodule() {}

    std::string PreprocessorSubmodule::Name() const
    {
      return FLAGS_preprocessor_submodule_name;
    }

    bool PreprocessorSubmodule::Init()
    {
      InitControlGFlags(this);
      apollo::common::gflags::init_common(this);
      apollo::common::gflags::init_common_adapter(this);
      injector_ = std::make_shared<DependencyInjector>();
      ACHECK(cyber::common::GetProtoFromASCIIFile(FLAGS_control_common_conf_file,
                                                  &control_common_conf_))
          << "Unable to load control common conf file: "
          << FLAGS_control_common_conf_file;

      // Preprocessor writer
      preprocessor_writer_ =
          node_->CreateWriter<Preprocessor>(FLAGS_control_preprocessor_topic);

      ACHECK(preprocessor_writer_ != nullptr);

      rd_proc = CreateReader<LocalView>(declare_parameter<std::string>("proc.channel.0", "/apollo/control/localview"),
                                        std::bind(&PreprocessorSubmodule::Proc, this, std::placeholders::_1));

      return true;
    }

    bool PreprocessorSubmodule::Proc(const std::shared_ptr<LocalView> &local_view)
    {
      ADEBUG << "Preprocessor started ....";

      Preprocessor control_preprocessor;
      // handling estop
      auto *preprocessor_status = &control_preprocessor.apolloheader.status;
      // control_preprocessor.header()->mutable_status();

      control_preprocessor.localview = (*local_view);

      Status status = ProducePreprocessorStatus(&control_preprocessor);
      if (!status.ok())
        AERROR_EVERY(6000) << "Failed to produce control preprocessor:"
                            << status.error_message();

      if (status.ok() && !estop_)
      {
        preprocessor_status->set__errorcode(ErrorCode::OK);
      }
      else
      {
        estop_ = true;
        preprocessor_status->set__errorcode(status.code());
        preprocessor_status->set__msg(status.error_message());
      }

      if (control_preprocessor.localview.padmsg != apollo_msgs::msg::ApollocontrolPadMessage())
      {
        const auto &pad_message = control_preprocessor.localview.padmsg;
        if (pad_message.action == DrivingAction::RESET)
        {
          AINFO << "Control received RESET action!";
          estop_ = false;
          preprocessor_status->set__errorcode(ErrorCode::OK);
          preprocessor_status->set__msg("");
        }
        control_preprocessor.set__receivedpadmsg(true);
      }

      control_preprocessor.apolloheader = local_view->trajectory.apolloheader;
      FillHeader(get_name(), &control_preprocessor);

      preprocessor_writer_->Write(control_preprocessor);
      ADEBUG << "Preprocessor finished.";

      return true;
    }

    Status PreprocessorSubmodule::ProducePreprocessorStatus(
        Preprocessor *control_preprocessor)
    {
      // TODO(SJiang): rename this function since local view got changed in this
      // function.
      Status status = CheckInput(&control_preprocessor->localview);

      if (!status.ok())
      {
        auto mutable_engage_advice = &control_preprocessor->engageadvice;
        mutable_engage_advice->set__advice(
            apollo::common::EngageAdvice::DISALLOW_ENGAGE);
        mutable_engage_advice->set__reason(status.error_message());
        // skip checking time stamp when failed input check
        return status;
      }

      Status status_ts = CheckTimestamp(control_preprocessor->localview);

      if (!status_ts.ok())
      {
        AERROR << "Input messages timeout";
        status = status_ts;
        if (control_preprocessor->localview.chassis.drivingmode !=
            apollo::canbus::Chassis::COMPLETE_AUTO_DRIVE)
        {
          control_preprocessor->engageadvice.set__advice(
              apollo::common::EngageAdvice::DISALLOW_ENGAGE);
          control_preprocessor->engageadvice.set__reason(
              status.error_message());
        }
        return status;
      }
      control_preprocessor->engageadvice.set__advice(
          apollo::common::EngageAdvice::READY_TO_ENGAGE);

      estop_ =
          control_common_conf_.enablepersistentestop
              ? estop_ || control_preprocessor->localview
                              .trajectory
                              .estop
                              .isestop
              : control_preprocessor->localview.trajectory.estop.isestop;

      if (control_preprocessor->localview.trajectory.estop.isestop)
      {
        return Status(
            ErrorCode::CONTROL_ESTOP_ERROR,
            absl::StrCat(
                "estop from planning : ",
                control_preprocessor->localview.trajectory.estop.reason));
      }

      if (FLAGS_enable_gear_drive_negative_speed_protection)
      {
        const double kEpsilon = 0.001;
        auto first_trajectory_point =
            control_preprocessor->localview.trajectory.trajectorypoint.at(0);
        if (control_preprocessor->localview.chassis.gearlocation ==
                apollo::canbus::Chassis::GEAR_DRIVE &&
            first_trajectory_point.v < -1 * kEpsilon)
        {
          return Status(
              ErrorCode::CONTROL_ESTOP_ERROR,
              "estop for empty planning trajectory, planning headers: ");
        }
      }

      auto input_debug = &control_preprocessor->inputdebug;
      input_debug->localizationheader = (control_preprocessor->localview.localization.apolloheader);
      input_debug->canbusheader = (control_preprocessor->localview.chassis.apolloheader);
      input_debug->trajectoryheader = (control_preprocessor->localview.trajectory.apolloheader);

      if (control_preprocessor->localview.trajectory.isreplan)
      {
        latest_replan_trajectory_header_ = (control_preprocessor->localview.trajectory.apolloheader);
      }

      if (latest_replan_trajectory_header_ != apollo::common::Header())
      {
        input_debug->latestreplantrajectoryheader = (latest_replan_trajectory_header_);
      }

      return status;
    }

    Status PreprocessorSubmodule::CheckInput(LocalView *local_view)
    {
      ADEBUG << "Received localization:"
             << local_view->localization;
      ADEBUG << "Received chassis:" << local_view->chassis;

      if (!local_view->trajectory.estop.isestop &&
          local_view->trajectory.trajectorypoint.empty())
      {
        const std::string msg = "planning has no trajectory point. planning_seq_num: ";
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, msg);
      }
      {
        for (auto trajectory_point : local_view->trajectory.trajectorypoint)
        {
          if (std::abs(trajectory_point.v) <
                  control_common_conf_.minimumspeedresolution &&
              std::abs(trajectory_point.a) <
                  control_common_conf_.maxaccelerationwhenstopped)
          {
            trajectory_point.set__v(0.0);
            trajectory_point.set__a(0.0);
          }
        }
      }
      injector_->vehicle_state()->Update(local_view->localization,
                                         local_view->chassis);

      return Status::OK();
    }

    Status PreprocessorSubmodule::CheckTimestamp(const LocalView &local_view)
    {
      if (!control_common_conf_.enableinputtimestampcheck ||
          control_common_conf_.iscontroltestmode)
      {
        ADEBUG << "Skip input timestamp check by gflags.";
        return Status::OK();
      }

      double current_timestamp = Clock::NowInSeconds();
      double localization_diff =
          current_timestamp - local_view.localization.apolloheader.timestampsec;

      if (localization_diff > (control_common_conf_.maxlocalizationmissnum *
                               control_common_conf_.localizationperiod))
      {
        AERROR << "Localization msg lost for " << std::setprecision(6)
               << localization_diff << "s";
        // monitor_logger_buffer_.ERROR("Localization msg lost");
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, "Localization msg timeout");
      }

      double chassis_diff =
          current_timestamp - local_view.chassis.apolloheader.timestampsec;

      if (chassis_diff > (control_common_conf_.maxchassismissnum *
                          control_common_conf_.chassisperiod))
      {
        AERROR << "Chassis msg lost for " << std::setprecision(6) << chassis_diff
               << "s";
        // monitor_logger_buffer_.ERROR("Chassis msg lost");
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, "Chassis msg timeout");
      }

      double trajectory_diff =
          current_timestamp - local_view.trajectory.apolloheader.timestampsec;

      if (trajectory_diff > (control_common_conf_.maxplanningmissnum *
                             control_common_conf_.trajectoryperiod))
      {
        AERROR << "Trajectory msg lost for " << std::setprecision(6)
               << trajectory_diff << "s";
        // monitor_logger_buffer_.ERROR("Trajectory msg lost");
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, "Trajectory msg timeout");
      }

      return Status::OK();
    }

  } // namespace control
} // namespace apollo
CYBER_REGISTER_COMPONENT(PreprocessorSubmodule);