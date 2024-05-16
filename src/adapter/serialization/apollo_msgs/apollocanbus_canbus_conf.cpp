#include "adapter/serialization/apollo_msgs/apollocanbus_canbus_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCanbusConf &msg) {
        nlohmann::json obj;
        obj["vehicleparameter"] = to_json(msg.vehicleparameter);
        obj["cancardparameter"] = to_json(msg.cancardparameter);
        obj["enabledebugmode"] = (msg.enabledebugmode);
        obj["enablereceiverlog"] = (msg.enablereceiverlog);
        obj["enablesenderlog"] = (msg.enablesenderlog);
        return obj;
    }
    ApollocanbusCanbusConf from_json_ApollocanbusCanbusConf (nlohmann::json obj) {
        ApollocanbusCanbusConf msg;
        if(obj.contains("vehicleparameter"))
        {
            msg.vehicleparameter = from_json_ApollocanbusVehicleParameter(obj["vehicleparameter"]);
        }
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
        if(obj.contains("enablesenderlog"))
        {
            msg.enablesenderlog = (obj["enablesenderlog"].is_string()?(bool)atoi(obj["enablesenderlog"].get<std::string>().c_str()):obj["enablesenderlog"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusCanbusConf from_json<ApollocanbusCanbusConf>(nlohmann::json obj){
        return from_json_ApollocanbusCanbusConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCanbusConf &dt)
    {
        dt=from_json_ApollocanbusCanbusConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCanbusConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCanbusConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
