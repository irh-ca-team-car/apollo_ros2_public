#include "adapter/serialization/apollo_msgs/camera_image.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const CameraImage &msg) {
        nlohmann::json obj;
        obj["timestamp"] = (msg.timestamp);
        obj["imageurl"] = (msg.imageurl);
        obj["position"] = to_json(msg.position);
        obj["heading"] = to_json(msg.heading);
        obj["fx"] = (msg.fx);
        obj["fy"] = (msg.fy);
        obj["cx"] = (msg.cx);
        obj["cy"] = (msg.cy);
        obj["skew"] = (msg.skew);
        obj["k1"] = (msg.k1);
        obj["k2"] = (msg.k2);
        obj["k3"] = (msg.k3);
        obj["p1"] = (msg.p1);
        obj["p2"] = (msg.p2);
        obj["channel"] = (msg.channel);
        return obj;
    }
    CameraImage from_json_CameraImage (nlohmann::json obj) {
        CameraImage msg;
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("imageurl"))
        {
            msg.imageurl = (obj["imageurl"].is_string()?(obj["imageurl"].get<std::string>().c_str()):obj["imageurl"].get<std::string>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_Vector3(obj["position"]);
        }
        if(obj.contains("heading"))
        {
            msg.heading = from_json_Quaternion(obj["heading"]);
        }
        if(obj.contains("fx"))
        {
            msg.fx = (obj["fx"].is_string()?atof(obj["fx"].get<std::string>().c_str()):obj["fx"].get<double>());
        }
        if(obj.contains("fy"))
        {
            msg.fy = (obj["fy"].is_string()?atof(obj["fy"].get<std::string>().c_str()):obj["fy"].get<double>());
        }
        if(obj.contains("cx"))
        {
            msg.cx = (obj["cx"].is_string()?atof(obj["cx"].get<std::string>().c_str()):obj["cx"].get<double>());
        }
        if(obj.contains("cy"))
        {
            msg.cy = (obj["cy"].is_string()?atof(obj["cy"].get<std::string>().c_str()):obj["cy"].get<double>());
        }
        if(obj.contains("skew"))
        {
            msg.skew = (obj["skew"].is_string()?atof(obj["skew"].get<std::string>().c_str()):obj["skew"].get<double>());
        }
        if(obj.contains("k1"))
        {
            msg.k1 = (obj["k1"].is_string()?atof(obj["k1"].get<std::string>().c_str()):obj["k1"].get<double>());
        }
        if(obj.contains("k2"))
        {
            msg.k2 = (obj["k2"].is_string()?atof(obj["k2"].get<std::string>().c_str()):obj["k2"].get<double>());
        }
        if(obj.contains("k3"))
        {
            msg.k3 = (obj["k3"].is_string()?atof(obj["k3"].get<std::string>().c_str()):obj["k3"].get<double>());
        }
        if(obj.contains("p1"))
        {
            msg.p1 = (obj["p1"].is_string()?atof(obj["p1"].get<std::string>().c_str()):obj["p1"].get<double>());
        }
        if(obj.contains("p2"))
        {
            msg.p2 = (obj["p2"].is_string()?atof(obj["p2"].get<std::string>().c_str()):obj["p2"].get<double>());
        }
        if(obj.contains("channel"))
        {
            msg.channel = (obj["channel"].is_string()?(obj["channel"].get<std::string>().c_str()):obj["channel"].get<std::string>());
        }
        return msg;
    }
    template <>
    CameraImage from_json<CameraImage>(nlohmann::json obj){
        return from_json_CameraImage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, CameraImage &dt)
    {
        dt=from_json_CameraImage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const CameraImage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const CameraImage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
