#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_cmd90.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperCmd90 &msg) {
        nlohmann::json obj;
        obj["wipercmd"] = (msg.wipercmd);
        return obj;
    }
    ApollocanbusWiperCmd90 from_json_ApollocanbusWiperCmd90 (nlohmann::json obj) {
        ApollocanbusWiperCmd90 msg;
        if(obj.contains("wipercmd"))
        {
            msg.wipercmd = (obj["wipercmd"].is_string()?atoi(obj["wipercmd"].get<std::string>().c_str()):obj["wipercmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusWiperCmd90 from_json<ApollocanbusWiperCmd90>(nlohmann::json obj){
        return from_json_ApollocanbusWiperCmd90(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperCmd90 &dt)
    {
        dt=from_json_ApollocanbusWiperCmd90(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperCmd90 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperCmd90 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
