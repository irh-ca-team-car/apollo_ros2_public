#include "adapter/serialization/apollo_msgs/apollocanbus_horn_cmd78.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHornCmd78 &msg) {
        nlohmann::json obj;
        obj["horncmd"] = (msg.horncmd);
        return obj;
    }
    ApollocanbusHornCmd78 from_json_ApollocanbusHornCmd78 (nlohmann::json obj) {
        ApollocanbusHornCmd78 msg;
        if(obj.contains("horncmd"))
        {
            msg.horncmd = (obj["horncmd"].is_string()?atoi(obj["horncmd"].get<std::string>().c_str()):obj["horncmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusHornCmd78 from_json<ApollocanbusHornCmd78>(nlohmann::json obj){
        return from_json_ApollocanbusHornCmd78(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHornCmd78 &dt)
    {
        dt=from_json_ApollocanbusHornCmd78(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHornCmd78 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHornCmd78 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
