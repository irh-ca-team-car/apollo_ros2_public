#include "adapter/serialization/apollo_msgs/apollocanbus_veh_specific_rpt1412.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehSpecificRpt1412 &msg) {
        nlohmann::json obj;
        obj["shiftpos2"] = (msg.shiftpos2);
        obj["shiftpos1"] = (msg.shiftpos1);
        return obj;
    }
    ApollocanbusVehSpecificRpt1412 from_json_ApollocanbusVehSpecificRpt1412 (nlohmann::json obj) {
        ApollocanbusVehSpecificRpt1412 msg;
        if(obj.contains("shiftpos2"))
        {
            msg.shiftpos2 = (obj["shiftpos2"].is_string()?atoi(obj["shiftpos2"].get<std::string>().c_str()):obj["shiftpos2"].get<int>());
        }
        if(obj.contains("shiftpos1"))
        {
            msg.shiftpos1 = (obj["shiftpos1"].is_string()?atoi(obj["shiftpos1"].get<std::string>().c_str()):obj["shiftpos1"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehSpecificRpt1412 from_json<ApollocanbusVehSpecificRpt1412>(nlohmann::json obj){
        return from_json_ApollocanbusVehSpecificRpt1412(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehSpecificRpt1412 &dt)
    {
        dt=from_json_ApollocanbusVehSpecificRpt1412(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehSpecificRpt1412 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehSpecificRpt1412 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
