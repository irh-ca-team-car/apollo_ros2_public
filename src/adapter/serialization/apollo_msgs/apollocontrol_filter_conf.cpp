#include "adapter/serialization/apollo_msgs/apollocontrol_filter_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolFilterConf &msg) {
        nlohmann::json obj;
        obj["cutofffreq"] = (msg.cutofffreq);
        return obj;
    }
    ApollocontrolFilterConf from_json_ApollocontrolFilterConf (nlohmann::json obj) {
        ApollocontrolFilterConf msg;
        if(obj.contains("cutofffreq"))
        {
            msg.cutofffreq = (obj["cutofffreq"].is_string()?atoi(obj["cutofffreq"].get<std::string>().c_str()):obj["cutofffreq"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocontrolFilterConf from_json<ApollocontrolFilterConf>(nlohmann::json obj){
        return from_json_ApollocontrolFilterConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolFilterConf &dt)
    {
        dt=from_json_ApollocontrolFilterConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolFilterConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolFilterConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
