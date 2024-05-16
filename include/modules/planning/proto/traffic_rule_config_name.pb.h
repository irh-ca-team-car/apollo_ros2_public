#pragma once
#include "modules/planning/proto/traffic_rule_config.pb.h"
#include <string>
namespace apollo::planning::TrafficRuleConfig
{
    std::string RuleId_Name(RuleId val);
}