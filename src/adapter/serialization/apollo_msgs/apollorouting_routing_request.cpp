#include "adapter/serialization/apollo_msgs/apollorouting_routing_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoutingRequest &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_waypoint;
        for (auto it = msg.waypoint.begin(); it != msg.waypoint.end(); ++it) {
            arr_waypoint.push_back(to_json(*it));
        }
        obj["waypoint"] = arr_waypoint;
        nlohmann::json arr_blacklistedlane;
        for (auto it = msg.blacklistedlane.begin(); it != msg.blacklistedlane.end(); ++it) {
            arr_blacklistedlane.push_back(to_json(*it));
        }
        obj["blacklistedlane"] = arr_blacklistedlane;
        nlohmann::json arr_blacklistedroad;
        for (auto it = msg.blacklistedroad.begin(); it != msg.blacklistedroad.end(); ++it) {
            arr_blacklistedroad.push_back((*it));
        }
        obj["blacklistedroad"] = arr_blacklistedroad;
        obj["broadcast"] = (msg.broadcast);
        obj["parkingspace"] = to_json(msg.parkingspace);
        obj["parkinginfo"] = to_json(msg.parkinginfo);
        return obj;
    }
    ApolloroutingRoutingRequest from_json_ApolloroutingRoutingRequest (nlohmann::json obj) {
        ApolloroutingRoutingRequest msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
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
        if(obj.contains("blacklistedlane"))
        {
            if(obj["blacklistedlane"].is_array())
            {
                for (auto& element : obj["blacklistedlane"])
                {
                    msg.blacklistedlane.push_back(from_json_ApolloroutingLaneSegment(element));
                }
            }
            else
            {
                msg.blacklistedlane.push_back(from_json_ApolloroutingLaneSegment(obj["blacklistedlane"]));
            }
        }
        if(obj.contains("blacklistedroad"))
        {
            if(obj["blacklistedroad"].is_array())
            {
                for (auto& element : obj["blacklistedroad"])
                {
                    msg.blacklistedroad.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.blacklistedroad.push_back((obj["blacklistedroad"].is_string()?(obj["blacklistedroad"].get<std::string>().c_str()):obj["blacklistedroad"].get<std::string>()));
            }
        }
        if(obj.contains("broadcast"))
        {
            msg.broadcast = (obj["broadcast"].is_string()?(bool)atoi(obj["broadcast"].get<std::string>().c_str()):obj["broadcast"].get<bool>());
        }
        if(obj.contains("parkingspace"))
        {
            msg.parkingspace = from_json_ApollohdmapParkingSpace(obj["parkingspace"]);
        }
        if(obj.contains("parkinginfo"))
        {
            msg.parkinginfo = from_json_ApolloroutingParkingInfo(obj["parkinginfo"]);
        }
        return msg;
    }
    template <>
    ApolloroutingRoutingRequest from_json<ApolloroutingRoutingRequest>(nlohmann::json obj){
        return from_json_ApolloroutingRoutingRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoutingRequest &dt)
    {
        dt=from_json_ApolloroutingRoutingRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoutingRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoutingRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
