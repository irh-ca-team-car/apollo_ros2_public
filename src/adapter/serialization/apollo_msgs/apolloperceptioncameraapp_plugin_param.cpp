#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_plugin_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappPluginParam &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["rootdir"] = (msg.rootdir);
        obj["configfile"] = (msg.configfile);
        return obj;
    }
    ApolloperceptioncameraappPluginParam from_json_ApolloperceptioncameraappPluginParam (nlohmann::json obj) {
        ApolloperceptioncameraappPluginParam msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("rootdir"))
        {
            msg.rootdir = (obj["rootdir"].is_string()?(obj["rootdir"].get<std::string>().c_str()):obj["rootdir"].get<std::string>());
        }
        if(obj.contains("configfile"))
        {
            msg.configfile = (obj["configfile"].is_string()?(obj["configfile"].get<std::string>().c_str()):obj["configfile"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappPluginParam from_json<ApolloperceptioncameraappPluginParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappPluginParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappPluginParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappPluginParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappPluginParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappPluginParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
