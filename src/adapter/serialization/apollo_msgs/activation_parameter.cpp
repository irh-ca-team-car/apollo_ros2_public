#include "adapter/serialization/apollo_msgs/activation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ActivationParameter &msg) {
        nlohmann::json obj;
        obj["activation"] = (msg.activation);
        return obj;
    }
    ActivationParameter from_json_ActivationParameter (nlohmann::json obj) {
        ActivationParameter msg;
        if(obj.contains("activation"))
        {
            msg.activation = (obj["activation"].is_string()?(obj["activation"].get<std::string>().c_str()):obj["activation"].get<std::string>());
        }
        return msg;
    }
    template <>
    ActivationParameter from_json<ActivationParameter>(nlohmann::json obj){
        return from_json_ActivationParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ActivationParameter &dt)
    {
        dt=from_json_ActivationParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ActivationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ActivationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
