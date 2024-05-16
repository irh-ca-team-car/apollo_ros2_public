#include "adapter/serialization/apollo_msgs/apolloperception_key_value_string.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueString &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["value"] = to_json(msg.value);
        return obj;
    }
    ApolloperceptionKeyValueString from_json_ApolloperceptionKeyValueString (nlohmann::json obj) {
        ApolloperceptionKeyValueString msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("value"))
        {
            msg.value = from_json_Bytes(obj["value"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueString from_json<ApolloperceptionKeyValueString>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueString(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueString &dt)
    {
        dt=from_json_ApolloperceptionKeyValueString(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueString & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueString & dt)
    {
        os << to_json(dt);
        return os;
    }
}
