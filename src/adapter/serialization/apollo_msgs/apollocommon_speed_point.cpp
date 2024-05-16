#include "adapter/serialization/apollo_msgs/apollocommon_speed_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonSpeedPoint &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["t"] = (msg.t);
        obj["v"] = (msg.v);
        obj["a"] = (msg.a);
        obj["da"] = (msg.da);
        return obj;
    }
    ApollocommonSpeedPoint from_json_ApollocommonSpeedPoint (nlohmann::json obj) {
        ApollocommonSpeedPoint msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("t"))
        {
            msg.t = (obj["t"].is_string()?atof(obj["t"].get<std::string>().c_str()):obj["t"].get<double>());
        }
        if(obj.contains("v"))
        {
            msg.v = (obj["v"].is_string()?atof(obj["v"].get<std::string>().c_str()):obj["v"].get<double>());
        }
        if(obj.contains("a"))
        {
            msg.a = (obj["a"].is_string()?atof(obj["a"].get<std::string>().c_str()):obj["a"].get<double>());
        }
        if(obj.contains("da"))
        {
            msg.da = (obj["da"].is_string()?atof(obj["da"].get<std::string>().c_str()):obj["da"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonSpeedPoint from_json<ApollocommonSpeedPoint>(nlohmann::json obj){
        return from_json_ApollocommonSpeedPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonSpeedPoint &dt)
    {
        dt=from_json_ApollocommonSpeedPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonSpeedPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonSpeedPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
