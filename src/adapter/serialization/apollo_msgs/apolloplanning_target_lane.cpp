#include "adapter/serialization/apollo_msgs/apolloplanning_target_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTargetLane &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["starts"] = (msg.starts);
        obj["ends"] = (msg.ends);
        obj["speedlimit"] = (msg.speedlimit);
        return obj;
    }
    ApolloplanningTargetLane from_json_ApolloplanningTargetLane (nlohmann::json obj) {
        ApolloplanningTargetLane msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("starts"))
        {
            msg.starts = (obj["starts"].is_string()?atof(obj["starts"].get<std::string>().c_str()):obj["starts"].get<double>());
        }
        if(obj.contains("ends"))
        {
            msg.ends = (obj["ends"].is_string()?atof(obj["ends"].get<std::string>().c_str()):obj["ends"].get<double>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningTargetLane from_json<ApolloplanningTargetLane>(nlohmann::json obj){
        return from_json_ApolloplanningTargetLane(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTargetLane &dt)
    {
        dt=from_json_ApolloplanningTargetLane(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTargetLane & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTargetLane & dt)
    {
        os << to_json(dt);
        return os;
    }
}
