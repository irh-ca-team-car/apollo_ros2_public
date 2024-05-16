#include "adapter/serialization/apollo_msgs/apolloperceptioninference_spp_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSPPParameter &msg) {
        nlohmann::json obj;
        obj["pyramidheight"] = (msg.pyramidheight);
        obj["pool"] = (msg.pool);
        obj["engine"] = (msg.engine);
        return obj;
    }
    ApolloperceptioninferenceSPPParameter from_json_ApolloperceptioninferenceSPPParameter (nlohmann::json obj) {
        ApolloperceptioninferenceSPPParameter msg;
        if(obj.contains("pyramidheight"))
        {
            msg.pyramidheight = (obj["pyramidheight"].is_string()?atoi(obj["pyramidheight"].get<std::string>().c_str()):obj["pyramidheight"].get<uint32_t>());
        }
        if(obj.contains("pool"))
        {
            msg.pool = (obj["pool"].is_string()?atoi(obj["pool"].get<std::string>().c_str()):obj["pool"].get<int>());
        }
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSPPParameter from_json<ApolloperceptioninferenceSPPParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSPPParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSPPParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceSPPParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSPPParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSPPParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
