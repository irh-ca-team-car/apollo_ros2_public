#include "adapter/serialization/apollo_msgs/apolloplanning_cos_theta_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCosThetaSmootherConfig &msg) {
        nlohmann::json obj;
        obj["weightcosincludedangle"] = (msg.weightcosincludedangle);
        obj["weightanchorpoints"] = (msg.weightanchorpoints);
        obj["weightlength"] = (msg.weightlength);
        obj["printlevel"] = (msg.printlevel);
        obj["maxnumofiterations"] = (msg.maxnumofiterations);
        obj["acceptablenumofiterations"] = (msg.acceptablenumofiterations);
        obj["tol"] = (msg.tol);
        obj["acceptabletol"] = (msg.acceptabletol);
        obj["ipoptuseautomaticdifferentiation"] = (msg.ipoptuseautomaticdifferentiation);
        return obj;
    }
    ApolloplanningCosThetaSmootherConfig from_json_ApolloplanningCosThetaSmootherConfig (nlohmann::json obj) {
        ApolloplanningCosThetaSmootherConfig msg;
        if(obj.contains("weightcosincludedangle"))
        {
            msg.weightcosincludedangle = (obj["weightcosincludedangle"].is_string()?atof(obj["weightcosincludedangle"].get<std::string>().c_str()):obj["weightcosincludedangle"].get<double>());
        }
        if(obj.contains("weightanchorpoints"))
        {
            msg.weightanchorpoints = (obj["weightanchorpoints"].is_string()?atof(obj["weightanchorpoints"].get<std::string>().c_str()):obj["weightanchorpoints"].get<double>());
        }
        if(obj.contains("weightlength"))
        {
            msg.weightlength = (obj["weightlength"].is_string()?atof(obj["weightlength"].get<std::string>().c_str()):obj["weightlength"].get<double>());
        }
        if(obj.contains("printlevel"))
        {
            msg.printlevel = (obj["printlevel"].is_string()?atoi(obj["printlevel"].get<std::string>().c_str()):obj["printlevel"].get<int>());
        }
        if(obj.contains("maxnumofiterations"))
        {
            msg.maxnumofiterations = (obj["maxnumofiterations"].is_string()?atoi(obj["maxnumofiterations"].get<std::string>().c_str()):obj["maxnumofiterations"].get<int>());
        }
        if(obj.contains("acceptablenumofiterations"))
        {
            msg.acceptablenumofiterations = (obj["acceptablenumofiterations"].is_string()?atoi(obj["acceptablenumofiterations"].get<std::string>().c_str()):obj["acceptablenumofiterations"].get<int>());
        }
        if(obj.contains("tol"))
        {
            msg.tol = (obj["tol"].is_string()?atof(obj["tol"].get<std::string>().c_str()):obj["tol"].get<double>());
        }
        if(obj.contains("acceptabletol"))
        {
            msg.acceptabletol = (obj["acceptabletol"].is_string()?atof(obj["acceptabletol"].get<std::string>().c_str()):obj["acceptabletol"].get<double>());
        }
        if(obj.contains("ipoptuseautomaticdifferentiation"))
        {
            msg.ipoptuseautomaticdifferentiation = (obj["ipoptuseautomaticdifferentiation"].is_string()?(bool)atoi(obj["ipoptuseautomaticdifferentiation"].get<std::string>().c_str()):obj["ipoptuseautomaticdifferentiation"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningCosThetaSmootherConfig from_json<ApolloplanningCosThetaSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningCosThetaSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCosThetaSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningCosThetaSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCosThetaSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCosThetaSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
