#include "adapter/serialization/apollo_msgs/apollomonitor_system_statusother_components.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatusotherComponents &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollomonitorSystemStatusotherComponents from_json_ApollomonitorSystemStatusotherComponents (nlohmann::json obj) {
        ApollomonitorSystemStatusotherComponents msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?(obj["key"].get<std::string>().c_str()):obj["key"].get<std::string>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollomonitorComponentStatus(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollomonitorSystemStatusotherComponents from_json<ApollomonitorSystemStatusotherComponents>(nlohmann::json obj){
        return from_json_ApollomonitorSystemStatusotherComponents(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatusotherComponents &dt)
    {
        dt=from_json_ApollomonitorSystemStatusotherComponents(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatusotherComponents & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatusotherComponents & dt)
    {
        os << to_json(dt);
        return os;
    }
}
