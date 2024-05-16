#include "adapter/serialization/apollo_msgs/apollocanbus_fbs4235.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs4235 &msg) {
        nlohmann::json obj;
        obj["steerwheelangle"] = (msg.steerwheelangle);
        obj["steerwheelspd"] = (msg.steerwheelspd);
        return obj;
    }
    ApollocanbusFbs4235 from_json_ApollocanbusFbs4235 (nlohmann::json obj) {
        ApollocanbusFbs4235 msg;
        if(obj.contains("steerwheelangle"))
        {
            msg.steerwheelangle = (obj["steerwheelangle"].is_string()?atof(obj["steerwheelangle"].get<std::string>().c_str()):obj["steerwheelangle"].get<double>());
        }
        if(obj.contains("steerwheelspd"))
        {
            msg.steerwheelspd = (obj["steerwheelspd"].is_string()?atof(obj["steerwheelspd"].get<std::string>().c_str()):obj["steerwheelspd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusFbs4235 from_json<ApollocanbusFbs4235>(nlohmann::json obj){
        return from_json_ApollocanbusFbs4235(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs4235 &dt)
    {
        dt=from_json_ApollocanbusFbs4235(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs4235 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs4235 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
