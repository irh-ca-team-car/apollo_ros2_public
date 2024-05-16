#include "adapter/serialization/apollo_msgs/apollocanbus_steer_command112.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteerCommand112 &msg) {
        nlohmann::json obj;
        obj["steerangleenctrl"] = (msg.steerangleenctrl);
        obj["steeranglecmd"] = (msg.steeranglecmd);
        return obj;
    }
    ApollocanbusSteerCommand112 from_json_ApollocanbusSteerCommand112 (nlohmann::json obj) {
        ApollocanbusSteerCommand112 msg;
        if(obj.contains("steerangleenctrl"))
        {
            msg.steerangleenctrl = (obj["steerangleenctrl"].is_string()?atoi(obj["steerangleenctrl"].get<std::string>().c_str()):obj["steerangleenctrl"].get<int>());
        }
        if(obj.contains("steeranglecmd"))
        {
            msg.steeranglecmd = (obj["steeranglecmd"].is_string()?atof(obj["steeranglecmd"].get<std::string>().c_str()):obj["steeranglecmd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteerCommand112 from_json<ApollocanbusSteerCommand112>(nlohmann::json obj){
        return from_json_ApollocanbusSteerCommand112(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteerCommand112 &dt)
    {
        dt=from_json_ApollocanbusSteerCommand112(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteerCommand112 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteerCommand112 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
