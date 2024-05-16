#include "adapter/serialization/apollo_msgs/apollocommon_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPath &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_pathpoint;
        for (auto it = msg.pathpoint.begin(); it != msg.pathpoint.end(); ++it) {
            arr_pathpoint.push_back(to_json(*it));
        }
        obj["pathpoint"] = arr_pathpoint;
        return obj;
    }
    ApollocommonPath from_json_ApollocommonPath (nlohmann::json obj) {
        ApollocommonPath msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("pathpoint"))
        {
            if(obj["pathpoint"].is_array())
            {
                for (auto& element : obj["pathpoint"])
                {
                    msg.pathpoint.push_back(from_json_ApollocommonPathPoint(element));
                }
            }
            else
            {
                msg.pathpoint.push_back(from_json_ApollocommonPathPoint(obj["pathpoint"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonPath from_json<ApollocommonPath>(nlohmann::json obj){
        return from_json_ApollocommonPath(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPath &dt)
    {
        dt=from_json_ApollocommonPath(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonPath & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPath & dt)
    {
        os << to_json(dt);
        return os;
    }
}
