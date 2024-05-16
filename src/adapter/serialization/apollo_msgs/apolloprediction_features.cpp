#include "adapter/serialization/apollo_msgs/apolloprediction_features.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFeatures &msg) {
        nlohmann::json obj;
        nlohmann::json arr_feature;
        for (auto it = msg.feature.begin(); it != msg.feature.end(); ++it) {
            arr_feature.push_back(to_json(*it));
        }
        obj["feature"] = arr_feature;
        return obj;
    }
    ApollopredictionFeatures from_json_ApollopredictionFeatures (nlohmann::json obj) {
        ApollopredictionFeatures msg;
        if(obj.contains("feature"))
        {
            if(obj["feature"].is_array())
            {
                for (auto& element : obj["feature"])
                {
                    msg.feature.push_back(from_json_ApollopredictionFeature(element));
                }
            }
            else
            {
                msg.feature.push_back(from_json_ApollopredictionFeature(obj["feature"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionFeatures from_json<ApollopredictionFeatures>(nlohmann::json obj){
        return from_json_ApollopredictionFeatures(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFeatures &dt)
    {
        dt=from_json_ApollopredictionFeatures(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFeatures & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFeatures & dt)
    {
        os << to_json(dt);
        return os;
    }
}
