#include "adapter/serialization/apollo_msgs/apollorouting_lane_waypoint.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingLaneWaypoint &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["s"] = (msg.s);
        obj["pose"] = to_json(msg.pose);
        return obj;
    }
    ApolloroutingLaneWaypoint from_json_ApolloroutingLaneWaypoint (nlohmann::json obj) {
        ApolloroutingLaneWaypoint msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("pose"))
        {
            msg.pose = from_json_ApollocommonPointENU(obj["pose"]);
        }
        return msg;
    }
    template <>
    ApolloroutingLaneWaypoint from_json<ApolloroutingLaneWaypoint>(nlohmann::json obj){
        return from_json_ApolloroutingLaneWaypoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingLaneWaypoint &dt)
    {
        dt=from_json_ApolloroutingLaneWaypoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingLaneWaypoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingLaneWaypoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
