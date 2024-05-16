#include "adapter/serialization/apollo_msgs/apollocanbus_gear_status514.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearStatus514 &msg) {
        nlohmann::json obj;
        obj["gearsts"] = (msg.gearsts);
        return obj;
    }
    ApollocanbusGearStatus514 from_json_ApollocanbusGearStatus514 (nlohmann::json obj) {
        ApollocanbusGearStatus514 msg;
        if(obj.contains("gearsts"))
        {
            msg.gearsts = (obj["gearsts"].is_string()?atoi(obj["gearsts"].get<std::string>().c_str()):obj["gearsts"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGearStatus514 from_json<ApollocanbusGearStatus514>(nlohmann::json obj){
        return from_json_ApollocanbusGearStatus514(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearStatus514 &dt)
    {
        dt=from_json_ApollocanbusGearStatus514(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearStatus514 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearStatus514 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
