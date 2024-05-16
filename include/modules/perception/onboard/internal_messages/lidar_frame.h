#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/lidar/common/lidar_frame.h"
#include "modules/perception/onboard/internal_messages/point.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/sensor_meta.h"
#include "modules/perception/onboard/internal_messages/hdmap_struct.h"
#include "modules/perception/onboard/internal_messages/object.h"

namespace apollo_msgs::msg
{
    using apollo::perception::lidar::LidarFrame;
    nlohmann::json to_json(const LidarFrame &msg);
    LidarFrame from_json_LidarFrame(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LidarFrame &dt);
    std::ostream &operator<<(std::ostream &os, const LidarFrame &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarFrame &dt);
}
