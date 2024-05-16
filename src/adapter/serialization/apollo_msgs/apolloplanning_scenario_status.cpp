#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioStatus &msg) {
        nlohmann::json obj;
        obj["scenariotype"] = (msg.scenariotype);
        obj["stagetype"] = (msg.stagetype);
        return obj;
    }
    ApolloplanningScenarioStatus from_json_ApolloplanningScenarioStatus (nlohmann::json obj) {
        ApolloplanningScenarioStatus msg;
        if(obj.contains("scenariotype"))
        {
            msg.scenariotype = (obj["scenariotype"].is_string()?atoi(obj["scenariotype"].get<std::string>().c_str()):obj["scenariotype"].get<int>());
        }
        if(obj.contains("stagetype"))
        {
            msg.stagetype = (obj["stagetype"].is_string()?atoi(obj["stagetype"].get<std::string>().c_str()):obj["stagetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioStatus from_json<ApolloplanningScenarioStatus>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioStatus &dt)
    {
        dt=from_json_ApolloplanningScenarioStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
