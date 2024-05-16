#include "adapter/serialization/apollo_msgs/apollov2x_intersection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xIntersection &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["position"] = to_json(msg.position);
        nlohmann::json arr_roads;
        for (auto it = msg.roads.begin(); it != msg.roads.end(); ++it) {
            arr_roads.push_back(to_json(*it));
        }
        obj["roads"] = arr_roads;
        return obj;
    }
    Apollov2xIntersection from_json_Apollov2xIntersection (nlohmann::json obj) {
        Apollov2xIntersection msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_Apollov2xPosition2D(obj["position"]);
        }
        if(obj.contains("roads"))
        {
            if(obj["roads"].is_array())
            {
                for (auto& element : obj["roads"])
                {
                    msg.roads.push_back(from_json_Apollov2xRoad(element));
                }
            }
            else
            {
                msg.roads.push_back(from_json_Apollov2xRoad(obj["roads"]));
            }
        }
        return msg;
    }
    template <>
    Apollov2xIntersection from_json<Apollov2xIntersection>(nlohmann::json obj){
        return from_json_Apollov2xIntersection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xIntersection &dt)
    {
        dt=from_json_Apollov2xIntersection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xIntersection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xIntersection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
