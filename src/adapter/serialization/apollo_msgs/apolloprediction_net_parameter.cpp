#include "adapter/serialization/apollo_msgs/apolloprediction_net_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionNetParameter &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["name"] = (msg.name);
        nlohmann::json arr_layers;
        for (auto it = msg.layers.begin(); it != msg.layers.end(); ++it) {
            arr_layers.push_back(to_json(*it));
        }
        obj["layers"] = arr_layers;
        nlohmann::json arr_verificationsamples;
        for (auto it = msg.verificationsamples.begin(); it != msg.verificationsamples.end(); ++it) {
            arr_verificationsamples.push_back(to_json(*it));
        }
        obj["verificationsamples"] = arr_verificationsamples;
        obj["performance"] = to_json(msg.performance);
        obj["timedumped"] = (msg.timedumped);
        return obj;
    }
    ApollopredictionNetParameter from_json_ApollopredictionNetParameter (nlohmann::json obj) {
        ApollopredictionNetParameter msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("layers"))
        {
            if(obj["layers"].is_array())
            {
                for (auto& element : obj["layers"])
                {
                    msg.layers.push_back(from_json_ApollopredictionLayerParameter(element));
                }
            }
            else
            {
                msg.layers.push_back(from_json_ApollopredictionLayerParameter(obj["layers"]));
            }
        }
        if(obj.contains("verificationsamples"))
        {
            if(obj["verificationsamples"].is_array())
            {
                for (auto& element : obj["verificationsamples"])
                {
                    msg.verificationsamples.push_back(from_json_ApollopredictionVerificationSample(element));
                }
            }
            else
            {
                msg.verificationsamples.push_back(from_json_ApollopredictionVerificationSample(obj["verificationsamples"]));
            }
        }
        if(obj.contains("performance"))
        {
            msg.performance = from_json_ApollopredictionPerformance(obj["performance"]);
        }
        if(obj.contains("timedumped"))
        {
            msg.timedumped = (obj["timedumped"].is_string()?(float)atof(obj["timedumped"].get<std::string>().c_str()):obj["timedumped"].get<float>());
        }
        return msg;
    }
    template <>
    ApollopredictionNetParameter from_json<ApollopredictionNetParameter>(nlohmann::json obj){
        return from_json_ApollopredictionNetParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionNetParameter &dt)
    {
        dt=from_json_ApollopredictionNetParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionNetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionNetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
