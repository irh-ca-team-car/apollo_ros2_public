#include "adapter/serialization/apollo_msgs/apollocanbus_brake_command111.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCommand111 &msg) {
        nlohmann::json obj;
        obj["brakepedalenctrl"] = (msg.brakepedalenctrl);
        obj["brakepedalcmd"] = (msg.brakepedalcmd);
        return obj;
    }
    ApollocanbusBrakeCommand111 from_json_ApollocanbusBrakeCommand111 (nlohmann::json obj) {
        ApollocanbusBrakeCommand111 msg;
        if(obj.contains("brakepedalenctrl"))
        {
            msg.brakepedalenctrl = (obj["brakepedalenctrl"].is_string()?atoi(obj["brakepedalenctrl"].get<std::string>().c_str()):obj["brakepedalenctrl"].get<int>());
        }
        if(obj.contains("brakepedalcmd"))
        {
            msg.brakepedalcmd = (obj["brakepedalcmd"].is_string()?atoi(obj["brakepedalcmd"].get<std::string>().c_str()):obj["brakepedalcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeCommand111 from_json<ApollocanbusBrakeCommand111>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeCommand111(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCommand111 &dt)
    {
        dt=from_json_ApollocanbusBrakeCommand111(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCommand111 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCommand111 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
