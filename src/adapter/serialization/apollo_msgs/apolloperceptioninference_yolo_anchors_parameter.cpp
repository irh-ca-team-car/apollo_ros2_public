#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_anchors_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloAnchorsParameter &msg) {
        nlohmann::json obj;
        obj["anchorsfile"] = (msg.anchorsfile);
        obj["refw"] = (msg.refw);
        obj["refh"] = (msg.refh);
        return obj;
    }
    ApolloperceptioninferenceYoloAnchorsParameter from_json_ApolloperceptioninferenceYoloAnchorsParameter (nlohmann::json obj) {
        ApolloperceptioninferenceYoloAnchorsParameter msg;
        if(obj.contains("anchorsfile"))
        {
            msg.anchorsfile = (obj["anchorsfile"].is_string()?(obj["anchorsfile"].get<std::string>().c_str()):obj["anchorsfile"].get<std::string>());
        }
        if(obj.contains("refw"))
        {
            msg.refw = (obj["refw"].is_string()?atoi(obj["refw"].get<std::string>().c_str()):obj["refw"].get<int>());
        }
        if(obj.contains("refh"))
        {
            msg.refh = (obj["refh"].is_string()?atoi(obj["refh"].get<std::string>().c_str()):obj["refh"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceYoloAnchorsParameter from_json<ApolloperceptioninferenceYoloAnchorsParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceYoloAnchorsParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloAnchorsParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceYoloAnchorsParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloAnchorsParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloAnchorsParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
