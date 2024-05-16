#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/onboard/inner_component_messages/inner_component_messages.h"
#include "modules/perception/onboard/internal_messages/frame.h"
#include "modules/perception/onboard/internal_messages/hdmap_struct.h"

namespace apollo_msgs::msg
{
    using apollo::perception::onboard::SensorFrameMessage;
    nlohmann::json to_json(const SensorFrameMessage &msg);
    SensorFrameMessage from_json_SensorFrameMessage(nlohmann::json obj);
    template <>
    SensorFrameMessage from_json<SensorFrameMessage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, SensorFrameMessage &dt);
    std::ostream &operator<<(std::ostream &os, const SensorFrameMessage &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SensorFrameMessage &dt);
}
