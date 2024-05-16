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

#include "modules/control/submodules/lat_lon_controller_submodule.h"

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
    using apollo::common::StatusPb;
    using apollo::cyber::Clock;

    LatLonControllerSubmodule::LatLonControllerSubmodule() : cyber::Component("LatLonControllerSubmodule") {}

    LatLonControllerSubmodule::~LatLonControllerSubmodule() {}

    std::string LatLonControllerSubmodule::Name() const
    {
      return FLAGS_lat_lon_controller_submodule_name;
    }

    bool LatLonControllerSubmodule::Init()
    {
      injector_ = std::make_shared<DependencyInjector>();
      InitControlGFlags(this);
      apollo::common::gflags::init_common(this);
      apollo::common::gflags::init_common_adapter(this);
      // lateral controller initialization
      ACHECK(cyber::common::GetProtoFromASCIIFile(FLAGS_lateral_controller_conf_file,
                                                  &lateral_controller_conf_))
          << "Unable to load lateral controller conf file: "
          << FLAGS_lateral_controller_conf_file;

      if (!lateral_controller_.Init(injector_, &lateral_controller_conf_).ok())
      {
        // monitor_logger_buffer_.ERROR(
        //     "Control init lateral controller failed! Stopping...");
        return false;
      }
      // longitudinal controller
      ACHECK(cyber::common::GetProtoFromASCIIFile(
          FLAGS_longitudinal_controller_conf_file, &longitudinal_controller_conf_))
          << "Unable to load longitudinal controller conf file: " +
                 FLAGS_longitudinal_controller_conf_file;

      if (!longitudinal_controller_.Init(injector_, &longitudinal_controller_conf_)
               .ok())
      {
        // monitor_logger_buffer_.ERROR(
        //     "Control init longitudinal controller failed! Stopping...");
        return false;
      }

      control_core_writer_ =
          node_->CreateWriter<ControlCommand>(FLAGS_control_core_command_topic);

      ACHECK(control_core_writer_ != nullptr);

      rd_proc = CreateReader<Preprocessor>(declare_parameter<std::string>("proc.channel.0", "/apollo/control/preprocessor"),
                                           std::bind(&LatLonControllerSubmodule::Proc, this, std::placeholders::_1));

      return true;
    }

    bool LatLonControllerSubmodule::Proc(
        const std::shared_ptr<Preprocessor> &preprocessor_status)
    {
      //  const auto //start_time = Clock::Now();
      ControlCommand control_core_command;

      // recording pad msg
      if (preprocessor_status->receivedpadmsg)
      {
        control_core_command.padmsg = (preprocessor_status->localview.padmsg);
      }
      ADEBUG_EVERY(60000) << "Lat+Lon controller submodule started ....";

      // skip produce control command when estop for lat+lon controller
      StatusPb pre_status = preprocessor_status->apolloheader.status;
      if (pre_status.errorcode != ErrorCode::OK)
      {
        control_core_command.apolloheader.status = (pre_status);
        AERROR << "Error in preprocessor submodule.";
        return false;
      }

      Status status = ProduceControlCoreCommand(preprocessor_status->localview,
                                                &control_core_command);
      AERROR_IF(!status.ok()) << "Failed to produce control command:"
                              << status.error_message();

      control_core_command.apolloheader = preprocessor_status->apolloheader;
      FillHeader(get_name(), &control_core_command);

      control_core_command.apolloheader.status.set__errorcode(
          status.code());
      control_core_command.apolloheader.status.set__msg(
          status.error_message());

      control_core_writer_->Write(control_core_command);
      return status.ok();
    }

    Status LatLonControllerSubmodule::ProduceControlCoreCommand(
        const LocalView &local_view, ControlCommand *control_core_command)
    {
      if (local_view.chassis.drivingmode == apollo::canbus::Chassis::COMPLETE_MANUAL)
      {
        lateral_controller_.Reset();
        longitudinal_controller_.Reset();
        // AINFO_EVERY(100) << "Reset Controllers in Manual Mode";
      }
      // fill out control command sequentially
      Status lateral_status = lateral_controller_.ComputeControlCommand(
          &local_view.localization, &local_view.chassis,
          &local_view.trajectory, control_core_command);
      // return error if lateral status has error
      if (!lateral_status.ok())
      {
        return lateral_status;
      }
      Status longitudinal_status = longitudinal_controller_.ComputeControlCommand(
          &local_view.localization, &local_view.chassis,
          &local_view.trajectory, control_core_command);
      return longitudinal_status;
    }

  } // namespace control
} // namespace apollo
CYBER_REGISTER_COMPONENT(LatLonControllerSubmodule)