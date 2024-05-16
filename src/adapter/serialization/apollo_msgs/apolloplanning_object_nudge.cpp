#include "adapter/serialization/apollo_msgs/apolloplanning_object_nudge.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectNudge &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["distancel"] = (msg.distancel);
        return obj;
    }
    ApolloplanningObjectNudge from_json_ApolloplanningObjectNudge (nlohmann::json obj) {
        ApolloplanningObjectNudge msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("distancel"))
        {
            msg.distancel = (obj["distancel"].is_string()?atof(obj["distancel"].get<std::string>().c_str()):obj["distancel"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningObjectNudge from_json<ApolloplanningObjectNudge>(nlohmann::json obj){
        return from_json_ApolloplanningObjectNudge(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectNudge &dt)
    {
        dt=from_json_ApolloplanningObjectNudge(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectNudge & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectNudge & dt)
    {
        os << to_json(dt);
        return os;
    }
}
