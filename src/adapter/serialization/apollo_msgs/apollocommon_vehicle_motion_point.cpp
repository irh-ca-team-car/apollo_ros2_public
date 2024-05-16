#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_motion_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleMotionPoint &msg) {
        nlohmann::json obj;
        obj["trajectorypoint"] = to_json(msg.trajectorypoint);
        obj["steer"] = (msg.steer);
        return obj;
    }
    ApollocommonVehicleMotionPoint from_json_ApollocommonVehicleMotionPoint (nlohmann::json obj) {
        ApollocommonVehicleMotionPoint msg;
        if(obj.contains("trajectorypoint"))
        {
            msg.trajectorypoint = from_json_ApollocommonTrajectoryPoint(obj["trajectorypoint"]);
        }
        if(obj.contains("steer"))
        {
            msg.steer = (obj["steer"].is_string()?atof(obj["steer"].get<std::string>().c_str()):obj["steer"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonVehicleMotionPoint from_json<ApollocommonVehicleMotionPoint>(nlohmann::json obj){
        return from_json_ApollocommonVehicleMotionPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleMotionPoint &dt)
    {
        dt=from_json_ApollocommonVehicleMotionPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleMotionPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleMotionPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
