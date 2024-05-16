#include "adapter/serialization/apollo_msgs/apolloplanning_routing_response_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRoutingResponseFeature &msg) {
        nlohmann::json obj;
        nlohmann::json arr_road;
        for (auto it = msg.road.begin(); it != msg.road.end(); ++it) {
            arr_road.push_back(to_json(*it));
        }
        obj["road"] = arr_road;
        obj["measurement"] = to_json(msg.measurement);
        return obj;
    }
    ApolloplanningRoutingResponseFeature from_json_ApolloplanningRoutingResponseFeature (nlohmann::json obj) {
        ApolloplanningRoutingResponseFeature msg;
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
        return msg;
    }
    template <>
    ApolloplanningRoutingResponseFeature from_json<ApolloplanningRoutingResponseFeature>(nlohmann::json obj){
        return from_json_ApolloplanningRoutingResponseFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRoutingResponseFeature &dt)
    {
        dt=from_json_ApolloplanningRoutingResponseFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRoutingResponseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRoutingResponseFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
