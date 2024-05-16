#include "adapter/serialization/apollo_msgs/apollocommon_mlp_model_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonMlpModelConfig &msg) {
        nlohmann::json obj;
        obj["dt"] = (msg.dt);
        return obj;
    }
    ApollocommonMlpModelConfig from_json_ApollocommonMlpModelConfig (nlohmann::json obj) {
        ApollocommonMlpModelConfig msg;
        if(obj.contains("dt"))
        {
            msg.dt = (obj["dt"].is_string()?atof(obj["dt"].get<std::string>().c_str()):obj["dt"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonMlpModelConfig from_json<ApollocommonMlpModelConfig>(nlohmann::json obj){
        return from_json_ApollocommonMlpModelConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonMlpModelConfig &dt)
    {
        dt=from_json_ApollocommonMlpModelConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonMlpModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonMlpModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
