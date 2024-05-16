#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_point_raw_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryPointRawFeature &msg) {
        nlohmann::json obj;
        obj["pathfeature"] = to_json(msg.pathfeature);
        obj["speedfeature"] = to_json(msg.speedfeature);
        return obj;
    }
    ApolloplanningautotuningTrajectoryPointRawFeature from_json_ApolloplanningautotuningTrajectoryPointRawFeature (nlohmann::json obj) {
        ApolloplanningautotuningTrajectoryPointRawFeature msg;
        if(obj.contains("pathfeature"))
        {
            msg.pathfeature = from_json_ApolloplanningautotuningPathPointRawFeature(obj["pathfeature"]);
        }
        if(obj.contains("speedfeature"))
        {
            msg.speedfeature = from_json_ApolloplanningautotuningSpeedPointRawFeature(obj["speedfeature"]);
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningTrajectoryPointRawFeature from_json<ApolloplanningautotuningTrajectoryPointRawFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningTrajectoryPointRawFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryPointRawFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningTrajectoryPointRawFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryPointRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryPointRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
