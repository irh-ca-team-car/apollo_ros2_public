#include "adapter/serialization/apollo_msgs/apollocanbus_battery.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBattery &msg) {
        nlohmann::json obj;
        obj["batterypercent"] = (msg.batterypercent);
        obj["fuellevel"] = (msg.fuellevel);
        return obj;
    }
    ApollocanbusBattery from_json_ApollocanbusBattery (nlohmann::json obj) {
        ApollocanbusBattery msg;
        if(obj.contains("batterypercent"))
        {
            msg.batterypercent = (obj["batterypercent"].is_string()?atof(obj["batterypercent"].get<std::string>().c_str()):obj["batterypercent"].get<double>());
        }
        if(obj.contains("fuellevel"))
        {
            msg.fuellevel = (obj["fuellevel"].is_string()?atof(obj["fuellevel"].get<std::string>().c_str()):obj["fuellevel"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusBattery from_json<ApollocanbusBattery>(nlohmann::json obj){
        return from_json_ApollocanbusBattery(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBattery &dt)
    {
        dt=from_json_ApollocanbusBattery(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBattery & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBattery & dt)
    {
        os << to_json(dt);
        return os;
    }
}
