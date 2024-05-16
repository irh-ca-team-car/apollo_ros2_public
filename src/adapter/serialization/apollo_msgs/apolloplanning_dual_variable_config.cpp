#include "adapter/serialization/apollo_msgs/apolloplanning_dual_variable_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDualVariableConfig &msg) {
        nlohmann::json obj;
        obj["weightd"] = (msg.weightd);
        obj["ipoptconfig"] = to_json(msg.ipoptconfig);
        obj["qpformat"] = (msg.qpformat);
        obj["minsafetydistance"] = (msg.minsafetydistance);
        obj["debugosqp"] = (msg.debugosqp);
        obj["beta"] = (msg.beta);
        return obj;
    }
    ApolloplanningDualVariableConfig from_json_ApolloplanningDualVariableConfig (nlohmann::json obj) {
        ApolloplanningDualVariableConfig msg;
        if(obj.contains("weightd"))
        {
            msg.weightd = (obj["weightd"].is_string()?atof(obj["weightd"].get<std::string>().c_str()):obj["weightd"].get<double>());
        }
        if(obj.contains("ipoptconfig"))
        {
            msg.ipoptconfig = from_json_ApolloplanningIpoptSolverConfig(obj["ipoptconfig"]);
        }
        if(obj.contains("qpformat"))
        {
            msg.qpformat = (obj["qpformat"].is_string()?atoi(obj["qpformat"].get<std::string>().c_str()):obj["qpformat"].get<int>());
        }
        if(obj.contains("minsafetydistance"))
        {
            msg.minsafetydistance = (obj["minsafetydistance"].is_string()?atof(obj["minsafetydistance"].get<std::string>().c_str()):obj["minsafetydistance"].get<double>());
        }
        if(obj.contains("debugosqp"))
        {
            msg.debugosqp = (obj["debugosqp"].is_string()?(bool)atoi(obj["debugosqp"].get<std::string>().c_str()):obj["debugosqp"].get<bool>());
        }
        if(obj.contains("beta"))
        {
            msg.beta = (obj["beta"].is_string()?atof(obj["beta"].get<std::string>().c_str()):obj["beta"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningDualVariableConfig from_json<ApolloplanningDualVariableConfig>(nlohmann::json obj){
        return from_json_ApolloplanningDualVariableConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDualVariableConfig &dt)
    {
        dt=from_json_ApolloplanningDualVariableConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDualVariableConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDualVariableConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
