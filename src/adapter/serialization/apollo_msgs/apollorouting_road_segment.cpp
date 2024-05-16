#include "adapter/serialization/apollo_msgs/apollorouting_road_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoadSegment &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        nlohmann::json arr_passage;
        for (auto it = msg.passage.begin(); it != msg.passage.end(); ++it) {
            arr_passage.push_back(to_json(*it));
        }
        obj["passage"] = arr_passage;
        return obj;
    }
    ApolloroutingRoadSegment from_json_ApolloroutingRoadSegment (nlohmann::json obj) {
        ApolloroutingRoadSegment msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("passage"))
        {
            if(obj["passage"].is_array())
            {
                for (auto& element : obj["passage"])
                {
                    msg.passage.push_back(from_json_ApolloroutingPassage(element));
                }
            }
            else
            {
                msg.passage.push_back(from_json_ApolloroutingPassage(obj["passage"]));
            }
        }
        return msg;
    }
    template <>
    ApolloroutingRoadSegment from_json<ApolloroutingRoadSegment>(nlohmann::json obj){
        return from_json_ApolloroutingRoadSegment(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoadSegment &dt)
    {
        dt=from_json_ApolloroutingRoadSegment(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoadSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoadSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
}
