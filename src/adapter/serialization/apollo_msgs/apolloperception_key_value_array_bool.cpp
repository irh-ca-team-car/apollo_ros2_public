#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_bool.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayBool &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_values;
        for (auto it = msg.values.begin(); it != msg.values.end(); ++it) {
            arr_values.push_back((*it));
        }
        obj["values"] = arr_values;
        return obj;
    }
    ApolloperceptionKeyValueArrayBool from_json_ApolloperceptionKeyValueArrayBool (nlohmann::json obj) {
        ApolloperceptionKeyValueArrayBool msg;
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
                    msg.values.push_back((element.is_string()?(bool)atoi(element.get<std::string>().c_str()):element.get<bool>()));
                }
            }
            else
            {
                msg.values.push_back((obj["values"].is_string()?(bool)atoi(obj["values"].get<std::string>().c_str()):obj["values"].get<bool>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueArrayBool from_json<ApolloperceptionKeyValueArrayBool>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueArrayBool(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayBool &dt)
    {
        dt=from_json_ApolloperceptionKeyValueArrayBool(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayBool & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayBool & dt)
    {
        os << to_json(dt);
        return os;
    }
}
