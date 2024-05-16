#include "adapter/serialization/apollo_msgs/apolloperception_key_value_bool.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueBool &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["value"] = (msg.value);
        return obj;
    }
    ApolloperceptionKeyValueBool from_json_ApolloperceptionKeyValueBool (nlohmann::json obj) {
        ApolloperceptionKeyValueBool msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("value"))
        {
            msg.value = (obj["value"].is_string()?(bool)atoi(obj["value"].get<std::string>().c_str()):obj["value"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueBool from_json<ApolloperceptionKeyValueBool>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueBool(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueBool &dt)
    {
        dt=from_json_ApolloperceptionKeyValueBool(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueBool & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueBool & dt)
    {
        os << to_json(dt);
        return os;
    }
}
