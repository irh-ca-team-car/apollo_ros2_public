#include "adapter/serialization/apollo_msgs/apolloperceptioninference_anchor_box.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnchorBox &msg) {
        nlohmann::json obj;
        obj["w"] = (msg.w);
        obj["h"] = (msg.h);
        return obj;
    }
    ApolloperceptioninferenceAnchorBox from_json_ApolloperceptioninferenceAnchorBox (nlohmann::json obj) {
        ApolloperceptioninferenceAnchorBox msg;
        if(obj.contains("w"))
        {
            msg.w = (obj["w"].is_string()?(float)atof(obj["w"].get<std::string>().c_str()):obj["w"].get<float>());
        }
        if(obj.contains("h"))
        {
            msg.h = (obj["h"].is_string()?(float)atof(obj["h"].get<std::string>().c_str()):obj["h"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceAnchorBox from_json<ApolloperceptioninferenceAnchorBox>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceAnchorBox(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnchorBox &dt)
    {
        dt=from_json_ApolloperceptioninferenceAnchorBox(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnchorBox & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnchorBox & dt)
    {
        os << to_json(dt);
        return os;
    }
}
