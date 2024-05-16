#include "adapter/serialization/apollo_msgs/apolloplanning_osqp_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOSQPConfig &msg) {
        nlohmann::json obj;
        obj["alpha"] = (msg.alpha);
        obj["epsabs"] = (msg.epsabs);
        obj["epsrel"] = (msg.epsrel);
        obj["maxiter"] = (msg.maxiter);
        obj["polish"] = (msg.polish);
        obj["osqpdebuglog"] = (msg.osqpdebuglog);
        return obj;
    }
    ApolloplanningOSQPConfig from_json_ApolloplanningOSQPConfig (nlohmann::json obj) {
        ApolloplanningOSQPConfig msg;
        if(obj.contains("alpha"))
        {
            msg.alpha = (obj["alpha"].is_string()?atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<double>());
        }
        if(obj.contains("epsabs"))
        {
            msg.epsabs = (obj["epsabs"].is_string()?atof(obj["epsabs"].get<std::string>().c_str()):obj["epsabs"].get<double>());
        }
        if(obj.contains("epsrel"))
        {
            msg.epsrel = (obj["epsrel"].is_string()?atof(obj["epsrel"].get<std::string>().c_str()):obj["epsrel"].get<double>());
        }
        if(obj.contains("maxiter"))
        {
            msg.maxiter = (obj["maxiter"].is_string()?atoi(obj["maxiter"].get<std::string>().c_str()):obj["maxiter"].get<int>());
        }
        if(obj.contains("polish"))
        {
            msg.polish = (obj["polish"].is_string()?(bool)atoi(obj["polish"].get<std::string>().c_str()):obj["polish"].get<bool>());
        }
        if(obj.contains("osqpdebuglog"))
        {
            msg.osqpdebuglog = (obj["osqpdebuglog"].is_string()?(bool)atoi(obj["osqpdebuglog"].get<std::string>().c_str()):obj["osqpdebuglog"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningOSQPConfig from_json<ApolloplanningOSQPConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOSQPConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOSQPConfig &dt)
    {
        dt=from_json_ApolloplanningOSQPConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOSQPConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOSQPConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
