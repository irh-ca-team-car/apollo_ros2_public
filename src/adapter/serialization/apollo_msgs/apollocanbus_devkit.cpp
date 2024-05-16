#include "adapter/serialization/apollo_msgs/apollocanbus_devkit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDevkit &msg) {
        nlohmann::json obj;
        obj["throttlecommand100"] = to_json(msg.throttlecommand100);
        obj["brakecommand101"] = to_json(msg.brakecommand101);
        obj["steeringcommand102"] = to_json(msg.steeringcommand102);
        obj["gearcommand103"] = to_json(msg.gearcommand103);
        obj["parkcommand104"] = to_json(msg.parkcommand104);
        obj["throttlereport500"] = to_json(msg.throttlereport500);
        obj["brakereport501"] = to_json(msg.brakereport501);
        obj["steeringreport502"] = to_json(msg.steeringreport502);
        obj["gearreport503"] = to_json(msg.gearreport503);
        obj["parkreport504"] = to_json(msg.parkreport504);
        obj["vcureport505"] = to_json(msg.vcureport505);
        obj["wheelspeedreport506"] = to_json(msg.wheelspeedreport506);
        obj["ultrsensor1507"] = to_json(msg.ultrsensor1507);
        obj["ultrsensor2508"] = to_json(msg.ultrsensor2508);
        obj["ultrsensor3509"] = to_json(msg.ultrsensor3509);
        obj["ultrsensor4510"] = to_json(msg.ultrsensor4510);
        obj["ultrsensor5511"] = to_json(msg.ultrsensor5511);
        obj["bmsreport512"] = to_json(msg.bmsreport512);
        return obj;
    }
    ApollocanbusDevkit from_json_ApollocanbusDevkit (nlohmann::json obj) {
        ApollocanbusDevkit msg;
        if(obj.contains("throttlecommand100"))
        {
            msg.throttlecommand100 = from_json_ApollocanbusThrottleCommand100(obj["throttlecommand100"]);
        }
        if(obj.contains("brakecommand101"))
        {
            msg.brakecommand101 = from_json_ApollocanbusBrakeCommand101(obj["brakecommand101"]);
        }
        if(obj.contains("steeringcommand102"))
        {
            msg.steeringcommand102 = from_json_ApollocanbusSteeringCommand102(obj["steeringcommand102"]);
        }
        if(obj.contains("gearcommand103"))
        {
            msg.gearcommand103 = from_json_ApollocanbusGearCommand103(obj["gearcommand103"]);
        }
        if(obj.contains("parkcommand104"))
        {
            msg.parkcommand104 = from_json_ApollocanbusParkCommand104(obj["parkcommand104"]);
        }
        if(obj.contains("throttlereport500"))
        {
            msg.throttlereport500 = from_json_ApollocanbusThrottleReport500(obj["throttlereport500"]);
        }
        if(obj.contains("brakereport501"))
        {
            msg.brakereport501 = from_json_ApollocanbusBrakeReport501(obj["brakereport501"]);
        }
        if(obj.contains("steeringreport502"))
        {
            msg.steeringreport502 = from_json_ApollocanbusSteeringReport502(obj["steeringreport502"]);
        }
        if(obj.contains("gearreport503"))
        {
            msg.gearreport503 = from_json_ApollocanbusGearReport503(obj["gearreport503"]);
        }
        if(obj.contains("parkreport504"))
        {
            msg.parkreport504 = from_json_ApollocanbusParkReport504(obj["parkreport504"]);
        }
        if(obj.contains("vcureport505"))
        {
            msg.vcureport505 = from_json_ApollocanbusVcuReport505(obj["vcureport505"]);
        }
        if(obj.contains("wheelspeedreport506"))
        {
            msg.wheelspeedreport506 = from_json_ApollocanbusWheelspeedReport506(obj["wheelspeedreport506"]);
        }
        if(obj.contains("ultrsensor1507"))
        {
            msg.ultrsensor1507 = from_json_ApollocanbusUltrSensor1507(obj["ultrsensor1507"]);
        }
        if(obj.contains("ultrsensor2508"))
        {
            msg.ultrsensor2508 = from_json_ApollocanbusUltrSensor2508(obj["ultrsensor2508"]);
        }
        if(obj.contains("ultrsensor3509"))
        {
            msg.ultrsensor3509 = from_json_ApollocanbusUltrSensor3509(obj["ultrsensor3509"]);
        }
        if(obj.contains("ultrsensor4510"))
        {
            msg.ultrsensor4510 = from_json_ApollocanbusUltrSensor4510(obj["ultrsensor4510"]);
        }
        if(obj.contains("ultrsensor5511"))
        {
            msg.ultrsensor5511 = from_json_ApollocanbusUltrSensor5511(obj["ultrsensor5511"]);
        }
        if(obj.contains("bmsreport512"))
        {
            msg.bmsreport512 = from_json_ApollocanbusBmsReport512(obj["bmsreport512"]);
        }
        return msg;
    }
    template <>
    ApollocanbusDevkit from_json<ApollocanbusDevkit>(nlohmann::json obj){
        return from_json_ApollocanbusDevkit(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDevkit &dt)
    {
        dt=from_json_ApollocanbusDevkit(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDevkit & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDevkit & dt)
    {
        os << to_json(dt);
        return os;
    }
}
