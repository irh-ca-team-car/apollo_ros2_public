#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonQuaternion &msg) {
        nlohmann::json obj;
        obj["qx"] = (msg.qx);
        obj["qy"] = (msg.qy);
        obj["qz"] = (msg.qz);
        obj["qw"] = (msg.qw);
        return obj;
    }
    ApollocommonQuaternion from_json_ApollocommonQuaternion (nlohmann::json obj) {
        ApollocommonQuaternion msg;
        if(obj.contains("qx"))
        {
            msg.qx = (obj["qx"].is_string()?atof(obj["qx"].get<std::string>().c_str()):obj["qx"].get<double>());
        }
        if(obj.contains("qy"))
        {
            msg.qy = (obj["qy"].is_string()?atof(obj["qy"].get<std::string>().c_str()):obj["qy"].get<double>());
        }
        if(obj.contains("qz"))
        {
            msg.qz = (obj["qz"].is_string()?atof(obj["qz"].get<std::string>().c_str()):obj["qz"].get<double>());
        }
        if(obj.contains("qw"))
        {
            msg.qw = (obj["qw"].is_string()?atof(obj["qw"].get<std::string>().c_str()):obj["qw"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonQuaternion from_json<ApollocommonQuaternion>(nlohmann::json obj){
        return from_json_ApollocommonQuaternion(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonQuaternion &dt)
    {
        dt=from_json_ApollocommonQuaternion(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonQuaternion & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonQuaternion & dt)
    {
        os << to_json(dt);
        return os;
    }
}
