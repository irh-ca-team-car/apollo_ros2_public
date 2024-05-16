#include "adapter/serialization/apollo_msgs/apollocanbus_gear_command114.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearCommand114 &msg) {
        nlohmann::json obj;
        obj["gearcmd"] = (msg.gearcmd);
        return obj;
    }
    ApollocanbusGearCommand114 from_json_ApollocanbusGearCommand114 (nlohmann::json obj) {
        ApollocanbusGearCommand114 msg;
        if(obj.contains("gearcmd"))
        {
            msg.gearcmd = (obj["gearcmd"].is_string()?atoi(obj["gearcmd"].get<std::string>().c_str()):obj["gearcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGearCommand114 from_json<ApollocanbusGearCommand114>(nlohmann::json obj){
        return from_json_ApollocanbusGearCommand114(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearCommand114 &dt)
    {
        dt=from_json_ApollocanbusGearCommand114(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearCommand114 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearCommand114 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
