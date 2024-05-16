#include "adapter/serialization/apollo_msgs/apollohdmap_line_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLineSegment &msg) {
        nlohmann::json obj;
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        return obj;
    }
    ApollohdmapLineSegment from_json_ApollohdmapLineSegment (nlohmann::json obj) {
        ApollohdmapLineSegment msg;
        if(obj.contains("point"))
        {
            if(obj["point"].is_array())
            {
                for (auto& element : obj["point"])
                {
                    msg.point.push_back(from_json_ApollocommonPointENU(element));
                }
            }
            else
            {
                msg.point.push_back(from_json_ApollocommonPointENU(obj["point"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapLineSegment from_json<ApollohdmapLineSegment>(nlohmann::json obj){
        return from_json_ApollohdmapLineSegment(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLineSegment &dt)
    {
        dt=from_json_ApollohdmapLineSegment(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLineSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLineSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
}
