#include "adapter/serialization/apollo_msgs/apolloperception_key_value_int.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueInt &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["value"] = (msg.value);
        return obj;
    }
    ApolloperceptionKeyValueInt from_json_ApolloperceptionKeyValueInt (nlohmann::json obj) {
        ApolloperceptionKeyValueInt msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("value"))
        {
            msg.value = (obj["value"].is_string()?atoi(obj["value"].get<std::string>().c_str()):obj["value"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueInt from_json<ApolloperceptionKeyValueInt>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueInt(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueInt &dt)
    {
        dt=from_json_ApolloperceptionKeyValueInt(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueInt & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueInt & dt)
    {
        os << to_json(dt);
        return os;
    }
}
