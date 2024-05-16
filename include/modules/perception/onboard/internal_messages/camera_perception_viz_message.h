#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/onboard/component/camera_perception_viz_message.h"
#include "modules/perception/onboard/internal_messages/lane_struct.h"
#include "modules/perception/onboard/internal_messages/object.h"
#include "modules/perception/onboard/internal_messages/blob.h"

namespace apollo_msgs::msg
{
    using apollo::perception::onboard::CameraPerceptionVizMessage;
    nlohmann::json to_json(const CameraPerceptionVizMessage &msg);
    CameraPerceptionVizMessage from_json_CameraPerceptionVizMessage(nlohmann::json obj);
    template <>
    CameraPerceptionVizMessage from_json<CameraPerceptionVizMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, CameraPerceptionVizMessage &dt);
    std::ostream &operator<<(std::ostream &os, const CameraPerceptionVizMessage &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CameraPerceptionVizMessage &dt);
}
