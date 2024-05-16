#include "adapter/serialization/apollo_msgs/apollocontrol_control_command.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolControlCommand &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["throttle"] = (msg.throttle);
        obj["brake"] = (msg.brake);
        obj["steeringrate"] = (msg.steeringrate);
        obj["steeringtarget"] = (msg.steeringtarget);
        obj["parkingbrake"] = (msg.parkingbrake);
        obj["speed"] = (msg.speed);
        obj["acceleration"] = (msg.acceleration);
        obj["resetmodel"] = (msg.resetmodel);
        obj["engineonoff"] = (msg.engineonoff);
        obj["trajectoryfraction"] = (msg.trajectoryfraction);
        obj["drivingmode"] = (msg.drivingmode);
        obj["gearlocation"] = (msg.gearlocation);
        obj["debug"] = to_json(msg.debug);
        obj["signal"] = to_json(msg.signal);
        obj["latencystats"] = to_json(msg.latencystats);
        obj["padmsg"] = to_json(msg.padmsg);
        obj["engageadvice"] = to_json(msg.engageadvice);
        obj["isinsafemode"] = (msg.isinsafemode);
        obj["leftturn"] = (msg.leftturn);
        obj["rightturn"] = (msg.rightturn);
        obj["highbeam"] = (msg.highbeam);
        obj["lowbeam"] = (msg.lowbeam);
        obj["horn"] = (msg.horn);
        obj["turnsignal"] = (msg.turnsignal);
        return obj;
    }
    ApollocontrolControlCommand from_json_ApollocontrolControlCommand (nlohmann::json obj) {
        ApollocontrolControlCommand msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("throttle"))
        {
            msg.throttle = (obj["throttle"].is_string()?atof(obj["throttle"].get<std::string>().c_str()):obj["throttle"].get<double>());
        }
        if(obj.contains("brake"))
        {
            msg.brake = (obj["brake"].is_string()?atof(obj["brake"].get<std::string>().c_str()):obj["brake"].get<double>());
        }
        if(obj.contains("steeringrate"))
        {
            msg.steeringrate = (obj["steeringrate"].is_string()?atof(obj["steeringrate"].get<std::string>().c_str()):obj["steeringrate"].get<double>());
        }
        if(obj.contains("steeringtarget"))
        {
            msg.steeringtarget = (obj["steeringtarget"].is_string()?atof(obj["steeringtarget"].get<std::string>().c_str()):obj["steeringtarget"].get<double>());
        }
        if(obj.contains("parkingbrake"))
        {
            msg.parkingbrake = (obj["parkingbrake"].is_string()?(bool)atoi(obj["parkingbrake"].get<std::string>().c_str()):obj["parkingbrake"].get<bool>());
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("acceleration"))
        {
            msg.acceleration = (obj["acceleration"].is_string()?atof(obj["acceleration"].get<std::string>().c_str()):obj["acceleration"].get<double>());
        }
        if(obj.contains("resetmodel"))
        {
            msg.resetmodel = (obj["resetmodel"].is_string()?(bool)atoi(obj["resetmodel"].get<std::string>().c_str()):obj["resetmodel"].get<bool>());
        }
        if(obj.contains("engineonoff"))
        {
            msg.engineonoff = (obj["engineonoff"].is_string()?(bool)atoi(obj["engineonoff"].get<std::string>().c_str()):obj["engineonoff"].get<bool>());
        }
        if(obj.contains("trajectoryfraction"))
        {
            msg.trajectoryfraction = (obj["trajectoryfraction"].is_string()?atof(obj["trajectoryfraction"].get<std::string>().c_str()):obj["trajectoryfraction"].get<double>());
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        if(obj.contains("gearlocation"))
        {
            msg.gearlocation = (obj["gearlocation"].is_string()?atoi(obj["gearlocation"].get<std::string>().c_str()):obj["gearlocation"].get<int>());
        }
        if(obj.contains("debug"))
        {
            msg.debug = from_json_ApollocontrolDebug(obj["debug"]);
        }
        if(obj.contains("signal"))
        {
            msg.signal = from_json_ApollocommonVehicleSignal(obj["signal"]);
        }
        if(obj.contains("latencystats"))
        {
            msg.latencystats = from_json_ApollocontrolLatencyStats(obj["latencystats"]);
        }
        if(obj.contains("padmsg"))
        {
            msg.padmsg = from_json_ApollocontrolPadMessage(obj["padmsg"]);
        }
        if(obj.contains("engageadvice"))
        {
            msg.engageadvice = from_json_ApollocommonEngageAdvice(obj["engageadvice"]);
        }
        if(obj.contains("isinsafemode"))
        {
            msg.isinsafemode = (obj["isinsafemode"].is_string()?(bool)atoi(obj["isinsafemode"].get<std::string>().c_str()):obj["isinsafemode"].get<bool>());
        }
        if(obj.contains("leftturn"))
        {
            msg.leftturn = (obj["leftturn"].is_string()?(bool)atoi(obj["leftturn"].get<std::string>().c_str()):obj["leftturn"].get<bool>());
        }
        if(obj.contains("rightturn"))
        {
            msg.rightturn = (obj["rightturn"].is_string()?(bool)atoi(obj["rightturn"].get<std::string>().c_str()):obj["rightturn"].get<bool>());
        }
        if(obj.contains("highbeam"))
        {
            msg.highbeam = (obj["highbeam"].is_string()?(bool)atoi(obj["highbeam"].get<std::string>().c_str()):obj["highbeam"].get<bool>());
        }
        if(obj.contains("lowbeam"))
        {
            msg.lowbeam = (obj["lowbeam"].is_string()?(bool)atoi(obj["lowbeam"].get<std::string>().c_str()):obj["lowbeam"].get<bool>());
        }
        if(obj.contains("horn"))
        {
            msg.horn = (obj["horn"].is_string()?(bool)atoi(obj["horn"].get<std::string>().c_str()):obj["horn"].get<bool>());
        }
        if(obj.contains("turnsignal"))
        {
            msg.turnsignal = (obj["turnsignal"].is_string()?atoi(obj["turnsignal"].get<std::string>().c_str()):obj["turnsignal"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocontrolControlCommand from_json<ApollocontrolControlCommand>(nlohmann::json obj){
        return from_json_ApollocontrolControlCommand(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolControlCommand &dt)
    {
        dt=from_json_ApollocontrolControlCommand(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolControlCommand & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolControlCommand & dt)
    {
        os << to_json(dt);
        return os;
    }
}
