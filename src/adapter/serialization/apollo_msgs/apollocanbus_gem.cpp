#include "adapter/serialization/apollo_msgs/apollocanbus_gem.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGem &msg) {
        nlohmann::json obj;
        obj["globalrpt6a"] = to_json(msg.globalrpt6a);
        obj["brakecmd6b"] = to_json(msg.brakecmd6b);
        obj["brakerpt6c"] = to_json(msg.brakerpt6c);
        obj["steeringcmd6d"] = to_json(msg.steeringcmd6d);
        obj["steeringrpt16e"] = to_json(msg.steeringrpt16e);
        obj["wheelspeedrpt7a"] = to_json(msg.wheelspeedrpt7a);
        obj["datetimerpt83"] = to_json(msg.datetimerpt83);
        obj["brakemotorrpt170"] = to_json(msg.brakemotorrpt170);
        obj["headlightrpt77"] = to_json(msg.headlightrpt77);
        obj["accelrpt68"] = to_json(msg.accelrpt68);
        obj["steeringmotorrpt375"] = to_json(msg.steeringmotorrpt375);
        obj["turncmd63"] = to_json(msg.turncmd63);
        obj["turnrpt64"] = to_json(msg.turnrpt64);
        obj["shiftcmd65"] = to_json(msg.shiftcmd65);
        obj["shiftrpt66"] = to_json(msg.shiftrpt66);
        obj["accelcmd67"] = to_json(msg.accelcmd67);
        obj["latlonheadingrpt82"] = to_json(msg.latlonheadingrpt82);
        obj["globalcmd69"] = to_json(msg.globalcmd69);
        obj["parkingbrakestatusrpt80"] = to_json(msg.parkingbrakestatusrpt80);
        obj["yawraterpt81"] = to_json(msg.yawraterpt81);
        obj["hornrpt79"] = to_json(msg.hornrpt79);
        obj["horncmd78"] = to_json(msg.horncmd78);
        obj["wiperrpt91"] = to_json(msg.wiperrpt91);
        obj["vehiclespeedrpt6f"] = to_json(msg.vehiclespeedrpt6f);
        obj["headlightcmd76"] = to_json(msg.headlightcmd76);
        obj["steeringmotorrpt274"] = to_json(msg.steeringmotorrpt274);
        obj["brakemotorrpt271"] = to_json(msg.brakemotorrpt271);
        obj["steeringmotorrpt173"] = to_json(msg.steeringmotorrpt173);
        obj["wipercmd90"] = to_json(msg.wipercmd90);
        obj["brakemotorrpt372"] = to_json(msg.brakemotorrpt372);
        return obj;
    }
    ApollocanbusGem from_json_ApollocanbusGem (nlohmann::json obj) {
        ApollocanbusGem msg;
        if(obj.contains("globalrpt6a"))
        {
            msg.globalrpt6a = from_json_ApollocanbusGlobalRpt6a(obj["globalrpt6a"]);
        }
        if(obj.contains("brakecmd6b"))
        {
            msg.brakecmd6b = from_json_ApollocanbusBrakeCmd6b(obj["brakecmd6b"]);
        }
        if(obj.contains("brakerpt6c"))
        {
            msg.brakerpt6c = from_json_ApollocanbusBrakeRpt6c(obj["brakerpt6c"]);
        }
        if(obj.contains("steeringcmd6d"))
        {
            msg.steeringcmd6d = from_json_ApollocanbusSteeringCmd6d(obj["steeringcmd6d"]);
        }
        if(obj.contains("steeringrpt16e"))
        {
            msg.steeringrpt16e = from_json_ApollocanbusSteeringRpt16e(obj["steeringrpt16e"]);
        }
        if(obj.contains("wheelspeedrpt7a"))
        {
            msg.wheelspeedrpt7a = from_json_ApollocanbusWheelSpeedRpt7a(obj["wheelspeedrpt7a"]);
        }
        if(obj.contains("datetimerpt83"))
        {
            msg.datetimerpt83 = from_json_ApollocanbusDateTimeRpt83(obj["datetimerpt83"]);
        }
        if(obj.contains("brakemotorrpt170"))
        {
            msg.brakemotorrpt170 = from_json_ApollocanbusBrakeMotorRpt170(obj["brakemotorrpt170"]);
        }
        if(obj.contains("headlightrpt77"))
        {
            msg.headlightrpt77 = from_json_ApollocanbusHeadlightRpt77(obj["headlightrpt77"]);
        }
        if(obj.contains("accelrpt68"))
        {
            msg.accelrpt68 = from_json_ApollocanbusAccelRpt68(obj["accelrpt68"]);
        }
        if(obj.contains("steeringmotorrpt375"))
        {
            msg.steeringmotorrpt375 = from_json_ApollocanbusSteeringMotorRpt375(obj["steeringmotorrpt375"]);
        }
        if(obj.contains("turncmd63"))
        {
            msg.turncmd63 = from_json_ApollocanbusTurnCmd63(obj["turncmd63"]);
        }
        if(obj.contains("turnrpt64"))
        {
            msg.turnrpt64 = from_json_ApollocanbusTurnRpt64(obj["turnrpt64"]);
        }
        if(obj.contains("shiftcmd65"))
        {
            msg.shiftcmd65 = from_json_ApollocanbusShiftCmd65(obj["shiftcmd65"]);
        }
        if(obj.contains("shiftrpt66"))
        {
            msg.shiftrpt66 = from_json_ApollocanbusShiftRpt66(obj["shiftrpt66"]);
        }
        if(obj.contains("accelcmd67"))
        {
            msg.accelcmd67 = from_json_ApollocanbusAccelCmd67(obj["accelcmd67"]);
        }
        if(obj.contains("latlonheadingrpt82"))
        {
            msg.latlonheadingrpt82 = from_json_ApollocanbusLatLonHeadingRpt82(obj["latlonheadingrpt82"]);
        }
        if(obj.contains("globalcmd69"))
        {
            msg.globalcmd69 = from_json_ApollocanbusGlobalCmd69(obj["globalcmd69"]);
        }
        if(obj.contains("parkingbrakestatusrpt80"))
        {
            msg.parkingbrakestatusrpt80 = from_json_ApollocanbusParkingBrakeStatusRpt80(obj["parkingbrakestatusrpt80"]);
        }
        if(obj.contains("yawraterpt81"))
        {
            msg.yawraterpt81 = from_json_ApollocanbusYawRateRpt81(obj["yawraterpt81"]);
        }
        if(obj.contains("hornrpt79"))
        {
            msg.hornrpt79 = from_json_ApollocanbusHornRpt79(obj["hornrpt79"]);
        }
        if(obj.contains("horncmd78"))
        {
            msg.horncmd78 = from_json_ApollocanbusHornCmd78(obj["horncmd78"]);
        }
        if(obj.contains("wiperrpt91"))
        {
            msg.wiperrpt91 = from_json_ApollocanbusWiperRpt91(obj["wiperrpt91"]);
        }
        if(obj.contains("vehiclespeedrpt6f"))
        {
            msg.vehiclespeedrpt6f = from_json_ApollocanbusVehicleSpeedRpt6f(obj["vehiclespeedrpt6f"]);
        }
        if(obj.contains("headlightcmd76"))
        {
            msg.headlightcmd76 = from_json_ApollocanbusHeadlightCmd76(obj["headlightcmd76"]);
        }
        if(obj.contains("steeringmotorrpt274"))
        {
            msg.steeringmotorrpt274 = from_json_ApollocanbusSteeringMotorRpt274(obj["steeringmotorrpt274"]);
        }
        if(obj.contains("brakemotorrpt271"))
        {
            msg.brakemotorrpt271 = from_json_ApollocanbusBrakeMotorRpt271(obj["brakemotorrpt271"]);
        }
        if(obj.contains("steeringmotorrpt173"))
        {
            msg.steeringmotorrpt173 = from_json_ApollocanbusSteeringMotorRpt173(obj["steeringmotorrpt173"]);
        }
        if(obj.contains("wipercmd90"))
        {
            msg.wipercmd90 = from_json_ApollocanbusWiperCmd90(obj["wipercmd90"]);
        }
        if(obj.contains("brakemotorrpt372"))
        {
            msg.brakemotorrpt372 = from_json_ApollocanbusBrakeMotorRpt372(obj["brakemotorrpt372"]);
        }
        return msg;
    }
    template <>
    ApollocanbusGem from_json<ApollocanbusGem>(nlohmann::json obj){
        return from_json_ApollocanbusGem(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGem &dt)
    {
        dt=from_json_ApollocanbusGem(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGem & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGem & dt)
    {
        os << to_json(dt);
        return os;
    }
}
