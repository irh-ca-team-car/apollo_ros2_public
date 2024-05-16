#include "adapter/serialization/apollo_msgs/apollomonitor_system_statushmi_modules.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatushmiModules &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollomonitorSystemStatushmiModules from_json_ApollomonitorSystemStatushmiModules (nlohmann::json obj) {
        ApollomonitorSystemStatushmiModules msg;
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
    ApollomonitorSystemStatushmiModules from_json<ApollomonitorSystemStatushmiModules>(nlohmann::json obj){
        return from_json_ApollomonitorSystemStatushmiModules(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatushmiModules &dt)
    {
        dt=from_json_ApollomonitorSystemStatushmiModules(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatushmiModules & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatushmiModules & dt)
    {
        os << to_json(dt);
        return os;
    }
}
