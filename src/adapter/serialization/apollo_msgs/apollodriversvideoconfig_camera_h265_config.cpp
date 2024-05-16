#include "adapter/serialization/apollo_msgs/apollodriversvideoconfig_camera_h265_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvideoconfigCameraH265Config &msg) {
        nlohmann::json obj;
        obj["udpport"] = (msg.udpport);
        obj["frameid"] = (msg.frameid);
        obj["pixelformat"] = (msg.pixelformat);
        obj["record"] = (msg.record);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["framerate"] = (msg.framerate);
        obj["monochrome"] = (msg.monochrome);
        obj["brightness"] = (msg.brightness);
        obj["contrast"] = (msg.contrast);
        obj["saturation"] = (msg.saturation);
        obj["sharpness"] = (msg.sharpness);
        obj["gain"] = (msg.gain);
        obj["autofocus"] = (msg.autofocus);
        obj["focus"] = (msg.focus);
        obj["autoexposure"] = (msg.autoexposure);
        obj["exposure"] = (msg.exposure);
        obj["autowhitebalance"] = (msg.autowhitebalance);
        obj["whitebalance"] = (msg.whitebalance);
        obj["bytesperpixel"] = (msg.bytesperpixel);
        obj["triggerparam"] = (msg.triggerparam);
        obj["metricerrorcode"] = (msg.metricerrorcode);
        obj["fpgadevnumber"] = (msg.fpgadevnumber);
        obj["cameraseqnumber"] = (msg.cameraseqnumber);
        obj["compressconf"] = (msg.compressconf);
        return obj;
    }
    ApollodriversvideoconfigCameraH265Config from_json_ApollodriversvideoconfigCameraH265Config (nlohmann::json obj) {
        ApollodriversvideoconfigCameraH265Config msg;
        if(obj.contains("udpport"))
        {
            msg.udpport = (obj["udpport"].is_string()?atoi(obj["udpport"].get<std::string>().c_str()):obj["udpport"].get<uint32_t>());
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("pixelformat"))
        {
            msg.pixelformat = (obj["pixelformat"].is_string()?(obj["pixelformat"].get<std::string>().c_str()):obj["pixelformat"].get<std::string>());
        }
        if(obj.contains("record"))
        {
            msg.record = (obj["record"].is_string()?atoi(obj["record"].get<std::string>().c_str()):obj["record"].get<uint32_t>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>());
        }
        if(obj.contains("framerate"))
        {
            msg.framerate = (obj["framerate"].is_string()?atoi(obj["framerate"].get<std::string>().c_str()):obj["framerate"].get<uint32_t>());
        }
        if(obj.contains("monochrome"))
        {
            msg.monochrome = (obj["monochrome"].is_string()?(bool)atoi(obj["monochrome"].get<std::string>().c_str()):obj["monochrome"].get<bool>());
        }
        if(obj.contains("brightness"))
        {
            msg.brightness = (obj["brightness"].is_string()?atoi(obj["brightness"].get<std::string>().c_str()):obj["brightness"].get<int>());
        }
        if(obj.contains("contrast"))
        {
            msg.contrast = (obj["contrast"].is_string()?atoi(obj["contrast"].get<std::string>().c_str()):obj["contrast"].get<int>());
        }
        if(obj.contains("saturation"))
        {
            msg.saturation = (obj["saturation"].is_string()?atoi(obj["saturation"].get<std::string>().c_str()):obj["saturation"].get<int>());
        }
        if(obj.contains("sharpness"))
        {
            msg.sharpness = (obj["sharpness"].is_string()?atoi(obj["sharpness"].get<std::string>().c_str()):obj["sharpness"].get<int>());
        }
        if(obj.contains("gain"))
        {
            msg.gain = (obj["gain"].is_string()?atoi(obj["gain"].get<std::string>().c_str()):obj["gain"].get<int>());
        }
        if(obj.contains("autofocus"))
        {
            msg.autofocus = (obj["autofocus"].is_string()?(bool)atoi(obj["autofocus"].get<std::string>().c_str()):obj["autofocus"].get<bool>());
        }
        if(obj.contains("focus"))
        {
            msg.focus = (obj["focus"].is_string()?atoi(obj["focus"].get<std::string>().c_str()):obj["focus"].get<int>());
        }
        if(obj.contains("autoexposure"))
        {
            msg.autoexposure = (obj["autoexposure"].is_string()?(bool)atoi(obj["autoexposure"].get<std::string>().c_str()):obj["autoexposure"].get<bool>());
        }
        if(obj.contains("exposure"))
        {
            msg.exposure = (obj["exposure"].is_string()?atoi(obj["exposure"].get<std::string>().c_str()):obj["exposure"].get<int>());
        }
        if(obj.contains("autowhitebalance"))
        {
            msg.autowhitebalance = (obj["autowhitebalance"].is_string()?(bool)atoi(obj["autowhitebalance"].get<std::string>().c_str()):obj["autowhitebalance"].get<bool>());
        }
        if(obj.contains("whitebalance"))
        {
            msg.whitebalance = (obj["whitebalance"].is_string()?atoi(obj["whitebalance"].get<std::string>().c_str()):obj["whitebalance"].get<int>());
        }
        if(obj.contains("bytesperpixel"))
        {
            msg.bytesperpixel = (obj["bytesperpixel"].is_string()?atoi(obj["bytesperpixel"].get<std::string>().c_str()):obj["bytesperpixel"].get<uint32_t>());
        }
        if(obj.contains("triggerparam"))
        {
            msg.triggerparam = (obj["triggerparam"].is_string()?(obj["triggerparam"].get<std::string>().c_str()):obj["triggerparam"].get<std::string>());
        }
        if(obj.contains("metricerrorcode"))
        {
            msg.metricerrorcode = (obj["metricerrorcode"].is_string()?atoi(obj["metricerrorcode"].get<std::string>().c_str()):obj["metricerrorcode"].get<uint32_t>());
        }
        if(obj.contains("fpgadevnumber"))
        {
            msg.fpgadevnumber = (obj["fpgadevnumber"].is_string()?atoi(obj["fpgadevnumber"].get<std::string>().c_str()):obj["fpgadevnumber"].get<int>());
        }
        if(obj.contains("cameraseqnumber"))
        {
            msg.cameraseqnumber = (obj["cameraseqnumber"].is_string()?atoi(obj["cameraseqnumber"].get<std::string>().c_str()):obj["cameraseqnumber"].get<int>());
        }
        if(obj.contains("compressconf"))
        {
            msg.compressconf = (obj["compressconf"].is_string()?atoi(obj["compressconf"].get<std::string>().c_str()):obj["compressconf"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversvideoconfigCameraH265Config from_json<ApollodriversvideoconfigCameraH265Config>(nlohmann::json obj){
        return from_json_ApollodriversvideoconfigCameraH265Config(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvideoconfigCameraH265Config &dt)
    {
        dt=from_json_ApollodriversvideoconfigCameraH265Config(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvideoconfigCameraH265Config & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvideoconfigCameraH265Config & dt)
    {
        os << to_json(dt);
        return os;
    }
}
