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

#pragma once

#include <memory>
#include <string>

#include "cyber/common/macros.h"
#include "modules/common/monitor_log/monitor_log_buffer.h"

namespace apollo {
namespace storytelling {

class FrameManager {
 public:
  FrameManager();

  void StartFrame();
  void EndFrame();

  // Getters.
  apollo::common::monitor::MonitorLogBuffer& LogBuffer() { return log_buffer_; }

  // Cyber reader / writer creator.
  template <class T>
  std::shared_ptr<cyber::Reader<T>> CreateOrGetReader(
      const std::string& channel) {
    auto reader = apollo::cyber::ComponentBase::instance()->GetReader<T>(channel);
    return reader != nullptr ? reader : apollo::cyber::ComponentBase::instance()->CreateReader<T>(channel);
  }

  template <class T>
  std::shared_ptr<cyber::Writer<T>> CreateWriter(const std::string& channel) {
    return apollo::cyber::ComponentBase::instance()->CreateWriter<T>(channel);
  }

 private:
  apollo::common::monitor::MonitorLogBuffer log_buffer_;
};

}  // namespace storytelling
}  // namespace apollo
