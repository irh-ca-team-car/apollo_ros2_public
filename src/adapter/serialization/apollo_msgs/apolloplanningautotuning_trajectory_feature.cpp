#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryFeature &msg) {
        nlohmann::json obj;
        nlohmann::json arr_pointfeature;
        for (auto it = msg.pointfeature.begin(); it != msg.pointfeature.end(); ++it) {
            arr_pointfeature.push_back(to_json(*it));
        }
        obj["pointfeature"] = arr_pointfeature;
        return obj;
    }
    ApolloplanningautotuningTrajectoryFeature from_json_ApolloplanningautotuningTrajectoryFeature (nlohmann::json obj) {
        ApolloplanningautotuningTrajectoryFeature msg;
        if(obj.contains("pointfeature"))
        {
            if(obj["pointfeature"].is_array())
            {
                for (auto& element : obj["pointfeature"])
                {
                    msg.pointfeature.push_back(from_json_ApolloplanningautotuningTrajectoryPointwiseFeature(element));
                }
            }
            else
            {
                msg.pointfeature.push_back(from_json_ApolloplanningautotuningTrajectoryPointwiseFeature(obj["pointfeature"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningTrajectoryFeature from_json<ApolloplanningautotuningTrajectoryFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningTrajectoryFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningTrajectoryFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
