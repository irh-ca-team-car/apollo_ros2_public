#include "adapter/serialization/apollo_msgs/apolloplanning_rerouting_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReroutingConfig &msg) {
        nlohmann::json obj;
        obj["cooldowntime"] = (msg.cooldowntime);
        obj["preparereroutingtime"] = (msg.preparereroutingtime);
        return obj;
    }
    ApolloplanningReroutingConfig from_json_ApolloplanningReroutingConfig (nlohmann::json obj) {
        ApolloplanningReroutingConfig msg;
        if(obj.contains("cooldowntime"))
        {
            msg.cooldowntime = (obj["cooldowntime"].is_string()?atof(obj["cooldowntime"].get<std::string>().c_str()):obj["cooldowntime"].get<double>());
        }
        if(obj.contains("preparereroutingtime"))
        {
            msg.preparereroutingtime = (obj["preparereroutingtime"].is_string()?atof(obj["preparereroutingtime"].get<std::string>().c_str()):obj["preparereroutingtime"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningReroutingConfig from_json<ApolloplanningReroutingConfig>(nlohmann::json obj){
        return from_json_ApolloplanningReroutingConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReroutingConfig &dt)
    {
        dt=from_json_ApolloplanningReroutingConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReroutingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReroutingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
