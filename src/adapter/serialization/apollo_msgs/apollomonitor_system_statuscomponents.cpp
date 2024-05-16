#include "adapter/serialization/apollo_msgs/apollomonitor_system_statuscomponents.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatuscomponents &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollomonitorSystemStatuscomponents from_json_ApollomonitorSystemStatuscomponents (nlohmann::json obj) {
        ApollomonitorSystemStatuscomponents msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?(obj["key"].get<std::string>().c_str()):obj["key"].get<std::string>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollomonitorComponent(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollomonitorSystemStatuscomponents from_json<ApollomonitorSystemStatuscomponents>(nlohmann::json obj){
        return from_json_ApollomonitorSystemStatuscomponents(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatuscomponents &dt)
    {
        dt=from_json_ApollomonitorSystemStatuscomponents(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatuscomponents & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatuscomponents & dt)
    {
        os << to_json(dt);
        return os;
    }
}
