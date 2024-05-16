#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_command100.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleCommand100 &msg) {
        nlohmann::json obj;
        obj["throttleacc"] = (msg.throttleacc);
        obj["checksum100"] = (msg.checksum100);
        obj["throttlepedaltarget"] = (msg.throttlepedaltarget);
        obj["throttleenctrl"] = (msg.throttleenctrl);
        return obj;
    }
    ApollocanbusThrottleCommand100 from_json_ApollocanbusThrottleCommand100 (nlohmann::json obj) {
        ApollocanbusThrottleCommand100 msg;
        if(obj.contains("throttleacc"))
        {
            msg.throttleacc = (obj["throttleacc"].is_string()?atof(obj["throttleacc"].get<std::string>().c_str()):obj["throttleacc"].get<double>());
        }
        if(obj.contains("checksum100"))
        {
            msg.checksum100 = (obj["checksum100"].is_string()?atoi(obj["checksum100"].get<std::string>().c_str()):obj["checksum100"].get<int>());
        }
        if(obj.contains("throttlepedaltarget"))
        {
            msg.throttlepedaltarget = (obj["throttlepedaltarget"].is_string()?atof(obj["throttlepedaltarget"].get<std::string>().c_str()):obj["throttlepedaltarget"].get<double>());
        }
        if(obj.contains("throttleenctrl"))
        {
            msg.throttleenctrl = (obj["throttleenctrl"].is_string()?atoi(obj["throttleenctrl"].get<std::string>().c_str()):obj["throttleenctrl"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusThrottleCommand100 from_json<ApollocanbusThrottleCommand100>(nlohmann::json obj){
        return from_json_ApollocanbusThrottleCommand100(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleCommand100 &dt)
    {
        dt=from_json_ApollocanbusThrottleCommand100(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleCommand100 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleCommand100 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
