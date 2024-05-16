#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_smoother_config_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReferenceLineSmootherConfigSmootherConfig &msg) {
        nlohmann::json obj;
        obj["qpspline"] = to_json(msg.qpspline);
        obj["spiral"] = to_json(msg.spiral);
        obj["discretepoints"] = to_json(msg.discretepoints);
        return obj;
    }
    ApolloplanningReferenceLineSmootherConfigSmootherConfig from_json_ApolloplanningReferenceLineSmootherConfigSmootherConfig (nlohmann::json obj) {
        ApolloplanningReferenceLineSmootherConfigSmootherConfig msg;
        if(obj.contains("qpspline"))
        {
            msg.qpspline = from_json_ApolloplanningQpSplineSmootherConfig(obj["qpspline"]);
        }
        if(obj.contains("spiral"))
        {
            msg.spiral = from_json_ApolloplanningSpiralSmootherConfig(obj["spiral"]);
        }
        if(obj.contains("discretepoints"))
        {
            msg.discretepoints = from_json_ApolloplanningDiscretePointsSmootherConfig(obj["discretepoints"]);
        }
        return msg;
    }
    template <>
    ApolloplanningReferenceLineSmootherConfigSmootherConfig from_json<ApolloplanningReferenceLineSmootherConfigSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningReferenceLineSmootherConfigSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReferenceLineSmootherConfigSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningReferenceLineSmootherConfigSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReferenceLineSmootherConfigSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReferenceLineSmootherConfigSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
