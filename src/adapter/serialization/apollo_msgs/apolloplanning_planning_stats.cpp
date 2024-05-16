#include "adapter/serialization/apollo_msgs/apolloplanning_planning_stats.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningStats &msg) {
        nlohmann::json obj;
        obj["totalpathlength"] = to_json(msg.totalpathlength);
        obj["totalpathtime"] = to_json(msg.totalpathtime);
        obj["v"] = to_json(msg.v);
        obj["a"] = to_json(msg.a);
        obj["kappa"] = to_json(msg.kappa);
        obj["dkappa"] = to_json(msg.dkappa);
        return obj;
    }
    ApolloplanningPlanningStats from_json_ApolloplanningPlanningStats (nlohmann::json obj) {
        ApolloplanningPlanningStats msg;
        if(obj.contains("totalpathlength"))
        {
            msg.totalpathlength = from_json_ApolloplanningStatsGroup(obj["totalpathlength"]);
        }
        if(obj.contains("totalpathtime"))
        {
            msg.totalpathtime = from_json_ApolloplanningStatsGroup(obj["totalpathtime"]);
        }
        if(obj.contains("v"))
        {
            msg.v = from_json_ApolloplanningStatsGroup(obj["v"]);
        }
        if(obj.contains("a"))
        {
            msg.a = from_json_ApolloplanningStatsGroup(obj["a"]);
        }
        if(obj.contains("kappa"))
        {
            msg.kappa = from_json_ApolloplanningStatsGroup(obj["kappa"]);
        }
        if(obj.contains("dkappa"))
        {
            msg.dkappa = from_json_ApolloplanningStatsGroup(obj["dkappa"]);
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningStats from_json<ApolloplanningPlanningStats>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningStats(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningStats &dt)
    {
        dt=from_json_ApolloplanningPlanningStats(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningStats & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningStats & dt)
    {
        os << to_json(dt);
        return os;
    }
}
