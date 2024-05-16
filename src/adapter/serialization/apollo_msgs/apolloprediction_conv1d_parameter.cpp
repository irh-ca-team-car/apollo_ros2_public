#include "adapter/serialization/apollo_msgs/apolloprediction_conv1d_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionConv1dParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_shape;
        for (auto it = msg.shape.begin(); it != msg.shape.end(); ++it) {
            arr_shape.push_back((*it));
        }
        obj["shape"] = arr_shape;
        obj["usebias"] = (msg.usebias);
        obj["kernel"] = to_json(msg.kernel);
        obj["bias"] = to_json(msg.bias);
        obj["stride"] = (msg.stride);
        return obj;
    }
    ApollopredictionConv1dParameter from_json_ApollopredictionConv1dParameter (nlohmann::json obj) {
        ApollopredictionConv1dParameter msg;
        if(obj.contains("shape"))
        {
            if(obj["shape"].is_array())
            {
                for (auto& element : obj["shape"])
                {
                    msg.shape.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.shape.push_back((obj["shape"].is_string()?atoi(obj["shape"].get<std::string>().c_str()):obj["shape"].get<int>()));
            }
        }
        if(obj.contains("usebias"))
        {
            msg.usebias = (obj["usebias"].is_string()?(bool)atoi(obj["usebias"].get<std::string>().c_str()):obj["usebias"].get<bool>());
        }
        if(obj.contains("kernel"))
        {
            msg.kernel = from_json_ApollopredictionTensorParameter(obj["kernel"]);
        }
        if(obj.contains("bias"))
        {
            msg.bias = from_json_ApollopredictionTensorParameter(obj["bias"]);
        }
        if(obj.contains("stride"))
        {
            msg.stride = (obj["stride"].is_string()?atoi(obj["stride"].get<std::string>().c_str()):obj["stride"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionConv1dParameter from_json<ApollopredictionConv1dParameter>(nlohmann::json obj){
        return from_json_ApollopredictionConv1dParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionConv1dParameter &dt)
    {
        dt=from_json_ApollopredictionConv1dParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionConv1dParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionConv1dParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
