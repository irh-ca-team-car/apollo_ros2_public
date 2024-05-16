#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/prediction/container/obstacles/obstacle.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::prediction::Obstacle &msg);
    apollo::prediction::Obstacle from_json_Obstacle(nlohmann::json obj);
    template <>
    apollo::prediction::Obstacle from_json<apollo::prediction::Obstacle>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, apollo::prediction::Obstacle &dt);
    std::ostream &operator<<(std::ostream &os, const apollo::prediction::Obstacle &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::prediction::Obstacle &dt);
}