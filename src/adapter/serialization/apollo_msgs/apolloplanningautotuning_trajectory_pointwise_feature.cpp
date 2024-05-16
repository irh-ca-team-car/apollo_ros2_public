#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_pointwise_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryPointwiseFeature &msg) {
        nlohmann::json obj;
        obj["pathinputfeature"] = to_json(msg.pathinputfeature);
        obj["speedinputfeature"] = to_json(msg.speedinputfeature);
        return obj;
    }
    ApolloplanningautotuningTrajectoryPointwiseFeature from_json_ApolloplanningautotuningTrajectoryPointwiseFeature (nlohmann::json obj) {
        ApolloplanningautotuningTrajectoryPointwiseFeature msg;
        if(obj.contains("pathinputfeature"))
        {
            msg.pathinputfeature = from_json_ApolloplanningautotuningPathPointwiseFeature(obj["pathinputfeature"]);
        }
        if(obj.contains("speedinputfeature"))
        {
            msg.speedinputfeature = from_json_ApolloplanningautotuningSpeedPointwiseFeature(obj["speedinputfeature"]);
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningTrajectoryPointwiseFeature from_json<ApolloplanningautotuningTrajectoryPointwiseFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningTrajectoryPointwiseFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryPointwiseFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningTrajectoryPointwiseFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryPointwiseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryPointwiseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
