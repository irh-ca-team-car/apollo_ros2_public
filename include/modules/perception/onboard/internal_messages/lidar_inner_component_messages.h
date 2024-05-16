#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/onboard/component/lidar_inner_component_messages.h"
#include "modules/perception/onboard/internal_messages/lidar_frame.h"

namespace apollo_msgs::msg
{
    using apollo::perception::onboard::LidarFrameMessage;
    nlohmann::json to_json(const LidarFrameMessage &msg);
    LidarFrameMessage from_json_LidarFrameMessage(nlohmann::json obj);
    template <>
    LidarFrameMessage from_json<LidarFrameMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LidarFrameMessage &dt);
    std::ostream &operator<<(std::ostream &os, const LidarFrameMessage &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarFrameMessage &dt);
}
