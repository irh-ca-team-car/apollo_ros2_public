#include "adapter/serialization/apollo_msgs/apolloperception_key_value_double.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueDouble &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["value"] = (msg.value);
        return obj;
    }
    ApolloperceptionKeyValueDouble from_json_ApolloperceptionKeyValueDouble (nlohmann::json obj) {
        ApolloperceptionKeyValueDouble msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("value"))
        {
            msg.value = (obj["value"].is_string()?atof(obj["value"].get<std::string>().c_str()):obj["value"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueDouble from_json<ApolloperceptionKeyValueDouble>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueDouble(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueDouble &dt)
    {
        dt=from_json_ApolloperceptionKeyValueDouble(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueDouble & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueDouble & dt)
    {
        os << to_json(dt);
        return os;
    }
}
