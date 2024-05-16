#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/map/hdmap/hdmap_common.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::hdmap::LaneInfo &msg);
    apollo::hdmap::LaneInfo from_json_LaneInfo(nlohmann::json obj);
    template <>
    apollo::hdmap::LaneInfo from_json<apollo::hdmap::LaneInfo>(nlohmann::json obj);
    std::ostream &operator<<(std::ostream &os, const apollo::hdmap::LaneInfo &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::hdmap::LaneInfo &dt);
}