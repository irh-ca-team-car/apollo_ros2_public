#include "adapter/serialization/apollo_msgs/apollocanbus_fbs1243.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs1243 &msg) {
        nlohmann::json obj;
        obj["longitudeacce"] = (msg.longitudeacce);
        obj["lateralacce"] = (msg.lateralacce);
        obj["vehdynyawrate"] = (msg.vehdynyawrate);
        obj["flwheelspd"] = (msg.flwheelspd);
        obj["frwheeldirection"] = (msg.frwheeldirection);
        return obj;
    }
    ApollocanbusFbs1243 from_json_ApollocanbusFbs1243 (nlohmann::json obj) {
        ApollocanbusFbs1243 msg;
        if(obj.contains("longitudeacce"))
        {
            msg.longitudeacce = (obj["longitudeacce"].is_string()?atof(obj["longitudeacce"].get<std::string>().c_str()):obj["longitudeacce"].get<double>());
        }
        if(obj.contains("lateralacce"))
        {
            msg.lateralacce = (obj["lateralacce"].is_string()?atof(obj["lateralacce"].get<std::string>().c_str()):obj["lateralacce"].get<double>());
        }
        if(obj.contains("vehdynyawrate"))
        {
            msg.vehdynyawrate = (obj["vehdynyawrate"].is_string()?atof(obj["vehdynyawrate"].get<std::string>().c_str()):obj["vehdynyawrate"].get<double>());
        }
        if(obj.contains("flwheelspd"))
        {
            msg.flwheelspd = (obj["flwheelspd"].is_string()?atof(obj["flwheelspd"].get<std::string>().c_str()):obj["flwheelspd"].get<double>());
        }
        if(obj.contains("frwheeldirection"))
        {
            msg.frwheeldirection = (obj["frwheeldirection"].is_string()?atoi(obj["frwheeldirection"].get<std::string>().c_str()):obj["frwheeldirection"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusFbs1243 from_json<ApollocanbusFbs1243>(nlohmann::json obj){
        return from_json_ApollocanbusFbs1243(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs1243 &dt)
    {
        dt=from_json_ApollocanbusFbs1243(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs1243 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs1243 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
