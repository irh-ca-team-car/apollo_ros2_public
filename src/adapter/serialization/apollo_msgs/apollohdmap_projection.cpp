#include "adapter/serialization/apollo_msgs/apollohdmap_projection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapProjection &msg) {
        nlohmann::json obj;
        obj["proj"] = (msg.proj);
        return obj;
    }
    ApollohdmapProjection from_json_ApollohdmapProjection (nlohmann::json obj) {
        ApollohdmapProjection msg;
        if(obj.contains("proj"))
        {
            msg.proj = (obj["proj"].is_string()?(obj["proj"].get<std::string>().c_str()):obj["proj"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollohdmapProjection from_json<ApollohdmapProjection>(nlohmann::json obj){
        return from_json_ApollohdmapProjection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapProjection &dt)
    {
        dt=from_json_ApollohdmapProjection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapProjection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapProjection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
