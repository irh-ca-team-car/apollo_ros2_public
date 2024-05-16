#include "adapter/serialization/apollo_msgs/apollocanbus_brake_report501.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeReport501 &msg) {
        nlohmann::json obj;
        obj["brakepedalactual"] = (msg.brakepedalactual);
        obj["brakeflt2"] = (msg.brakeflt2);
        obj["brakeflt1"] = (msg.brakeflt1);
        obj["brakeenstate"] = (msg.brakeenstate);
        return obj;
    }
    ApollocanbusBrakeReport501 from_json_ApollocanbusBrakeReport501 (nlohmann::json obj) {
        ApollocanbusBrakeReport501 msg;
        if(obj.contains("brakepedalactual"))
        {
            msg.brakepedalactual = (obj["brakepedalactual"].is_string()?atof(obj["brakepedalactual"].get<std::string>().c_str()):obj["brakepedalactual"].get<double>());
        }
        if(obj.contains("brakeflt2"))
        {
            msg.brakeflt2 = (obj["brakeflt2"].is_string()?atoi(obj["brakeflt2"].get<std::string>().c_str()):obj["brakeflt2"].get<int>());
        }
        if(obj.contains("brakeflt1"))
        {
            msg.brakeflt1 = (obj["brakeflt1"].is_string()?atoi(obj["brakeflt1"].get<std::string>().c_str()):obj["brakeflt1"].get<int>());
        }
        if(obj.contains("brakeenstate"))
        {
            msg.brakeenstate = (obj["brakeenstate"].is_string()?atoi(obj["brakeenstate"].get<std::string>().c_str()):obj["brakeenstate"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeReport501 from_json<ApollocanbusBrakeReport501>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeReport501(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeReport501 &dt)
    {
        dt=from_json_ApollocanbusBrakeReport501(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeReport501 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeReport501 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
