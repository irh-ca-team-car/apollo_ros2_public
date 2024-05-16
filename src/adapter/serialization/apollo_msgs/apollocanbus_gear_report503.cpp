#include "adapter/serialization/apollo_msgs/apollocanbus_gear_report503.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGearReport503 &msg) {
        nlohmann::json obj;
        obj["gearflt"] = (msg.gearflt);
        obj["gearactual"] = (msg.gearactual);
        return obj;
    }
    ApollocanbusGearReport503 from_json_ApollocanbusGearReport503 (nlohmann::json obj) {
        ApollocanbusGearReport503 msg;
        if(obj.contains("gearflt"))
        {
            msg.gearflt = (obj["gearflt"].is_string()?atoi(obj["gearflt"].get<std::string>().c_str()):obj["gearflt"].get<int>());
        }
        if(obj.contains("gearactual"))
        {
            msg.gearactual = (obj["gearactual"].is_string()?atoi(obj["gearactual"].get<std::string>().c_str()):obj["gearactual"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusGearReport503 from_json<ApollocanbusGearReport503>(nlohmann::json obj){
        return from_json_ApollocanbusGearReport503(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGearReport503 &dt)
    {
        dt=from_json_ApollocanbusGearReport503(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGearReport503 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGearReport503 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
