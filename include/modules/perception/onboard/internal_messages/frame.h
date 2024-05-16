#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/frame.h"
#include "modules/perception/onboard/internal_messages/sensor_meta.h"
#include "modules/perception/onboard/internal_messages/object.h"
#include "modules/perception/onboard/internal_messages/frame_supplement.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Frame;
    nlohmann::json to_json(const Frame &msg);
    Frame from_json_Frame(nlohmann::json obj);
    template <>
    Frame from_json<Frame>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, Frame &dt);
    std::ostream &operator<<(std::ostream &os, const Frame &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Frame &dt);
}
