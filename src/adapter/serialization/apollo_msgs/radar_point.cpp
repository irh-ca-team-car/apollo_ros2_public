#include "adapter/serialization/apollo_msgs/radar_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const RadarPoint &msg) {
        nlohmann::json obj;
        obj["position"] = to_json(msg.position);
        obj["direction"] = to_json(msg.direction);
        obj["type"] = (msg.type);
        return obj;
    }
    RadarPoint from_json_RadarPoint (nlohmann::json obj) {
        RadarPoint msg;
        if(obj.contains("position"))
        {
            msg.position = from_json_Vector3(obj["position"]);
        }
        if(obj.contains("direction"))
        {
            msg.direction = from_json_Vector3(obj["direction"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    RadarPoint from_json<RadarPoint>(nlohmann::json obj){
        return from_json_RadarPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, RadarPoint &dt)
    {
        dt=from_json_RadarPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const RadarPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const RadarPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
