#include "adapter/serialization/apollo_msgs/apollocommon_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPolygon &msg) {
        nlohmann::json obj;
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        return obj;
    }
    ApollocommonPolygon from_json_ApollocommonPolygon (nlohmann::json obj) {
        ApollocommonPolygon msg;
        if(obj.contains("point"))
        {
            if(obj["point"].is_array())
            {
                for (auto& element : obj["point"])
                {
                    msg.point.push_back(from_json_ApollocommonPoint3D(element));
                }
            }
            else
            {
                msg.point.push_back(from_json_ApollocommonPoint3D(obj["point"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonPolygon from_json<ApollocommonPolygon>(nlohmann::json obj){
        return from_json_ApollocommonPolygon(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPolygon &dt)
    {
        dt=from_json_ApollocommonPolygon(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonPolygon & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPolygon & dt)
    {
        os << to_json(dt);
        return os;
    }
}
