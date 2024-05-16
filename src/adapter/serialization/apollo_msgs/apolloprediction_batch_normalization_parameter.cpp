#include "adapter/serialization/apollo_msgs/apolloprediction_batch_normalization_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionBatchNormalizationParameter &msg) {
        nlohmann::json obj;
        obj["epsilon"] = (msg.epsilon);
        obj["axis"] = (msg.axis);
        obj["center"] = (msg.center);
        obj["scale"] = (msg.scale);
        obj["momentum"] = (msg.momentum);
        obj["mu"] = to_json(msg.mu);
        obj["sigma"] = to_json(msg.sigma);
        obj["gamma"] = to_json(msg.gamma);
        obj["beta"] = to_json(msg.beta);
        return obj;
    }
    ApollopredictionBatchNormalizationParameter from_json_ApollopredictionBatchNormalizationParameter (nlohmann::json obj) {
        ApollopredictionBatchNormalizationParameter msg;
        if(obj.contains("epsilon"))
        {
            msg.epsilon = (obj["epsilon"].is_string()?atof(obj["epsilon"].get<std::string>().c_str()):obj["epsilon"].get<double>());
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("center"))
        {
            msg.center = (obj["center"].is_string()?(bool)atoi(obj["center"].get<std::string>().c_str()):obj["center"].get<bool>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(bool)atoi(obj["scale"].get<std::string>().c_str()):obj["scale"].get<bool>());
        }
        if(obj.contains("momentum"))
        {
            msg.momentum = (obj["momentum"].is_string()?(float)atof(obj["momentum"].get<std::string>().c_str()):obj["momentum"].get<float>());
        }
        if(obj.contains("mu"))
        {
            msg.mu = from_json_ApollopredictionTensorParameter(obj["mu"]);
        }
        if(obj.contains("sigma"))
        {
            msg.sigma = from_json_ApollopredictionTensorParameter(obj["sigma"]);
        }
        if(obj.contains("gamma"))
        {
            msg.gamma = from_json_ApollopredictionTensorParameter(obj["gamma"]);
        }
        if(obj.contains("beta"))
        {
            msg.beta = from_json_ApollopredictionTensorParameter(obj["beta"]);
        }
        return msg;
    }
    template <>
    ApollopredictionBatchNormalizationParameter from_json<ApollopredictionBatchNormalizationParameter>(nlohmann::json obj){
        return from_json_ApollopredictionBatchNormalizationParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionBatchNormalizationParameter &dt)
    {
        dt=from_json_ApollopredictionBatchNormalizationParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionBatchNormalizationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionBatchNormalizationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
