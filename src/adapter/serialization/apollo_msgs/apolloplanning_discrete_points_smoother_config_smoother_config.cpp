#include "adapter/serialization/apollo_msgs/apolloplanning_discrete_points_smoother_config_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDiscretePointsSmootherConfigSmootherConfig &msg) {
        nlohmann::json obj;
        obj["costhetasmoothing"] = to_json(msg.costhetasmoothing);
        obj["femposdeviationsmoothing"] = to_json(msg.femposdeviationsmoothing);
        return obj;
    }
    ApolloplanningDiscretePointsSmootherConfigSmootherConfig from_json_ApolloplanningDiscretePointsSmootherConfigSmootherConfig (nlohmann::json obj) {
        ApolloplanningDiscretePointsSmootherConfigSmootherConfig msg;
        if(obj.contains("costhetasmoothing"))
        {
            msg.costhetasmoothing = from_json_ApolloplanningCosThetaSmootherConfig(obj["costhetasmoothing"]);
        }
        if(obj.contains("femposdeviationsmoothing"))
        {
            msg.femposdeviationsmoothing = from_json_ApolloplanningFemPosDeviationSmootherConfig(obj["femposdeviationsmoothing"]);
        }
        return msg;
    }
    template <>
    ApolloplanningDiscretePointsSmootherConfigSmootherConfig from_json<ApolloplanningDiscretePointsSmootherConfigSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningDiscretePointsSmootherConfigSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDiscretePointsSmootherConfigSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningDiscretePointsSmootherConfigSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDiscretePointsSmootherConfigSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDiscretePointsSmootherConfigSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
