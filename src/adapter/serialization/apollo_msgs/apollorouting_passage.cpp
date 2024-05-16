#include "adapter/serialization/apollo_msgs/apollorouting_passage.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingPassage &msg) {
        nlohmann::json obj;
        nlohmann::json arr_segment;
        for (auto it = msg.segment.begin(); it != msg.segment.end(); ++it) {
            arr_segment.push_back(to_json(*it));
        }
        obj["segment"] = arr_segment;
        obj["canexit"] = (msg.canexit);
        obj["changelanetype"] = (msg.changelanetype);
        return obj;
    }
    ApolloroutingPassage from_json_ApolloroutingPassage (nlohmann::json obj) {
        ApolloroutingPassage msg;
        if(obj.contains("segment"))
        {
            if(obj["segment"].is_array())
            {
                for (auto& element : obj["segment"])
                {
                    msg.segment.push_back(from_json_ApolloroutingLaneSegment(element));
                }
            }
            else
            {
                msg.segment.push_back(from_json_ApolloroutingLaneSegment(obj["segment"]));
            }
        }
        if(obj.contains("canexit"))
        {
            msg.canexit = (obj["canexit"].is_string()?(bool)atoi(obj["canexit"].get<std::string>().c_str()):obj["canexit"].get<bool>());
        }
        if(obj.contains("changelanetype"))
        {
            msg.changelanetype = (obj["changelanetype"].is_string()?atoi(obj["changelanetype"].get<std::string>().c_str()):obj["changelanetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloroutingPassage from_json<ApolloroutingPassage>(nlohmann::json obj){
        return from_json_ApolloroutingPassage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingPassage &dt)
    {
        dt=from_json_ApolloroutingPassage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingPassage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingPassage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
