#include "adapter/serialization/apollo_msgs/apollocommon_com_centered_dynamic_bicycle_model_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonComCenteredDynamicBicycleModelConfig &msg) {
        nlohmann::json obj;
        obj["dt"] = (msg.dt);
        return obj;
    }
    ApollocommonComCenteredDynamicBicycleModelConfig from_json_ApollocommonComCenteredDynamicBicycleModelConfig (nlohmann::json obj) {
        ApollocommonComCenteredDynamicBicycleModelConfig msg;
        if(obj.contains("dt"))
        {
            msg.dt = (obj["dt"].is_string()?atof(obj["dt"].get<std::string>().c_str()):obj["dt"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonComCenteredDynamicBicycleModelConfig from_json<ApollocommonComCenteredDynamicBicycleModelConfig>(nlohmann::json obj){
        return from_json_ApollocommonComCenteredDynamicBicycleModelConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonComCenteredDynamicBicycleModelConfig &dt)
    {
        dt=from_json_ApollocommonComCenteredDynamicBicycleModelConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonComCenteredDynamicBicycleModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonComCenteredDynamicBicycleModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
