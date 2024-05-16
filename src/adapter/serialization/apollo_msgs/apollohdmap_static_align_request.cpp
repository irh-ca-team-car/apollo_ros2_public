#include "adapter/serialization/apollo_msgs/apollohdmap_static_align_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapStaticAlignRequest &msg) {
        nlohmann::json obj;
        obj["cmd"] = (msg.cmd);
        return obj;
    }
    ApollohdmapStaticAlignRequest from_json_ApollohdmapStaticAlignRequest (nlohmann::json obj) {
        ApollohdmapStaticAlignRequest msg;
        if(obj.contains("cmd"))
        {
            msg.cmd = (obj["cmd"].is_string()?atoi(obj["cmd"].get<std::string>().c_str()):obj["cmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapStaticAlignRequest from_json<ApollohdmapStaticAlignRequest>(nlohmann::json obj){
        return from_json_ApollohdmapStaticAlignRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapStaticAlignRequest &dt)
    {
        dt=from_json_ApollohdmapStaticAlignRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapStaticAlignRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapStaticAlignRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
