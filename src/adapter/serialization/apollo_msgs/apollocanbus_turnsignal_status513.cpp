#include "adapter/serialization/apollo_msgs/apollocanbus_turnsignal_status513.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnsignalStatus513 &msg) {
        nlohmann::json obj;
        obj["turnsignalsts"] = (msg.turnsignalsts);
        return obj;
    }
    ApollocanbusTurnsignalStatus513 from_json_ApollocanbusTurnsignalStatus513 (nlohmann::json obj) {
        ApollocanbusTurnsignalStatus513 msg;
        if(obj.contains("turnsignalsts"))
        {
            msg.turnsignalsts = (obj["turnsignalsts"].is_string()?atoi(obj["turnsignalsts"].get<std::string>().c_str()):obj["turnsignalsts"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusTurnsignalStatus513 from_json<ApollocanbusTurnsignalStatus513>(nlohmann::json obj){
        return from_json_ApollocanbusTurnsignalStatus513(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnsignalStatus513 &dt)
    {
        dt=from_json_ApollocanbusTurnsignalStatus513(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnsignalStatus513 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnsignalStatus513 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
