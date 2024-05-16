#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_command110.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleCommand110 &msg) {
        nlohmann::json obj;
        obj["throttlepedalenctrl"] = (msg.throttlepedalenctrl);
        obj["throttlepedalcmd"] = (msg.throttlepedalcmd);
        return obj;
    }
    ApollocanbusThrottleCommand110 from_json_ApollocanbusThrottleCommand110 (nlohmann::json obj) {
        ApollocanbusThrottleCommand110 msg;
        if(obj.contains("throttlepedalenctrl"))
        {
            msg.throttlepedalenctrl = (obj["throttlepedalenctrl"].is_string()?atoi(obj["throttlepedalenctrl"].get<std::string>().c_str()):obj["throttlepedalenctrl"].get<int>());
        }
        if(obj.contains("throttlepedalcmd"))
        {
            msg.throttlepedalcmd = (obj["throttlepedalcmd"].is_string()?atoi(obj["throttlepedalcmd"].get<std::string>().c_str()):obj["throttlepedalcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusThrottleCommand110 from_json<ApollocanbusThrottleCommand110>(nlohmann::json obj){
        return from_json_ApollocanbusThrottleCommand110(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleCommand110 &dt)
    {
        dt=from_json_ApollocanbusThrottleCommand110(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleCommand110 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleCommand110 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
