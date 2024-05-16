#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tan_h_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceTanHParameter &msg) {
        nlohmann::json obj;
        obj["engine"] = (msg.engine);
        return obj;
    }
    ApolloperceptioninferenceTanHParameter from_json_ApolloperceptioninferenceTanHParameter (nlohmann::json obj) {
        ApolloperceptioninferenceTanHParameter msg;
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceTanHParameter from_json<ApolloperceptioninferenceTanHParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceTanHParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceTanHParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceTanHParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceTanHParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceTanHParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
