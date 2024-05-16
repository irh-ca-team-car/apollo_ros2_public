#include "adapter/serialization/apollo_msgs/apolloplanning_discrete_points_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDiscretePointsSmootherConfig &msg) {
        nlohmann::json obj;
        obj["smoothingmethod"] = (msg.smoothingmethod);
        obj["smootherconfig"] = to_json(msg.smootherconfig);
        return obj;
    }
    ApolloplanningDiscretePointsSmootherConfig from_json_ApolloplanningDiscretePointsSmootherConfig (nlohmann::json obj) {
        ApolloplanningDiscretePointsSmootherConfig msg;
        if(obj.contains("smoothingmethod"))
        {
            msg.smoothingmethod = (obj["smoothingmethod"].is_string()?atoi(obj["smoothingmethod"].get<std::string>().c_str()):obj["smoothingmethod"].get<int>());
        }
        if(obj.contains("smootherconfig"))
        {
            msg.smootherconfig = from_json_ApolloplanningDiscretePointsSmootherConfigSmootherConfig(obj["smootherconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningDiscretePointsSmootherConfig from_json<ApolloplanningDiscretePointsSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningDiscretePointsSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDiscretePointsSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningDiscretePointsSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDiscretePointsSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDiscretePointsSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
