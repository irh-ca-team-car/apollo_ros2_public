#include "adapter/serialization/apollo_msgs/apolloprediction_verification_sample.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionVerificationSample &msg) {
        nlohmann::json obj;
        nlohmann::json arr_features;
        for (auto it = msg.features.begin(); it != msg.features.end(); ++it) {
            arr_features.push_back(to_json(*it));
        }
        obj["features"] = arr_features;
        obj["probability"] = (msg.probability);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollopredictionVerificationSample from_json_ApollopredictionVerificationSample (nlohmann::json obj) {
        ApollopredictionVerificationSample msg;
        if(obj.contains("features"))
        {
            if(obj["features"].is_array())
            {
                for (auto& element : obj["features"])
                {
                    msg.features.push_back(from_json_ApollopredictionTensorParameter(element));
                }
            }
            else
            {
                msg.features.push_back(from_json_ApollopredictionTensorParameter(obj["features"]));
            }
        }
        if(obj.contains("probability"))
        {
            msg.probability = (obj["probability"].is_string()?(float)atof(obj["probability"].get<std::string>().c_str()):obj["probability"].get<float>());
        }
        if(obj.contains("distance"))
        {
            msg.distance = (obj["distance"].is_string()?(float)atof(obj["distance"].get<std::string>().c_str()):obj["distance"].get<float>());
        }
        return msg;
    }
    template <>
    ApollopredictionVerificationSample from_json<ApollopredictionVerificationSample>(nlohmann::json obj){
        return from_json_ApollopredictionVerificationSample(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionVerificationSample &dt)
    {
        dt=from_json_ApollopredictionVerificationSample(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionVerificationSample & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionVerificationSample & dt)
    {
        os << to_json(dt);
        return os;
    }
}
