#include "adapter/serialization/apollo_msgs/apollocanbus_gear_command103.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearCommand103 &msg) {
        nlohmann::json obj;
        obj["geartarget"] = (msg.geartarget);
        obj["gearenctrl"] = (msg.gearenctrl);
        obj["checksum103"] = (msg.checksum103);
        return obj;
    }
    ApollocanbusGearCommand103 from_json_ApollocanbusGearCommand103 (nlohmann::json obj) {
        ApollocanbusGearCommand103 msg;
        if(obj.contains("geartarget"))
        {
            msg.geartarget = (obj["geartarget"].is_string()?atoi(obj["geartarget"].get<std::string>().c_str()):obj["geartarget"].get<int>());
        }
        if(obj.contains("gearenctrl"))
        {
            msg.gearenctrl = (obj["gearenctrl"].is_string()?atoi(obj["gearenctrl"].get<std::string>().c_str()):obj["gearenctrl"].get<int>());
        }
        if(obj.contains("checksum103"))
        {
            msg.checksum103 = (obj["checksum103"].is_string()?atoi(obj["checksum103"].get<std::string>().c_str()):obj["checksum103"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGearCommand103 from_json<ApollocanbusGearCommand103>(nlohmann::json obj){
        return from_json_ApollocanbusGearCommand103(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearCommand103 &dt)
    {
        dt=from_json_ApollocanbusGearCommand103(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearCommand103 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearCommand103 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
