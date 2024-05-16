#include "adapter/serialization/apollo_msgs/apolloplanning_st_drivable_boundary_instance.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSTDrivableBoundaryInstance &msg) {
        nlohmann::json obj;
        obj["t"] = (msg.t);
        obj["slower"] = (msg.slower);
        obj["supper"] = (msg.supper);
        obj["vobslower"] = (msg.vobslower);
        obj["vobsupper"] = (msg.vobsupper);
        return obj;
    }
    ApolloplanningSTDrivableBoundaryInstance from_json_ApolloplanningSTDrivableBoundaryInstance (nlohmann::json obj) {
        ApolloplanningSTDrivableBoundaryInstance msg;
        if(obj.contains("t"))
        {
            msg.t = (obj["t"].is_string()?atof(obj["t"].get<std::string>().c_str()):obj["t"].get<double>());
        }
        if(obj.contains("slower"))
        {
            msg.slower = (obj["slower"].is_string()?atof(obj["slower"].get<std::string>().c_str()):obj["slower"].get<double>());
        }
        if(obj.contains("supper"))
        {
            msg.supper = (obj["supper"].is_string()?atof(obj["supper"].get<std::string>().c_str()):obj["supper"].get<double>());
        }
        if(obj.contains("vobslower"))
        {
            msg.vobslower = (obj["vobslower"].is_string()?atof(obj["vobslower"].get<std::string>().c_str()):obj["vobslower"].get<double>());
        }
        if(obj.contains("vobsupper"))
        {
            msg.vobsupper = (obj["vobsupper"].is_string()?atof(obj["vobsupper"].get<std::string>().c_str()):obj["vobsupper"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningSTDrivableBoundaryInstance from_json<ApolloplanningSTDrivableBoundaryInstance>(nlohmann::json obj){
        return from_json_ApolloplanningSTDrivableBoundaryInstance(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSTDrivableBoundaryInstance &dt)
    {
        dt=from_json_ApolloplanningSTDrivableBoundaryInstance(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSTDrivableBoundaryInstance & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSTDrivableBoundaryInstance & dt)
    {
        os << to_json(dt);
        return os;
    }
}
