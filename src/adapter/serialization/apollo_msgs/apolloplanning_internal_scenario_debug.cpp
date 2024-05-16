#include "adapter/serialization/apollo_msgs/apolloplanning_internal_scenario_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalScenarioDebug &msg) {
        nlohmann::json obj;
        obj["scenariotype"] = (msg.scenariotype);
        obj["stagetype"] = (msg.stagetype);
        obj["msg"] = (msg.msg);
        return obj;
    }
    ApolloplanningInternalScenarioDebug from_json_ApolloplanningInternalScenarioDebug (nlohmann::json obj) {
        ApolloplanningInternalScenarioDebug msg;
        if(obj.contains("scenariotype"))
        {
            msg.scenariotype = (obj["scenariotype"].is_string()?atoi(obj["scenariotype"].get<std::string>().c_str()):obj["scenariotype"].get<int>());
        }
        if(obj.contains("stagetype"))
        {
            msg.stagetype = (obj["stagetype"].is_string()?atoi(obj["stagetype"].get<std::string>().c_str()):obj["stagetype"].get<int>());
        }
        if(obj.contains("msg"))
        {
            msg.msg = (obj["msg"].is_string()?(obj["msg"].get<std::string>().c_str()):obj["msg"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalScenarioDebug from_json<ApolloplanningInternalScenarioDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalScenarioDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalScenarioDebug &dt)
    {
        dt=from_json_ApolloplanningInternalScenarioDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalScenarioDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalScenarioDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
