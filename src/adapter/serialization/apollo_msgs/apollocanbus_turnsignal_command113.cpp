#include "adapter/serialization/apollo_msgs/apollocanbus_turnsignal_command113.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnsignalCommand113 &msg) {
        nlohmann::json obj;
        obj["turnsignalcmd"] = (msg.turnsignalcmd);
        return obj;
    }
    ApollocanbusTurnsignalCommand113 from_json_ApollocanbusTurnsignalCommand113 (nlohmann::json obj) {
        ApollocanbusTurnsignalCommand113 msg;
        if(obj.contains("turnsignalcmd"))
        {
            msg.turnsignalcmd = (obj["turnsignalcmd"].is_string()?atoi(obj["turnsignalcmd"].get<std::string>().c_str()):obj["turnsignalcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusTurnsignalCommand113 from_json<ApollocanbusTurnsignalCommand113>(nlohmann::json obj){
        return from_json_ApollocanbusTurnsignalCommand113(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnsignalCommand113 &dt)
    {
        dt=from_json_ApollocanbusTurnsignalCommand113(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnsignalCommand113 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnsignalCommand113 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
