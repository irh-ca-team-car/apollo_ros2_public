#include "adapter/serialization/apollo_msgs/apollorouting_lane_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingLaneSegment &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["starts"] = (msg.starts);
        obj["ends"] = (msg.ends);
        return obj;
    }
    ApolloroutingLaneSegment from_json_ApolloroutingLaneSegment (nlohmann::json obj) {
        ApolloroutingLaneSegment msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("starts"))
        {
            msg.starts = (obj["starts"].is_string()?atof(obj["starts"].get<std::string>().c_str()):obj["starts"].get<double>());
        }
        if(obj.contains("ends"))
        {
            msg.ends = (obj["ends"].is_string()?atof(obj["ends"].get<std::string>().c_str()):obj["ends"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloroutingLaneSegment from_json<ApolloroutingLaneSegment>(nlohmann::json obj){
        return from_json_ApolloroutingLaneSegment(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingLaneSegment &dt)
    {
        dt=from_json_ApolloroutingLaneSegment(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingLaneSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingLaneSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
}
