#include "modules/planning/proto/traffic_rule_config_name.pb.h"
namespace apollo::planning::TrafficRuleConfig
{
    std::string RuleId_Name(RuleId val)
    {
        switch (val)
        {
        case BACKSIDE_VEHICLE:
            return "BACKSIDE_VEHICLE";
        case CROSSWALK:
            return "CROSSWALK";
        case DESTINATION:
            return "DESTINATION";
        case KEEP_CLEAR:
            return "KEEP_CLEAR";
        case REFERENCE_LINE_END:
            return "REFERENCE_LINE_END";
        case REROUTING:
            return "REROUTING";
        case STOP_SIGN:
            return "STOP_SIGN";
        case TRAFFIC_LIGHT:
            return "TRAFFIC_LIGHT";
        case YIELD_SIGN:
            return "YIELD_SIGN";
        }
        return "?";
    }
}