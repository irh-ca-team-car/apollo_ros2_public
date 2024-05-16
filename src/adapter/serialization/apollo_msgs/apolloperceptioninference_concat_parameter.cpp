#include "adapter/serialization/apollo_msgs/apolloperceptioninference_concat_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceConcatParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        obj["concatdim"] = (msg.concatdim);
        return obj;
    }
    ApolloperceptioninferenceConcatParameter from_json_ApolloperceptioninferenceConcatParameter (nlohmann::json obj) {
        ApolloperceptioninferenceConcatParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("concatdim"))
        {
            msg.concatdim = (obj["concatdim"].is_string()?atoi(obj["concatdim"].get<std::string>().c_str()):obj["concatdim"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceConcatParameter from_json<ApolloperceptioninferenceConcatParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceConcatParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceConcatParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceConcatParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceConcatParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceConcatParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
