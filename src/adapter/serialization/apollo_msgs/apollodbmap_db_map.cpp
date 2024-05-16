#include "adapter/serialization/apollo_msgs/apollodbmap_db_map.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBMap &msg) {
        nlohmann::json obj;
        nlohmann::json arr_paths;
        for (auto it = msg.paths.begin(); it != msg.paths.end(); ++it) {
            arr_paths.push_back(to_json(*it));
        }
        obj["paths"] = arr_paths;
        return obj;
    }
    ApollodbmapDBMap from_json_ApollodbmapDBMap (nlohmann::json obj) {
        ApollodbmapDBMap msg;
        if(obj.contains("paths"))
        {
            if(obj["paths"].is_array())
            {
                for (auto& element : obj["paths"])
                {
                    msg.paths.push_back(from_json_ApollodbmapDBPath(element));
                }
            }
            else
            {
                msg.paths.push_back(from_json_ApollodbmapDBPath(obj["paths"]));
            }
        }
        return msg;
    }
    template <>
    ApollodbmapDBMap from_json<ApollodbmapDBMap>(nlohmann::json obj){
        return from_json_ApollodbmapDBMap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBMap &dt)
    {
        dt=from_json_ApollodbmapDBMap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBMap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBMap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
