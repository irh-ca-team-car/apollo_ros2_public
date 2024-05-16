#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_state_feedback_c1.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleStateFeedbackC1 &msg) {
        nlohmann::json obj;
        obj["parkingactual"] = (msg.parkingactual);
        obj["braketorquefeedback"] = (msg.braketorquefeedback);
        obj["gearstateactual"] = (msg.gearstateactual);
        obj["steeringactual"] = (msg.steeringactual);
        obj["speed"] = (msg.speed);
        return obj;
    }
    ApollocanbusVehicleStateFeedbackC1 from_json_ApollocanbusVehicleStateFeedbackC1 (nlohmann::json obj) {
        ApollocanbusVehicleStateFeedbackC1 msg;
        if(obj.contains("parkingactual"))
        {
            msg.parkingactual = (obj["parkingactual"].is_string()?atoi(obj["parkingactual"].get<std::string>().c_str()):obj["parkingactual"].get<int>());
        }
        if(obj.contains("braketorquefeedback"))
        {
            msg.braketorquefeedback = (obj["braketorquefeedback"].is_string()?atof(obj["braketorquefeedback"].get<std::string>().c_str()):obj["braketorquefeedback"].get<double>());
        }
        if(obj.contains("gearstateactual"))
        {
            msg.gearstateactual = (obj["gearstateactual"].is_string()?atoi(obj["gearstateactual"].get<std::string>().c_str()):obj["gearstateactual"].get<int>());
        }
        if(obj.contains("steeringactual"))
        {
            msg.steeringactual = (obj["steeringactual"].is_string()?atof(obj["steeringactual"].get<std::string>().c_str()):obj["steeringactual"].get<double>());
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehicleStateFeedbackC1 from_json<ApollocanbusVehicleStateFeedbackC1>(nlohmann::json obj){
        return from_json_ApollocanbusVehicleStateFeedbackC1(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleStateFeedbackC1 &dt)
    {
        dt=from_json_ApollocanbusVehicleStateFeedbackC1(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleStateFeedbackC1 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleStateFeedbackC1 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
