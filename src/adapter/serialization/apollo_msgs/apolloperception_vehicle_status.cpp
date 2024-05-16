#include "adapter/serialization/apollo_msgs/apolloperception_vehicle_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionVehicleStatus &msg) {
        nlohmann::json obj;
        obj["rollrate"] = (msg.rollrate);
        obj["pitchrate"] = (msg.pitchrate);
        obj["yawrate"] = (msg.yawrate);
        obj["velocity"] = (msg.velocity);
        obj["velocityx"] = (msg.velocityx);
        obj["velocityy"] = (msg.velocityy);
        obj["velocityz"] = (msg.velocityz);
        obj["timets"] = (msg.timets);
        obj["timed"] = (msg.timed);
        obj["motion"] = to_json(msg.motion);
        return obj;
    }
    ApolloperceptionVehicleStatus from_json_ApolloperceptionVehicleStatus (nlohmann::json obj) {
        ApolloperceptionVehicleStatus msg;
        if(obj.contains("rollrate"))
        {
            msg.rollrate = (obj["rollrate"].is_string()?(float)atof(obj["rollrate"].get<std::string>().c_str()):obj["rollrate"].get<float>());
        }
        if(obj.contains("pitchrate"))
        {
            msg.pitchrate = (obj["pitchrate"].is_string()?(float)atof(obj["pitchrate"].get<std::string>().c_str()):obj["pitchrate"].get<float>());
        }
        if(obj.contains("yawrate"))
        {
            msg.yawrate = (obj["yawrate"].is_string()?(float)atof(obj["yawrate"].get<std::string>().c_str()):obj["yawrate"].get<float>());
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = (obj["velocity"].is_string()?(float)atof(obj["velocity"].get<std::string>().c_str()):obj["velocity"].get<float>());
        }
        if(obj.contains("velocityx"))
        {
            msg.velocityx = (obj["velocityx"].is_string()?(float)atof(obj["velocityx"].get<std::string>().c_str()):obj["velocityx"].get<float>());
        }
        if(obj.contains("velocityy"))
        {
            msg.velocityy = (obj["velocityy"].is_string()?(float)atof(obj["velocityy"].get<std::string>().c_str()):obj["velocityy"].get<float>());
        }
        if(obj.contains("velocityz"))
        {
            msg.velocityz = (obj["velocityz"].is_string()?(float)atof(obj["velocityz"].get<std::string>().c_str()):obj["velocityz"].get<float>());
        }
        if(obj.contains("timets"))
        {
            msg.timets = (obj["timets"].is_string()?atof(obj["timets"].get<std::string>().c_str()):obj["timets"].get<double>());
        }
        if(obj.contains("timed"))
        {
            msg.timed = (obj["timed"].is_string()?atof(obj["timed"].get<std::string>().c_str()):obj["timed"].get<double>());
        }
        if(obj.contains("motion"))
        {
            msg.motion = from_json_ApolloperceptionMotionType(obj["motion"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionVehicleStatus from_json<ApolloperceptionVehicleStatus>(nlohmann::json obj){
        return from_json_ApolloperceptionVehicleStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionVehicleStatus &dt)
    {
        dt=from_json_ApolloperceptionVehicleStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionVehicleStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionVehicleStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
