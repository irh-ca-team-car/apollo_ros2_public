#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficRuleConfig &msg) {
        nlohmann::json obj;
        obj["ruleid"] = (msg.ruleid);
        obj["enabled"] = (msg.enabled);
        obj["config"] = to_json(msg.config);
        return obj;
    }
    ApolloplanningTrafficRuleConfig from_json_ApolloplanningTrafficRuleConfig (nlohmann::json obj) {
        ApolloplanningTrafficRuleConfig msg;
        if(obj.contains("ruleid"))
        {
            msg.ruleid = (obj["ruleid"].is_string()?atoi(obj["ruleid"].get<std::string>().c_str()):obj["ruleid"].get<int>());
        }
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("config"))
        {
            msg.config = from_json_ApolloplanningTrafficRuleConfigconfig(obj["config"]);
        }
        return msg;
    }
    template <>
    ApolloplanningTrafficRuleConfig from_json<ApolloplanningTrafficRuleConfig>(nlohmann::json obj){
        return from_json_ApolloplanningTrafficRuleConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficRuleConfig &dt)
    {
        dt=from_json_ApolloplanningTrafficRuleConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficRuleConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficRuleConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
