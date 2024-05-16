#include "adapter/serialization/apollo_msgs/apollocanbus_gear_control_a1.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearControlA1 &msg) {
        nlohmann::json obj;
        obj["gearstatetarget"] = (msg.gearstatetarget);
        obj["gearenablecontrol"] = (msg.gearenablecontrol);
        return obj;
    }
    ApollocanbusGearControlA1 from_json_ApollocanbusGearControlA1 (nlohmann::json obj) {
        ApollocanbusGearControlA1 msg;
        if(obj.contains("gearstatetarget"))
        {
            msg.gearstatetarget = (obj["gearstatetarget"].is_string()?atoi(obj["gearstatetarget"].get<std::string>().c_str()):obj["gearstatetarget"].get<int>());
        }
        if(obj.contains("gearenablecontrol"))
        {
            msg.gearenablecontrol = (obj["gearenablecontrol"].is_string()?atoi(obj["gearenablecontrol"].get<std::string>().c_str()):obj["gearenablecontrol"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGearControlA1 from_json<ApollocanbusGearControlA1>(nlohmann::json obj){
        return from_json_ApollocanbusGearControlA1(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearControlA1 &dt)
    {
        dt=from_json_ApollocanbusGearControlA1(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearControlA1 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearControlA1 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
