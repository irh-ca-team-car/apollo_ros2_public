#include "adapter/serialization/apollo_msgs/apollocontrol_pad_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolPadMessage &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["drivingmode"] = (msg.drivingmode);
        obj["action"] = (msg.action);
        return obj;
    }
    ApollocontrolPadMessage from_json_ApollocontrolPadMessage (nlohmann::json obj) {
        ApollocontrolPadMessage msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        if(obj.contains("action"))
        {
            msg.action = (obj["action"].is_string()?atoi(obj["action"].get<std::string>().c_str()):obj["action"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocontrolPadMessage from_json<ApollocontrolPadMessage>(nlohmann::json obj){
        return from_json_ApollocontrolPadMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolPadMessage &dt)
    {
        dt=from_json_ApollocontrolPadMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolPadMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolPadMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
