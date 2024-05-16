#include "adapter/serialization/apollo_msgs/apolloplanning_fem_pos_deviation_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningFemPosDeviationSmootherConfig &msg) {
        nlohmann::json obj;
        obj["weightfemposdeviation"] = (msg.weightfemposdeviation);
        obj["weightrefdeviation"] = (msg.weightrefdeviation);
        obj["weightpathlength"] = (msg.weightpathlength);
        obj["applycurvatureconstraint"] = (msg.applycurvatureconstraint);
        obj["weightcurvatureconstraintslackvar"] = (msg.weightcurvatureconstraintslackvar);
        obj["curvatureconstraint"] = (msg.curvatureconstraint);
        obj["usesqp"] = (msg.usesqp);
        obj["sqpftol"] = (msg.sqpftol);
        obj["sqpctol"] = (msg.sqpctol);
        obj["sqppenmaxiter"] = (msg.sqppenmaxiter);
        obj["sqpsubmaxiter"] = (msg.sqpsubmaxiter);
        obj["maxiter"] = (msg.maxiter);
        obj["timelimit"] = (msg.timelimit);
        obj["verbose"] = (msg.verbose);
        obj["scaledtermination"] = (msg.scaledtermination);
        obj["warmstart"] = (msg.warmstart);
        obj["printlevel"] = (msg.printlevel);
        obj["maxnumofiterations"] = (msg.maxnumofiterations);
        obj["acceptablenumofiterations"] = (msg.acceptablenumofiterations);
        obj["tol"] = (msg.tol);
        obj["acceptabletol"] = (msg.acceptabletol);
        return obj;
    }
    ApolloplanningFemPosDeviationSmootherConfig from_json_ApolloplanningFemPosDeviationSmootherConfig (nlohmann::json obj) {
        ApolloplanningFemPosDeviationSmootherConfig msg;
        if(obj.contains("weightfemposdeviation"))
        {
            msg.weightfemposdeviation = (obj["weightfemposdeviation"].is_string()?atof(obj["weightfemposdeviation"].get<std::string>().c_str()):obj["weightfemposdeviation"].get<double>());
        }
        if(obj.contains("weightrefdeviation"))
        {
            msg.weightrefdeviation = (obj["weightrefdeviation"].is_string()?atof(obj["weightrefdeviation"].get<std::string>().c_str()):obj["weightrefdeviation"].get<double>());
        }
        if(obj.contains("weightpathlength"))
        {
            msg.weightpathlength = (obj["weightpathlength"].is_string()?atof(obj["weightpathlength"].get<std::string>().c_str()):obj["weightpathlength"].get<double>());
        }
        if(obj.contains("applycurvatureconstraint"))
        {
            msg.applycurvatureconstraint = (obj["applycurvatureconstraint"].is_string()?(bool)atoi(obj["applycurvatureconstraint"].get<std::string>().c_str()):obj["applycurvatureconstraint"].get<bool>());
        }
        if(obj.contains("weightcurvatureconstraintslackvar"))
        {
            msg.weightcurvatureconstraintslackvar = (obj["weightcurvatureconstraintslackvar"].is_string()?atof(obj["weightcurvatureconstraintslackvar"].get<std::string>().c_str()):obj["weightcurvatureconstraintslackvar"].get<double>());
        }
        if(obj.contains("curvatureconstraint"))
        {
            msg.curvatureconstraint = (obj["curvatureconstraint"].is_string()?atof(obj["curvatureconstraint"].get<std::string>().c_str()):obj["curvatureconstraint"].get<double>());
        }
        if(obj.contains("usesqp"))
        {
            msg.usesqp = (obj["usesqp"].is_string()?(bool)atoi(obj["usesqp"].get<std::string>().c_str()):obj["usesqp"].get<bool>());
        }
        if(obj.contains("sqpftol"))
        {
            msg.sqpftol = (obj["sqpftol"].is_string()?atof(obj["sqpftol"].get<std::string>().c_str()):obj["sqpftol"].get<double>());
        }
        if(obj.contains("sqpctol"))
        {
            msg.sqpctol = (obj["sqpctol"].is_string()?atof(obj["sqpctol"].get<std::string>().c_str()):obj["sqpctol"].get<double>());
        }
        if(obj.contains("sqppenmaxiter"))
        {
            msg.sqppenmaxiter = (obj["sqppenmaxiter"].is_string()?atoi(obj["sqppenmaxiter"].get<std::string>().c_str()):obj["sqppenmaxiter"].get<int>());
        }
        if(obj.contains("sqpsubmaxiter"))
        {
            msg.sqpsubmaxiter = (obj["sqpsubmaxiter"].is_string()?atoi(obj["sqpsubmaxiter"].get<std::string>().c_str()):obj["sqpsubmaxiter"].get<int>());
        }
        if(obj.contains("maxiter"))
        {
            msg.maxiter = (obj["maxiter"].is_string()?atoi(obj["maxiter"].get<std::string>().c_str()):obj["maxiter"].get<int>());
        }
        if(obj.contains("timelimit"))
        {
            msg.timelimit = (obj["timelimit"].is_string()?atof(obj["timelimit"].get<std::string>().c_str()):obj["timelimit"].get<double>());
        }
        if(obj.contains("verbose"))
        {
            msg.verbose = (obj["verbose"].is_string()?(bool)atoi(obj["verbose"].get<std::string>().c_str()):obj["verbose"].get<bool>());
        }
        if(obj.contains("scaledtermination"))
        {
            msg.scaledtermination = (obj["scaledtermination"].is_string()?(bool)atoi(obj["scaledtermination"].get<std::string>().c_str()):obj["scaledtermination"].get<bool>());
        }
        if(obj.contains("warmstart"))
        {
            msg.warmstart = (obj["warmstart"].is_string()?(bool)atoi(obj["warmstart"].get<std::string>().c_str()):obj["warmstart"].get<bool>());
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
        return msg;
    }
    template <>
    ApolloplanningFemPosDeviationSmootherConfig from_json<ApolloplanningFemPosDeviationSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningFemPosDeviationSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningFemPosDeviationSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningFemPosDeviationSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningFemPosDeviationSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningFemPosDeviationSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
