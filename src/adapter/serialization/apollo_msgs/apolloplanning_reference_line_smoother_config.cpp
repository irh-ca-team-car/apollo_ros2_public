#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReferenceLineSmootherConfig &msg) {
        nlohmann::json obj;
        obj["maxconstraintinterval"] = (msg.maxconstraintinterval);
        obj["longitudinalboundarybound"] = (msg.longitudinalboundarybound);
        obj["maxlateralboundarybound"] = (msg.maxlateralboundarybound);
        obj["minlateralboundarybound"] = (msg.minlateralboundarybound);
        obj["numoftotalpoints"] = (msg.numoftotalpoints);
        obj["curbshift"] = (msg.curbshift);
        obj["lateralbuffer"] = (msg.lateralbuffer);
        obj["resolution"] = (msg.resolution);
        obj["smootherconfig"] = to_json(msg.smootherconfig);
        return obj;
    }
    ApolloplanningReferenceLineSmootherConfig from_json_ApolloplanningReferenceLineSmootherConfig (nlohmann::json obj) {
        ApolloplanningReferenceLineSmootherConfig msg;
        if(obj.contains("maxconstraintinterval"))
        {
            msg.maxconstraintinterval = (obj["maxconstraintinterval"].is_string()?atof(obj["maxconstraintinterval"].get<std::string>().c_str()):obj["maxconstraintinterval"].get<double>());
        }
        if(obj.contains("longitudinalboundarybound"))
        {
            msg.longitudinalboundarybound = (obj["longitudinalboundarybound"].is_string()?atof(obj["longitudinalboundarybound"].get<std::string>().c_str()):obj["longitudinalboundarybound"].get<double>());
        }
        if(obj.contains("maxlateralboundarybound"))
        {
            msg.maxlateralboundarybound = (obj["maxlateralboundarybound"].is_string()?atof(obj["maxlateralboundarybound"].get<std::string>().c_str()):obj["maxlateralboundarybound"].get<double>());
        }
        if(obj.contains("minlateralboundarybound"))
        {
            msg.minlateralboundarybound = (obj["minlateralboundarybound"].is_string()?atof(obj["minlateralboundarybound"].get<std::string>().c_str()):obj["minlateralboundarybound"].get<double>());
        }
        if(obj.contains("numoftotalpoints"))
        {
            msg.numoftotalpoints = (obj["numoftotalpoints"].is_string()?atoi(obj["numoftotalpoints"].get<std::string>().c_str()):obj["numoftotalpoints"].get<uint32_t>());
        }
        if(obj.contains("curbshift"))
        {
            msg.curbshift = (obj["curbshift"].is_string()?atof(obj["curbshift"].get<std::string>().c_str()):obj["curbshift"].get<double>());
        }
        if(obj.contains("lateralbuffer"))
        {
            msg.lateralbuffer = (obj["lateralbuffer"].is_string()?atof(obj["lateralbuffer"].get<std::string>().c_str()):obj["lateralbuffer"].get<double>());
        }
        if(obj.contains("resolution"))
        {
            msg.resolution = (obj["resolution"].is_string()?atof(obj["resolution"].get<std::string>().c_str()):obj["resolution"].get<double>());
        }
        if(obj.contains("smootherconfig"))
        {
            msg.smootherconfig = from_json_ApolloplanningReferenceLineSmootherConfigSmootherConfig(obj["smootherconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningReferenceLineSmootherConfig from_json<ApolloplanningReferenceLineSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningReferenceLineSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReferenceLineSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningReferenceLineSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReferenceLineSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReferenceLineSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
