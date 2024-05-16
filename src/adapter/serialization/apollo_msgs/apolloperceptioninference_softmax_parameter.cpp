#include "adapter/serialization/apollo_msgs/apolloperceptioninference_softmax_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSoftmaxParameter &msg) {
        nlohmann::json obj;
        obj["engine"] = (msg.engine);
        obj["axis"] = (msg.axis);
        return obj;
    }
    ApolloperceptioninferenceSoftmaxParameter from_json_ApolloperceptioninferenceSoftmaxParameter (nlohmann::json obj) {
        ApolloperceptioninferenceSoftmaxParameter msg;
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSoftmaxParameter from_json<ApolloperceptioninferenceSoftmaxParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSoftmaxParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSoftmaxParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceSoftmaxParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSoftmaxParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSoftmaxParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
