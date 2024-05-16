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
 * @file postprocessor_submodule.cc
 */

#include "modules/control/submodules/postprocessor_submodule.h"

#include <string>

#include "cyber/time/clock.h"

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/control/common/control_gflags.h"

namespace apollo {
namespace control {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::cyber::Clock;

std::string PostprocessorSubmodule::Name() const {
  return FLAGS_postprocessor_submodule_name;
}

bool PostprocessorSubmodule::Init() {
  InitControlGFlags(this);
  apollo::common::gflags::init_common(this);
  apollo::common::gflags::init_common_adapter(this);
  ACHECK(cyber::common::GetProtoFromASCIIFile(FLAGS_control_common_conf_file,
                                         &control_common_conf_))
      << "Unable to load control common conf file: "
      << FLAGS_control_common_conf_file;
  postprocessor_writer_ =
      node_->CreateWriter<ControlCommand>(FLAGS_control_command_topic);
  ACHECK(postprocessor_writer_ != nullptr);

  rd_proc = CreateReader<ControlCommand>(declare_parameter<std::string>("proc.channel.0", "/apollo/control/controlcore"),
                                         std::bind(&PostprocessorSubmodule::Proc, this, std::placeholders::_1));

  return true;
}

bool PostprocessorSubmodule::Proc(
    const std::shared_ptr<ControlCommand>& control_core_command) {
  //const auto start_time = Clock::Instance()->Now();
  ControlCommand control_command;
  // get all fields from control_core_command for now
  control_command = *control_core_command;

  // estop handling
  
  if (control_core_command->apolloheader.status.errorcode != ErrorCode::OK) {
    control_command.set__speed(0);
    control_command.set__throttle(0);
    control_command.set__brake(control_common_conf_.softestopbrake);
    control_command.set__gearlocation(apollo::canbus::Chassis::GEAR_DRIVE);
  }

  control_command.apolloheader = control_core_command->apolloheader;

  FillHeader(get_name(), &control_command);

  postprocessor_writer_->Write(control_command);

  return true;
}

}  // namespace control
}  // namespace apollo
CYBER_REGISTER_COMPONENT(PostprocessorSubmodule)