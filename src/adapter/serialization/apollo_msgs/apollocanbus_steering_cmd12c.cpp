#include "adapter/serialization/apollo_msgs/apollocanbus_steering_cmd12c.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringCmd12c &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["position"] = (msg.position);
        obj["rotationrate"] = (msg.rotationrate);
        return obj;
    }
    ApollocanbusSteeringCmd12c from_json_ApollocanbusSteeringCmd12c (nlohmann::json obj) {
        ApollocanbusSteeringCmd12c msg;
        if(obj.contains("ignoreoverrides"))
        {
            msg.ignoreoverrides = (obj["ignoreoverrides"].is_string()?(bool)atoi(obj["ignoreoverrides"].get<std::string>().c_str()):obj["ignoreoverrides"].get<bool>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?(bool)atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        if(obj.contains("position"))
        {
            msg.position = (obj["position"].is_string()?atof(obj["position"].get<std::string>().c_str()):obj["position"].get<double>());
        }
        if(obj.contains("rotationrate"))
        {
            msg.rotationrate = (obj["rotationrate"].is_string()?atof(obj["rotationrate"].get<std::string>().c_str()):obj["rotationrate"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringCmd12c from_json<ApollocanbusSteeringCmd12c>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringCmd12c(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringCmd12c &dt)
    {
        dt=from_json_ApollocanbusSteeringCmd12c(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringCmd12c & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringCmd12c & dt)
    {
        os << to_json(dt);
        return os;
    }
}
