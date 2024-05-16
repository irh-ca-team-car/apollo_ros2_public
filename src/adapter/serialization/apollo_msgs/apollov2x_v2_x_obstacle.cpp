#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xV2XObstacle &msg) {
        nlohmann::json obj;
        obj["perceptionobstacle"] = to_json(msg.perceptionobstacle);
        obj["v2xinfo"] = to_json(msg.v2xinfo);
        return obj;
    }
    Apollov2xV2XObstacle from_json_Apollov2xV2XObstacle (nlohmann::json obj) {
        Apollov2xV2XObstacle msg;
        if(obj.contains("perceptionobstacle"))
        {
            msg.perceptionobstacle = from_json_ApolloperceptionPerceptionObstacle(obj["perceptionobstacle"]);
        }
        if(obj.contains("v2xinfo"))
        {
            msg.v2xinfo = from_json_Apollov2xV2XInformation(obj["v2xinfo"]);
        }
        return msg;
    }
    template <>
    Apollov2xV2XObstacle from_json<Apollov2xV2XObstacle>(nlohmann::json obj){
        return from_json_Apollov2xV2XObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xV2XObstacle &dt)
    {
        dt=from_json_Apollov2xV2XObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xV2XObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xV2XObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
