#include "adapter/serialization/apollo_msgs/apollocanbus_parking_brake_status_rpt80.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingBrakeStatusRpt80 &msg) {
        nlohmann::json obj;
        obj["parkingbrakeenabled"] = (msg.parkingbrakeenabled);
        return obj;
    }
    ApollocanbusParkingBrakeStatusRpt80 from_json_ApollocanbusParkingBrakeStatusRpt80 (nlohmann::json obj) {
        ApollocanbusParkingBrakeStatusRpt80 msg;
        if(obj.contains("parkingbrakeenabled"))
        {
            msg.parkingbrakeenabled = (obj["parkingbrakeenabled"].is_string()?atoi(obj["parkingbrakeenabled"].get<std::string>().c_str()):obj["parkingbrakeenabled"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusParkingBrakeStatusRpt80 from_json<ApollocanbusParkingBrakeStatusRpt80>(nlohmann::json obj){
        return from_json_ApollocanbusParkingBrakeStatusRpt80(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingBrakeStatusRpt80 &dt)
    {
        dt=from_json_ApollocanbusParkingBrakeStatusRpt80(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingBrakeStatusRpt80 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingBrakeStatusRpt80 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
