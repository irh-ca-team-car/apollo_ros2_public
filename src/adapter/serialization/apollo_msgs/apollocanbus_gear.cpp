#include "adapter/serialization/apollo_msgs/apollocanbus_gear.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGear &msg) {
        nlohmann::json obj;
        obj["isshiftpositionvalid"] = (msg.isshiftpositionvalid);
        obj["gearstate"] = (msg.gearstate);
        obj["driveroverride"] = (msg.driveroverride);
        obj["gearcmd"] = (msg.gearcmd);
        obj["canbusfault"] = (msg.canbusfault);
        return obj;
    }
    ApollocanbusGear from_json_ApollocanbusGear (nlohmann::json obj) {
        ApollocanbusGear msg;
        if(obj.contains("isshiftpositionvalid"))
        {
            msg.isshiftpositionvalid = (obj["isshiftpositionvalid"].is_string()?(bool)atoi(obj["isshiftpositionvalid"].get<std::string>().c_str()):obj["isshiftpositionvalid"].get<bool>());
        }
        if(obj.contains("gearstate"))
        {
            msg.gearstate = (obj["gearstate"].is_string()?atoi(obj["gearstate"].get<std::string>().c_str()):obj["gearstate"].get<int>());
        }
        if(obj.contains("driveroverride"))
        {
            msg.driveroverride = (obj["driveroverride"].is_string()?(bool)atoi(obj["driveroverride"].get<std::string>().c_str()):obj["driveroverride"].get<bool>());
        }
        if(obj.contains("gearcmd"))
        {
            msg.gearcmd = (obj["gearcmd"].is_string()?atoi(obj["gearcmd"].get<std::string>().c_str()):obj["gearcmd"].get<int>());
        }
        if(obj.contains("canbusfault"))
        {
            msg.canbusfault = (obj["canbusfault"].is_string()?(bool)atoi(obj["canbusfault"].get<std::string>().c_str()):obj["canbusfault"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusGear from_json<ApollocanbusGear>(nlohmann::json obj){
        return from_json_ApollocanbusGear(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGear &dt)
    {
        dt=from_json_ApollocanbusGear(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGear & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGear & dt)
    {
        os << to_json(dt);
        return os;
    }
}
