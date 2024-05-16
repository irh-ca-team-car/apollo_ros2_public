#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_int.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayInt &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_values;
        for (auto it = msg.values.begin(); it != msg.values.end(); ++it) {
            arr_values.push_back((*it));
        }
        obj["values"] = arr_values;
        return obj;
    }
    ApolloperceptionKeyValueArrayInt from_json_ApolloperceptionKeyValueArrayInt (nlohmann::json obj) {
        ApolloperceptionKeyValueArrayInt msg;
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
                    msg.values.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.values.push_back((obj["values"].is_string()?atoi(obj["values"].get<std::string>().c_str()):obj["values"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueArrayInt from_json<ApolloperceptionKeyValueArrayInt>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueArrayInt(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayInt &dt)
    {
        dt=from_json_ApolloperceptionKeyValueArrayInt(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayInt & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayInt & dt)
    {
        os << to_json(dt);
        return os;
    }
}
