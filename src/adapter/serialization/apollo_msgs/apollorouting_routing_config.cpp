#include "adapter/serialization/apollo_msgs/apollorouting_routing_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingRoutingConfig &msg) {
        nlohmann::json obj;
        obj["basespeed"] = (msg.basespeed);
        obj["leftturnpenalty"] = (msg.leftturnpenalty);
        obj["rightturnpenalty"] = (msg.rightturnpenalty);
        obj["uturnpenalty"] = (msg.uturnpenalty);
        obj["changepenalty"] = (msg.changepenalty);
        obj["basechanginglength"] = (msg.basechanginglength);
        obj["topicconfig"] = to_json(msg.topicconfig);
        return obj;
    }
    ApolloroutingRoutingConfig from_json_ApolloroutingRoutingConfig (nlohmann::json obj) {
        ApolloroutingRoutingConfig msg;
        if(obj.contains("basespeed"))
        {
            msg.basespeed = (obj["basespeed"].is_string()?atof(obj["basespeed"].get<std::string>().c_str()):obj["basespeed"].get<double>());
        }
        if(obj.contains("leftturnpenalty"))
        {
            msg.leftturnpenalty = (obj["leftturnpenalty"].is_string()?atof(obj["leftturnpenalty"].get<std::string>().c_str()):obj["leftturnpenalty"].get<double>());
        }
        if(obj.contains("rightturnpenalty"))
        {
            msg.rightturnpenalty = (obj["rightturnpenalty"].is_string()?atof(obj["rightturnpenalty"].get<std::string>().c_str()):obj["rightturnpenalty"].get<double>());
        }
        if(obj.contains("uturnpenalty"))
        {
            msg.uturnpenalty = (obj["uturnpenalty"].is_string()?atof(obj["uturnpenalty"].get<std::string>().c_str()):obj["uturnpenalty"].get<double>());
        }
        if(obj.contains("changepenalty"))
        {
            msg.changepenalty = (obj["changepenalty"].is_string()?atof(obj["changepenalty"].get<std::string>().c_str()):obj["changepenalty"].get<double>());
        }
        if(obj.contains("basechanginglength"))
        {
            msg.basechanginglength = (obj["basechanginglength"].is_string()?atof(obj["basechanginglength"].get<std::string>().c_str()):obj["basechanginglength"].get<double>());
        }
        if(obj.contains("topicconfig"))
        {
            msg.topicconfig = from_json_ApolloroutingTopicConfig(obj["topicconfig"]);
        }
        return msg;
    }
    template <>
    ApolloroutingRoutingConfig from_json<ApolloroutingRoutingConfig>(nlohmann::json obj){
        return from_json_ApolloroutingRoutingConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingRoutingConfig &dt)
    {
        dt=from_json_ApolloroutingRoutingConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingRoutingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingRoutingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
