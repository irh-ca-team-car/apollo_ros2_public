#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_float.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayFloat &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_values;
        for (auto it = msg.values.begin(); it != msg.values.end(); ++it) {
            arr_values.push_back((*it));
        }
        obj["values"] = arr_values;
        return obj;
    }
    ApolloperceptionKeyValueArrayFloat from_json_ApolloperceptionKeyValueArrayFloat (nlohmann::json obj) {
        ApolloperceptionKeyValueArrayFloat msg;
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
                    msg.values.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.values.push_back((obj["values"].is_string()?(float)atof(obj["values"].get<std::string>().c_str()):obj["values"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueArrayFloat from_json<ApolloperceptionKeyValueArrayFloat>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueArrayFloat(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayFloat &dt)
    {
        dt=from_json_ApolloperceptionKeyValueArrayFloat(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayFloat & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayFloat & dt)
    {
        os << to_json(dt);
        return os;
    }
}
