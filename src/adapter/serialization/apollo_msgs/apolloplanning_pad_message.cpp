#include "adapter/serialization/apollo_msgs/apolloplanning_pad_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPadMessage &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["action"] = (msg.action);
        return obj;
    }
    ApolloplanningPadMessage from_json_ApolloplanningPadMessage (nlohmann::json obj) {
        ApolloplanningPadMessage msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("action"))
        {
            msg.action = (obj["action"].is_string()?atoi(obj["action"].get<std::string>().c_str()):obj["action"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningPadMessage from_json<ApolloplanningPadMessage>(nlohmann::json obj){
        return from_json_ApolloplanningPadMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPadMessage &dt)
    {
        dt=from_json_ApolloplanningPadMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPadMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPadMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
