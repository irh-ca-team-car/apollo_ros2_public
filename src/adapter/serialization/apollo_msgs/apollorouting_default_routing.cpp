#include "adapter/serialization/apollo_msgs/apollorouting_default_routing.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingDefaultRouting &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        return obj;
    }
    ApolloroutingDefaultRouting from_json_ApolloroutingDefaultRouting (nlohmann::json obj) {
        ApolloroutingDefaultRouting msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
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
    ApolloroutingDefaultRouting from_json<ApolloroutingDefaultRouting>(nlohmann::json obj){
        return from_json_ApolloroutingDefaultRouting(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingDefaultRouting &dt)
    {
        dt=from_json_ApolloroutingDefaultRouting(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingDefaultRouting & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingDefaultRouting & dt)
    {
        os << to_json(dt);
        return os;
    }
}
