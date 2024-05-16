#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_state_feedback2_c4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleStateFeedback2C4 &msg) {
        nlohmann::json obj;
        obj["motorspeed"] = (msg.motorspeed);
        obj["driventorquefeedback"] = (msg.driventorquefeedback);
        return obj;
    }
    ApollocanbusVehicleStateFeedback2C4 from_json_ApollocanbusVehicleStateFeedback2C4 (nlohmann::json obj) {
        ApollocanbusVehicleStateFeedback2C4 msg;
        if(obj.contains("motorspeed"))
        {
            msg.motorspeed = (obj["motorspeed"].is_string()?atoi(obj["motorspeed"].get<std::string>().c_str()):obj["motorspeed"].get<int>());
        }
        if(obj.contains("driventorquefeedback"))
        {
            msg.driventorquefeedback = (obj["driventorquefeedback"].is_string()?atof(obj["driventorquefeedback"].get<std::string>().c_str()):obj["driventorquefeedback"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehicleStateFeedback2C4 from_json<ApollocanbusVehicleStateFeedback2C4>(nlohmann::json obj){
        return from_json_ApollocanbusVehicleStateFeedback2C4(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleStateFeedback2C4 &dt)
    {
        dt=from_json_ApollocanbusVehicleStateFeedback2C4(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleStateFeedback2C4 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleStateFeedback2C4 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
