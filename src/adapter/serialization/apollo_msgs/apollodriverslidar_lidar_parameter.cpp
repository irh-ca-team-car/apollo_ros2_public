#include "adapter/serialization/apollo_msgs/apollodriverslidar_lidar_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverslidarLidarParameter &msg) {
        nlohmann::json obj;
        obj["brand"] = (msg.brand);
        return obj;
    }
    ApollodriverslidarLidarParameter from_json_ApollodriverslidarLidarParameter (nlohmann::json obj) {
        ApollodriverslidarLidarParameter msg;
        if(obj.contains("brand"))
        {
            msg.brand = (obj["brand"].is_string()?atoi(obj["brand"].get<std::string>().c_str()):obj["brand"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriverslidarLidarParameter from_json<ApollodriverslidarLidarParameter>(nlohmann::json obj){
        return from_json_ApollodriverslidarLidarParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverslidarLidarParameter &dt)
    {
        dt=from_json_ApollodriverslidarLidarParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverslidarLidarParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverslidarLidarParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
