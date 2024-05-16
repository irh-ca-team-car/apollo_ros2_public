#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_string.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayString &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_values;
        for (auto it = msg.values.begin(); it != msg.values.end(); ++it) {
            arr_values.push_back(to_json(*it));
        }
        obj["values"] = arr_values;
        return obj;
    }
    ApolloperceptionKeyValueArrayString from_json_ApolloperceptionKeyValueArrayString (nlohmann::json obj) {
        ApolloperceptionKeyValueArrayString msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("values"))
        {
            if(obj["values"].is_array())
            {
                for (auto& element : obj["values"])
                {
                    msg.values.push_back(from_json_Bytes(element));
                }
            }
            else
            {
                msg.values.push_back(from_json_Bytes(obj["values"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueArrayString from_json<ApolloperceptionKeyValueArrayString>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueArrayString(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayString &dt)
    {
        dt=from_json_ApolloperceptionKeyValueArrayString(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayString & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayString & dt)
    {
        os << to_json(dt);
        return os;
    }
}
