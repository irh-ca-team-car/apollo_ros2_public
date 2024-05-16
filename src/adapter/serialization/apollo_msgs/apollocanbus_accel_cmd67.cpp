#include "adapter/serialization/apollo_msgs/apollocanbus_accel_cmd67.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelCmd67 &msg) {
        nlohmann::json obj;
        obj["accelcmd"] = (msg.accelcmd);
        return obj;
    }
    ApollocanbusAccelCmd67 from_json_ApollocanbusAccelCmd67 (nlohmann::json obj) {
        ApollocanbusAccelCmd67 msg;
        if(obj.contains("accelcmd"))
        {
            msg.accelcmd = (obj["accelcmd"].is_string()?atof(obj["accelcmd"].get<std::string>().c_str()):obj["accelcmd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAccelCmd67 from_json<ApollocanbusAccelCmd67>(nlohmann::json obj){
        return from_json_ApollocanbusAccelCmd67(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelCmd67 &dt)
    {
        dt=from_json_ApollocanbusAccelCmd67(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelCmd67 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelCmd67 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
