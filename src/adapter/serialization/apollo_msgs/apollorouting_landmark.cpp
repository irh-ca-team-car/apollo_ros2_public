#include "adapter/serialization/apollo_msgs/apollorouting_landmark.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingLandmark &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_waypoint;
        for (auto it = msg.waypoint.begin(); it != msg.waypoint.end(); ++it) {
            arr_waypoint.push_back(to_json(*it));
        }
        obj["waypoint"] = arr_waypoint;
        obj["parkingspaceid"] = (msg.parkingspaceid);
        obj["parkinginfo"] = to_json(msg.parkinginfo);
        return obj;
    }
    ApolloroutingLandmark from_json_ApolloroutingLandmark (nlohmann::json obj) {
        ApolloroutingLandmark msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("waypoint"))
        {
            if(obj["waypoint"].is_array())
            {
                for (auto& element : obj["waypoint"])
                {
                    msg.waypoint.push_back(from_json_ApolloroutingLaneWaypoint(element));
                }
            }
            else
            {
                msg.waypoint.push_back(from_json_ApolloroutingLaneWaypoint(obj["waypoint"]));
            }
        }
        if(obj.contains("parkingspaceid"))
        {
            msg.parkingspaceid = (obj["parkingspaceid"].is_string()?(obj["parkingspaceid"].get<std::string>().c_str()):obj["parkingspaceid"].get<std::string>());
        }
        if(obj.contains("parkinginfo"))
        {
            msg.parkinginfo = from_json_ApolloroutingParkingInfo(obj["parkinginfo"]);
        }
        return msg;
    }
    template <>
    ApolloroutingLandmark from_json<ApolloroutingLandmark>(nlohmann::json obj){
        return from_json_ApolloroutingLandmark(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingLandmark &dt)
    {
        dt=from_json_ApolloroutingLandmark(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingLandmark & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingLandmark & dt)
    {
        os << to_json(dt);
        return os;
    }
}
