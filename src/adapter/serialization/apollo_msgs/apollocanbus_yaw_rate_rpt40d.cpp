#include "adapter/serialization/apollo_msgs/apollocanbus_yaw_rate_rpt40d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusYawRateRpt40d &msg) {
        nlohmann::json obj;
        obj["yawrate"] = (msg.yawrate);
        return obj;
    }
    ApollocanbusYawRateRpt40d from_json_ApollocanbusYawRateRpt40d (nlohmann::json obj) {
        ApollocanbusYawRateRpt40d msg;
        if(obj.contains("yawrate"))
        {
            msg.yawrate = (obj["yawrate"].is_string()?atof(obj["yawrate"].get<std::string>().c_str()):obj["yawrate"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusYawRateRpt40d from_json<ApollocanbusYawRateRpt40d>(nlohmann::json obj){
        return from_json_ApollocanbusYawRateRpt40d(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusYawRateRpt40d &dt)
    {
        dt=from_json_ApollocanbusYawRateRpt40d(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusYawRateRpt40d & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusYawRateRpt40d & dt)
    {
        os << to_json(dt);
        return os;
    }
}
