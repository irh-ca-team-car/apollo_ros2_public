#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sigmoid_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSigmoidParameter &msg) {
        nlohmann::json obj;
        obj["engine"] = (msg.engine);
        return obj;
    }
    ApolloperceptioninferenceSigmoidParameter from_json_ApolloperceptioninferenceSigmoidParameter (nlohmann::json obj) {
        ApolloperceptioninferenceSigmoidParameter msg;
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSigmoidParameter from_json<ApolloperceptioninferenceSigmoidParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSigmoidParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSigmoidParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceSigmoidParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSigmoidParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSigmoidParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
