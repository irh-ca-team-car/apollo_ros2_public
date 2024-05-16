#include "adapter/serialization/apollo_msgs/apolloplanning_ipopt_solver_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningIpoptSolverConfig &msg) {
        nlohmann::json obj;
        obj["ipoptprintlevel"] = (msg.ipoptprintlevel);
        obj["mumpsmempercent"] = (msg.mumpsmempercent);
        obj["mumpspivtol"] = (msg.mumpspivtol);
        obj["ipoptmaxiter"] = (msg.ipoptmaxiter);
        obj["ipopttol"] = (msg.ipopttol);
        obj["ipoptacceptableconstrvioltol"] = (msg.ipoptacceptableconstrvioltol);
        obj["ipoptminhessianperturbation"] = (msg.ipoptminhessianperturbation);
        obj["ipoptjacobianregularizationvalue"] = (msg.ipoptjacobianregularizationvalue);
        obj["ipoptprinttimingstatistics"] = (msg.ipoptprinttimingstatistics);
        obj["ipoptalphafory"] = (msg.ipoptalphafory);
        obj["ipoptrecalcy"] = (msg.ipoptrecalcy);
        obj["ipoptmuinit"] = (msg.ipoptmuinit);
        return obj;
    }
    ApolloplanningIpoptSolverConfig from_json_ApolloplanningIpoptSolverConfig (nlohmann::json obj) {
        ApolloplanningIpoptSolverConfig msg;
        if(obj.contains("ipoptprintlevel"))
        {
            msg.ipoptprintlevel = (obj["ipoptprintlevel"].is_string()?atoi(obj["ipoptprintlevel"].get<std::string>().c_str()):obj["ipoptprintlevel"].get<int>());
        }
        if(obj.contains("mumpsmempercent"))
        {
            msg.mumpsmempercent = (obj["mumpsmempercent"].is_string()?atoi(obj["mumpsmempercent"].get<std::string>().c_str()):obj["mumpsmempercent"].get<int>());
        }
        if(obj.contains("mumpspivtol"))
        {
            msg.mumpspivtol = (obj["mumpspivtol"].is_string()?atof(obj["mumpspivtol"].get<std::string>().c_str()):obj["mumpspivtol"].get<double>());
        }
        if(obj.contains("ipoptmaxiter"))
        {
            msg.ipoptmaxiter = (obj["ipoptmaxiter"].is_string()?atoi(obj["ipoptmaxiter"].get<std::string>().c_str()):obj["ipoptmaxiter"].get<int>());
        }
        if(obj.contains("ipopttol"))
        {
            msg.ipopttol = (obj["ipopttol"].is_string()?atof(obj["ipopttol"].get<std::string>().c_str()):obj["ipopttol"].get<double>());
        }
        if(obj.contains("ipoptacceptableconstrvioltol"))
        {
            msg.ipoptacceptableconstrvioltol = (obj["ipoptacceptableconstrvioltol"].is_string()?atof(obj["ipoptacceptableconstrvioltol"].get<std::string>().c_str()):obj["ipoptacceptableconstrvioltol"].get<double>());
        }
        if(obj.contains("ipoptminhessianperturbation"))
        {
            msg.ipoptminhessianperturbation = (obj["ipoptminhessianperturbation"].is_string()?atof(obj["ipoptminhessianperturbation"].get<std::string>().c_str()):obj["ipoptminhessianperturbation"].get<double>());
        }
        if(obj.contains("ipoptjacobianregularizationvalue"))
        {
            msg.ipoptjacobianregularizationvalue = (obj["ipoptjacobianregularizationvalue"].is_string()?atof(obj["ipoptjacobianregularizationvalue"].get<std::string>().c_str()):obj["ipoptjacobianregularizationvalue"].get<double>());
        }
        if(obj.contains("ipoptprinttimingstatistics"))
        {
            msg.ipoptprinttimingstatistics = (obj["ipoptprinttimingstatistics"].is_string()?(obj["ipoptprinttimingstatistics"].get<std::string>().c_str()):obj["ipoptprinttimingstatistics"].get<std::string>());
        }
        if(obj.contains("ipoptalphafory"))
        {
            msg.ipoptalphafory = (obj["ipoptalphafory"].is_string()?(obj["ipoptalphafory"].get<std::string>().c_str()):obj["ipoptalphafory"].get<std::string>());
        }
        if(obj.contains("ipoptrecalcy"))
        {
            msg.ipoptrecalcy = (obj["ipoptrecalcy"].is_string()?(obj["ipoptrecalcy"].get<std::string>().c_str()):obj["ipoptrecalcy"].get<std::string>());
        }
        if(obj.contains("ipoptmuinit"))
        {
            msg.ipoptmuinit = (obj["ipoptmuinit"].is_string()?atof(obj["ipoptmuinit"].get<std::string>().c_str()):obj["ipoptmuinit"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningIpoptSolverConfig from_json<ApolloplanningIpoptSolverConfig>(nlohmann::json obj){
        return from_json_ApolloplanningIpoptSolverConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningIpoptSolverConfig &dt)
    {
        dt=from_json_ApolloplanningIpoptSolverConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningIpoptSolverConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningIpoptSolverConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
