#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_calibrator.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraCalibrator &msg) {
        nlohmann::json obj;
        obj["pitchangle"] = (msg.pitchangle);
        obj["cameraheight"] = (msg.cameraheight);
        return obj;
    }
    ApolloperceptioncameraCameraCalibrator from_json_ApolloperceptioncameraCameraCalibrator (nlohmann::json obj) {
        ApolloperceptioncameraCameraCalibrator msg;
        if(obj.contains("pitchangle"))
        {
            msg.pitchangle = (obj["pitchangle"].is_string()?(float)atof(obj["pitchangle"].get<std::string>().c_str()):obj["pitchangle"].get<float>());
        }
        if(obj.contains("cameraheight"))
        {
            msg.cameraheight = (obj["cameraheight"].is_string()?(float)atof(obj["cameraheight"].get<std::string>().c_str()):obj["cameraheight"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraCameraCalibrator from_json<ApolloperceptioncameraCameraCalibrator>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraCameraCalibrator(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraCalibrator &dt)
    {
        dt=from_json_ApolloperceptioncameraCameraCalibrator(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraCalibrator & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraCalibrator & dt)
    {
        os << to_json(dt);
        return os;
    }
}
