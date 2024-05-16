#include "adapter/serialization/apollo_msgs/apollodriversracobit_radar_racobit_radar_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversracobitRadarRacobitRadarConf &msg) {
        nlohmann::json obj;
        obj["canconf"] = to_json(msg.canconf);
        obj["radarconf"] = to_json(msg.radarconf);
        return obj;
    }
    ApollodriversracobitRadarRacobitRadarConf from_json_ApollodriversracobitRadarRacobitRadarConf (nlohmann::json obj) {
        ApollodriversracobitRadarRacobitRadarConf msg;
        if(obj.contains("canconf"))
        {
            msg.canconf = from_json_ApollodriversracobitRadarCanConf(obj["canconf"]);
        }
        if(obj.contains("radarconf"))
        {
            msg.radarconf = from_json_ApollodriversracobitRadarRadarConf(obj["radarconf"]);
        }
        return msg;
    }
    template <>
    ApollodriversracobitRadarRacobitRadarConf from_json<ApollodriversracobitRadarRacobitRadarConf>(nlohmann::json obj){
        return from_json_ApollodriversracobitRadarRacobitRadarConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversracobitRadarRacobitRadarConf &dt)
    {
        dt=from_json_ApollodriversracobitRadarRacobitRadarConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversracobitRadarRacobitRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversracobitRadarRacobitRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
