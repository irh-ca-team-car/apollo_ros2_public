#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/map/hdmap/hdmap_common.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::hdmap::JunctionInfo &msg);
    apollo::hdmap::JunctionInfo from_json_JunctionInfo(nlohmann::json obj);
    template <>
    apollo::hdmap::JunctionInfo from_json<apollo::hdmap::JunctionInfo>(nlohmann::json obj);
    std::ostream &operator<<(std::ostream &os, const apollo::hdmap::JunctionInfo &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::hdmap::JunctionInfo &dt);
}