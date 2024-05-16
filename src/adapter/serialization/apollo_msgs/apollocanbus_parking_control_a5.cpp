#include "adapter/serialization/apollo_msgs/apollocanbus_parking_control_a5.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingControlA5 &msg) {
        nlohmann::json obj;
        obj["parkingtarget"] = (msg.parkingtarget);
        obj["parkingenablecontrol"] = (msg.parkingenablecontrol);
        return obj;
    }
    ApollocanbusParkingControlA5 from_json_ApollocanbusParkingControlA5 (nlohmann::json obj) {
        ApollocanbusParkingControlA5 msg;
        if(obj.contains("parkingtarget"))
        {
            msg.parkingtarget = (obj["parkingtarget"].is_string()?atoi(obj["parkingtarget"].get<std::string>().c_str()):obj["parkingtarget"].get<int>());
        }
        if(obj.contains("parkingenablecontrol"))
        {
            msg.parkingenablecontrol = (obj["parkingenablecontrol"].is_string()?atoi(obj["parkingenablecontrol"].get<std::string>().c_str()):obj["parkingenablecontrol"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusParkingControlA5 from_json<ApollocanbusParkingControlA5>(nlohmann::json obj){
        return from_json_ApollocanbusParkingControlA5(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingControlA5 &dt)
    {
        dt=from_json_ApollocanbusParkingControlA5(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingControlA5 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingControlA5 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
