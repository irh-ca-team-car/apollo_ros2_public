#include "adapter/serialization/apollo_msgs/apollorouting_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingTopicConfig &msg) {
        nlohmann::json obj;
        obj["routingresponsetopic"] = (msg.routingresponsetopic);
        obj["routingresponsehistorytopic"] = (msg.routingresponsehistorytopic);
        return obj;
    }
    ApolloroutingTopicConfig from_json_ApolloroutingTopicConfig (nlohmann::json obj) {
        ApolloroutingTopicConfig msg;
        if(obj.contains("routingresponsetopic"))
        {
            msg.routingresponsetopic = (obj["routingresponsetopic"].is_string()?(obj["routingresponsetopic"].get<std::string>().c_str()):obj["routingresponsetopic"].get<std::string>());
        }
        if(obj.contains("routingresponsehistorytopic"))
        {
            msg.routingresponsehistorytopic = (obj["routingresponsehistorytopic"].is_string()?(obj["routingresponsehistorytopic"].get<std::string>().c_str()):obj["routingresponsehistorytopic"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloroutingTopicConfig from_json<ApolloroutingTopicConfig>(nlohmann::json obj){
        return from_json_ApolloroutingTopicConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingTopicConfig &dt)
    {
        dt=from_json_ApolloroutingTopicConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
