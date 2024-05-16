#include "adapter/serialization/apollo_msgs/channels.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Channels &msg) {
        nlohmann::json obj;
        nlohmann::json arr_channel;
        for (auto it = msg.channel.begin(); it != msg.channel.end(); ++it) {
            arr_channel.push_back(to_json(*it));
        }
        obj["channel"] = arr_channel;
        return obj;
    }
    Channels from_json_Channels (nlohmann::json obj) {
        Channels msg;
        if(obj.contains("channel"))
        {
            if(obj["channel"].is_array())
            {
                for (auto& element : obj["channel"])
                {
                    msg.channel.push_back(from_json_ChannelConfig(element));
                }
            }
            else
            {
                msg.channel.push_back(from_json_ChannelConfig(obj["channel"]));
            }
        }
        return msg;
    }
    template <>
    Channels from_json<Channels>(nlohmann::json obj){
        return from_json_Channels(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Channels &dt)
    {
        dt=from_json_Channels(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Channels & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Channels & dt)
    {
        os << to_json(dt);
        return os;
    }
}
