#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_configs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficRuleConfigs &msg) {
        nlohmann::json obj;
        nlohmann::json arr_config;
        for (auto it = msg.config.begin(); it != msg.config.end(); ++it) {
            arr_config.push_back(to_json(*it));
        }
        obj["config"] = arr_config;
        return obj;
    }
    ApolloplanningTrafficRuleConfigs from_json_ApolloplanningTrafficRuleConfigs (nlohmann::json obj) {
        ApolloplanningTrafficRuleConfigs msg;
        if(obj.contains("config"))
        {
            if(obj["config"].is_array())
            {
                for (auto& element : obj["config"])
                {
                    msg.config.push_back(from_json_ApolloplanningTrafficRuleConfig(element));
                }
            }
            else
            {
                msg.config.push_back(from_json_ApolloplanningTrafficRuleConfig(obj["config"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningTrafficRuleConfigs from_json<ApolloplanningTrafficRuleConfigs>(nlohmann::json obj){
        return from_json_ApolloplanningTrafficRuleConfigs(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficRuleConfigs &dt)
    {
        dt=from_json_ApolloplanningTrafficRuleConfigs(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficRuleConfigs & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficRuleConfigs & dt)
    {
        os << to_json(dt);
        return os;
    }
}
