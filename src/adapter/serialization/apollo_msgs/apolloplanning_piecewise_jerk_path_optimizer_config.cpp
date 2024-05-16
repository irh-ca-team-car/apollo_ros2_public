#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_path_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkPathOptimizerConfig &msg) {
        nlohmann::json obj;
        obj["defaultpathconfig"] = to_json(msg.defaultpathconfig);
        obj["lanechangepathconfig"] = to_json(msg.lanechangepathconfig);
        obj["pathreferencelweight"] = (msg.pathreferencelweight);
        return obj;
    }
    ApolloplanningPiecewiseJerkPathOptimizerConfig from_json_ApolloplanningPiecewiseJerkPathOptimizerConfig (nlohmann::json obj) {
        ApolloplanningPiecewiseJerkPathOptimizerConfig msg;
        if(obj.contains("defaultpathconfig"))
        {
            msg.defaultpathconfig = from_json_ApolloplanningPiecewiseJerkPathWeights(obj["defaultpathconfig"]);
        }
        if(obj.contains("lanechangepathconfig"))
        {
            msg.lanechangepathconfig = from_json_ApolloplanningPiecewiseJerkPathWeights(obj["lanechangepathconfig"]);
        }
        if(obj.contains("pathreferencelweight"))
        {
            msg.pathreferencelweight = (obj["pathreferencelweight"].is_string()?atof(obj["pathreferencelweight"].get<std::string>().c_str()):obj["pathreferencelweight"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPiecewiseJerkPathOptimizerConfig from_json<ApolloplanningPiecewiseJerkPathOptimizerConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPiecewiseJerkPathOptimizerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkPathOptimizerConfig &dt)
    {
        dt=from_json_ApolloplanningPiecewiseJerkPathOptimizerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkPathOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkPathOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
