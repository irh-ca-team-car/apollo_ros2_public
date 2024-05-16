#include "adapter/serialization/apollo_msgs/apollocanbus_brake_cmd6b.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCmd6b &msg) {
        nlohmann::json obj;
        obj["brakecmd"] = (msg.brakecmd);
        return obj;
    }
    ApollocanbusBrakeCmd6b from_json_ApollocanbusBrakeCmd6b (nlohmann::json obj) {
        ApollocanbusBrakeCmd6b msg;
        if(obj.contains("brakecmd"))
        {
            msg.brakecmd = (obj["brakecmd"].is_string()?atof(obj["brakecmd"].get<std::string>().c_str()):obj["brakecmd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeCmd6b from_json<ApollocanbusBrakeCmd6b>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeCmd6b(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCmd6b &dt)
    {
        dt=from_json_ApollocanbusBrakeCmd6b(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCmd6b & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCmd6b & dt)
    {
        os << to_json(dt);
        return os;
    }
}
