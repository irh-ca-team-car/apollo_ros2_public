#include "adapter/serialization/apollo_msgs/apollocanbus_fbs2240.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs2240 &msg) {
        nlohmann::json obj;
        obj["flwheeldirection"] = (msg.flwheeldirection);
        obj["frwheelspd"] = (msg.frwheelspd);
        obj["rlwheeldrivedirection"] = (msg.rlwheeldrivedirection);
        obj["rlwheelspd"] = (msg.rlwheelspd);
        obj["rrwheeldirection"] = (msg.rrwheeldirection);
        obj["rrwheelspd"] = (msg.rrwheelspd);
        obj["vehiclespd"] = (msg.vehiclespd);
        return obj;
    }
    ApollocanbusFbs2240 from_json_ApollocanbusFbs2240 (nlohmann::json obj) {
        ApollocanbusFbs2240 msg;
        if(obj.contains("flwheeldirection"))
        {
            msg.flwheeldirection = (obj["flwheeldirection"].is_string()?atoi(obj["flwheeldirection"].get<std::string>().c_str()):obj["flwheeldirection"].get<int>());
        }
        if(obj.contains("frwheelspd"))
        {
            msg.frwheelspd = (obj["frwheelspd"].is_string()?atof(obj["frwheelspd"].get<std::string>().c_str()):obj["frwheelspd"].get<double>());
        }
        if(obj.contains("rlwheeldrivedirection"))
        {
            msg.rlwheeldrivedirection = (obj["rlwheeldrivedirection"].is_string()?atoi(obj["rlwheeldrivedirection"].get<std::string>().c_str()):obj["rlwheeldrivedirection"].get<int>());
        }
        if(obj.contains("rlwheelspd"))
        {
            msg.rlwheelspd = (obj["rlwheelspd"].is_string()?atof(obj["rlwheelspd"].get<std::string>().c_str()):obj["rlwheelspd"].get<double>());
        }
        if(obj.contains("rrwheeldirection"))
        {
            msg.rrwheeldirection = (obj["rrwheeldirection"].is_string()?atoi(obj["rrwheeldirection"].get<std::string>().c_str()):obj["rrwheeldirection"].get<int>());
        }
        if(obj.contains("rrwheelspd"))
        {
            msg.rrwheelspd = (obj["rrwheelspd"].is_string()?atof(obj["rrwheelspd"].get<std::string>().c_str()):obj["rrwheelspd"].get<double>());
        }
        if(obj.contains("vehiclespd"))
        {
            msg.vehiclespd = (obj["vehiclespd"].is_string()?atof(obj["vehiclespd"].get<std::string>().c_str()):obj["vehiclespd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusFbs2240 from_json<ApollocanbusFbs2240>(nlohmann::json obj){
        return from_json_ApollocanbusFbs2240(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs2240 &dt)
    {
        dt=from_json_ApollocanbusFbs2240(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs2240 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs2240 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
