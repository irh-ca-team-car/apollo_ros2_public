#include "adapter/serialization/apollo_msgs/apollov2x_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xLane &msg) {
        nlohmann::json obj;
        obj["laneid"] = (msg.laneid);
        nlohmann::json arr_positionoffset;
        for (auto it = msg.positionoffset.begin(); it != msg.positionoffset.end(); ++it) {
            arr_positionoffset.push_back(to_json(*it));
        }
        obj["positionoffset"] = arr_positionoffset;
        nlohmann::json arr_connections;
        for (auto it = msg.connections.begin(); it != msg.connections.end(); ++it) {
            arr_connections.push_back(to_json(*it));
        }
        obj["connections"] = arr_connections;
        return obj;
    }
    Apollov2xLane from_json_Apollov2xLane (nlohmann::json obj) {
        Apollov2xLane msg;
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?atoi(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<int>());
        }
        if(obj.contains("positionoffset"))
        {
            if(obj["positionoffset"].is_array())
            {
                for (auto& element : obj["positionoffset"])
                {
                    msg.positionoffset.push_back(from_json_Apollov2xPosition2D(element));
                }
            }
            else
            {
                msg.positionoffset.push_back(from_json_Apollov2xPosition2D(obj["positionoffset"]));
            }
        }
        if(obj.contains("connections"))
        {
            if(obj["connections"].is_array())
            {
                for (auto& element : obj["connections"])
                {
                    msg.connections.push_back(from_json_Apollov2xConnection(element));
                }
            }
            else
            {
                msg.connections.push_back(from_json_Apollov2xConnection(obj["connections"]));
            }
        }
        return msg;
    }
    template <>
    Apollov2xLane from_json<Apollov2xLane>(nlohmann::json obj){
        return from_json_Apollov2xLane(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xLane &dt)
    {
        dt=from_json_Apollov2xLane(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xLane & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xLane & dt)
    {
        os << to_json(dt);
        return os;
    }
}
