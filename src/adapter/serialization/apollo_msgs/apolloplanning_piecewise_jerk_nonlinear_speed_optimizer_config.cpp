#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_nonlinear_speed_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig &msg) {
        nlohmann::json obj;
        obj["accweight"] = (msg.accweight);
        obj["jerkweight"] = (msg.jerkweight);
        obj["lataccweight"] = (msg.lataccweight);
        obj["spotentialweight"] = (msg.spotentialweight);
        obj["refvweight"] = (msg.refvweight);
        obj["refsweight"] = (msg.refsweight);
        obj["endsweight"] = (msg.endsweight);
        obj["endvweight"] = (msg.endvweight);
        obj["endaweight"] = (msg.endaweight);
        obj["softsboundweight"] = (msg.softsboundweight);
        obj["usewarmstart"] = (msg.usewarmstart);
        return obj;
    }
    ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig from_json_ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig (nlohmann::json obj) {
        ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig msg;
        if(obj.contains("accweight"))
        {
            msg.accweight = (obj["accweight"].is_string()?atof(obj["accweight"].get<std::string>().c_str()):obj["accweight"].get<double>());
        }
        if(obj.contains("jerkweight"))
        {
            msg.jerkweight = (obj["jerkweight"].is_string()?atof(obj["jerkweight"].get<std::string>().c_str()):obj["jerkweight"].get<double>());
        }
        if(obj.contains("lataccweight"))
        {
            msg.lataccweight = (obj["lataccweight"].is_string()?atof(obj["lataccweight"].get<std::string>().c_str()):obj["lataccweight"].get<double>());
        }
        if(obj.contains("spotentialweight"))
        {
            msg.spotentialweight = (obj["spotentialweight"].is_string()?atof(obj["spotentialweight"].get<std::string>().c_str()):obj["spotentialweight"].get<double>());
        }
        if(obj.contains("refvweight"))
        {
            msg.refvweight = (obj["refvweight"].is_string()?atof(obj["refvweight"].get<std::string>().c_str()):obj["refvweight"].get<double>());
        }
        if(obj.contains("refsweight"))
        {
            msg.refsweight = (obj["refsweight"].is_string()?atof(obj["refsweight"].get<std::string>().c_str()):obj["refsweight"].get<double>());
        }
        if(obj.contains("endsweight"))
        {
            msg.endsweight = (obj["endsweight"].is_string()?atof(obj["endsweight"].get<std::string>().c_str()):obj["endsweight"].get<double>());
        }
        if(obj.contains("endvweight"))
        {
            msg.endvweight = (obj["endvweight"].is_string()?atof(obj["endvweight"].get<std::string>().c_str()):obj["endvweight"].get<double>());
        }
        if(obj.contains("endaweight"))
        {
            msg.endaweight = (obj["endaweight"].is_string()?atof(obj["endaweight"].get<std::string>().c_str()):obj["endaweight"].get<double>());
        }
        if(obj.contains("softsboundweight"))
        {
            msg.softsboundweight = (obj["softsboundweight"].is_string()?atof(obj["softsboundweight"].get<std::string>().c_str()):obj["softsboundweight"].get<double>());
        }
        if(obj.contains("usewarmstart"))
        {
            msg.usewarmstart = (obj["usewarmstart"].is_string()?(bool)atoi(obj["usewarmstart"].get<std::string>().c_str()):obj["usewarmstart"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig from_json<ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig &dt)
    {
        dt=from_json_ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkNonlinearSpeedOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
