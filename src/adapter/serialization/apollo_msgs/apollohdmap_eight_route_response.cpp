#include "adapter/serialization/apollo_msgs/apollohdmap_eight_route_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapEightRouteResponse &msg) {
        nlohmann::json obj;
        obj["code"] = (msg.code);
        obj["progress"] = (msg.progress);
        return obj;
    }
    ApollohdmapEightRouteResponse from_json_ApollohdmapEightRouteResponse (nlohmann::json obj) {
        ApollohdmapEightRouteResponse msg;
        if(obj.contains("code"))
        {
            msg.code = (obj["code"].is_string()?atoi(obj["code"].get<std::string>().c_str()):obj["code"].get<int>());
        }
        if(obj.contains("progress"))
        {
            msg.progress = (obj["progress"].is_string()?atof(obj["progress"].get<std::string>().c_str()):obj["progress"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapEightRouteResponse from_json<ApollohdmapEightRouteResponse>(nlohmann::json obj){
        return from_json_ApollohdmapEightRouteResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapEightRouteResponse &dt)
    {
        dt=from_json_ApollohdmapEightRouteResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapEightRouteResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapEightRouteResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
