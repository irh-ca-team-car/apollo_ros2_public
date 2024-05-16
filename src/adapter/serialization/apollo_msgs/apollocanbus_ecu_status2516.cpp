#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status2516.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEcuStatus2516 &msg) {
        nlohmann::json obj;
        obj["batterysoc"] = (msg.batterysoc);
        obj["batterycapacity"] = (msg.batterycapacity);
        obj["batteryvoltage"] = (msg.batteryvoltage);
        obj["batterycurrent"] = (msg.batterycurrent);
        obj["batterytemperature"] = (msg.batterytemperature);
        return obj;
    }
    ApollocanbusEcuStatus2516 from_json_ApollocanbusEcuStatus2516 (nlohmann::json obj) {
        ApollocanbusEcuStatus2516 msg;
        if(obj.contains("batterysoc"))
        {
            msg.batterysoc = (obj["batterysoc"].is_string()?atoi(obj["batterysoc"].get<std::string>().c_str()):obj["batterysoc"].get<int>());
        }
        if(obj.contains("batterycapacity"))
        {
            msg.batterycapacity = (obj["batterycapacity"].is_string()?atoi(obj["batterycapacity"].get<std::string>().c_str()):obj["batterycapacity"].get<int>());
        }
        if(obj.contains("batteryvoltage"))
        {
            msg.batteryvoltage = (obj["batteryvoltage"].is_string()?atof(obj["batteryvoltage"].get<std::string>().c_str()):obj["batteryvoltage"].get<double>());
        }
        if(obj.contains("batterycurrent"))
        {
            msg.batterycurrent = (obj["batterycurrent"].is_string()?atof(obj["batterycurrent"].get<std::string>().c_str()):obj["batterycurrent"].get<double>());
        }
        if(obj.contains("batterytemperature"))
        {
            msg.batterytemperature = (obj["batterytemperature"].is_string()?atoi(obj["batterytemperature"].get<std::string>().c_str()):obj["batterytemperature"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusEcuStatus2516 from_json<ApollocanbusEcuStatus2516>(nlohmann::json obj){
        return from_json_ApollocanbusEcuStatus2516(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEcuStatus2516 &dt)
    {
        dt=from_json_ApollocanbusEcuStatus2516(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEcuStatus2516 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEcuStatus2516 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
