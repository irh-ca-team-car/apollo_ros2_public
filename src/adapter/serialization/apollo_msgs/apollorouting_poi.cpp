#include "adapter/serialization/apollo_msgs/apollorouting_poi.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingPOI &msg) {
        nlohmann::json obj;
        nlohmann::json arr_landmark;
        for (auto it = msg.landmark.begin(); it != msg.landmark.end(); ++it) {
            arr_landmark.push_back(to_json(*it));
        }
        obj["landmark"] = arr_landmark;
        return obj;
    }
    ApolloroutingPOI from_json_ApolloroutingPOI (nlohmann::json obj) {
        ApolloroutingPOI msg;
        if(obj.contains("landmark"))
        {
            if(obj["landmark"].is_array())
            {
                for (auto& element : obj["landmark"])
                {
                    msg.landmark.push_back(from_json_ApolloroutingLandmark(element));
                }
            }
            else
            {
                msg.landmark.push_back(from_json_ApolloroutingLandmark(obj["landmark"]));
            }
        }
        return msg;
    }
    template <>
    ApolloroutingPOI from_json<ApolloroutingPOI>(nlohmann::json obj){
        return from_json_ApolloroutingPOI(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingPOI &dt)
    {
        dt=from_json_ApolloroutingPOI(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingPOI & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingPOI & dt)
    {
        os << to_json(dt);
        return os;
    }
}
