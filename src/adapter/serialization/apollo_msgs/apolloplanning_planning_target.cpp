#include "adapter/serialization/apollo_msgs/apolloplanning_planning_target.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningTarget &msg) {
        nlohmann::json obj;
        obj["stoppoint"] = to_json(msg.stoppoint);
        obj["cruisespeed"] = (msg.cruisespeed);
        return obj;
    }
    ApolloplanningPlanningTarget from_json_ApolloplanningPlanningTarget (nlohmann::json obj) {
        ApolloplanningPlanningTarget msg;
        if(obj.contains("stoppoint"))
        {
            msg.stoppoint = from_json_ApolloplanningStopPoint(obj["stoppoint"]);
        }
        if(obj.contains("cruisespeed"))
        {
            msg.cruisespeed = (obj["cruisespeed"].is_string()?atof(obj["cruisespeed"].get<std::string>().c_str()):obj["cruisespeed"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningTarget from_json<ApolloplanningPlanningTarget>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningTarget(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningTarget &dt)
    {
        dt=from_json_ApolloplanningPlanningTarget(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningTarget & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningTarget & dt)
    {
        os << to_json(dt);
        return os;
    }
}
