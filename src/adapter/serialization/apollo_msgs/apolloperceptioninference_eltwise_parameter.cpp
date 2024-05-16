#include "adapter/serialization/apollo_msgs/apolloperceptioninference_eltwise_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceEltwiseParameter &msg) {
        nlohmann::json obj;
        obj["operation"] = (msg.operation);
        nlohmann::json arr_coeff;
        for (auto it = msg.coeff.begin(); it != msg.coeff.end(); ++it) {
            arr_coeff.push_back((*it));
        }
        obj["coeff"] = arr_coeff;
        obj["stableprodgrad"] = (msg.stableprodgrad);
        return obj;
    }
    ApolloperceptioninferenceEltwiseParameter from_json_ApolloperceptioninferenceEltwiseParameter (nlohmann::json obj) {
        ApolloperceptioninferenceEltwiseParameter msg;
        if(obj.contains("operation"))
        {
            msg.operation = (obj["operation"].is_string()?atoi(obj["operation"].get<std::string>().c_str()):obj["operation"].get<int>());
        }
        if(obj.contains("coeff"))
        {
            if(obj["coeff"].is_array())
            {
                for (auto& element : obj["coeff"])
                {
                    msg.coeff.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.coeff.push_back((obj["coeff"].is_string()?(float)atof(obj["coeff"].get<std::string>().c_str()):obj["coeff"].get<float>()));
            }
        }
        if(obj.contains("stableprodgrad"))
        {
            msg.stableprodgrad = (obj["stableprodgrad"].is_string()?(bool)atoi(obj["stableprodgrad"].get<std::string>().c_str()):obj["stableprodgrad"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceEltwiseParameter from_json<ApolloperceptioninferenceEltwiseParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceEltwiseParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceEltwiseParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceEltwiseParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceEltwiseParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceEltwiseParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
