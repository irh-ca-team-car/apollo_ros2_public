#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_speed_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkSpeedOptimizerConfig &msg) {
        nlohmann::json obj;
        obj["accweight"] = (msg.accweight);
        obj["jerkweight"] = (msg.jerkweight);
        obj["kappapenaltyweight"] = (msg.kappapenaltyweight);
        obj["refsweight"] = (msg.refsweight);
        obj["refvweight"] = (msg.refvweight);
        return obj;
    }
    ApolloplanningPiecewiseJerkSpeedOptimizerConfig from_json_ApolloplanningPiecewiseJerkSpeedOptimizerConfig (nlohmann::json obj) {
        ApolloplanningPiecewiseJerkSpeedOptimizerConfig msg;
        if(obj.contains("accweight"))
        {
            msg.accweight = (obj["accweight"].is_string()?atof(obj["accweight"].get<std::string>().c_str()):obj["accweight"].get<double>());
        }
        if(obj.contains("jerkweight"))
        {
            msg.jerkweight = (obj["jerkweight"].is_string()?atof(obj["jerkweight"].get<std::string>().c_str()):obj["jerkweight"].get<double>());
        }
        if(obj.contains("kappapenaltyweight"))
        {
            msg.kappapenaltyweight = (obj["kappapenaltyweight"].is_string()?atof(obj["kappapenaltyweight"].get<std::string>().c_str()):obj["kappapenaltyweight"].get<double>());
        }
        if(obj.contains("refsweight"))
        {
            msg.refsweight = (obj["refsweight"].is_string()?atof(obj["refsweight"].get<std::string>().c_str()):obj["refsweight"].get<double>());
        }
        if(obj.contains("refvweight"))
        {
            msg.refvweight = (obj["refvweight"].is_string()?atof(obj["refvweight"].get<std::string>().c_str()):obj["refvweight"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPiecewiseJerkSpeedOptimizerConfig from_json<ApolloplanningPiecewiseJerkSpeedOptimizerConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPiecewiseJerkSpeedOptimizerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkSpeedOptimizerConfig &dt)
    {
        dt=from_json_ApolloplanningPiecewiseJerkSpeedOptimizerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkSpeedOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkSpeedOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
