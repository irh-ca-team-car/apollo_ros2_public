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
#include "component/control.h"

#include "absl/strings/str_cat.h"
#include "cyber/common/file.h"
#include "cyber/common/log.h"
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

    ControlComponent::ControlComponent()
        : TimerComponent("ControlComponent"), monitor_logger_buffer_(common::monitor::MonitorMessageItem::CONTROL) {}

    bool ControlComponent::Init()
    {
      injector_ = std::make_shared<DependencyInjector>();
      init_time_ = Clock::Now();
      InitControlGFlags(this);
      apollo::common::gflags::init_common(this);
      apollo::common::gflags::init_common_adapter(this);

      AINFO << "Control init, starting ...";

      ACHECK(
          cyber::common::GetProtoFromFile(FLAGS_control_conf_file, &control_conf_))
          << "Unable to load control conf file: " + FLAGS_control_conf_file;

      AINFO << "Conf file: " << FLAGS_control_conf_file << " is loaded.";

      // initial controller agent when not using control submodules
      ADEBUG_EVERY(60000) << "FLAGS_use_control_submodules: " << FLAGS_use_control_submodules;
      if (!FLAGS_use_control_submodules &&
          !controller_agent_.Init(injector_, &control_conf_).ok())
      {
        // set controller
        ADEBUG_EVERY(60000) << "original control";
        monitor_logger_buffer_.ERROR("Control init controller failed! Stopping...");
        return false;
      }
      cyber::ReaderConfig chassis_reader_config;
      chassis_reader_config.channel_name = FLAGS_chassis_topic;
      chassis_reader_config.pending_queue_size = FLAGS_chassis_pending_queue_size;
      chassis_reader_ =
          node_->CreateReader<apollo_msgs::msg::ApollocanbusChassis>(chassis_reader_config, nullptr);
      ACHECK(chassis_reader_ != nullptr);
      cyber::ReaderConfig planning_reader_config;
      planning_reader_config.channel_name = FLAGS_planning_trajectory_topic;
      planning_reader_config.pending_queue_size = FLAGS_planning_pending_queue_size;
      trajectory_reader_ =
          node_->CreateReader<apollo_msgs::msg::ApolloplanningADCTrajectory>(planning_reader_config, nullptr);
      ACHECK(trajectory_reader_ != nullptr);
      cyber::ReaderConfig localization_reader_config;
      localization_reader_config.channel_name = FLAGS_localization_topic;
      localization_reader_config.pending_queue_size =
          FLAGS_localization_pending_queue_size;
      localization_reader_ = node_->CreateReader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>(
          localization_reader_config, nullptr);
      ACHECK(localization_reader_ != nullptr);
      cyber::ReaderConfig pad_msg_reader_config;
      pad_msg_reader_config.channel_name = FLAGS_pad_topic;
      pad_msg_reader_config.pending_queue_size = FLAGS_pad_msg_pending_queue_size;
      pad_msg_reader_ =
          node_->CreateReader<PadMessage>(pad_msg_reader_config, nullptr);
      ACHECK(pad_msg_reader_ != nullptr);
      ADEBUG << "pad_msg_reader_:" << pad_msg_reader_;
      if (!FLAGS_use_control_submodules)
      {
        control_cmd_writer_ =
            node_->CreateWriter<ControlCommand>(FLAGS_control_command_topic);
        ADEBUG << "control_cmd_writer_:" << control_cmd_writer_;
        ACHECK(control_cmd_writer_ != nullptr);
      }
      else
      {
        local_view_writer_ =
            node_->CreateWriter<LocalView>(FLAGS_control_local_view_topic);
        ADEBUG << "local_view_writer_:" << local_view_writer_;
        ACHECK(local_view_writer_ != nullptr);
      }
      // set initial vehicle state by cmd
      // need to sleep, because advertised channel is not ready immediately
      // simple test shows a short delay of 80 ms or so
      AINFO << "Control resetting vehicle state, sleeping for 1000 ms ...";
      // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      //  should init_vehicle first, let car enter work status, then use status msg
      //  trigger control

      AINFO << "Control default driving action is "
            << (control_conf_.action);
      pad_msg_.set__action(control_conf_.action);
      return true;
    }

    void ControlComponent::OnPad(const std::shared_ptr<PadMessage> &pad)
    {
      pad_msg_ = (*pad);
      ADEBUG << "Received Pad Msg:" << pad_msg_;
      AERROR_IF(pad_msg_.action == 0) << "pad message check failed!";
    }

    void ControlComponent::OnChassis(const std::shared_ptr<apollo_msgs::msg::ApollocanbusChassis> &chassis)
    {
      ADEBUG_EVERY(60000) << "Received chassis data: run chassis callback.";
      latest_chassis_ = (*chassis);
    }

    void ControlComponent::OnPlanning(
        const std::shared_ptr<apollo_msgs::msg::ApolloplanningADCTrajectory> &trajectory)
    {
      ADEBUG_EVERY(60000) << "Received chassis data: run trajectory callback.";
      latest_trajectory_ = (*trajectory);
    }

    void ControlComponent::OnLocalization(
        const std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate> &localization)
    {
      ADEBUG_EVERY(60000) << "Received control data: run localization message callback.";
      latest_localization_ = (*localization);
    }

    void ControlComponent::OnMonitor(
        const common::monitor::MonitorMessage &monitor_message)
    {
      for (const auto &item : monitor_message.item)
      {
        if (item.loglevel == common::monitor::MonitorMessageItem::FATAL)
        {
          estop_ = true;
          return;
        }
      }
    }

    Status ControlComponent::ProduceControlCommand(
        ControlCommand *control_command)
    {
      Status status = CheckInput(&local_view_);
      // check data

      if (!status.ok())
      {
        control_command->engageadvice.set__advice(
            apollo::common::EngageAdvice::DISALLOW_ENGAGE);
        control_command->engageadvice.set__reason(
            status.error_message());
        estop_ = true;
        estop_reason_ = status.error_message();
      }
      else
      {
        Status status_ts = CheckTimestamp(local_view_);
        if (!status_ts.ok())
        {
          AERROR << "Input messages timeout";
          // estop_ = true;
          status = status_ts;
          if (local_view_.chassis.drivingmode !=
              apollo::canbus::Chassis::COMPLETE_AUTO_DRIVE)
          {
            control_command->engageadvice.set__advice(
                apollo::common::EngageAdvice::DISALLOW_ENGAGE);
            control_command->engageadvice.set__reason(
                status.error_message());
          }
        }
        else
        {
          control_command->engageadvice.set__advice(
              apollo::common::EngageAdvice::READY_TO_ENGAGE);
        }
      }

      // check estop
      estop_ = control_conf_.enablepersistentestop
                   ? estop_ || local_view_.trajectory.estop.isestop
                   : local_view_.trajectory.estop.isestop;

      if (local_view_.trajectory.estop.isestop)
      {
        estop_ = true;
        estop_reason_ = "estop from planning : ";
        estop_reason_ += local_view_.trajectory.estop.reason;
      }

      if (local_view_.trajectory.trajectorypoint.empty())
      {
        estop_ = true;
        estop_reason_ = "estop for empty planning trajectory, planning headers: ";
      }

      if (FLAGS_enable_gear_drive_negative_speed_protection)
      {
        const double kEpsilon = 0.001;
        auto first_trajectory_point = local_view_.trajectory.trajectorypoint.at(0);
        if (local_view_.chassis.gearlocation == apollo::canbus::Chassis::GEAR_DRIVE &&
            first_trajectory_point.v < -1 * kEpsilon)
        {
          estop_ = true;
          estop_reason_ = "estop for negative speed when gear_drive";
        }
      }

      if (!estop_)
      {
        if (local_view_.chassis.drivingmode == apollo::canbus::Chassis::COMPLETE_MANUAL)
        {
          controller_agent_.Reset();
        }

        // auto debug = &control_command->debug.inputdebug;
        /*debug->localizationheader=(
            local_view_.localization.header);
        debug->canbusheader=(local_view_.chassis.header);
        debug->trajectoryheader=(
            local_view_.trajectory.header);
    */
        if (local_view_.trajectory.isreplan)
        {
          latest_replan_trajectory_header_ = local_view_.trajectory.apolloheader;
        }

        // controller agent
        Status status_compute = controller_agent_.ComputeControlCommand(
            &local_view_.localization, &local_view_.chassis,
            &local_view_.trajectory, control_command);

        if (!status_compute.ok())
        {
          AERROR << "Control main function failed"
                 << " with localization: "
                 << local_view_.localization
                 << " with chassis: " << local_view_.chassis
                 << " with trajectory: "
                 << local_view_.trajectory
                 << " with cmd: " << *control_command
                 << " status:" << status_compute.error_message();
          estop_ = true;
          estop_reason_ = status_compute.error_message();
          status = status_compute;
        }
      }
      // if planning set estop, then no control process triggered
      if (estop_)
      {
        // set Estop command
        control_command->set__speed(0);
        control_command->set__throttle(0);
        control_command->set__brake(control_conf_.softestopbrake);
        control_command->set__gearlocation(apollo::canbus::Chassis::GEAR_DRIVE);
      }
      // check signal
      if (local_view_.trajectory.decision.vehiclesignal != apollo_msgs::msg::ApollocommonVehicleSignal())
      {
        control_command->signal = (local_view_.trajectory.decision.vehiclesignal);
      }
      return status;
    }
    std::mutex mtx_proc;
    bool ControlComponent::Proc()
    {
      if(!mtx_proc.try_lock())
        return false;
      const auto start_time = Clock::Now();

      chassis_reader_->Observe();
      const auto &chassis_msg = chassis_reader_->GetLatestObserved();
      if (chassis_msg == nullptr)
      {
        AWARN_EVERY(60000) << "Chassis msg is not ready!";
        mtx_proc.unlock();
        return true;
      }

      OnChassis(chassis_msg);

      trajectory_reader_->Observe();
      const auto &trajectory_msg = trajectory_reader_->GetLatestObserved();
      if (trajectory_msg == nullptr)
      {
        AWARN_EVERY(60000) << "planning msg is not ready!";
        mtx_proc.unlock();
        return true;
      }
      OnPlanning(trajectory_msg);

      localization_reader_->Observe();
      const auto &localization_msg = localization_reader_->GetLatestObserved();
      if (localization_msg == nullptr)
      {
        AWARN_EVERY(60000) << "localization msg is not ready!";
        mtx_proc.unlock();
        return true;
      }
      OnLocalization(localization_msg);

      pad_msg_reader_->Observe();
      const auto &pad_msg = pad_msg_reader_->GetLatestObserved();
      if (pad_msg != nullptr)
      {
        OnPad(pad_msg);
      }

      {
        // TODO(SHU): to avoid redundent copy
        local_view_.chassis = (latest_chassis_);
        local_view_.trajectory = (latest_trajectory_);
        local_view_.localization = (latest_localization_);
        if (pad_msg != nullptr)
        {
          local_view_.padmsg = (pad_msg_);
        }
      }

      // use control submodules
      if (FLAGS_use_control_submodules)
      {
        // local_view_.mutable_header()->set_lidar_timestamp(
        //     local_view_.trajectory().header().lidar_timestamp());
        // local_view_.mutable_header()->set_camera_timestamp(
        //     local_view_.trajectory().header().camera_timestamp());
        // local_view_.mutable_header()->set_radar_timestamp(
        //     local_view_.trajectory().header().radar_timestamp());
        FillHeader(FLAGS_control_local_view_topic, &local_view_);

        // const auto end_time = Clock::Now();

        local_view_writer_->Write(local_view_);
        mtx_proc.unlock();
        return true;
      }

      if (pad_msg != nullptr)
      {
        ADEBUG << "pad_msg: " << pad_msg_;
        if (pad_msg_.action == DrivingAction::RESET)
        {
          AINFO << "Control received RESET action!";
          estop_ = false;
          estop_reason_.clear();
        }
        pad_received_ = true;
      }

      if (control_conf_.iscontroltestmode &&
          control_conf_.controltestduration > 0 &&
          (start_time - init_time_).ToSecond() >
              control_conf_.controltestduration)
      {
        AERROR << "Control finished testing. exit";
        mtx_proc.unlock();
        return false;
      }

      ControlCommand control_command;

      Status status = ProduceControlCommand(&control_command);
      AERROR_IF(!status.ok()) << "Failed to produce control command:"
                              << status.error_message();

      if (pad_received_)
      {
        control_command.padmsg = (pad_msg_);
        pad_received_ = false;
      }

      // forward estop reason among following control frames.
      if (estop_)
      {
        control_command.apolloheader.status.set__msg(estop_reason_);
      }

      // set header
      control_command.apolloheader.lidartimestamp = local_view_.trajectory.apolloheader.lidartimestamp;
      control_command.apolloheader.cameratimestamp = local_view_.trajectory.apolloheader.cameratimestamp;
      control_command.apolloheader.radartimestamp = local_view_.trajectory.apolloheader.radartimestamp;

      FillHeader(node_->get_name(), &control_command);

      ADEBUG_EVERY(60000) << control_command;
      if (control_conf_.iscontroltestmode)
      {
        ADEBUG_EVERY(60000) << "Skip publish control command in test mode";
        mtx_proc.unlock();
        return true;
      }

      const auto end_time = Clock::Now();
      const double time_diff_ms = (end_time - start_time).ToSecond() * 1e3;
      ADEBUG_EVERY(60000) << "total control time spend: " << time_diff_ms << " ms.";

      control_command.latencystats.set__totaltimems(time_diff_ms);
      control_command.latencystats.set__totaltimeexceeded(
          time_diff_ms > control_conf_.controlperiod * 1e3);
      ADEBUG_EVERY(60000) << "control cycle time is: " << time_diff_ms << " ms.";
      status.Save(&control_command.apolloheader.status);

      control_cmd_writer_->Write(control_command);
      mtx_proc.unlock();
      return true;
    }

    Status ControlComponent::CheckInput(LocalView *local_view)
    {
      ADEBUG_EVERY(60000) << "Received localization:"
             << local_view->localization;
      ADEBUG_EVERY(60000) << "Received chassis:" << local_view->chassis;

      if (!local_view->trajectory.estop.isestop &&
          local_view->trajectory.trajectorypoint.empty())
      {
        const std::string msg =
            "planning has no trajectory point. planning_seq_num:";
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, msg);
      }

      for (auto &trajectory_point :
           local_view->trajectory.trajectorypoint)
      {
        if (std::abs(trajectory_point.v) <
                control_conf_.minimumspeedresolution &&
            std::abs(trajectory_point.a) <
                control_conf_.maxaccelerationwhenstopped)
        {
          trajectory_point.set__v(0.0);
          trajectory_point.set__a(0.0);
        }
      }

      injector_->vehicle_state()->Update(local_view->localization,
                                         local_view->chassis);

      return Status::OK();
    }

    Status ControlComponent::CheckTimestamp(const LocalView &local_view)
    {
      if (!control_conf_.enableinputtimestampcheck ||
          control_conf_.iscontroltestmode)
      {
        ADEBUG_EVERY(60000) << "Skip input timestamp check by gflags.";
        return Status::OK();
      }
      double current_timestamp = Clock::NowInSeconds();
      double localization_diff =
          current_timestamp - local_view.localization.apolloheader.timestampsec;
      if (localization_diff > (control_conf_.maxlocalizationmissnum *
                               control_conf_.localizationperiod))
      {
        AERROR << "Localization msg lost for " << std::setprecision(6)
               << localization_diff << "s";
        monitor_logger_buffer_.ERROR("Localization msg lost");
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, "Localization msg timeout");
      }

      double chassis_diff =
          current_timestamp - local_view.chassis.apolloheader.timestampsec;
      if (chassis_diff >
          (control_conf_.maxchassismissnum * control_conf_.chassisperiod))
      {
        AERROR << "Chassis msg lost for " << std::setprecision(6) << chassis_diff
               << "s";
        monitor_logger_buffer_.ERROR("Chassis msg lost");
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, "Chassis msg timeout");
      }

      double trajectory_diff =
          current_timestamp - local_view.trajectory.apolloheader.timestampsec;
      if (trajectory_diff > (control_conf_.maxplanningmissnum *
                             control_conf_.trajectoryperiod))
      {
        AERROR << "Trajectory msg lost for " << std::setprecision(6)
               << trajectory_diff << "s";
        monitor_logger_buffer_.ERROR("Trajectory msg lost");
        return Status(ErrorCode::CONTROL_COMPUTE_ERROR, "Trajectory msg timeout");
      }
      return Status::OK();
    }

  } // namespace control
} // namespace apollo
CYBER_REGISTER_COMPONENT(ControlComponent)