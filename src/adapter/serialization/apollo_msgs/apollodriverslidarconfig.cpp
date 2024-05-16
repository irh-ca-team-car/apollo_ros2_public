#include "adapter/serialization/apollo_msgs/apollodriverslidarconfig.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollodriverslidarconfig &msg) {
        nlohmann::json obj;
        obj["brand"] = (msg.brand);
        obj["hesai"] = to_json(msg.hesai);
        obj["robosense"] = to_json(msg.robosense);
        obj["velodyne"] = to_json(msg.velodyne);
        return obj;
    }
    Apollodriverslidarconfig from_json_Apollodriverslidarconfig (nlohmann::json obj) {
        Apollodriverslidarconfig msg;
        if(obj.contains("brand"))
        {
            msg.brand = (obj["brand"].is_string()?atoi(obj["brand"].get<std::string>().c_str()):obj["brand"].get<int>());
        }
        if(obj.contains("hesai"))
        {
            msg.hesai = from_json_ApollodrivershesaiConfig(obj["hesai"]);
        }
        if(obj.contains("robosense"))
        {
            msg.robosense = from_json_ApollodriversrobosenseConfig(obj["robosense"]);
        }
        if(obj.contains("velodyne"))
        {
            msg.velodyne = from_json_ApollodriversvelodyneConfig(obj["velodyne"]);
        }
        return msg;
    }
    template <>
    Apollodriverslidarconfig from_json<Apollodriverslidarconfig>(nlohmann::json obj){
        return from_json_Apollodriverslidarconfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollodriverslidarconfig &dt)
    {
        dt=from_json_Apollodriverslidarconfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollodriverslidarconfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollodriverslidarconfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
