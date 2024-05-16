#include "adapter/serialization/apollo_msgs/apollohdmap_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapId &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        return obj;
    }
    ApollohdmapId from_json_ApollohdmapId (nlohmann::json obj) {
        ApollohdmapId msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollohdmapId from_json<ApollohdmapId>(nlohmann::json obj){
        return from_json_ApollohdmapId(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapId &dt)
    {
        dt=from_json_ApollohdmapId(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapId & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapId & dt)
    {
        os << to_json(dt);
        return os;
    }
}
