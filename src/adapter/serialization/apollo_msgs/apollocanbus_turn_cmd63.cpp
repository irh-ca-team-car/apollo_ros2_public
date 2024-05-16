#include "adapter/serialization/apollo_msgs/apollocanbus_turn_cmd63.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnCmd63 &msg) {
        nlohmann::json obj;
        obj["turnsignalcmd"] = (msg.turnsignalcmd);
        return obj;
    }
    ApollocanbusTurnCmd63 from_json_ApollocanbusTurnCmd63 (nlohmann::json obj) {
        ApollocanbusTurnCmd63 msg;
        if(obj.contains("turnsignalcmd"))
        {
            msg.turnsignalcmd = (obj["turnsignalcmd"].is_string()?atoi(obj["turnsignalcmd"].get<std::string>().c_str()):obj["turnsignalcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusTurnCmd63 from_json<ApollocanbusTurnCmd63>(nlohmann::json obj){
        return from_json_ApollocanbusTurnCmd63(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnCmd63 &dt)
    {
        dt=from_json_ApollocanbusTurnCmd63(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnCmd63 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnCmd63 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
