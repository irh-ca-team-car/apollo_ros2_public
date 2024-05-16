#include "adapter/serialization/apollo_msgs/apolloplanning_common_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCommonTrajectoryPointFeature &msg) {
        nlohmann::json obj;
        obj["pathpoint"] = to_json(msg.pathpoint);
        obj["v"] = (msg.v);
        obj["a"] = (msg.a);
        obj["relativetime"] = (msg.relativetime);
        obj["gaussianinfo"] = to_json(msg.gaussianinfo);
        return obj;
    }
    ApolloplanningCommonTrajectoryPointFeature from_json_ApolloplanningCommonTrajectoryPointFeature (nlohmann::json obj) {
        ApolloplanningCommonTrajectoryPointFeature msg;
        if(obj.contains("pathpoint"))
        {
            msg.pathpoint = from_json_ApolloplanningCommonPathPointFeature(obj["pathpoint"]);
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
        if(obj.contains("gaussianinfo"))
        {
            msg.gaussianinfo = from_json_ApollocommonGaussianInfo(obj["gaussianinfo"]);
        }
        return msg;
    }
    template <>
    ApolloplanningCommonTrajectoryPointFeature from_json<ApolloplanningCommonTrajectoryPointFeature>(nlohmann::json obj){
        return from_json_ApolloplanningCommonTrajectoryPointFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCommonTrajectoryPointFeature &dt)
    {
        dt=from_json_ApolloplanningCommonTrajectoryPointFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCommonTrajectoryPointFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCommonTrajectoryPointFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
