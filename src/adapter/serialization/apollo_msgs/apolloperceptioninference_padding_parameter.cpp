#include "adapter/serialization/apollo_msgs/apolloperceptioninference_padding_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePaddingParameter &msg) {
        nlohmann::json obj;
        obj["padt"] = (msg.padt);
        obj["padb"] = (msg.padb);
        obj["padl"] = (msg.padl);
        obj["padr"] = (msg.padr);
        obj["val"] = (msg.val);
        return obj;
    }
    ApolloperceptioninferencePaddingParameter from_json_ApolloperceptioninferencePaddingParameter (nlohmann::json obj) {
        ApolloperceptioninferencePaddingParameter msg;
        if(obj.contains("padt"))
        {
            msg.padt = (obj["padt"].is_string()?atoi(obj["padt"].get<std::string>().c_str()):obj["padt"].get<uint32_t>());
        }
        if(obj.contains("padb"))
        {
            msg.padb = (obj["padb"].is_string()?atoi(obj["padb"].get<std::string>().c_str()):obj["padb"].get<uint32_t>());
        }
        if(obj.contains("padl"))
        {
            msg.padl = (obj["padl"].is_string()?atoi(obj["padl"].get<std::string>().c_str()):obj["padl"].get<uint32_t>());
        }
        if(obj.contains("padr"))
        {
            msg.padr = (obj["padr"].is_string()?atoi(obj["padr"].get<std::string>().c_str()):obj["padr"].get<uint32_t>());
        }
        if(obj.contains("val"))
        {
            msg.val = (obj["val"].is_string()?(float)atof(obj["val"].get<std::string>().c_str()):obj["val"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePaddingParameter from_json<ApolloperceptioninferencePaddingParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePaddingParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePaddingParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePaddingParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePaddingParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePaddingParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
