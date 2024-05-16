#include "adapter/serialization/apollo_msgs/apollocommon_rear_centered_kinematic_bicycle_model_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonRearCenteredKinematicBicycleModelConfig &msg) {
        nlohmann::json obj;
        obj["dt"] = (msg.dt);
        return obj;
    }
    ApollocommonRearCenteredKinematicBicycleModelConfig from_json_ApollocommonRearCenteredKinematicBicycleModelConfig (nlohmann::json obj) {
        ApollocommonRearCenteredKinematicBicycleModelConfig msg;
        if(obj.contains("dt"))
        {
            msg.dt = (obj["dt"].is_string()?atof(obj["dt"].get<std::string>().c_str()):obj["dt"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonRearCenteredKinematicBicycleModelConfig from_json<ApollocommonRearCenteredKinematicBicycleModelConfig>(nlohmann::json obj){
        return from_json_ApollocommonRearCenteredKinematicBicycleModelConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonRearCenteredKinematicBicycleModelConfig &dt)
    {
        dt=from_json_ApollocommonRearCenteredKinematicBicycleModelConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonRearCenteredKinematicBicycleModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonRearCenteredKinematicBicycleModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
