#include "adapter/serialization/apollo_msgs/apollodriverscanbus_sensor_canbus_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscanbusSensorCanbusConf &msg) {
        nlohmann::json obj;
        obj["cancardparameter"] = to_json(msg.cancardparameter);
        obj["enabledebugmode"] = (msg.enabledebugmode);
        obj["enablereceiverlog"] = (msg.enablereceiverlog);
        return obj;
    }
    ApollodriverscanbusSensorCanbusConf from_json_ApollodriverscanbusSensorCanbusConf (nlohmann::json obj) {
        ApollodriverscanbusSensorCanbusConf msg;
        if(obj.contains("cancardparameter"))
        {
            msg.cancardparameter = from_json_ApollodriverscanbusCANCardParameter(obj["cancardparameter"]);
        }
        if(obj.contains("enabledebugmode"))
        {
            msg.enabledebugmode = (obj["enabledebugmode"].is_string()?(bool)atoi(obj["enabledebugmode"].get<std::string>().c_str()):obj["enabledebugmode"].get<bool>());
        }
        if(obj.contains("enablereceiverlog"))
        {
            msg.enablereceiverlog = (obj["enablereceiverlog"].is_string()?(bool)atoi(obj["enablereceiverlog"].get<std::string>().c_str()):obj["enablereceiverlog"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriverscanbusSensorCanbusConf from_json<ApollodriverscanbusSensorCanbusConf>(nlohmann::json obj){
        return from_json_ApollodriverscanbusSensorCanbusConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscanbusSensorCanbusConf &dt)
    {
        dt=from_json_ApollodriverscanbusSensorCanbusConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverscanbusSensorCanbusConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscanbusSensorCanbusConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
