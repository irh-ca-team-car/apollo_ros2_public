#include "adapter/serialization/apollo_msgs/apolloperceptioninference_permute_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePermuteParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_order;
        for (auto it = msg.order.begin(); it != msg.order.end(); ++it) {
            arr_order.push_back((*it));
        }
        obj["order"] = arr_order;
        return obj;
    }
    ApolloperceptioninferencePermuteParameter from_json_ApolloperceptioninferencePermuteParameter (nlohmann::json obj) {
        ApolloperceptioninferencePermuteParameter msg;
        if(obj.contains("order"))
        {
            if(obj["order"].is_array())
            {
                for (auto& element : obj["order"])
                {
                    msg.order.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.order.push_back((obj["order"].is_string()?atoi(obj["order"].get<std::string>().c_str()):obj["order"].get<uint32_t>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePermuteParameter from_json<ApolloperceptioninferencePermuteParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePermuteParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePermuteParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePermuteParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePermuteParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePermuteParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
