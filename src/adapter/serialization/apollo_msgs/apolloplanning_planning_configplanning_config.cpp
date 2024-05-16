#include "adapter/serialization/apollo_msgs/apolloplanning_planning_configplanning_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningConfigplanningConfig &msg) {
        nlohmann::json obj;
        obj["rtkplanningconfig"] = to_json(msg.rtkplanningconfig);
        obj["standardplanningconfig"] = to_json(msg.standardplanningconfig);
        obj["navigationplanningconfig"] = to_json(msg.navigationplanningconfig);
        return obj;
    }
    ApolloplanningPlanningConfigplanningConfig from_json_ApolloplanningPlanningConfigplanningConfig (nlohmann::json obj) {
        ApolloplanningPlanningConfigplanningConfig msg;
        if(obj.contains("rtkplanningconfig"))
        {
            msg.rtkplanningconfig = from_json_ApolloplanningRtkPlanningConfig(obj["rtkplanningconfig"]);
        }
        if(obj.contains("standardplanningconfig"))
        {
            msg.standardplanningconfig = from_json_ApolloplanningStandardPlanningConfig(obj["standardplanningconfig"]);
        }
        if(obj.contains("navigationplanningconfig"))
        {
            msg.navigationplanningconfig = from_json_ApolloplanningNavigationPlanningConfig(obj["navigationplanningconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningConfigplanningConfig from_json<ApolloplanningPlanningConfigplanningConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningConfigplanningConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningConfigplanningConfig &dt)
    {
        dt=from_json_ApolloplanningPlanningConfigplanningConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningConfigplanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningConfigplanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
