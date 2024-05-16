/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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
#include "modules/control/controller/lon_controller.h"

#include <algorithm>
#include <utility>

#include "absl/strings/str_cat.h"
#include "cyber/common/log.h"
#include "cyber/time/time.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/math/math_utils.h"
#include "modules/control/common/control_gflags.h"
#include "modules/localization/common/localization_gflags.h"

namespace apollo
{
  namespace control
  {

    using apollo::common::ErrorCode;
    using apollo::common::Status;
    using apollo::common::TrajectoryPoint;
    using apollo::common::VehicleStateProvider;
    using apollo::cyber::Time;

    constexpr double GRA_ACC = 9.8;

    LonController::LonController()
        : name_(ControlConf::ControllerType_Name(ControlConf::LON_CONTROLLER))
    {
      if (FLAGS_enable_csv_debug)
      {
        time_t rawtime;
        char name_buffer[80];
        std::time(&rawtime);
        std::tm time_tm;
        localtime_r(&rawtime, &time_tm);
        strftime(name_buffer, 80, "/tmp/speed_log__%F_%H%M%S.csv", &time_tm);
        speed_log_file_ = fopen(name_buffer, "w");
        if (speed_log_file_ == nullptr)
        {
          AERROR << "Fail to open file:" << name_buffer;
          FLAGS_enable_csv_debug = false;
        }
        if (speed_log_file_ != nullptr)
        {
          fprintf(speed_log_file_,
                  "station_reference,"
                  "station_error,"
                  "station_error_limited,"
                  "preview_station_error,"
                  "speed_reference,"
                  "speed_error,"
                  "speed_error_limited,"
                  "preview_speed_reference,"
                  "preview_speed_error,"
                  "preview_acceleration_reference,"
                  "acceleration_cmd_closeloop,"
                  "acceleration_cmd,"
                  "acceleration_lookup,"
                  "speed_lookup,"
                  "calibration_value,"
                  "throttle_cmd,"
                  "brake_cmd,"
                  "is_full_stop,"
                  "\r\n");

          fflush(speed_log_file_);
        }
        AINFO << name_ << " used.";
      }
    }

    void LonController::CloseLogFile()
    {
      if (FLAGS_enable_csv_debug)
      {
        if (speed_log_file_ != nullptr)
        {
          fclose(speed_log_file_);
          speed_log_file_ = nullptr;
        }
      }
    }
    void LonController::Stop() { CloseLogFile(); }

    LonController::~LonController() { CloseLogFile(); }

    Status LonController::Init(std::shared_ptr<DependencyInjector> injector,
                               const apollo_msgs::msg::ApollocontrolControlConf *control_conf)
    {
      control_conf_ = control_conf;
      if (control_conf_ == nullptr)
      {
        controller_initialized_ = false;
        AERROR << "get_longitudinal_param() nullptr";
        return Status(ErrorCode::CONTROL_INIT_ERROR,
                      "Failed to load LonController conf");
      }
      injector_ = injector;
      const LonControllerConf &lon_controller_conf =
          control_conf_->loncontrollerconf;
      double ts = lon_controller_conf.ts;
      bool enable_leadlag =
          lon_controller_conf.enablereverseleadlagcompensation;

      station_pid_controller_.Init(lon_controller_conf.stationpidconf);
      speed_pid_controller_.Init(lon_controller_conf.lowspeedpidconf);

      if (enable_leadlag)
      {
        station_leadlag_controller_.Init(
            lon_controller_conf.reversestationleadlagconf, ts);
        speed_leadlag_controller_.Init(
            lon_controller_conf.reversespeedleadlagconf, ts);
      }

      vehicle_param_ = (common::VehicleConfigHelper::Instance()->GetConfig().vehicleparam);

      SetDigitalFilterPitchAngle(lon_controller_conf);

      LoadControlCalibrationTable(lon_controller_conf);
      controller_initialized_ = true;

      return Status::OK();
    }

    void LonController::SetDigitalFilterPitchAngle(
        const LonControllerConf &lon_controller_conf)
    {
      double cutoff_freq =
          lon_controller_conf.pitchanglefilterconf.cutofffreq;
      double ts = lon_controller_conf.ts;
      SetDigitalFilter(ts, cutoff_freq, &digital_filter_pitch_angle_);
    }

    void LonController::LoadControlCalibrationTable(
        const LonControllerConf &lon_controller_conf)
    {
      const auto &control_table = lon_controller_conf.calibrationtable;
      AINFO << "Control calibration table loaded";
      AINFO << "Control calibration table size is "
            << control_table.calibration.size();
      Interpolation2D::DataType xyz;
      for (const auto &calibration : control_table.calibration)
      {
        xyz.push_back(std::make_tuple(calibration.speed,
                                      calibration.acceleration,
                                      calibration.command));
      }
      control_interpolation_.reset(new Interpolation2D);
      ACHECK(control_interpolation_->Init(xyz))
          << "Fail to load control calibration table";
    }

    Status LonController::ComputeControlCommand(
        const localization::LocalizationEstimate *localization,
        const apollo_msgs::msg::ApollocanbusChassis *chassis,
        const apollo_msgs::msg::ApolloplanningADCTrajectory *planning_published_trajectory,
        control::ControlCommand *cmd)
    {
      localization_ = localization;
      chassis_ = chassis;

      trajectory_message_ = planning_published_trajectory;
      if (!control_interpolation_)
      {
        AERROR << "Fail to initialize calibration table.";
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR,
                      "Fail to initialize calibration table.");
      }

      if (trajectory_analyzer_ == nullptr //||
                                          // trajectory_analyzer_->seq_num() !=
                                          //   trajectory_message_->apolloheader.sequence_num()
      )
      {
        trajectory_analyzer_.reset(new TrajectoryAnalyzer(trajectory_message_));
      }
      const LonControllerConf &lon_controller_conf =
          control_conf_->loncontrollerconf;

      auto debug = &cmd->debug.simplelondebug;
      *debug = apollo_msgs::msg::ApollocontrolSimpleLongitudinalDebug();

      double brake_cmd = 0.0;
      double throttle_cmd = 0.0;
      double ts = lon_controller_conf.ts;
      double preview_time = lon_controller_conf.previewwindow * ts;
      bool enable_leadlag =
          lon_controller_conf.enablereverseleadlagcompensation;

      if (preview_time < 0.0)
      {
        const auto error_msg =
            absl::StrCat("Preview time set as: ", preview_time, " less than 0");
        AERROR << error_msg;
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, error_msg);
      }
      ComputeLongitudinalErrors(trajectory_analyzer_.get(), preview_time, ts,
                                debug);

      double station_error_limit = lon_controller_conf.stationerrorlimit;
      double station_error_limited = 0.0;
      if (FLAGS_enable_speed_station_preview)
      {
        station_error_limited =
            common::math::Clamp(debug->previewstationerror,
                                -station_error_limit, station_error_limit);
      }
      else
      {
        station_error_limited = common::math::Clamp(
            debug->stationerror, -station_error_limit, station_error_limit);
      }

      if (trajectory_message_->gear == canbus::Chassis::GEAR_REVERSE)
      {
        station_pid_controller_.SetPID(
            lon_controller_conf.reversestationpidconf);
        speed_pid_controller_.SetPID(lon_controller_conf.reversespeedpidconf);
        if (enable_leadlag)
        {
          station_leadlag_controller_.SetLeadlag(
              lon_controller_conf.reversestationleadlagconf);
          speed_leadlag_controller_.SetLeadlag(
              lon_controller_conf.reversespeedleadlagconf);
        }
      }
      else if (injector_->vehicle_state()->linear_velocity() <=
               lon_controller_conf.switchspeed)
      {
        speed_pid_controller_.SetPID(lon_controller_conf.lowspeedpidconf);
      }
      else
      {
        speed_pid_controller_.SetPID(lon_controller_conf.highspeedpidconf);
      }

      double speed_offset =
          station_pid_controller_.Control(station_error_limited, ts);
      if (enable_leadlag)
      {
        speed_offset = station_leadlag_controller_.Control(speed_offset, ts);
      }

      double speed_controller_input = 0.0;
      double speed_controller_input_limit =
          lon_controller_conf.speedcontrollerinputlimit;
      double speed_controller_input_limited = 0.0;
      if (FLAGS_enable_speed_station_preview)
      {
        speed_controller_input = speed_offset + debug->previewspeederror;
      }
      else
      {
        speed_controller_input = speed_offset + debug->speederror;
      }
      speed_controller_input_limited =
          common::math::Clamp(speed_controller_input, -speed_controller_input_limit,
                              speed_controller_input_limit);

      double acceleration_cmd_closeloop = 0.0;

      acceleration_cmd_closeloop =
          speed_pid_controller_.Control(speed_controller_input_limited, ts);
      debug->set__pidsaturationstatus(
          speed_pid_controller_.IntegratorSaturationStatus());
      if (enable_leadlag)
      {
        acceleration_cmd_closeloop =
            speed_leadlag_controller_.Control(acceleration_cmd_closeloop, ts);
        debug->set__leadlagsaturationstatus(
            speed_leadlag_controller_.InnerstateSaturationStatus());
      }

      double slope_offset_compensation = digital_filter_pitch_angle_.Filter(
          GRA_ACC * std::sin(injector_->vehicle_state()->pitch()));

      if (std::isnan(slope_offset_compensation))
      {
        slope_offset_compensation = 0;
      }

      debug->set__slopeoffsetcompensation(slope_offset_compensation);

      double acceleration_cmd =
          acceleration_cmd_closeloop + debug->previewaccelerationreference +
          FLAGS_enable_slope_offset * debug->slopeoffsetcompensation;
      debug->set__isfullstop(false);
      GetPathRemain(debug);

      // At near-stop stage, replace the brake control command with the standstill
      // acceleration if the former is even softer than the latter
      if ((trajectory_message_->trajectorytype ==
           apollo::planning::ADCTrajectory::NORMAL) &&
          ((std::fabs(debug->previewaccelerationreference) <=
                control_conf_->maxaccelerationwhenstopped &&
            std::fabs(debug->previewspeedreference) <=
                vehicle_param_.maxabsspeedwhenstopped) ||
           std::abs(debug->pathremain) <
               control_conf_->maxpathremainwhenstopped))
      {
        acceleration_cmd =
            (chassis->gearlocation == canbus::Chassis::GEAR_REVERSE)
                ? std::max(acceleration_cmd,
                           -lon_controller_conf.standstillacceleration)
                : std::min(acceleration_cmd,
                           lon_controller_conf.standstillacceleration);
        ADEBUG << "Stop location reached";
        debug->set__isfullstop(true);
      }

      double throttle_lowerbound =
          std::max(vehicle_param_.throttledeadzone,
                   lon_controller_conf.throttleminimumaction);
      double brake_lowerbound =
          std::max(vehicle_param_.brakedeadzone,
                   lon_controller_conf.brakeminimumaction);
      double calibration_value = 0.0;
      double acceleration_lookup =
          (chassis->gearlocation == canbus::Chassis::GEAR_REVERSE)
              ? -acceleration_cmd
              : acceleration_cmd;

      if (FLAGS_use_preview_speed_for_table)
      {
        calibration_value = control_interpolation_->Interpolate(
            std::make_pair(debug->previewspeedreference, acceleration_lookup));
      }
      else
      {
        calibration_value = control_interpolation_->Interpolate(
            std::make_pair(chassis_->speedmps, acceleration_lookup));
      }

      if (acceleration_lookup >= 0)
      {
        if (calibration_value >= 0)
        {
          throttle_cmd = std::max(calibration_value, throttle_lowerbound);
        }
        else
        {
          throttle_cmd = throttle_lowerbound;
        }
        brake_cmd = 0.0;
      }
      else
      {
        throttle_cmd = 0.0;
        if (calibration_value >= 0)
        {
          brake_cmd = brake_lowerbound;
        }
        else
        {
          brake_cmd = std::max(-calibration_value, brake_lowerbound);
        }
      }

      debug->set__stationerrorlimited(station_error_limited);
      debug->set__speedoffset(speed_offset);
      debug->set__speedcontrollerinputlimited(speed_controller_input_limited);
      debug->set__accelerationcmd(acceleration_cmd);
      debug->set__throttlecmd(throttle_cmd);
      debug->set__brakecmd(brake_cmd);
      debug->set__accelerationlookup(acceleration_lookup);
      debug->set__speedlookup(chassis_->speedmps);
      debug->set__calibrationvalue(calibration_value);
      debug->set__accelerationcmdcloseloop(acceleration_cmd_closeloop);

      if (FLAGS_enable_csv_debug && speed_log_file_ != nullptr)
      {
        fprintf(speed_log_file_,
                "%.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f,"
                "%.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f, %d,\r\n",
                debug->stationreference, debug->stationerror,
                station_error_limited, debug->previewstationerror,
                debug->speedreference, debug->speederror,
                speed_controller_input_limited, debug->previewspeedreference,
                debug->previewspeederror,
                debug->previewaccelerationreference, acceleration_cmd_closeloop,
                acceleration_cmd, debug->accelerationlookup,
                debug->speedlookup, calibration_value, throttle_cmd, brake_cmd,
                debug->isfullstop);
      }

      // if the car is driven by acceleration, disgard the cmd->throttle and brake
      cmd->set__throttle(throttle_cmd);
      cmd->set__brake(brake_cmd);
      cmd->set__acceleration(acceleration_cmd);

      if (std::fabs(injector_->vehicle_state()->linear_velocity()) <=
              vehicle_param_.maxabsspeedwhenstopped ||
          chassis->gearlocation == trajectory_message_->gear ||
          chassis->gearlocation == canbus::Chassis::GEAR_NEUTRAL)
      {
        cmd->set__gearlocation(trajectory_message_->gear);
      }
      else
      {
        cmd->set__gearlocation(chassis->gearlocation);
      }

      return Status::OK();
    }

    Status LonController::Reset()
    {
      speed_pid_controller_.Reset();
      station_pid_controller_.Reset();
      return Status::OK();
    }

    std::string LonController::Name() const { return name_; }

    void LonController::ComputeLongitudinalErrors(
        const TrajectoryAnalyzer *trajectory_analyzer, const double preview_time,
        const double ts, SimpleLongitudinalDebug *debug)
    {
      // the decomposed vehicle motion onto Frenet frame
      // s: longitudinal accumulated distance along reference trajectory
      // s_dot: longitudinal velocity along reference trajectory
      // d: lateral distance w.r.t. reference trajectory
      // d_dot: lateral distance change rate, i.e. dd/dt
      double s_matched = 0.0;
      double s_dot_matched = 0.0;
      double d_matched = 0.0;
      double d_dot_matched = 0.0;

      auto vehicle_state = injector_->vehicle_state();
      auto matched_point = trajectory_analyzer->QueryMatchedPathPoint(
          vehicle_state->x(), vehicle_state->y());

      trajectory_analyzer->ToTrajectoryFrame(
          vehicle_state->x(), vehicle_state->y(), vehicle_state->heading(),
          vehicle_state->linear_velocity(), matched_point, &s_matched,
          &s_dot_matched, &d_matched, &d_dot_matched);

      double current_control_time = Time::Now().ToSecond();
      double preview_control_time = current_control_time + preview_time;

      TrajectoryPoint reference_point =
          trajectory_analyzer->QueryNearestPointByAbsoluteTime(
              current_control_time);
      TrajectoryPoint preview_point =
          trajectory_analyzer->QueryNearestPointByAbsoluteTime(
              preview_control_time);

      debug->currentmatchedpoint.pathpoint.set__x(
          matched_point.x);
      debug->currentmatchedpoint.pathpoint.set__y(
          matched_point.y);
      debug->currentreferencepoint.pathpoint.set__x(
          reference_point.pathpoint.x);
      debug->currentreferencepoint.pathpoint.set__y(
          reference_point.pathpoint.y);
      debug->previewreferencepoint.pathpoint.set__x(
          preview_point.pathpoint.x);
      debug->previewreferencepoint.pathpoint.set__y(
          preview_point.pathpoint.y);

      ADEBUG << "matched point:" << matched_point;
      ADEBUG << "reference point:" << reference_point;
      ADEBUG << "preview point:" << preview_point;

      double heading_error = common::math::NormalizeAngle(vehicle_state->heading() -
                                                          matched_point.theta);
      double lon_speed = vehicle_state->linear_velocity() * std::cos(heading_error);
      double lon_acceleration =
          vehicle_state->linear_acceleration() * std::cos(heading_error);
      double one_minus_kappa_lat_error = 1 - reference_point.pathpoint.kappa *
                                                 vehicle_state->linear_velocity() *
                                                 std::sin(heading_error);

      debug->set__stationreference(reference_point.pathpoint.s);
      debug->set__currentstation(s_matched);
      debug->set__stationerror(reference_point.pathpoint.s - s_matched);
      debug->set__speedreference(reference_point.v);
      debug->set__currentspeed(lon_speed);
      debug->set__speederror(reference_point.v - s_dot_matched);
      debug->set__accelerationreference(reference_point.a);
      debug->set__currentacceleration(lon_acceleration);
      debug->set__accelerationerror(reference_point.a -
                                    lon_acceleration / one_minus_kappa_lat_error);
      double jerk_reference =
          (debug->accelerationreference - previous_acceleration_reference_) / ts;
      double lon_jerk =
          (debug->currentacceleration - previous_acceleration_) / ts;
      debug->set__jerkreference(jerk_reference);
      debug->set__currentjerk(lon_jerk);
      debug->set__jerkerror(jerk_reference - lon_jerk / one_minus_kappa_lat_error);
      previous_acceleration_reference_ = debug->accelerationreference;
      previous_acceleration_ = debug->currentacceleration;

      debug->set__previewstationerror(preview_point.pathpoint.s - s_matched);
      debug->set__previewspeederror(preview_point.v - s_dot_matched);
      debug->set__previewspeedreference(preview_point.v);
      debug->set__previewaccelerationreference(preview_point.a);
    }

    void LonController::SetDigitalFilter(double ts, double cutoff_freq,
                                         common::DigitalFilter *digital_filter)
    {
      std::vector<double> denominators;
      std::vector<double> numerators;
      common::LpfCoefficients(ts, cutoff_freq, &denominators, &numerators);
      digital_filter->set_coefficients(denominators, numerators);
    }

    // TODO(all): Refactor and simplify
    void LonController::GetPathRemain(SimpleLongitudinalDebug *debug)
    {
      int stop_index = 0;
      static constexpr double kSpeedThreshold = 1e-3;
      static constexpr double kForwardAccThreshold = -1e-2;
      static constexpr double kBackwardAccThreshold = 1e-1;
      static constexpr double kParkingSpeed = 0.1;

      if (trajectory_message_->gear == canbus::Chassis::GEAR_DRIVE)
      {
        while (stop_index < (int)trajectory_message_->trajectorypoint.size())
        {
          auto &current_trajectory_point =
              trajectory_message_->trajectorypoint.at(stop_index);
          if (fabs(current_trajectory_point.v) < kSpeedThreshold &&
              current_trajectory_point.a > kForwardAccThreshold &&
              current_trajectory_point.a < 0.0)
          {
            break;
          }
          ++stop_index;
        }
      }
      else
      {
        while (stop_index < (int)trajectory_message_->trajectorypoint.size())
        {
          auto &current_trajectory_point =
              trajectory_message_->trajectorypoint.at(stop_index);
          if (current_trajectory_point.v < kSpeedThreshold &&
              current_trajectory_point.a < kBackwardAccThreshold &&
              current_trajectory_point.a > 0.0)
          {
            break;
          }
          ++stop_index;
        }
      }
      if (stop_index == (int)trajectory_message_->trajectorypoint.size())
      {
        --stop_index;
        if (trajectory_message_->trajectorypoint.size() != 0 && fabs(trajectory_message_->trajectorypoint.at(stop_index).v) <
                                               kParkingSpeed)
        {
          ADEBUG << "the last point is selected as parking point";
        }
        else
        {
          ADEBUG << "the last point found in path and speed > speed_deadzone";
        }
      }
      if (trajectory_message_->trajectorypoint.size() != 0)
        debug->set__pathremain(
            trajectory_message_->trajectorypoint.at(stop_index).pathpoint.s -
            debug->currentstation);
      else
        debug->set__pathremain(0);
    }

  } // namespace control
} // namespace apollo
