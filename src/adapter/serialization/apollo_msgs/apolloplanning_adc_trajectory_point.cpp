#include "adapter/serialization/apollo_msgs/apolloplanning_adc_trajectory_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningADCTrajectoryPoint &msg) {
        nlohmann::json obj;
        obj["timestampsec"] = (msg.timestampsec);
        obj["planningtag"] = to_json(msg.planningtag);
        obj["trajectorypoint"] = to_json(msg.trajectorypoint);
        return obj;
    }
    ApolloplanningADCTrajectoryPoint from_json_ApolloplanningADCTrajectoryPoint (nlohmann::json obj) {
        ApolloplanningADCTrajectoryPoint msg;
        if(obj.contains("timestampsec"))
        {
            msg.timestampsec = (obj["timestampsec"].is_string()?atof(obj["timestampsec"].get<std::string>().c_str()):obj["timestampsec"].get<double>());
        }
        if(obj.contains("planningtag"))
        {
            msg.planningtag = from_json_ApolloplanningPlanningTag(obj["planningtag"]);
        }
        if(obj.contains("trajectorypoint"))
        {
            msg.trajectorypoint = from_json_ApolloplanningCommonTrajectoryPointFeature(obj["trajectorypoint"]);
        }
        return msg;
    }
    template <>
    ApolloplanningADCTrajectoryPoint from_json<ApolloplanningADCTrajectoryPoint>(nlohmann::json obj){
        return from_json_ApolloplanningADCTrajectoryPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningADCTrajectoryPoint &dt)
    {
        dt=from_json_ApolloplanningADCTrajectoryPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningADCTrajectoryPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningADCTrajectoryPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
