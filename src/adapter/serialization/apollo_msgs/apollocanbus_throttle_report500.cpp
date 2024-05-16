#include "adapter/serialization/apollo_msgs/apollocanbus_throttle_report500.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusThrottleReport500 &msg) {
        nlohmann::json obj;
        obj["throttlepedalactual"] = (msg.throttlepedalactual);
        obj["throttleflt2"] = (msg.throttleflt2);
        obj["throttleflt1"] = (msg.throttleflt1);
        obj["throttleenstate"] = (msg.throttleenstate);
        return obj;
    }
    ApollocanbusThrottleReport500 from_json_ApollocanbusThrottleReport500 (nlohmann::json obj) {
        ApollocanbusThrottleReport500 msg;
        if(obj.contains("throttlepedalactual"))
        {
            msg.throttlepedalactual = (obj["throttlepedalactual"].is_string()?atof(obj["throttlepedalactual"].get<std::string>().c_str()):obj["throttlepedalactual"].get<double>());
        }
        if(obj.contains("throttleflt2"))
        {
            msg.throttleflt2 = (obj["throttleflt2"].is_string()?atoi(obj["throttleflt2"].get<std::string>().c_str()):obj["throttleflt2"].get<int>());
        }
        if(obj.contains("throttleflt1"))
        {
            msg.throttleflt1 = (obj["throttleflt1"].is_string()?atoi(obj["throttleflt1"].get<std::string>().c_str()):obj["throttleflt1"].get<int>());
        }
        if(obj.contains("throttleenstate"))
        {
            msg.throttleenstate = (obj["throttleenstate"].is_string()?atoi(obj["throttleenstate"].get<std::string>().c_str()):obj["throttleenstate"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusThrottleReport500 from_json<ApollocanbusThrottleReport500>(nlohmann::json obj){
        return from_json_ApollocanbusThrottleReport500(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusThrottleReport500 &dt)
    {
        dt=from_json_ApollocanbusThrottleReport500(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusThrottleReport500 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusThrottleReport500 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
