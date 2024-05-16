#include "adapter/serialization/apollo_msgs/apolloplanning_main_emergency_stoptask.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainEmergencyStoptask &msg) {
        nlohmann::json obj;
        obj["hardbrake"] = (msg.hardbrake);
        obj["cruisetostop"] = (msg.cruisetostop);
        return obj;
    }
    ApolloplanningMainEmergencyStoptask from_json_ApolloplanningMainEmergencyStoptask (nlohmann::json obj) {
        ApolloplanningMainEmergencyStoptask msg;
        if(obj.contains("hardbrake"))
        {
            msg.hardbrake = (obj["hardbrake"].is_string()?atoi(obj["hardbrake"].get<std::string>().c_str()):obj["hardbrake"].get<int>());
        }
        if(obj.contains("cruisetostop"))
        {
            msg.cruisetostop = (obj["cruisetostop"].is_string()?atoi(obj["cruisetostop"].get<std::string>().c_str()):obj["cruisetostop"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningMainEmergencyStoptask from_json<ApolloplanningMainEmergencyStoptask>(nlohmann::json obj){
        return from_json_ApolloplanningMainEmergencyStoptask(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainEmergencyStoptask &dt)
    {
        dt=from_json_ApolloplanningMainEmergencyStoptask(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainEmergencyStoptask & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainEmergencyStoptask & dt)
    {
        os << to_json(dt);
        return os;
    }
}
