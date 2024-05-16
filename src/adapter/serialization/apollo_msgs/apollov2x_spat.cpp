#include "adapter/serialization/apollo_msgs/apollov2x_spat.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xSpat &msg) {
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
    Apollov2xSpat from_json_Apollov2xSpat (nlohmann::json obj) {
        Apollov2xSpat msg;
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
                    msg.intersections.push_back(from_json_Apollov2xIntersectionState(element));
                }
            }
            else
            {
                msg.intersections.push_back(from_json_Apollov2xIntersectionState(obj["intersections"]));
            }
        }
        return msg;
    }
    template <>
    Apollov2xSpat from_json<Apollov2xSpat>(nlohmann::json obj){
        return from_json_Apollov2xSpat(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xSpat &dt)
    {
        dt=from_json_Apollov2xSpat(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xSpat & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xSpat & dt)
    {
        os << to_json(dt);
        return os;
    }
}
