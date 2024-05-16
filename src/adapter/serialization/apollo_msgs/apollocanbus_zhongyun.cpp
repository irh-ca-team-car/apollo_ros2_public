#include "adapter/serialization/apollo_msgs/apollocanbus_zhongyun.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusZhongyun &msg) {
        nlohmann::json obj;
        obj["gearcontrola1"] = to_json(msg.gearcontrola1);
        obj["torquecontrola3"] = to_json(msg.torquecontrola3);
        obj["steeringcontrola2"] = to_json(msg.steeringcontrola2);
        obj["parkingcontrola5"] = to_json(msg.parkingcontrola5);
        obj["brakecontrola4"] = to_json(msg.brakecontrola4);
        obj["enablestatefeedbackc3"] = to_json(msg.enablestatefeedbackc3);
        obj["vehiclestatefeedbackc1"] = to_json(msg.vehiclestatefeedbackc1);
        obj["errorstatee1"] = to_json(msg.errorstatee1);
        obj["vehiclestatefeedback2c4"] = to_json(msg.vehiclestatefeedback2c4);
        return obj;
    }
    ApollocanbusZhongyun from_json_ApollocanbusZhongyun (nlohmann::json obj) {
        ApollocanbusZhongyun msg;
        if(obj.contains("gearcontrola1"))
        {
            msg.gearcontrola1 = from_json_ApollocanbusGearControlA1(obj["gearcontrola1"]);
        }
        if(obj.contains("torquecontrola3"))
        {
            msg.torquecontrola3 = from_json_ApollocanbusTorqueControlA3(obj["torquecontrola3"]);
        }
        if(obj.contains("steeringcontrola2"))
        {
            msg.steeringcontrola2 = from_json_ApollocanbusSteeringControlA2(obj["steeringcontrola2"]);
        }
        if(obj.contains("parkingcontrola5"))
        {
            msg.parkingcontrola5 = from_json_ApollocanbusParkingControlA5(obj["parkingcontrola5"]);
        }
        if(obj.contains("brakecontrola4"))
        {
            msg.brakecontrola4 = from_json_ApollocanbusBrakeControlA4(obj["brakecontrola4"]);
        }
        if(obj.contains("enablestatefeedbackc3"))
        {
            msg.enablestatefeedbackc3 = from_json_ApollocanbusEnableStateFeedbackC3(obj["enablestatefeedbackc3"]);
        }
        if(obj.contains("vehiclestatefeedbackc1"))
        {
            msg.vehiclestatefeedbackc1 = from_json_ApollocanbusVehicleStateFeedbackC1(obj["vehiclestatefeedbackc1"]);
        }
        if(obj.contains("errorstatee1"))
        {
            msg.errorstatee1 = from_json_ApollocanbusErrorStateE1(obj["errorstatee1"]);
        }
        if(obj.contains("vehiclestatefeedback2c4"))
        {
            msg.vehiclestatefeedback2c4 = from_json_ApollocanbusVehicleStateFeedback2C4(obj["vehiclestatefeedback2c4"]);
        }
        return msg;
    }
    template <>
    ApollocanbusZhongyun from_json<ApollocanbusZhongyun>(nlohmann::json obj){
        return from_json_ApollocanbusZhongyun(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusZhongyun &dt)
    {
        dt=from_json_ApollocanbusZhongyun(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusZhongyun & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusZhongyun & dt)
    {
        os << to_json(dt);
        return os;
    }
}
