#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_status510.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleStatus510 &msg) {
        nlohmann::json obj;
        obj["throttlepedalensts"] = (msg.throttlepedalensts);
        obj["throttlepedalsts"] = (msg.throttlepedalsts);
        obj["drivemotorerr"] = (msg.drivemotorerr);
        obj["batterybmserr"] = (msg.batterybmserr);
        return obj;
    }
    ApollocanbusThrottleStatus510 from_json_ApollocanbusThrottleStatus510 (nlohmann::json obj) {
        ApollocanbusThrottleStatus510 msg;
        if(obj.contains("throttlepedalensts"))
        {
            msg.throttlepedalensts = (obj["throttlepedalensts"].is_string()?atoi(obj["throttlepedalensts"].get<std::string>().c_str()):obj["throttlepedalensts"].get<int>());
        }
        if(obj.contains("throttlepedalsts"))
        {
            msg.throttlepedalsts = (obj["throttlepedalsts"].is_string()?atoi(obj["throttlepedalsts"].get<std::string>().c_str()):obj["throttlepedalsts"].get<int>());
        }
        if(obj.contains("drivemotorerr"))
        {
            msg.drivemotorerr = (obj["drivemotorerr"].is_string()?atoi(obj["drivemotorerr"].get<std::string>().c_str()):obj["drivemotorerr"].get<int>());
        }
        if(obj.contains("batterybmserr"))
        {
            msg.batterybmserr = (obj["batterybmserr"].is_string()?atoi(obj["batterybmserr"].get<std::string>().c_str()):obj["batterybmserr"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusThrottleStatus510 from_json<ApollocanbusThrottleStatus510>(nlohmann::json obj){
        return from_json_ApollocanbusThrottleStatus510(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleStatus510 &dt)
    {
        dt=from_json_ApollocanbusThrottleStatus510(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleStatus510 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleStatus510 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
