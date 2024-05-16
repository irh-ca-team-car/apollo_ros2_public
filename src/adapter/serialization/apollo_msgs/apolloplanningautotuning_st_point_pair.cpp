#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_st_point_pair.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningSTPointPair &msg) {
        nlohmann::json obj;
        obj["slower"] = (msg.slower);
        obj["supper"] = (msg.supper);
        obj["t"] = (msg.t);
        obj["l"] = (msg.l);
        return obj;
    }
    ApolloplanningautotuningSTPointPair from_json_ApolloplanningautotuningSTPointPair (nlohmann::json obj) {
        ApolloplanningautotuningSTPointPair msg;
        if(obj.contains("slower"))
        {
            msg.slower = (obj["slower"].is_string()?atof(obj["slower"].get<std::string>().c_str()):obj["slower"].get<double>());
        }
        if(obj.contains("supper"))
        {
            msg.supper = (obj["supper"].is_string()?atof(obj["supper"].get<std::string>().c_str()):obj["supper"].get<double>());
        }
        if(obj.contains("t"))
        {
            msg.t = (obj["t"].is_string()?atof(obj["t"].get<std::string>().c_str()):obj["t"].get<double>());
        }
        if(obj.contains("l"))
        {
            msg.l = (obj["l"].is_string()?atof(obj["l"].get<std::string>().c_str()):obj["l"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningSTPointPair from_json<ApolloplanningautotuningSTPointPair>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningSTPointPair(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningSTPointPair &dt)
    {
        dt=from_json_ApolloplanningautotuningSTPointPair(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningSTPointPair & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningSTPointPair & dt)
    {
        os << to_json(dt);
        return os;
    }
}
