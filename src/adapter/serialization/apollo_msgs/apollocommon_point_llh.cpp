#include "adapter/serialization/apollo_msgs/apollocommon_point_llh.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonPointLLH &msg) {
        nlohmann::json obj;
        obj["lon"] = (msg.lon);
        obj["lat"] = (msg.lat);
        obj["height"] = (msg.height);
        return obj;
    }
    ApollocommonPointLLH from_json_ApollocommonPointLLH (nlohmann::json obj) {
        ApollocommonPointLLH msg;
        if(obj.contains("lon"))
        {
            msg.lon = (obj["lon"].is_string()?atof(obj["lon"].get<std::string>().c_str()):obj["lon"].get<double>());
        }
        if(obj.contains("lat"))
        {
            msg.lat = (obj["lat"].is_string()?atof(obj["lat"].get<std::string>().c_str()):obj["lat"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atof(obj["height"].get<std::string>().c_str()):obj["height"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonPointLLH from_json<ApollocommonPointLLH>(nlohmann::json obj){
        return from_json_ApollocommonPointLLH(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonPointLLH &dt)
    {
        dt=from_json_ApollocommonPointLLH(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonPointLLH & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonPointLLH & dt)
    {
        os << to_json(dt);
        return os;
    }
}
