#include "adapter/serialization/apollo_msgs/apolloperception_key_value_float.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueFloat &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["value"] = (msg.value);
        return obj;
    }
    ApolloperceptionKeyValueFloat from_json_ApolloperceptionKeyValueFloat (nlohmann::json obj) {
        ApolloperceptionKeyValueFloat msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("value"))
        {
            msg.value = (obj["value"].is_string()?(float)atof(obj["value"].get<std::string>().c_str()):obj["value"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueFloat from_json<ApolloperceptionKeyValueFloat>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueFloat(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueFloat &dt)
    {
        dt=from_json_ApolloperceptionKeyValueFloat(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueFloat & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueFloat & dt)
    {
        os << to_json(dt);
        return os;
    }
}
