#include "adapter/serialization/apollo_msgs/apollohdmap_sign_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSignInfo &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        return obj;
    }
    ApollohdmapSignInfo from_json_ApollohdmapSignInfo (nlohmann::json obj) {
        ApollohdmapSignInfo msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapSignInfo from_json<ApollohdmapSignInfo>(nlohmann::json obj){
        return from_json_ApollohdmapSignInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSignInfo &dt)
    {
        dt=from_json_ApollohdmapSignInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSignInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSignInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
