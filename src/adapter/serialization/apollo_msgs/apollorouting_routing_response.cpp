#include "adapter/serialization/apollo_msgs/apollorouting_routing_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoutingResponse &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_road;
        for (auto it = msg.road.begin(); it != msg.road.end(); ++it) {
            arr_road.push_back(to_json(*it));
        }
        obj["road"] = arr_road;
        obj["measurement"] = to_json(msg.measurement);
        obj["routingrequest"] = to_json(msg.routingrequest);
        obj["mapversion"] = (msg.mapversion);
        obj["status"] = to_json(msg.status);
        return obj;
    }
    ApolloroutingRoutingResponse from_json_ApolloroutingRoutingResponse (nlohmann::json obj) {
        ApolloroutingRoutingResponse msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("road"))
        {
            if(obj["road"].is_array())
            {
                for (auto& element : obj["road"])
                {
                    msg.road.push_back(from_json_ApolloroutingRoadSegment(element));
                }
            }
            else
            {
                msg.road.push_back(from_json_ApolloroutingRoadSegment(obj["road"]));
            }
        }
        if(obj.contains("measurement"))
        {
            msg.measurement = from_json_ApolloroutingMeasurement(obj["measurement"]);
        }
        if(obj.contains("routingrequest"))
        {
            msg.routingrequest = from_json_ApolloroutingRoutingRequest(obj["routingrequest"]);
        }
        if(obj.contains("mapversion"))
        {
            msg.mapversion = (obj["mapversion"].is_string()?(obj["mapversion"].get<std::string>().c_str()):obj["mapversion"].get<std::string>());
        }
        if(obj.contains("status"))
        {
            msg.status = from_json_ApollocommonStatusPb(obj["status"]);
        }
        return msg;
    }
    template <>
    ApolloroutingRoutingResponse from_json<ApolloroutingRoutingResponse>(nlohmann::json obj){
        return from_json_ApolloroutingRoutingResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoutingResponse &dt)
    {
        dt=from_json_ApolloroutingRoutingResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoutingResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoutingResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
