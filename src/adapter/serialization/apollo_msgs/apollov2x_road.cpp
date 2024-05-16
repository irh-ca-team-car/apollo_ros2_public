#include "adapter/serialization/apollo_msgs/apollov2x_road.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRoad &msg) {
        nlohmann::json obj;
        obj["upstreamnodeid"] = (msg.upstreamnodeid);
        obj["points"] = to_json(msg.points);
        nlohmann::json arr_lanes;
        for (auto it = msg.lanes.begin(); it != msg.lanes.end(); ++it) {
            arr_lanes.push_back(to_json(*it));
        }
        obj["lanes"] = arr_lanes;
        return obj;
    }
    Apollov2xRoad from_json_Apollov2xRoad (nlohmann::json obj) {
        Apollov2xRoad msg;
        if(obj.contains("upstreamnodeid"))
        {
            msg.upstreamnodeid = (obj["upstreamnodeid"].is_string()?atoi(obj["upstreamnodeid"].get<std::string>().c_str()):obj["upstreamnodeid"].get<int>());
        }
        if(obj.contains("points"))
        {
            msg.points = from_json_Apollov2xPosition2D(obj["points"]);
        }
        if(obj.contains("lanes"))
        {
            if(obj["lanes"].is_array())
            {
                for (auto& element : obj["lanes"])
                {
                    msg.lanes.push_back(from_json_Apollov2xLane(element));
                }
            }
            else
            {
                msg.lanes.push_back(from_json_Apollov2xLane(obj["lanes"]));
            }
        }
        return msg;
    }
    template <>
    Apollov2xRoad from_json<Apollov2xRoad>(nlohmann::json obj){
        return from_json_Apollov2xRoad(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRoad &dt)
    {
        dt=from_json_Apollov2xRoad(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xRoad & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRoad & dt)
    {
        os << to_json(dt);
        return os;
    }
}
