#include "adapter/serialization/apollo_msgs/apolloperceptioninference_input_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceInputParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_shape;
        for (auto it = msg.shape.begin(); it != msg.shape.end(); ++it) {
            arr_shape.push_back(to_json(*it));
        }
        obj["shape"] = arr_shape;
        return obj;
    }
    ApolloperceptioninferenceInputParameter from_json_ApolloperceptioninferenceInputParameter (nlohmann::json obj) {
        ApolloperceptioninferenceInputParameter msg;
        if(obj.contains("shape"))
        {
            if(obj["shape"].is_array())
            {
                for (auto& element : obj["shape"])
                {
                    msg.shape.push_back(from_json_ApolloperceptioninferenceBlobShape(element));
                }
            }
            else
            {
                msg.shape.push_back(from_json_ApolloperceptioninferenceBlobShape(obj["shape"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceInputParameter from_json<ApolloperceptioninferenceInputParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceInputParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceInputParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceInputParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceInputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceInputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
