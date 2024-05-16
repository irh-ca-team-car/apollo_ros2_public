#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_conti_radar_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscontiRadarContiRadarConf &msg) {
        nlohmann::json obj;
        obj["canconf"] = to_json(msg.canconf);
        obj["radarconf"] = to_json(msg.radarconf);
        obj["radarchannel"] = (msg.radarchannel);
        return obj;
    }
    ApollodriverscontiRadarContiRadarConf from_json_ApollodriverscontiRadarContiRadarConf (nlohmann::json obj) {
        ApollodriverscontiRadarContiRadarConf msg;
        if(obj.contains("canconf"))
        {
            msg.canconf = from_json_ApollodriverscontiRadarCanConf(obj["canconf"]);
        }
        if(obj.contains("radarconf"))
        {
            msg.radarconf = from_json_ApollodriverscontiRadarRadarConf(obj["radarconf"]);
        }
        if(obj.contains("radarchannel"))
        {
            msg.radarchannel = (obj["radarchannel"].is_string()?(obj["radarchannel"].get<std::string>().c_str()):obj["radarchannel"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodriverscontiRadarContiRadarConf from_json<ApollodriverscontiRadarContiRadarConf>(nlohmann::json obj){
        return from_json_ApollodriverscontiRadarContiRadarConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscontiRadarContiRadarConf &dt)
    {
        dt=from_json_ApollodriverscontiRadarContiRadarConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverscontiRadarContiRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscontiRadarContiRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
