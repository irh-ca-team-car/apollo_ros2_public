#include "adapter/serialization/apollo_msgs/apolloperception_camera_valid_dist.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionCameraValidDist &msg) {
        nlohmann::json obj;
        obj["cameraname"] = (msg.cameraname);
        obj["validdist"] = (msg.validdist);
        return obj;
    }
    ApolloperceptionCameraValidDist from_json_ApolloperceptionCameraValidDist (nlohmann::json obj) {
        ApolloperceptionCameraValidDist msg;
        if(obj.contains("cameraname"))
        {
            msg.cameraname = (obj["cameraname"].is_string()?(obj["cameraname"].get<std::string>().c_str()):obj["cameraname"].get<std::string>());
        }
        if(obj.contains("validdist"))
        {
            msg.validdist = (obj["validdist"].is_string()?atof(obj["validdist"].get<std::string>().c_str()):obj["validdist"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionCameraValidDist from_json<ApolloperceptionCameraValidDist>(nlohmann::json obj){
        return from_json_ApolloperceptionCameraValidDist(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionCameraValidDist &dt)
    {
        dt=from_json_ApolloperceptionCameraValidDist(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionCameraValidDist & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionCameraValidDist & dt)
    {
        os << to_json(dt);
        return os;
    }
}
