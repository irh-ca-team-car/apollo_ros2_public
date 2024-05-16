#include "adapter/serialization/apollo_msgs/apolloplanning_main_not_ready.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainNotReady &msg) {
        nlohmann::json obj;
        obj["reason"] = (msg.reason);
        return obj;
    }
    ApolloplanningMainNotReady from_json_ApolloplanningMainNotReady (nlohmann::json obj) {
        ApolloplanningMainNotReady msg;
        if(obj.contains("reason"))
        {
            msg.reason = (obj["reason"].is_string()?(obj["reason"].get<std::string>().c_str()):obj["reason"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloplanningMainNotReady from_json<ApolloplanningMainNotReady>(nlohmann::json obj){
        return from_json_ApolloplanningMainNotReady(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainNotReady &dt)
    {
        dt=from_json_ApolloplanningMainNotReady(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainNotReady & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainNotReady & dt)
    {
        os << to_json(dt);
        return os;
    }
}
