#pragma once
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "modules/prediction/submodules/submodule_output.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const apollo::prediction::SubmoduleOutput &msg);
    apollo::prediction::SubmoduleOutput from_json_SubmoduleOutput(nlohmann::json obj);
    template <>
    apollo::prediction::SubmoduleOutput from_json<apollo::prediction::SubmoduleOutput>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, apollo::prediction::SubmoduleOutput &dt);
    std::ostream &operator<<(std::ostream &os, const apollo::prediction::SubmoduleOutput &dt);
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const apollo::prediction::SubmoduleOutput &dt);
}