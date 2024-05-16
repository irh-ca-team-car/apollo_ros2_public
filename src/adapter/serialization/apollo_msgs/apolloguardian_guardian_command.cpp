#include "adapter/serialization/apollo_msgs/apolloguardian_guardian_command.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloguardianGuardianCommand &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["controlcommand"] = to_json(msg.controlcommand);
        return obj;
    }
    ApolloguardianGuardianCommand from_json_ApolloguardianGuardianCommand (nlohmann::json obj) {
        ApolloguardianGuardianCommand msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("controlcommand"))
        {
            msg.controlcommand = from_json_ApollocontrolControlCommand(obj["controlcommand"]);
        }
        return msg;
    }
    template <>
    ApolloguardianGuardianCommand from_json<ApolloguardianGuardianCommand>(nlohmann::json obj){
        return from_json_ApolloguardianGuardianCommand(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloguardianGuardianCommand &dt)
    {
        dt=from_json_ApolloguardianGuardianCommand(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloguardianGuardianCommand & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloguardianGuardianCommand & dt)
    {
        os << to_json(dt);
        return os;
    }
}
