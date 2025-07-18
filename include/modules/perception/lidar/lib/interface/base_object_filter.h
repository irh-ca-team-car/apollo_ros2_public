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
#pragma once

#include <string>

#include "cyber/cyber.h"
#include "modules/perception/lib/registerer/registerer.h"
#include "modules/perception/lidar/common/lidar_frame.h"

namespace apollo {
namespace perception {
namespace lidar {

struct ObjectFilterInitOptions {
  std::string sensor_name = "velodyne64";
};

struct ObjectFilterOptions {};

class BaseObjectFilter {
 public:
  BaseObjectFilter() = default;

  virtual ~BaseObjectFilter() = default;

  virtual bool Init(
      const ObjectFilterInitOptions& options = ObjectFilterInitOptions()) = 0;

  // @brief: filter objects
  // @param [in]: options
  // @param [in/out]: frame
  // segmented_objects should be valid, and will be filtered,
  virtual bool Filter(const ObjectFilterOptions& options,
                      LidarFrame* frame) = 0;

  virtual std::string Name() const = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(BaseObjectFilter);
};  // class BaseObjectFilter

PERCEPTION_REGISTER_REGISTERER(BaseObjectFilter);
#define PERCEPTION_REGISTER_OBJECTFILTER(name) \
  PERCEPTION_REGISTER_CLASS(BaseObjectFilter, name)

}  // namespace lidar
}  // namespace perception
}  // namespace apollo
