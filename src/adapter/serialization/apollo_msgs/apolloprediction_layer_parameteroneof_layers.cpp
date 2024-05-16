#include "adapter/serialization/apollo_msgs/apolloprediction_layer_parameteroneof_layers.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLayerParameteroneofLayers &msg) {
        nlohmann::json obj;
        obj["input"] = to_json(msg.input);
        obj["activation"] = to_json(msg.activation);
        obj["dense"] = to_json(msg.dense);
        obj["batchnormalization"] = to_json(msg.batchnormalization);
        obj["lstm"] = to_json(msg.lstm);
        obj["flatten"] = (msg.flatten);
        obj["concatenate"] = to_json(msg.concatenate);
        obj["conv1d"] = to_json(msg.conv1d);
        obj["maxpool1d"] = to_json(msg.maxpool1d);
        obj["avgpool1d"] = to_json(msg.avgpool1d);
        return obj;
    }
    ApollopredictionLayerParameteroneofLayers from_json_ApollopredictionLayerParameteroneofLayers (nlohmann::json obj) {
        ApollopredictionLayerParameteroneofLayers msg;
        if(obj.contains("input"))
        {
            msg.input = from_json_ApollopredictionInputParameter(obj["input"]);
        }
        if(obj.contains("activation"))
        {
            msg.activation = from_json_ApollopredictionActivationParameter(obj["activation"]);
        }
        if(obj.contains("dense"))
        {
            msg.dense = from_json_ApollopredictionDenseParameter(obj["dense"]);
        }
        if(obj.contains("batchnormalization"))
        {
            msg.batchnormalization = from_json_ApollopredictionBatchNormalizationParameter(obj["batchnormalization"]);
        }
        if(obj.contains("lstm"))
        {
            msg.lstm = from_json_ApollopredictionLSTMParameter(obj["lstm"]);
        }
        if(obj.contains("flatten"))
        {
            msg.flatten = (obj["flatten"].is_string()?atoi(obj["flatten"].get<std::string>().c_str()):obj["flatten"].get<int>());
        }
        if(obj.contains("concatenate"))
        {
            msg.concatenate = from_json_ApollopredictionConcatenateParameter(obj["concatenate"]);
        }
        if(obj.contains("conv1d"))
        {
            msg.conv1d = from_json_ApollopredictionConv1dParameter(obj["conv1d"]);
        }
        if(obj.contains("maxpool1d"))
        {
            msg.maxpool1d = from_json_ApollopredictionMaxPool1dParameter(obj["maxpool1d"]);
        }
        if(obj.contains("avgpool1d"))
        {
            msg.avgpool1d = from_json_ApollopredictionAvgPool1dParameter(obj["avgpool1d"]);
        }
        return msg;
    }
    template <>
    ApollopredictionLayerParameteroneofLayers from_json<ApollopredictionLayerParameteroneofLayers>(nlohmann::json obj){
        return from_json_ApollopredictionLayerParameteroneofLayers(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLayerParameteroneofLayers &dt)
    {
        dt=from_json_ApollopredictionLayerParameteroneofLayers(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLayerParameteroneofLayers & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLayerParameteroneofLayers & dt)
    {
        os << to_json(dt);
        return os;
    }
}
