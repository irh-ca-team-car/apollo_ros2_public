#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_provider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceTrajectoryProviderConfig &msg) {
        nlohmann::json obj;
        obj["openspacetrajectoryoptimizerconfig"] = to_json(msg.openspacetrajectoryoptimizerconfig);
        return obj;
    }
    ApolloplanningOpenSpaceTrajectoryProviderConfig from_json_ApolloplanningOpenSpaceTrajectoryProviderConfig (nlohmann::json obj) {
        ApolloplanningOpenSpaceTrajectoryProviderConfig msg;
        if(obj.contains("openspacetrajectoryoptimizerconfig"))
        {
            msg.openspacetrajectoryoptimizerconfig = from_json_ApolloplanningOpenSpaceTrajectoryOptimizerConfig(obj["openspacetrajectoryoptimizerconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpaceTrajectoryProviderConfig from_json<ApolloplanningOpenSpaceTrajectoryProviderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpaceTrajectoryProviderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceTrajectoryProviderConfig &dt)
    {
        dt=from_json_ApolloplanningOpenSpaceTrajectoryProviderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceTrajectoryProviderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceTrajectoryProviderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
