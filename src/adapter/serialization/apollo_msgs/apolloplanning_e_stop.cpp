#include "adapter/serialization/apollo_msgs/apolloplanning_e_stop.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningEStop &msg) {
        nlohmann::json obj;
        obj["isestop"] = (msg.isestop);
        obj["reason"] = (msg.reason);
        return obj;
    }
    ApolloplanningEStop from_json_ApolloplanningEStop (nlohmann::json obj) {
        ApolloplanningEStop msg;
        if(obj.contains("isestop"))
        {
            msg.isestop = (obj["isestop"].is_string()?(bool)atoi(obj["isestop"].get<std::string>().c_str()):obj["isestop"].get<bool>());
        }
        if(obj.contains("reason"))
        {
            msg.reason = (obj["reason"].is_string()?(obj["reason"].get<std::string>().c_str()):obj["reason"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloplanningEStop from_json<ApolloplanningEStop>(nlohmann::json obj){
        return from_json_ApolloplanningEStop(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningEStop &dt)
    {
        dt=from_json_ApolloplanningEStop(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningEStop & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningEStop & dt)
    {
        os << to_json(dt);
        return os;
    }
}
