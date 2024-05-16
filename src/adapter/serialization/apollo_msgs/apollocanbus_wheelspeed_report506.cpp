#include "adapter/serialization/apollo_msgs/apollocanbus_wheelspeed_report506.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWheelspeedReport506 &msg) {
        nlohmann::json obj;
        obj["rr"] = (msg.rr);
        obj["rl"] = (msg.rl);
        obj["fr"] = (msg.fr);
        obj["fl"] = (msg.fl);
        return obj;
    }
    ApollocanbusWheelspeedReport506 from_json_ApollocanbusWheelspeedReport506 (nlohmann::json obj) {
        ApollocanbusWheelspeedReport506 msg;
        if(obj.contains("rr"))
        {
            msg.rr = (obj["rr"].is_string()?atof(obj["rr"].get<std::string>().c_str()):obj["rr"].get<double>());
        }
        if(obj.contains("rl"))
        {
            msg.rl = (obj["rl"].is_string()?atof(obj["rl"].get<std::string>().c_str()):obj["rl"].get<double>());
        }
        if(obj.contains("fr"))
        {
            msg.fr = (obj["fr"].is_string()?atof(obj["fr"].get<std::string>().c_str()):obj["fr"].get<double>());
        }
        if(obj.contains("fl"))
        {
            msg.fl = (obj["fl"].is_string()?atof(obj["fl"].get<std::string>().c_str()):obj["fl"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusWheelspeedReport506 from_json<ApollocanbusWheelspeedReport506>(nlohmann::json obj){
        return from_json_ApollocanbusWheelspeedReport506(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWheelspeedReport506 &dt)
    {
        dt=from_json_ApollocanbusWheelspeedReport506(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWheelspeedReport506 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWheelspeedReport506 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
