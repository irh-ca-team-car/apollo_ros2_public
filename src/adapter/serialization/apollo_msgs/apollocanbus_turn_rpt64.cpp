#include "adapter/serialization/apollo_msgs/apollocanbus_turn_rpt64.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnRpt64 &msg) {
        nlohmann::json obj;
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["outputvalue"] = (msg.outputvalue);
        return obj;
    }
    ApollocanbusTurnRpt64 from_json_ApollocanbusTurnRpt64 (nlohmann::json obj) {
        ApollocanbusTurnRpt64 msg;
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atoi(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<int>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atoi(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<int>());
        }
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atoi(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusTurnRpt64 from_json<ApollocanbusTurnRpt64>(nlohmann::json obj){
        return from_json_ApollocanbusTurnRpt64(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnRpt64 &dt)
    {
        dt=from_json_ApollocanbusTurnRpt64(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnRpt64 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnRpt64 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
