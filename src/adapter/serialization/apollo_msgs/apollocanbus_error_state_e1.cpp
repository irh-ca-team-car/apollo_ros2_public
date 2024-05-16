#include "adapter/serialization/apollo_msgs/apollocanbus_error_state_e1.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusErrorStateE1 &msg) {
        nlohmann::json obj;
        obj["brakeerrorcode"] = (msg.brakeerrorcode);
        obj["drivenerrorcode"] = (msg.drivenerrorcode);
        obj["steeringerrorcode"] = (msg.steeringerrorcode);
        obj["parkingerrorcode"] = (msg.parkingerrorcode);
        obj["gearerrormsg"] = (msg.gearerrormsg);
        return obj;
    }
    ApollocanbusErrorStateE1 from_json_ApollocanbusErrorStateE1 (nlohmann::json obj) {
        ApollocanbusErrorStateE1 msg;
        if(obj.contains("brakeerrorcode"))
        {
            msg.brakeerrorcode = (obj["brakeerrorcode"].is_string()?atoi(obj["brakeerrorcode"].get<std::string>().c_str()):obj["brakeerrorcode"].get<int>());
        }
        if(obj.contains("drivenerrorcode"))
        {
            msg.drivenerrorcode = (obj["drivenerrorcode"].is_string()?atoi(obj["drivenerrorcode"].get<std::string>().c_str()):obj["drivenerrorcode"].get<int>());
        }
        if(obj.contains("steeringerrorcode"))
        {
            msg.steeringerrorcode = (obj["steeringerrorcode"].is_string()?atoi(obj["steeringerrorcode"].get<std::string>().c_str()):obj["steeringerrorcode"].get<int>());
        }
        if(obj.contains("parkingerrorcode"))
        {
            msg.parkingerrorcode = (obj["parkingerrorcode"].is_string()?atoi(obj["parkingerrorcode"].get<std::string>().c_str()):obj["parkingerrorcode"].get<int>());
        }
        if(obj.contains("gearerrormsg"))
        {
            msg.gearerrormsg = (obj["gearerrormsg"].is_string()?atoi(obj["gearerrormsg"].get<std::string>().c_str()):obj["gearerrormsg"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusErrorStateE1 from_json<ApollocanbusErrorStateE1>(nlohmann::json obj){
        return from_json_ApollocanbusErrorStateE1(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusErrorStateE1 &dt)
    {
        dt=from_json_ApollocanbusErrorStateE1(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusErrorStateE1 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusErrorStateE1 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
