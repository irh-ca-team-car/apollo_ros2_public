#include "adapter/serialization/apollo_msgs/apollocommon_frenet_frame_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonFrenetFramePoint &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["l"] = (msg.l);
        obj["dl"] = (msg.dl);
        obj["ddl"] = (msg.ddl);
        return obj;
    }
    ApollocommonFrenetFramePoint from_json_ApollocommonFrenetFramePoint (nlohmann::json obj) {
        ApollocommonFrenetFramePoint msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("l"))
        {
            msg.l = (obj["l"].is_string()?atof(obj["l"].get<std::string>().c_str()):obj["l"].get<double>());
        }
        if(obj.contains("dl"))
        {
            msg.dl = (obj["dl"].is_string()?atof(obj["dl"].get<std::string>().c_str()):obj["dl"].get<double>());
        }
        if(obj.contains("ddl"))
        {
            msg.ddl = (obj["ddl"].is_string()?atof(obj["ddl"].get<std::string>().c_str()):obj["ddl"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonFrenetFramePoint from_json<ApollocommonFrenetFramePoint>(nlohmann::json obj){
        return from_json_ApollocommonFrenetFramePoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonFrenetFramePoint &dt)
    {
        dt=from_json_ApollocommonFrenetFramePoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonFrenetFramePoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonFrenetFramePoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
