#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_state.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleState &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["timestamp"] = (msg.timestamp);
        obj["roll"] = (msg.roll);
        obj["pitch"] = (msg.pitch);
        obj["yaw"] = (msg.yaw);
        obj["heading"] = (msg.heading);
        obj["kappa"] = (msg.kappa);
        obj["linearvelocity"] = (msg.linearvelocity);
        obj["angularvelocity"] = (msg.angularvelocity);
        obj["linearacceleration"] = (msg.linearacceleration);
        obj["gear"] = (msg.gear);
        obj["drivingmode"] = (msg.drivingmode);
        obj["pose"] = to_json(msg.pose);
        obj["steeringpercentage"] = (msg.steeringpercentage);
        return obj;
    }
    ApollocommonVehicleState from_json_ApollocommonVehicleState (nlohmann::json obj) {
        ApollocommonVehicleState msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?atof(obj["x"].get<std::string>().c_str()):obj["x"].get<double>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?atof(obj["y"].get<std::string>().c_str()):obj["y"].get<double>());
        }
        if(obj.contains("z"))
        {
            msg.z = (obj["z"].is_string()?atof(obj["z"].get<std::string>().c_str()):obj["z"].get<double>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("roll"))
        {
            msg.roll = (obj["roll"].is_string()?atof(obj["roll"].get<std::string>().c_str()):obj["roll"].get<double>());
        }
        if(obj.contains("pitch"))
        {
            msg.pitch = (obj["pitch"].is_string()?atof(obj["pitch"].get<std::string>().c_str()):obj["pitch"].get<double>());
        }
        if(obj.contains("yaw"))
        {
            msg.yaw = (obj["yaw"].is_string()?atof(obj["yaw"].get<std::string>().c_str()):obj["yaw"].get<double>());
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("kappa"))
        {
            msg.kappa = (obj["kappa"].is_string()?atof(obj["kappa"].get<std::string>().c_str()):obj["kappa"].get<double>());
        }
        if(obj.contains("linearvelocity"))
        {
            msg.linearvelocity = (obj["linearvelocity"].is_string()?atof(obj["linearvelocity"].get<std::string>().c_str()):obj["linearvelocity"].get<double>());
        }
        if(obj.contains("angularvelocity"))
        {
            msg.angularvelocity = (obj["angularvelocity"].is_string()?atof(obj["angularvelocity"].get<std::string>().c_str()):obj["angularvelocity"].get<double>());
        }
        if(obj.contains("linearacceleration"))
        {
            msg.linearacceleration = (obj["linearacceleration"].is_string()?atof(obj["linearacceleration"].get<std::string>().c_str()):obj["linearacceleration"].get<double>());
        }
        if(obj.contains("gear"))
        {
            msg.gear = (obj["gear"].is_string()?atoi(obj["gear"].get<std::string>().c_str()):obj["gear"].get<int>());
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        if(obj.contains("pose"))
        {
            msg.pose = from_json_ApollolocalizationPose(obj["pose"]);
        }
        if(obj.contains("steeringpercentage"))
        {
            msg.steeringpercentage = (obj["steeringpercentage"].is_string()?atof(obj["steeringpercentage"].get<std::string>().c_str()):obj["steeringpercentage"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonVehicleState from_json<ApollocommonVehicleState>(nlohmann::json obj){
        return from_json_ApollocommonVehicleState(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleState &dt)
    {
        dt=from_json_ApollocommonVehicleState(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleState & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleState & dt)
    {
        os << to_json(dt);
        return os;
    }
}
