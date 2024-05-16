#include "adapter/serialization/apollo_msgs/apollov2x_map.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xMap &msg) {
        nlohmann::json obj;
        obj["timestamp"] = (msg.timestamp);
        obj["msgcnt"] = (msg.msgcnt);
        nlohmann::json arr_intersections;
        for (auto it = msg.intersections.begin(); it != msg.intersections.end(); ++it) {
            arr_intersections.push_back(to_json(*it));
        }
        obj["intersections"] = arr_intersections;
        return obj;
    }
    Apollov2xMap from_json_Apollov2xMap (nlohmann::json obj) {
        Apollov2xMap msg;
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("msgcnt"))
        {
            msg.msgcnt = (obj["msgcnt"].is_string()?atoi(obj["msgcnt"].get<std::string>().c_str()):obj["msgcnt"].get<int>());
        }
        if(obj.contains("intersections"))
        {
            if(obj["intersections"].is_array())
            {
                for (auto& element : obj["intersections"])
                {
                    msg.intersections.push_back(from_json_Apollov2xIntersection(element));
                }
            }
            else
            {
                msg.intersections.push_back(from_json_Apollov2xIntersection(obj["intersections"]));
            }
        }
        return msg;
    }
    template <>
    Apollov2xMap from_json<Apollov2xMap>(nlohmann::json obj){
        return from_json_Apollov2xMap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xMap &dt)
    {
        dt=from_json_Apollov2xMap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xMap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xMap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
