#include "adapter/serialization/apollo_msgs/apolloperceptioninference_flatten_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceFlattenParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        obj["endaxis"] = (msg.endaxis);
        return obj;
    }
    ApolloperceptioninferenceFlattenParameter from_json_ApolloperceptioninferenceFlattenParameter (nlohmann::json obj) {
        ApolloperceptioninferenceFlattenParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("endaxis"))
        {
            msg.endaxis = (obj["endaxis"].is_string()?atoi(obj["endaxis"].get<std::string>().c_str()):obj["endaxis"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceFlattenParameter from_json<ApolloperceptioninferenceFlattenParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceFlattenParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceFlattenParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceFlattenParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceFlattenParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceFlattenParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
