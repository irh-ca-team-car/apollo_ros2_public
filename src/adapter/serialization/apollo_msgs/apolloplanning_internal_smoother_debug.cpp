#include "adapter/serialization/apollo_msgs/apolloplanning_internal_smoother_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSmootherDebug &msg) {
        nlohmann::json obj;
        obj["issmoothed"] = (msg.issmoothed);
        obj["type"] = (msg.type);
        obj["reason"] = (msg.reason);
        return obj;
    }
    ApolloplanningInternalSmootherDebug from_json_ApolloplanningInternalSmootherDebug (nlohmann::json obj) {
        ApolloplanningInternalSmootherDebug msg;
        if(obj.contains("issmoothed"))
        {
            msg.issmoothed = (obj["issmoothed"].is_string()?(bool)atoi(obj["issmoothed"].get<std::string>().c_str()):obj["issmoothed"].get<bool>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("reason"))
        {
            msg.reason = (obj["reason"].is_string()?(obj["reason"].get<std::string>().c_str()):obj["reason"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSmootherDebug from_json<ApolloplanningInternalSmootherDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSmootherDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSmootherDebug &dt)
    {
        dt=from_json_ApolloplanningInternalSmootherDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSmootherDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSmootherDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
