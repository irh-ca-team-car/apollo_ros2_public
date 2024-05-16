#include "adapter/serialization/apollo_msgs/apollocommon_path_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPathPoint &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["theta"] = (msg.theta);
        obj["kappa"] = (msg.kappa);
        obj["s"] = (msg.s);
        obj["dkappa"] = (msg.dkappa);
        obj["ddkappa"] = (msg.ddkappa);
        obj["laneid"] = (msg.laneid);
        obj["xderivative"] = (msg.xderivative);
        obj["yderivative"] = (msg.yderivative);
        return obj;
    }
    ApollocommonPathPoint from_json_ApollocommonPathPoint (nlohmann::json obj) {
        ApollocommonPathPoint msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atof(obj["x"].get<std::string>().c_str()):obj["x"].get<double>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atof(obj["y"].get<std::string>().c_str()):obj["y"].get<double>());
        }
        if(obj.contains("z"))
        {
            msg.z = (obj["z"].is_string()?atof(obj["z"].get<std::string>().c_str()):obj["z"].get<double>());
        }
        if(obj.contains("theta"))
        {
            msg.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<double>());
        }
        if(obj.contains("kappa"))
        {
            msg.kappa = (obj["kappa"].is_string()?atof(obj["kappa"].get<std::string>().c_str()):obj["kappa"].get<double>());
        }
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("dkappa"))
        {
            msg.dkappa = (obj["dkappa"].is_string()?atof(obj["dkappa"].get<std::string>().c_str()):obj["dkappa"].get<double>());
        }
        if(obj.contains("ddkappa"))
        {
            msg.ddkappa = (obj["ddkappa"].is_string()?atof(obj["ddkappa"].get<std::string>().c_str()):obj["ddkappa"].get<double>());
        }
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        if(obj.contains("xderivative"))
        {
            msg.xderivative = (obj["xderivative"].is_string()?atof(obj["xderivative"].get<std::string>().c_str()):obj["xderivative"].get<double>());
        }
        if(obj.contains("yderivative"))
        {
            msg.yderivative = (obj["yderivative"].is_string()?atof(obj["yderivative"].get<std::string>().c_str()):obj["yderivative"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonPathPoint from_json<ApollocommonPathPoint>(nlohmann::json obj){
        return from_json_ApollocommonPathPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPathPoint &dt)
    {
        dt=from_json_ApollocommonPathPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonPathPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPathPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
