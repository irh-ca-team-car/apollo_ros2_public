#include "adapter/serialization/apollo_msgs/apolloprediction_tensor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionTensorParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_data;
        for (auto it = msg.data.begin(); it != msg.data.end(); ++it) {
            arr_data.push_back((*it));
        }
        obj["data"] = arr_data;
        nlohmann::json arr_shape;
        for (auto it = msg.shape.begin(); it != msg.shape.end(); ++it) {
            arr_shape.push_back((*it));
        }
        obj["shape"] = arr_shape;
        return obj;
    }
    ApollopredictionTensorParameter from_json_ApollopredictionTensorParameter (nlohmann::json obj) {
        ApollopredictionTensorParameter msg;
        if(obj.contains("data"))
        {
            if(obj["data"].is_array())
            {
                for (auto& element : obj["data"])
                {
                    msg.data.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.data.push_back((obj["data"].is_string()?(float)atof(obj["data"].get<std::string>().c_str()):obj["data"].get<float>()));
            }
        }
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
        return msg;
    }
    template <>
    ApollopredictionTensorParameter from_json<ApollopredictionTensorParameter>(nlohmann::json obj){
        return from_json_ApollopredictionTensorParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionTensorParameter &dt)
    {
        dt=from_json_ApollopredictionTensorParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionTensorParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionTensorParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
