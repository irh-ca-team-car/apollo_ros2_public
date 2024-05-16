#include "adapter/serialization/apollo_msgs/apollocanbus_steering_report502.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringReport502 &msg) {
        nlohmann::json obj;
        obj["steeranglespdactual"] = (msg.steeranglespdactual);
        obj["steerflt2"] = (msg.steerflt2);
        obj["steerflt1"] = (msg.steerflt1);
        obj["steerenstate"] = (msg.steerenstate);
        obj["steerangleactual"] = (msg.steerangleactual);
        return obj;
    }
    ApollocanbusSteeringReport502 from_json_ApollocanbusSteeringReport502 (nlohmann::json obj) {
        ApollocanbusSteeringReport502 msg;
        if(obj.contains("steeranglespdactual"))
        {
            msg.steeranglespdactual = (obj["steeranglespdactual"].is_string()?atoi(obj["steeranglespdactual"].get<std::string>().c_str()):obj["steeranglespdactual"].get<int>());
        }
        if(obj.contains("steerflt2"))
        {
            msg.steerflt2 = (obj["steerflt2"].is_string()?atoi(obj["steerflt2"].get<std::string>().c_str()):obj["steerflt2"].get<int>());
        }
        if(obj.contains("steerflt1"))
        {
            msg.steerflt1 = (obj["steerflt1"].is_string()?atoi(obj["steerflt1"].get<std::string>().c_str()):obj["steerflt1"].get<int>());
        }
        if(obj.contains("steerenstate"))
        {
            msg.steerenstate = (obj["steerenstate"].is_string()?atoi(obj["steerenstate"].get<std::string>().c_str()):obj["steerenstate"].get<int>());
        }
        if(obj.contains("steerangleactual"))
        {
            msg.steerangleactual = (obj["steerangleactual"].is_string()?atoi(obj["steerangleactual"].get<std::string>().c_str()):obj["steerangleactual"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringReport502 from_json<ApollocanbusSteeringReport502>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringReport502(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringReport502 &dt)
    {
        dt=from_json_ApollocanbusSteeringReport502(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringReport502 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringReport502 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
