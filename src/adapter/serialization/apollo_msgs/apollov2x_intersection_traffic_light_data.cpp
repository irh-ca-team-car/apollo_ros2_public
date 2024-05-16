#include "adapter/serialization/apollo_msgs/apollov2x_intersection_traffic_light_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xIntersectionTrafficLightData &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_roadtrafficlight;
        for (auto it = msg.roadtrafficlight.begin(); it != msg.roadtrafficlight.end(); ++it) {
            arr_roadtrafficlight.push_back(to_json(*it));
        }
        obj["roadtrafficlight"] = arr_roadtrafficlight;
        obj["intersectionid"] = (msg.intersectionid);
        obj["confidence"] = (msg.confidence);
        return obj;
    }
    Apollov2xIntersectionTrafficLightData from_json_Apollov2xIntersectionTrafficLightData (nlohmann::json obj) {
        Apollov2xIntersectionTrafficLightData msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("roadtrafficlight"))
        {
            if(obj["roadtrafficlight"].is_array())
            {
                for (auto& element : obj["roadtrafficlight"])
                {
                    msg.roadtrafficlight.push_back(from_json_Apollov2xRoadTrafficLight(element));
                }
            }
            else
            {
                msg.roadtrafficlight.push_back(from_json_Apollov2xRoadTrafficLight(obj["roadtrafficlight"]));
            }
        }
        if(obj.contains("intersectionid"))
        {
            msg.intersectionid = (obj["intersectionid"].is_string()?atoi(obj["intersectionid"].get<std::string>().c_str()):obj["intersectionid"].get<int>());
        }
        if(obj.contains("confidence"))
        {
            msg.confidence = (obj["confidence"].is_string()?atof(obj["confidence"].get<std::string>().c_str()):obj["confidence"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xIntersectionTrafficLightData from_json<Apollov2xIntersectionTrafficLightData>(nlohmann::json obj){
        return from_json_Apollov2xIntersectionTrafficLightData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xIntersectionTrafficLightData &dt)
    {
        dt=from_json_Apollov2xIntersectionTrafficLightData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xIntersectionTrafficLightData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xIntersectionTrafficLightData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
