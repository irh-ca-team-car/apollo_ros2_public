#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrajectoryPointFeature &msg) {
        nlohmann::json obj;
        obj["timestampsec"] = (msg.timestampsec);
        obj["trajectorypoint"] = to_json(msg.trajectorypoint);
        return obj;
    }
    ApolloplanningTrajectoryPointFeature from_json_ApolloplanningTrajectoryPointFeature (nlohmann::json obj) {
        ApolloplanningTrajectoryPointFeature msg;
        if(obj.contains("timestampsec"))
        {
            msg.timestampsec = (obj["timestampsec"].is_string()?atof(obj["timestampsec"].get<std::string>().c_str()):obj["timestampsec"].get<double>());
        }
        if(obj.contains("trajectorypoint"))
        {
            msg.trajectorypoint = from_json_ApolloplanningCommonTrajectoryPointFeature(obj["trajectorypoint"]);
        }
        return msg;
    }
    template <>
    ApolloplanningTrajectoryPointFeature from_json<ApolloplanningTrajectoryPointFeature>(nlohmann::json obj){
        return from_json_ApolloplanningTrajectoryPointFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrajectoryPointFeature &dt)
    {
        dt=from_json_ApolloplanningTrajectoryPointFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrajectoryPointFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrajectoryPointFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
