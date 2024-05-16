#include "adapter/serialization/apollo_msgs/apolloprediction_input_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionInputParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_inputshape;
        for (auto it = msg.inputshape.begin(); it != msg.inputshape.end(); ++it) {
            arr_inputshape.push_back((*it));
        }
        obj["inputshape"] = arr_inputshape;
        obj["dtype"] = (msg.dtype);
        obj["sparse"] = (msg.sparse);
        return obj;
    }
    ApollopredictionInputParameter from_json_ApollopredictionInputParameter (nlohmann::json obj) {
        ApollopredictionInputParameter msg;
        if(obj.contains("inputshape"))
        {
            if(obj["inputshape"].is_array())
            {
                for (auto& element : obj["inputshape"])
                {
                    msg.inputshape.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.inputshape.push_back((obj["inputshape"].is_string()?atoi(obj["inputshape"].get<std::string>().c_str()):obj["inputshape"].get<int>()));
            }
        }
        if(obj.contains("dtype"))
        {
            msg.dtype = (obj["dtype"].is_string()?(obj["dtype"].get<std::string>().c_str()):obj["dtype"].get<std::string>());
        }
        if(obj.contains("sparse"))
        {
            msg.sparse = (obj["sparse"].is_string()?(bool)atoi(obj["sparse"].get<std::string>().c_str()):obj["sparse"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollopredictionInputParameter from_json<ApollopredictionInputParameter>(nlohmann::json obj){
        return from_json_ApollopredictionInputParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionInputParameter &dt)
    {
        dt=from_json_ApollopredictionInputParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionInputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionInputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
