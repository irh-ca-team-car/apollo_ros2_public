#include "adapter/serialization/apollo_msgs/apollohdmap_eight_route_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapEightRouteRequest &msg) {
        nlohmann::json obj;
        obj["cmd"] = (msg.cmd);
        return obj;
    }
    ApollohdmapEightRouteRequest from_json_ApollohdmapEightRouteRequest (nlohmann::json obj) {
        ApollohdmapEightRouteRequest msg;
        if(obj.contains("cmd"))
        {
            msg.cmd = (obj["cmd"].is_string()?atoi(obj["cmd"].get<std::string>().c_str()):obj["cmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapEightRouteRequest from_json<ApollohdmapEightRouteRequest>(nlohmann::json obj){
        return from_json_ApollohdmapEightRouteRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapEightRouteRequest &dt)
    {
        dt=from_json_ApollohdmapEightRouteRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapEightRouteRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapEightRouteRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
