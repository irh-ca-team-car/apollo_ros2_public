#include "adapter/serialization/apollo_msgs/apolloprediction_activation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionActivationParameter &msg) {
        nlohmann::json obj;
        obj["activation"] = (msg.activation);
        return obj;
    }
    ApollopredictionActivationParameter from_json_ApollopredictionActivationParameter (nlohmann::json obj) {
        ApollopredictionActivationParameter msg;
        if(obj.contains("activation"))
        {
            msg.activation = (obj["activation"].is_string()?(obj["activation"].get<std::string>().c_str()):obj["activation"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollopredictionActivationParameter from_json<ApollopredictionActivationParameter>(nlohmann::json obj){
        return from_json_ApollopredictionActivationParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionActivationParameter &dt)
    {
        dt=from_json_ApollopredictionActivationParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionActivationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionActivationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
