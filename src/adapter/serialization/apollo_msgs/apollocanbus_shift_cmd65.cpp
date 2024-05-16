#include "adapter/serialization/apollo_msgs/apollocanbus_shift_cmd65.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftCmd65 &msg) {
        nlohmann::json obj;
        obj["shiftcmd"] = (msg.shiftcmd);
        return obj;
    }
    ApollocanbusShiftCmd65 from_json_ApollocanbusShiftCmd65 (nlohmann::json obj) {
        ApollocanbusShiftCmd65 msg;
        if(obj.contains("shiftcmd"))
        {
            msg.shiftcmd = (obj["shiftcmd"].is_string()?atoi(obj["shiftcmd"].get<std::string>().c_str()):obj["shiftcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusShiftCmd65 from_json<ApollocanbusShiftCmd65>(nlohmann::json obj){
        return from_json_ApollocanbusShiftCmd65(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftCmd65 &dt)
    {
        dt=from_json_ApollocanbusShiftCmd65(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftCmd65 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftCmd65 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
