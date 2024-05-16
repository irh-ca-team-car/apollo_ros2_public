#include "adapter/serialization/apollo_msgs/apolloplanning_rerouting_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReroutingStatus &msg) {
        nlohmann::json obj;
        obj["lastreroutingtime"] = (msg.lastreroutingtime);
        obj["needrerouting"] = (msg.needrerouting);
        obj["routingrequest"] = to_json(msg.routingrequest);
        return obj;
    }
    ApolloplanningReroutingStatus from_json_ApolloplanningReroutingStatus (nlohmann::json obj) {
        ApolloplanningReroutingStatus msg;
        if(obj.contains("lastreroutingtime"))
        {
            msg.lastreroutingtime = (obj["lastreroutingtime"].is_string()?atof(obj["lastreroutingtime"].get<std::string>().c_str()):obj["lastreroutingtime"].get<double>());
        }
        if(obj.contains("needrerouting"))
        {
            msg.needrerouting = (obj["needrerouting"].is_string()?(bool)atoi(obj["needrerouting"].get<std::string>().c_str()):obj["needrerouting"].get<bool>());
        }
        if(obj.contains("routingrequest"))
        {
            msg.routingrequest = from_json_ApolloroutingRoutingRequest(obj["routingrequest"]);
        }
        return msg;
    }
    template <>
    ApolloplanningReroutingStatus from_json<ApolloplanningReroutingStatus>(nlohmann::json obj){
        return from_json_ApolloplanningReroutingStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReroutingStatus &dt)
    {
        dt=from_json_ApolloplanningReroutingStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReroutingStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReroutingStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
