#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPoint2D &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        return obj;
    }
    ApollocommonPoint2D from_json_ApollocommonPoint2D (nlohmann::json obj) {
        ApollocommonPoint2D msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atof(obj["x"].get<std::string>().c_str()):obj["x"].get<double>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atof(obj["y"].get<std::string>().c_str()):obj["y"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonPoint2D from_json<ApollocommonPoint2D>(nlohmann::json obj){
        return from_json_ApollocommonPoint2D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPoint2D &dt)
    {
        dt=from_json_ApollocommonPoint2D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonPoint2D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPoint2D & dt)
    {
        os << to_json(dt);
        return os;
    }
}
