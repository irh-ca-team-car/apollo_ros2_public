#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_pointwise_feature_obstacle_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningPathPointwiseFeatureObstacleFeature &msg) {
        nlohmann::json obj;
        obj["lateraldistance"] = (msg.lateraldistance);
        return obj;
    }
    ApolloplanningautotuningPathPointwiseFeatureObstacleFeature from_json_ApolloplanningautotuningPathPointwiseFeatureObstacleFeature (nlohmann::json obj) {
        ApolloplanningautotuningPathPointwiseFeatureObstacleFeature msg;
        if(obj.contains("lateraldistance"))
        {
            msg.lateraldistance = (obj["lateraldistance"].is_string()?atof(obj["lateraldistance"].get<std::string>().c_str()):obj["lateraldistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningPathPointwiseFeatureObstacleFeature from_json<ApolloplanningautotuningPathPointwiseFeatureObstacleFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningPathPointwiseFeatureObstacleFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningPathPointwiseFeatureObstacleFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningPathPointwiseFeatureObstacleFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningPathPointwiseFeatureObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningPathPointwiseFeatureObstacleFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
