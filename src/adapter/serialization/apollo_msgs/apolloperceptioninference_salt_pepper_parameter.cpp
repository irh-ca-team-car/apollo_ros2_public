#include "adapter/serialization/apollo_msgs/apolloperceptioninference_salt_pepper_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSaltPepperParameter &msg) {
        nlohmann::json obj;
        obj["fraction"] = (msg.fraction);
        nlohmann::json arr_value;
        for (auto it = msg.value.begin(); it != msg.value.end(); ++it) {
            arr_value.push_back((*it));
        }
        obj["value"] = arr_value;
        return obj;
    }
    ApolloperceptioninferenceSaltPepperParameter from_json_ApolloperceptioninferenceSaltPepperParameter (nlohmann::json obj) {
        ApolloperceptioninferenceSaltPepperParameter msg;
        if(obj.contains("fraction"))
        {
            msg.fraction = (obj["fraction"].is_string()?(float)atof(obj["fraction"].get<std::string>().c_str()):obj["fraction"].get<float>());
        }
        if(obj.contains("value"))
        {
            if(obj["value"].is_array())
            {
                for (auto& element : obj["value"])
                {
                    msg.value.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.value.push_back((obj["value"].is_string()?(float)atof(obj["value"].get<std::string>().c_str()):obj["value"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSaltPepperParameter from_json<ApolloperceptioninferenceSaltPepperParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSaltPepperParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSaltPepperParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceSaltPepperParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSaltPepperParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSaltPepperParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
