#include "adapter/serialization/apollo_msgs/apollocanbus_brake_status511.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeStatus511 &msg) {
        nlohmann::json obj;
        obj["brakepedalensts"] = (msg.brakepedalensts);
        obj["brakepedalsts"] = (msg.brakepedalsts);
        obj["brakeerr"] = (msg.brakeerr);
        obj["emergencybtnenv"] = (msg.emergencybtnenv);
        obj["frontbumpenv"] = (msg.frontbumpenv);
        obj["backbumpenv"] = (msg.backbumpenv);
        obj["overspdenv"] = (msg.overspdenv);
        return obj;
    }
    ApollocanbusBrakeStatus511 from_json_ApollocanbusBrakeStatus511 (nlohmann::json obj) {
        ApollocanbusBrakeStatus511 msg;
        if(obj.contains("brakepedalensts"))
        {
            msg.brakepedalensts = (obj["brakepedalensts"].is_string()?atoi(obj["brakepedalensts"].get<std::string>().c_str()):obj["brakepedalensts"].get<int>());
        }
        if(obj.contains("brakepedalsts"))
        {
            msg.brakepedalsts = (obj["brakepedalsts"].is_string()?atoi(obj["brakepedalsts"].get<std::string>().c_str()):obj["brakepedalsts"].get<int>());
        }
        if(obj.contains("brakeerr"))
        {
            msg.brakeerr = (obj["brakeerr"].is_string()?atoi(obj["brakeerr"].get<std::string>().c_str()):obj["brakeerr"].get<int>());
        }
        if(obj.contains("emergencybtnenv"))
        {
            msg.emergencybtnenv = (obj["emergencybtnenv"].is_string()?atoi(obj["emergencybtnenv"].get<std::string>().c_str()):obj["emergencybtnenv"].get<int>());
        }
        if(obj.contains("frontbumpenv"))
        {
            msg.frontbumpenv = (obj["frontbumpenv"].is_string()?atoi(obj["frontbumpenv"].get<std::string>().c_str()):obj["frontbumpenv"].get<int>());
        }
        if(obj.contains("backbumpenv"))
        {
            msg.backbumpenv = (obj["backbumpenv"].is_string()?atoi(obj["backbumpenv"].get<std::string>().c_str()):obj["backbumpenv"].get<int>());
        }
        if(obj.contains("overspdenv"))
        {
            msg.overspdenv = (obj["overspdenv"].is_string()?atoi(obj["overspdenv"].get<std::string>().c_str()):obj["overspdenv"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeStatus511 from_json<ApollocanbusBrakeStatus511>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeStatus511(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeStatus511 &dt)
    {
        dt=from_json_ApollocanbusBrakeStatus511(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeStatus511 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeStatus511 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
