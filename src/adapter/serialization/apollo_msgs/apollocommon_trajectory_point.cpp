#include "adapter/serialization/apollo_msgs/apollocommon_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonTrajectoryPoint &msg) {
        nlohmann::json obj;
        obj["pathpoint"] = to_json(msg.pathpoint);
        obj["v"] = (msg.v);
        obj["a"] = (msg.a);
        obj["relativetime"] = (msg.relativetime);
        obj["da"] = (msg.da);
        obj["steer"] = (msg.steer);
        obj["gaussianinfo"] = to_json(msg.gaussianinfo);
        return obj;
    }
    ApollocommonTrajectoryPoint from_json_ApollocommonTrajectoryPoint (nlohmann::json obj) {
        ApollocommonTrajectoryPoint msg;
        if(obj.contains("pathpoint"))
        {
            msg.pathpoint = from_json_ApollocommonPathPoint(obj["pathpoint"]);
        }
        if(obj.contains("v"))
        {
            msg.v = (obj["v"].is_string()?atof(obj["v"].get<std::string>().c_str()):obj["v"].get<double>());
        }
        if(obj.contains("a"))
        {
            msg.a = (obj["a"].is_string()?atof(obj["a"].get<std::string>().c_str()):obj["a"].get<double>());
        }
        if(obj.contains("relativetime"))
        {
            msg.relativetime = (obj["relativetime"].is_string()?atof(obj["relativetime"].get<std::string>().c_str()):obj["relativetime"].get<double>());
        }
        if(obj.contains("da"))
        {
            msg.da = (obj["da"].is_string()?atof(obj["da"].get<std::string>().c_str()):obj["da"].get<double>());
        }
        if(obj.contains("steer"))
        {
            msg.steer = (obj["steer"].is_string()?atof(obj["steer"].get<std::string>().c_str()):obj["steer"].get<double>());
        }
        if(obj.contains("gaussianinfo"))
        {
            msg.gaussianinfo = from_json_ApollocommonGaussianInfo(obj["gaussianinfo"]);
        }
        return msg;
    }
    template <>
    ApollocommonTrajectoryPoint from_json<ApollocommonTrajectoryPoint>(nlohmann::json obj){
        return from_json_ApollocommonTrajectoryPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonTrajectoryPoint &dt)
    {
        dt=from_json_ApollocommonTrajectoryPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonTrajectoryPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonTrajectoryPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
