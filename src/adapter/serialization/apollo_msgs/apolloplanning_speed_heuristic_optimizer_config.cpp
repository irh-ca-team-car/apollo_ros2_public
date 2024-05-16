#include "adapter/serialization/apollo_msgs/apolloplanning_speed_heuristic_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpeedHeuristicOptimizerConfig &msg) {
        nlohmann::json obj;
        obj["defaultspeedconfig"] = to_json(msg.defaultspeedconfig);
        obj["lanechangespeedconfig"] = to_json(msg.lanechangespeedconfig);
        return obj;
    }
    ApolloplanningSpeedHeuristicOptimizerConfig from_json_ApolloplanningSpeedHeuristicOptimizerConfig (nlohmann::json obj) {
        ApolloplanningSpeedHeuristicOptimizerConfig msg;
        if(obj.contains("defaultspeedconfig"))
        {
            msg.defaultspeedconfig = from_json_ApolloplanningDpStSpeedOptimizerConfig(obj["defaultspeedconfig"]);
        }
        if(obj.contains("lanechangespeedconfig"))
        {
            msg.lanechangespeedconfig = from_json_ApolloplanningDpStSpeedOptimizerConfig(obj["lanechangespeedconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningSpeedHeuristicOptimizerConfig from_json<ApolloplanningSpeedHeuristicOptimizerConfig>(nlohmann::json obj){
        return from_json_ApolloplanningSpeedHeuristicOptimizerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpeedHeuristicOptimizerConfig &dt)
    {
        dt=from_json_ApolloplanningSpeedHeuristicOptimizerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpeedHeuristicOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpeedHeuristicOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
