#include "adapter/serialization/apollo_msgs/apollorouting_default_routings.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingDefaultRoutings &msg) {
        nlohmann::json obj;
        nlohmann::json arr_defaultrouting;
        for (auto it = msg.defaultrouting.begin(); it != msg.defaultrouting.end(); ++it) {
            arr_defaultrouting.push_back(to_json(*it));
        }
        obj["defaultrouting"] = arr_defaultrouting;
        return obj;
    }
    ApolloroutingDefaultRoutings from_json_ApolloroutingDefaultRoutings (nlohmann::json obj) {
        ApolloroutingDefaultRoutings msg;
        if(obj.contains("defaultrouting"))
        {
            if(obj["defaultrouting"].is_array())
            {
                for (auto& element : obj["defaultrouting"])
                {
                    msg.defaultrouting.push_back(from_json_ApolloroutingDefaultRouting(element));
                }
            }
            else
            {
                msg.defaultrouting.push_back(from_json_ApolloroutingDefaultRouting(obj["defaultrouting"]));
            }
        }
        return msg;
    }
    template <>
    ApolloroutingDefaultRoutings from_json<ApolloroutingDefaultRoutings>(nlohmann::json obj){
        return from_json_ApolloroutingDefaultRoutings(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingDefaultRoutings &dt)
    {
        dt=from_json_ApolloroutingDefaultRoutings(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingDefaultRoutings & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingDefaultRoutings & dt)
    {
        os << to_json(dt);
        return os;
    }
}
