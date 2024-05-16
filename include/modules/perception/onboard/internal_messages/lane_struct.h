#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
#include "modules/perception/base/lane_struct.h"
#include "modules/perception/onboard/internal_messages/point.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::LaneLineCubicCurve;
    nlohmann::json to_json(const LaneLineCubicCurve &msg);
    LaneLineCubicCurve from_json_LaneLineCubicCurve(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LaneLineCubicCurve &dt);
    std::ostream &operator<<(std::ostream &os, const LaneLineCubicCurve &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LaneLineCubicCurve &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::EndPoints;
    nlohmann::json to_json(const EndPoints &msg);
    EndPoints from_json_EndPoints(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, EndPoints &dt);
    std::ostream &operator<<(std::ostream &os, const EndPoints &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const EndPoints &dt);
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::LaneLine;
    nlohmann::json to_json(const LaneLine &msg);
    LaneLine from_json_LaneLine(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, LaneLine &dt);
    std::ostream &operator<<(std::ostream &os, const LaneLine &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LaneLine &dt);
}
