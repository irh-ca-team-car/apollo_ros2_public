#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_cmd76.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightCmd76 &msg) {
        nlohmann::json obj;
        obj["headlightcmd"] = (msg.headlightcmd);
        return obj;
    }
    ApollocanbusHeadlightCmd76 from_json_ApollocanbusHeadlightCmd76 (nlohmann::json obj) {
        ApollocanbusHeadlightCmd76 msg;
        if(obj.contains("headlightcmd"))
        {
            msg.headlightcmd = (obj["headlightcmd"].is_string()?atoi(obj["headlightcmd"].get<std::string>().c_str()):obj["headlightcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusHeadlightCmd76 from_json<ApollocanbusHeadlightCmd76>(nlohmann::json obj){
        return from_json_ApollocanbusHeadlightCmd76(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightCmd76 &dt)
    {
        dt=from_json_ApollocanbusHeadlightCmd76(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightCmd76 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightCmd76 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
