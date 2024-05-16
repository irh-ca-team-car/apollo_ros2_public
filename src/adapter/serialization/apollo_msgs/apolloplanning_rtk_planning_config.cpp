#include "adapter/serialization/apollo_msgs/apolloplanning_rtk_planning_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRtkPlanningConfig &msg) {
        nlohmann::json obj;
        obj["plannertype"] = (msg.plannertype);
        return obj;
    }
    ApolloplanningRtkPlanningConfig from_json_ApolloplanningRtkPlanningConfig (nlohmann::json obj) {
        ApolloplanningRtkPlanningConfig msg;
        if(obj.contains("plannertype"))
        {
            msg.plannertype = (obj["plannertype"].is_string()?atoi(obj["plannertype"].get<std::string>().c_str()):obj["plannertype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningRtkPlanningConfig from_json<ApolloplanningRtkPlanningConfig>(nlohmann::json obj){
        return from_json_ApolloplanningRtkPlanningConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRtkPlanningConfig &dt)
    {
        dt=from_json_ApolloplanningRtkPlanningConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRtkPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRtkPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
