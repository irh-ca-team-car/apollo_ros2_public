#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_trajectory_raw_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningTrajectoryRawFeature &msg) {
        nlohmann::json obj;
        nlohmann::json arr_pointfeature;
        for (auto it = msg.pointfeature.begin(); it != msg.pointfeature.end(); ++it) {
            arr_pointfeature.push_back(to_json(*it));
        }
        obj["pointfeature"] = arr_pointfeature;
        obj["strawdata"] = to_json(msg.strawdata);
        return obj;
    }
    ApolloplanningautotuningTrajectoryRawFeature from_json_ApolloplanningautotuningTrajectoryRawFeature (nlohmann::json obj) {
        ApolloplanningautotuningTrajectoryRawFeature msg;
        if(obj.contains("pointfeature"))
        {
            if(obj["pointfeature"].is_array())
            {
                for (auto& element : obj["pointfeature"])
                {
                    msg.pointfeature.push_back(from_json_ApolloplanningautotuningTrajectoryPointRawFeature(element));
                }
            }
            else
            {
                msg.pointfeature.push_back(from_json_ApolloplanningautotuningTrajectoryPointRawFeature(obj["pointfeature"]));
            }
        }
        if(obj.contains("strawdata"))
        {
            msg.strawdata = from_json_ApolloplanningautotuningObstacleSTRawData(obj["strawdata"]);
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningTrajectoryRawFeature from_json<ApolloplanningautotuningTrajectoryRawFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningTrajectoryRawFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningTrajectoryRawFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningTrajectoryRawFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningTrajectoryRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningTrajectoryRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
