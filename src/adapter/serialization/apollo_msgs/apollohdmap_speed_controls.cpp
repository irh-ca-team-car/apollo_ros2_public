#include "adapter/serialization/apollo_msgs/apollohdmap_speed_controls.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapSpeedControls &msg) {
        nlohmann::json obj;
        nlohmann::json arr_speedcontrol;
        for (auto it = msg.speedcontrol.begin(); it != msg.speedcontrol.end(); ++it) {
            arr_speedcontrol.push_back(to_json(*it));
        }
        obj["speedcontrol"] = arr_speedcontrol;
        return obj;
    }
    ApollohdmapSpeedControls from_json_ApollohdmapSpeedControls (nlohmann::json obj) {
        ApollohdmapSpeedControls msg;
        if(obj.contains("speedcontrol"))
        {
            if(obj["speedcontrol"].is_array())
            {
                for (auto& element : obj["speedcontrol"])
                {
                    msg.speedcontrol.push_back(from_json_ApollohdmapSpeedControl(element));
                }
            }
            else
            {
                msg.speedcontrol.push_back(from_json_ApollohdmapSpeedControl(obj["speedcontrol"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapSpeedControls from_json<ApollohdmapSpeedControls>(nlohmann::json obj){
        return from_json_ApollohdmapSpeedControls(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapSpeedControls &dt)
    {
        dt=from_json_ApollohdmapSpeedControls(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapSpeedControls & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapSpeedControls & dt)
    {
        os << to_json(dt);
        return os;
    }
}
