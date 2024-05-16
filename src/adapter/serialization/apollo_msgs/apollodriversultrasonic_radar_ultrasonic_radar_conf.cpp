#include "adapter/serialization/apollo_msgs/apollodriversultrasonic_radar_ultrasonic_radar_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversultrasonicRadarUltrasonicRadarConf &msg) {
        nlohmann::json obj;
        obj["canconf"] = to_json(msg.canconf);
        obj["entrancenum"] = (msg.entrancenum);
        return obj;
    }
    ApollodriversultrasonicRadarUltrasonicRadarConf from_json_ApollodriversultrasonicRadarUltrasonicRadarConf (nlohmann::json obj) {
        ApollodriversultrasonicRadarUltrasonicRadarConf msg;
        if(obj.contains("canconf"))
        {
            msg.canconf = from_json_ApollodriversultrasonicRadarCanConf(obj["canconf"]);
        }
        if(obj.contains("entrancenum"))
        {
            msg.entrancenum = (obj["entrancenum"].is_string()?atoi(obj["entrancenum"].get<std::string>().c_str()):obj["entrancenum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversultrasonicRadarUltrasonicRadarConf from_json<ApollodriversultrasonicRadarUltrasonicRadarConf>(nlohmann::json obj){
        return from_json_ApollodriversultrasonicRadarUltrasonicRadarConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversultrasonicRadarUltrasonicRadarConf &dt)
    {
        dt=from_json_ApollodriversultrasonicRadarUltrasonicRadarConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversultrasonicRadarUltrasonicRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversultrasonicRadarUltrasonicRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
