#include "adapter/serialization/apollo_msgs/gps_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const GPSPose &msg) {
        nlohmann::json obj;
        obj["lat"] = (msg.lat);
        obj["lon"] = (msg.lon);
        obj["bearing"] = (msg.bearing);
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["z"] = (msg.z);
        obj["qw"] = (msg.qw);
        obj["qx"] = (msg.qx);
        obj["qy"] = (msg.qy);
        obj["qz"] = (msg.qz);
        return obj;
    }
    GPSPose from_json_GPSPose (nlohmann::json obj) {
        GPSPose msg;
        if(obj.contains("lat"))
        {
            msg.lat = (obj["lat"].is_string()?atof(obj["lat"].get<std::string>().c_str()):obj["lat"].get<double>());
        }
        if(obj.contains("lon"))
        {
            msg.lon = (obj["lon"].is_string()?atof(obj["lon"].get<std::string>().c_str()):obj["lon"].get<double>());
        }
        if(obj.contains("bearing"))
        {
            msg.bearing = (obj["bearing"].is_string()?atof(obj["bearing"].get<std::string>().c_str()):obj["bearing"].get<double>());
        }
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
        if(obj.contains("qw"))
        {
            msg.qw = (obj["qw"].is_string()?atof(obj["qw"].get<std::string>().c_str()):obj["qw"].get<double>());
        }
        if(obj.contains("qx"))
        {
            msg.qx = (obj["qx"].is_string()?atof(obj["qx"].get<std::string>().c_str()):obj["qx"].get<double>());
        }
        if(obj.contains("qy"))
        {
            msg.qy = (obj["qy"].is_string()?atof(obj["qy"].get<std::string>().c_str()):obj["qy"].get<double>());
        }
        if(obj.contains("qz"))
        {
            msg.qz = (obj["qz"].is_string()?atof(obj["qz"].get<std::string>().c_str()):obj["qz"].get<double>());
        }
        return msg;
    }
    template <>
    GPSPose from_json<GPSPose>(nlohmann::json obj){
        return from_json_GPSPose(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, GPSPose &dt)
    {
        dt=from_json_GPSPose(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const GPSPose & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const GPSPose & dt)
    {
        os << to_json(dt);
        return os;
    }
}
