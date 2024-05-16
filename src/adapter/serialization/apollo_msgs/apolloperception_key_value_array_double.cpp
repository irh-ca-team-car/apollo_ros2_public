#include "adapter/serialization/apollo_msgs/apolloperception_key_value_array_double.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionKeyValueArrayDouble &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_values;
        for (auto it = msg.values.begin(); it != msg.values.end(); ++it) {
            arr_values.push_back((*it));
        }
        obj["values"] = arr_values;
        return obj;
    }
    ApolloperceptionKeyValueArrayDouble from_json_ApolloperceptionKeyValueArrayDouble (nlohmann::json obj) {
        ApolloperceptionKeyValueArrayDouble msg;
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
                    msg.values.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.values.push_back((obj["values"].is_string()?atof(obj["values"].get<std::string>().c_str()):obj["values"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionKeyValueArrayDouble from_json<ApolloperceptionKeyValueArrayDouble>(nlohmann::json obj){
        return from_json_ApolloperceptionKeyValueArrayDouble(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionKeyValueArrayDouble &dt)
    {
        dt=from_json_ApolloperceptionKeyValueArrayDouble(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionKeyValueArrayDouble & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionKeyValueArrayDouble & dt)
    {
        os << to_json(dt);
        return os;
    }
}
