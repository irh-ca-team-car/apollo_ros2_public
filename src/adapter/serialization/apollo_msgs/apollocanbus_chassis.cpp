#include "adapter/serialization/apollo_msgs/apollocanbus_chassis.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusChassis &msg) {
        nlohmann::json obj;
        obj["enginestarted"] = (msg.enginestarted);
        obj["enginerpm"] = (msg.enginerpm);
        obj["speedmps"] = (msg.speedmps);
        obj["odometerm"] = (msg.odometerm);
        obj["fuelrangem"] = (msg.fuelrangem);
        obj["throttlepercentage"] = (msg.throttlepercentage);
        obj["brakepercentage"] = (msg.brakepercentage);
        obj["steeringpercentage"] = (msg.steeringpercentage);
        obj["steeringtorquenm"] = (msg.steeringtorquenm);
        obj["parkingbrake"] = (msg.parkingbrake);
        obj["highbeamsignal"] = (msg.highbeamsignal);
        obj["lowbeamsignal"] = (msg.lowbeamsignal);
        obj["leftturnsignal"] = (msg.leftturnsignal);
        obj["rightturnsignal"] = (msg.rightturnsignal);
        obj["horn"] = (msg.horn);
        obj["wiper"] = (msg.wiper);
        obj["disengagestatus"] = (msg.disengagestatus);
        obj["drivingmode"] = (msg.drivingmode);
        obj["errorcode"] = (msg.errorcode);
        obj["gearlocation"] = (msg.gearlocation);
        obj["steeringtimestamp"] = (msg.steeringtimestamp);
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["chassiserrormask"] = (msg.chassiserrormask);
        obj["signal"] = to_json(msg.signal);
        obj["chassisgps"] = to_json(msg.chassisgps);
        obj["engageadvice"] = to_json(msg.engageadvice);
        obj["wheelspeed"] = to_json(msg.wheelspeed);
        obj["surround"] = to_json(msg.surround);
        obj["license"] = to_json(msg.license);
        obj["vehicleid"] = to_json(msg.vehicleid);
        obj["batterysocpercentage"] = (msg.batterysocpercentage);
        return obj;
    }
    ApollocanbusChassis from_json_ApollocanbusChassis (nlohmann::json obj) {
        ApollocanbusChassis msg;
        if(obj.contains("enginestarted"))
        {
            msg.enginestarted = (obj["enginestarted"].is_string()?(bool)atoi(obj["enginestarted"].get<std::string>().c_str()):obj["enginestarted"].get<bool>());
        }
        if(obj.contains("enginerpm"))
        {
            msg.enginerpm = (obj["enginerpm"].is_string()?(float)atof(obj["enginerpm"].get<std::string>().c_str()):obj["enginerpm"].get<float>());
        }
        if(obj.contains("speedmps"))
        {
            msg.speedmps = (obj["speedmps"].is_string()?(float)atof(obj["speedmps"].get<std::string>().c_str()):obj["speedmps"].get<float>());
        }
        if(obj.contains("odometerm"))
        {
            msg.odometerm = (obj["odometerm"].is_string()?(float)atof(obj["odometerm"].get<std::string>().c_str()):obj["odometerm"].get<float>());
        }
        if(obj.contains("fuelrangem"))
        {
            msg.fuelrangem = (obj["fuelrangem"].is_string()?atoi(obj["fuelrangem"].get<std::string>().c_str()):obj["fuelrangem"].get<int>());
        }
        if(obj.contains("throttlepercentage"))
        {
            msg.throttlepercentage = (obj["throttlepercentage"].is_string()?(float)atof(obj["throttlepercentage"].get<std::string>().c_str()):obj["throttlepercentage"].get<float>());
        }
        if(obj.contains("brakepercentage"))
        {
            msg.brakepercentage = (obj["brakepercentage"].is_string()?(float)atof(obj["brakepercentage"].get<std::string>().c_str()):obj["brakepercentage"].get<float>());
        }
        if(obj.contains("steeringpercentage"))
        {
            msg.steeringpercentage = (obj["steeringpercentage"].is_string()?(float)atof(obj["steeringpercentage"].get<std::string>().c_str()):obj["steeringpercentage"].get<float>());
        }
        if(obj.contains("steeringtorquenm"))
        {
            msg.steeringtorquenm = (obj["steeringtorquenm"].is_string()?(float)atof(obj["steeringtorquenm"].get<std::string>().c_str()):obj["steeringtorquenm"].get<float>());
        }
        if(obj.contains("parkingbrake"))
        {
            msg.parkingbrake = (obj["parkingbrake"].is_string()?(bool)atoi(obj["parkingbrake"].get<std::string>().c_str()):obj["parkingbrake"].get<bool>());
        }
        if(obj.contains("highbeamsignal"))
        {
            msg.highbeamsignal = (obj["highbeamsignal"].is_string()?(bool)atoi(obj["highbeamsignal"].get<std::string>().c_str()):obj["highbeamsignal"].get<bool>());
        }
        if(obj.contains("lowbeamsignal"))
        {
            msg.lowbeamsignal = (obj["lowbeamsignal"].is_string()?(bool)atoi(obj["lowbeamsignal"].get<std::string>().c_str()):obj["lowbeamsignal"].get<bool>());
        }
        if(obj.contains("leftturnsignal"))
        {
            msg.leftturnsignal = (obj["leftturnsignal"].is_string()?(bool)atoi(obj["leftturnsignal"].get<std::string>().c_str()):obj["leftturnsignal"].get<bool>());
        }
        if(obj.contains("rightturnsignal"))
        {
            msg.rightturnsignal = (obj["rightturnsignal"].is_string()?(bool)atoi(obj["rightturnsignal"].get<std::string>().c_str()):obj["rightturnsignal"].get<bool>());
        }
        if(obj.contains("horn"))
        {
            msg.horn = (obj["horn"].is_string()?(bool)atoi(obj["horn"].get<std::string>().c_str()):obj["horn"].get<bool>());
        }
        if(obj.contains("wiper"))
        {
            msg.wiper = (obj["wiper"].is_string()?(bool)atoi(obj["wiper"].get<std::string>().c_str()):obj["wiper"].get<bool>());
        }
        if(obj.contains("disengagestatus"))
        {
            msg.disengagestatus = (obj["disengagestatus"].is_string()?(bool)atoi(obj["disengagestatus"].get<std::string>().c_str()):obj["disengagestatus"].get<bool>());
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        if(obj.contains("errorcode"))
        {
            msg.errorcode = (obj["errorcode"].is_string()?atoi(obj["errorcode"].get<std::string>().c_str()):obj["errorcode"].get<int>());
        }
        if(obj.contains("gearlocation"))
        {
            msg.gearlocation = (obj["gearlocation"].is_string()?atoi(obj["gearlocation"].get<std::string>().c_str()):obj["gearlocation"].get<int>());
        }
        if(obj.contains("steeringtimestamp"))
        {
            msg.steeringtimestamp = (obj["steeringtimestamp"].is_string()?atof(obj["steeringtimestamp"].get<std::string>().c_str()):obj["steeringtimestamp"].get<double>());
        }
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("chassiserrormask"))
        {
            msg.chassiserrormask = (obj["chassiserrormask"].is_string()?atoi(obj["chassiserrormask"].get<std::string>().c_str()):obj["chassiserrormask"].get<int>());
        }
        if(obj.contains("signal"))
        {
            msg.signal = from_json_ApollocommonVehicleSignal(obj["signal"]);
        }
        if(obj.contains("chassisgps"))
        {
            msg.chassisgps = from_json_ApollocanbusChassisGPS(obj["chassisgps"]);
        }
        if(obj.contains("engageadvice"))
        {
            msg.engageadvice = from_json_ApollocommonEngageAdvice(obj["engageadvice"]);
        }
        if(obj.contains("wheelspeed"))
        {
            msg.wheelspeed = from_json_ApollocanbusWheelSpeed(obj["wheelspeed"]);
        }
        if(obj.contains("surround"))
        {
            msg.surround = from_json_ApollocanbusSurround(obj["surround"]);
        }
        if(obj.contains("license"))
        {
            msg.license = from_json_ApollocanbusLicense(obj["license"]);
        }
        if(obj.contains("vehicleid"))
        {
            msg.vehicleid = from_json_ApollocommonVehicleID(obj["vehicleid"]);
        }
        if(obj.contains("batterysocpercentage"))
        {
            msg.batterysocpercentage = (obj["batterysocpercentage"].is_string()?atoi(obj["batterysocpercentage"].get<std::string>().c_str()):obj["batterysocpercentage"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusChassis from_json<ApollocanbusChassis>(nlohmann::json obj){
        return from_json_ApollocanbusChassis(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusChassis &dt)
    {
        dt=from_json_ApollocanbusChassis(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusChassis & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusChassis & dt)
    {
        os << to_json(dt);
        return os;
    }
}
