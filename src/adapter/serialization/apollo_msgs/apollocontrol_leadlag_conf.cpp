#include "adapter/serialization/apollo_msgs/apollocontrol_leadlag_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLeadlagConf &msg) {
        nlohmann::json obj;
        obj["innerstatesaturationlevel"] = (msg.innerstatesaturationlevel);
        obj["alpha"] = (msg.alpha);
        obj["beta"] = (msg.beta);
        obj["tau"] = (msg.tau);
        return obj;
    }
    ApollocontrolLeadlagConf from_json_ApollocontrolLeadlagConf (nlohmann::json obj) {
        ApollocontrolLeadlagConf msg;
        if(obj.contains("innerstatesaturationlevel"))
        {
            msg.innerstatesaturationlevel = (obj["innerstatesaturationlevel"].is_string()?atof(obj["innerstatesaturationlevel"].get<std::string>().c_str()):obj["innerstatesaturationlevel"].get<double>());
        }
        if(obj.contains("alpha"))
        {
            msg.alpha = (obj["alpha"].is_string()?atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<double>());
        }
        if(obj.contains("beta"))
        {
            msg.beta = (obj["beta"].is_string()?atof(obj["beta"].get<std::string>().c_str()):obj["beta"].get<double>());
        }
        if(obj.contains("tau"))
        {
            msg.tau = (obj["tau"].is_string()?atof(obj["tau"].get<std::string>().c_str()):obj["tau"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolLeadlagConf from_json<ApollocontrolLeadlagConf>(nlohmann::json obj){
        return from_json_ApollocontrolLeadlagConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLeadlagConf &dt)
    {
        dt=from_json_ApollocontrolLeadlagConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLeadlagConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLeadlagConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
