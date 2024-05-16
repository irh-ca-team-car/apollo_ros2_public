#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_debug_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappDebugParam &msg) {
        nlohmann::json obj;
        obj["detectionoutdir"] = (msg.detectionoutdir);
        obj["trackeddetectionoutdir"] = (msg.trackeddetectionoutdir);
        obj["trackoutfile"] = (msg.trackoutfile);
        obj["detectfeaturedir"] = (msg.detectfeaturedir);
        obj["laneoutdir"] = (msg.laneoutdir);
        obj["camera2worldoutfile"] = (msg.camera2worldoutfile);
        obj["calibrationoutdir"] = (msg.calibrationoutdir);
        return obj;
    }
    ApolloperceptioncameraappDebugParam from_json_ApolloperceptioncameraappDebugParam (nlohmann::json obj) {
        ApolloperceptioncameraappDebugParam msg;
        if(obj.contains("detectionoutdir"))
        {
            msg.detectionoutdir = (obj["detectionoutdir"].is_string()?(obj["detectionoutdir"].get<std::string>().c_str()):obj["detectionoutdir"].get<std::string>());
        }
        if(obj.contains("trackeddetectionoutdir"))
        {
            msg.trackeddetectionoutdir = (obj["trackeddetectionoutdir"].is_string()?(obj["trackeddetectionoutdir"].get<std::string>().c_str()):obj["trackeddetectionoutdir"].get<std::string>());
        }
        if(obj.contains("trackoutfile"))
        {
            msg.trackoutfile = (obj["trackoutfile"].is_string()?(obj["trackoutfile"].get<std::string>().c_str()):obj["trackoutfile"].get<std::string>());
        }
        if(obj.contains("detectfeaturedir"))
        {
            msg.detectfeaturedir = (obj["detectfeaturedir"].is_string()?(obj["detectfeaturedir"].get<std::string>().c_str()):obj["detectfeaturedir"].get<std::string>());
        }
        if(obj.contains("laneoutdir"))
        {
            msg.laneoutdir = (obj["laneoutdir"].is_string()?(obj["laneoutdir"].get<std::string>().c_str()):obj["laneoutdir"].get<std::string>());
        }
        if(obj.contains("camera2worldoutfile"))
        {
            msg.camera2worldoutfile = (obj["camera2worldoutfile"].is_string()?(obj["camera2worldoutfile"].get<std::string>().c_str()):obj["camera2worldoutfile"].get<std::string>());
        }
        if(obj.contains("calibrationoutdir"))
        {
            msg.calibrationoutdir = (obj["calibrationoutdir"].is_string()?(obj["calibrationoutdir"].get<std::string>().c_str()):obj["calibrationoutdir"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappDebugParam from_json<ApolloperceptioncameraappDebugParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappDebugParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappDebugParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappDebugParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappDebugParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappDebugParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
