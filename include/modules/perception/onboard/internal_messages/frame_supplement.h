#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/frame_supplement.h"
#include "modules/perception/onboard/internal_messages/blob.h"
#include "modules/perception/onboard/internal_messages/image_8u.h"
#include "modules/perception/onboard/internal_messages/impending_collision_edge.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::LidarFrameSupplement;
    nlohmann::json to_json(const LidarFrameSupplement &msg);
    LidarFrameSupplement from_json_LidarFrameSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LidarFrameSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const LidarFrameSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarFrameSupplement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::RadarFrameSupplement;
    nlohmann::json to_json(const RadarFrameSupplement &msg);
    RadarFrameSupplement from_json_RadarFrameSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, RadarFrameSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const RadarFrameSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const RadarFrameSupplement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::CameraFrameSupplement;
    nlohmann::json to_json(const CameraFrameSupplement &msg);
    CameraFrameSupplement from_json_CameraFrameSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, CameraFrameSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const CameraFrameSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CameraFrameSupplement &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::UltrasonicFrameSupplement;
    nlohmann::json to_json(const UltrasonicFrameSupplement &msg);
    UltrasonicFrameSupplement from_json_UltrasonicFrameSupplement(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, UltrasonicFrameSupplement &dt);
    std::ostream &operator<<(std::ostream &os, const UltrasonicFrameSupplement &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const UltrasonicFrameSupplement &dt);
}
