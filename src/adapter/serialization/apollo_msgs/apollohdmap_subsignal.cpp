#include "adapter/serialization/apollo_msgs/apollohdmap_subsignal.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSubsignal &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["type"] = (msg.type);
        obj["location"] = to_json(msg.location);
        return obj;
    }
    ApollohdmapSubsignal from_json_ApollohdmapSubsignal (nlohmann::json obj) {
        ApollohdmapSubsignal msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("location"))
        {
            msg.location = from_json_ApollocommonPointENU(obj["location"]);
        }
        return msg;
    }
    template <>
    ApollohdmapSubsignal from_json<ApollohdmapSubsignal>(nlohmann::json obj){
        return from_json_ApollohdmapSubsignal(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSubsignal &dt)
    {
        dt=from_json_ApollohdmapSubsignal(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSubsignal & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSubsignal & dt)
    {
        os << to_json(dt);
        return os;
    }
}
