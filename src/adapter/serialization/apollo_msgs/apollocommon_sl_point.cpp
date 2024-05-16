#include "adapter/serialization/apollo_msgs/apollocommon_sl_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonSLPoint &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["l"] = (msg.l);
        return obj;
    }
    ApollocommonSLPoint from_json_ApollocommonSLPoint (nlohmann::json obj) {
        ApollocommonSLPoint msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("l"))
        {
            msg.l = (obj["l"].is_string()?atof(obj["l"].get<std::string>().c_str()):obj["l"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonSLPoint from_json<ApollocommonSLPoint>(nlohmann::json obj){
        return from_json_ApollocommonSLPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonSLPoint &dt)
    {
        dt=from_json_ApollocommonSLPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonSLPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonSLPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
