#include "adapter/serialization/apollo_msgs/apolloplanning_common_path_point_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCommonPathPointFeature &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["theta"] = (msg.theta);
        obj["s"] = (msg.s);
        obj["laneid"] = (msg.laneid);
        return obj;
    }
    ApolloplanningCommonPathPointFeature from_json_ApolloplanningCommonPathPointFeature (nlohmann::json obj) {
        ApolloplanningCommonPathPointFeature msg;
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
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloplanningCommonPathPointFeature from_json<ApolloplanningCommonPathPointFeature>(nlohmann::json obj){
        return from_json_ApolloplanningCommonPathPointFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCommonPathPointFeature &dt)
    {
        dt=from_json_ApolloplanningCommonPathPointFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCommonPathPointFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCommonPathPointFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
