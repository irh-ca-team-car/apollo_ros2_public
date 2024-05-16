#include "adapter/serialization/apollo_msgs/apollocanbus_yaw_rate_rpt81.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusYawRateRpt81 &msg) {
        nlohmann::json obj;
        obj["yawrate"] = (msg.yawrate);
        return obj;
    }
    ApollocanbusYawRateRpt81 from_json_ApollocanbusYawRateRpt81 (nlohmann::json obj) {
        ApollocanbusYawRateRpt81 msg;
        if(obj.contains("yawrate"))
        {
            msg.yawrate = (obj["yawrate"].is_string()?atof(obj["yawrate"].get<std::string>().c_str()):obj["yawrate"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusYawRateRpt81 from_json<ApollocanbusYawRateRpt81>(nlohmann::json obj){
        return from_json_ApollocanbusYawRateRpt81(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusYawRateRpt81 &dt)
    {
        dt=from_json_ApollocanbusYawRateRpt81(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusYawRateRpt81 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusYawRateRpt81 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
