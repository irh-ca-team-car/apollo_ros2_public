#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPointENU &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        return obj;
    }
    ApollocommonPointENU from_json_ApollocommonPointENU (nlohmann::json obj) {
        ApollocommonPointENU msg;
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
        return msg;
    }
    template <>
    ApollocommonPointENU from_json<ApollocommonPointENU>(nlohmann::json obj){
        return from_json_ApollocommonPointENU(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPointENU &dt)
    {
        dt=from_json_ApollocommonPointENU(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonPointENU & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPointENU & dt)
    {
        os << to_json(dt);
        return os;
    }
}
