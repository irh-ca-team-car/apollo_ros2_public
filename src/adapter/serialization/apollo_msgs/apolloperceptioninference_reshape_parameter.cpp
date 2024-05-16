#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reshape_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceReshapeParameter &msg) {
        nlohmann::json obj;
        obj["shape"] = to_json(msg.shape);
        obj["axis"] = (msg.axis);
        obj["numaxes"] = (msg.numaxes);
        return obj;
    }
    ApolloperceptioninferenceReshapeParameter from_json_ApolloperceptioninferenceReshapeParameter (nlohmann::json obj) {
        ApolloperceptioninferenceReshapeParameter msg;
        if(obj.contains("shape"))
        {
            msg.shape = from_json_ApolloperceptioninferenceBlobShape(obj["shape"]);
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("numaxes"))
        {
            msg.numaxes = (obj["numaxes"].is_string()?atoi(obj["numaxes"].get<std::string>().c_str()):obj["numaxes"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceReshapeParameter from_json<ApolloperceptioninferenceReshapeParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceReshapeParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceReshapeParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceReshapeParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceReshapeParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceReshapeParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
