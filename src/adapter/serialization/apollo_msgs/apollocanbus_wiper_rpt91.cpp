#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_rpt91.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperRpt91 &msg) {
        nlohmann::json obj;
        obj["outputvalue"] = (msg.outputvalue);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["manualinput"] = (msg.manualinput);
        return obj;
    }
    ApollocanbusWiperRpt91 from_json_ApollocanbusWiperRpt91 (nlohmann::json obj) {
        ApollocanbusWiperRpt91 msg;
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<int>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<int>());
        }
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusWiperRpt91 from_json<ApollocanbusWiperRpt91>(nlohmann::json obj){
        return from_json_ApollocanbusWiperRpt91(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperRpt91 &dt)
    {
        dt=from_json_ApollocanbusWiperRpt91(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperRpt91 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperRpt91 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
