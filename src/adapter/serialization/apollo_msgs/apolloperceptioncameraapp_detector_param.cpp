#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_detector_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappDetectorParam &msg) {
        nlohmann::json obj;
        obj["pluginparam"] = to_json(msg.pluginparam);
        obj["cameraname"] = (msg.cameraname);
        return obj;
    }
    ApolloperceptioncameraappDetectorParam from_json_ApolloperceptioncameraappDetectorParam (nlohmann::json obj) {
        ApolloperceptioncameraappDetectorParam msg;
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        if(obj.contains("cameraname"))
        {
            msg.cameraname = (obj["cameraname"].is_string()?(obj["cameraname"].get<std::string>().c_str()):obj["cameraname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappDetectorParam from_json<ApolloperceptioncameraappDetectorParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappDetectorParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappDetectorParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappDetectorParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappDetectorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappDetectorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
