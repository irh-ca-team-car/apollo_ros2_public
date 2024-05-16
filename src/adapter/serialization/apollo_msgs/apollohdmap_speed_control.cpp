#include "adapter/serialization/apollo_msgs/apollohdmap_speed_control.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSpeedControl &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["polygon"] = to_json(msg.polygon);
        obj["speedlimit"] = (msg.speedlimit);
        return obj;
    }
    ApollohdmapSpeedControl from_json_ApollohdmapSpeedControl (nlohmann::json obj) {
        ApollohdmapSpeedControl msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("polygon"))
        {
            msg.polygon = from_json_ApollohdmapPolygon(obj["polygon"]);
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapSpeedControl from_json<ApollohdmapSpeedControl>(nlohmann::json obj){
        return from_json_ApollohdmapSpeedControl(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSpeedControl &dt)
    {
        dt=from_json_ApollohdmapSpeedControl(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSpeedControl & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSpeedControl & dt)
    {
        os << to_json(dt);
        return os;
    }
}
