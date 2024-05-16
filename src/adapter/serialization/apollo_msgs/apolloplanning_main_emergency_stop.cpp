#include "adapter/serialization/apollo_msgs/apolloplanning_main_emergency_stop.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainEmergencyStop &msg) {
        nlohmann::json obj;
        obj["reasoncode"] = (msg.reasoncode);
        obj["reason"] = (msg.reason);
        obj["task"] = to_json(msg.task);
        return obj;
    }
    ApolloplanningMainEmergencyStop from_json_ApolloplanningMainEmergencyStop (nlohmann::json obj) {
        ApolloplanningMainEmergencyStop msg;
        if(obj.contains("reasoncode"))
        {
            msg.reasoncode = (obj["reasoncode"].is_string()?atoi(obj["reasoncode"].get<std::string>().c_str()):obj["reasoncode"].get<int>());
        }
        if(obj.contains("reason"))
        {
            msg.reason = (obj["reason"].is_string()?(obj["reason"].get<std::string>().c_str()):obj["reason"].get<std::string>());
        }
        if(obj.contains("task"))
        {
            msg.task = from_json_ApolloplanningMainEmergencyStoptask(obj["task"]);
        }
        return msg;
    }
    template <>
    ApolloplanningMainEmergencyStop from_json<ApolloplanningMainEmergencyStop>(nlohmann::json obj){
        return from_json_ApolloplanningMainEmergencyStop(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainEmergencyStop &dt)
    {
        dt=from_json_ApolloplanningMainEmergencyStop(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainEmergencyStop & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainEmergencyStop & dt)
    {
        os << to_json(dt);
        return os;
    }
}
