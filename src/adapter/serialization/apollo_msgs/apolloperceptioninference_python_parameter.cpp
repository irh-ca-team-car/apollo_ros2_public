#include "adapter/serialization/apollo_msgs/apolloperceptioninference_python_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePythonParameter &msg) {
        nlohmann::json obj;
        obj["module"] = (msg.module);
        obj["layer"] = (msg.layer);
        obj["paramstr"] = (msg.paramstr);
        obj["shareinparallel"] = (msg.shareinparallel);
        return obj;
    }
    ApolloperceptioninferencePythonParameter from_json_ApolloperceptioninferencePythonParameter (nlohmann::json obj) {
        ApolloperceptioninferencePythonParameter msg;
        if(obj.contains("module"))
        {
            msg.module = (obj["module"].is_string()?(obj["module"].get<std::string>().c_str()):obj["module"].get<std::string>());
        }
        if(obj.contains("layer"))
        {
            msg.layer = (obj["layer"].is_string()?(obj["layer"].get<std::string>().c_str()):obj["layer"].get<std::string>());
        }
        if(obj.contains("paramstr"))
        {
            msg.paramstr = (obj["paramstr"].is_string()?(obj["paramstr"].get<std::string>().c_str()):obj["paramstr"].get<std::string>());
        }
        if(obj.contains("shareinparallel"))
        {
            msg.shareinparallel = (obj["shareinparallel"].is_string()?(bool)atoi(obj["shareinparallel"].get<std::string>().c_str()):obj["shareinparallel"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePythonParameter from_json<ApolloperceptioninferencePythonParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePythonParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePythonParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePythonParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePythonParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePythonParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
