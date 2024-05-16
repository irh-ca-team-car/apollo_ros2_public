#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status34e2.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus34e2 &msg) {
        nlohmann::json obj;
        obj["cantxswversionpld"] = (msg.cantxswversionpld);
        obj["cantxswversionhost"] = (msg.cantxswversionhost);
        obj["cantxhwversion"] = (msg.cantxhwversion);
        obj["cantxinterfaceversion"] = (msg.cantxinterfaceversion);
        obj["cantxserialnum"] = (msg.cantxserialnum);
        return obj;
    }
    ApollodriversEsrStatus34e2 from_json_ApollodriversEsrStatus34e2 (nlohmann::json obj) {
        ApollodriversEsrStatus34e2 msg;
        if(obj.contains("cantxswversionpld"))
        {
            msg.cantxswversionpld = (obj["cantxswversionpld"].is_string()?atoi(obj["cantxswversionpld"].get<std::string>().c_str()):obj["cantxswversionpld"].get<int>());
        }
        if(obj.contains("cantxswversionhost"))
        {
            msg.cantxswversionhost = (obj["cantxswversionhost"].is_string()?atoi(obj["cantxswversionhost"].get<std::string>().c_str()):obj["cantxswversionhost"].get<int>());
        }
        if(obj.contains("cantxhwversion"))
        {
            msg.cantxhwversion = (obj["cantxhwversion"].is_string()?atoi(obj["cantxhwversion"].get<std::string>().c_str()):obj["cantxhwversion"].get<int>());
        }
        if(obj.contains("cantxinterfaceversion"))
        {
            msg.cantxinterfaceversion = (obj["cantxinterfaceversion"].is_string()?atoi(obj["cantxinterfaceversion"].get<std::string>().c_str()):obj["cantxinterfaceversion"].get<int>());
        }
        if(obj.contains("cantxserialnum"))
        {
            msg.cantxserialnum = (obj["cantxserialnum"].is_string()?atoi(obj["cantxserialnum"].get<std::string>().c_str()):obj["cantxserialnum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus34e2 from_json<ApollodriversEsrStatus34e2>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus34e2(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus34e2 &dt)
    {
        dt=from_json_ApollodriversEsrStatus34e2(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus34e2 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus34e2 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
