#include "adapter/serialization/apollo_msgs/apollodbmap_db_line.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBLine &msg) {
        nlohmann::json obj;
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        return obj;
    }
    ApollodbmapDBLine from_json_ApollodbmapDBLine (nlohmann::json obj) {
        ApollodbmapDBLine msg;
        if(obj.contains("point"))
        {
            if(obj["point"].is_array())
            {
                for (auto& element : obj["point"])
                {
                    msg.point.push_back(from_json_ApollodbmapDBPoint(element));
                }
            }
            else
            {
                msg.point.push_back(from_json_ApollodbmapDBPoint(obj["point"]));
            }
        }
        return msg;
    }
    template <>
    ApollodbmapDBLine from_json<ApollodbmapDBLine>(nlohmann::json obj){
        return from_json_ApollodbmapDBLine(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBLine &dt)
    {
        dt=from_json_ApollodbmapDBLine(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBLine & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBLine & dt)
    {
        os << to_json(dt);
        return os;
    }
}
