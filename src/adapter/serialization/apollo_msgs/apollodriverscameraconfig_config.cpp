#include "adapter/serialization/apollo_msgs/apollodriverscameraconfig_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscameraconfigConfig &msg) {
        nlohmann::json obj;
        obj["cameradev"] = (msg.cameradev);
        obj["frameid"] = (msg.frameid);
        obj["pixelformat"] = (msg.pixelformat);
        obj["iomethod"] = (msg.iomethod);
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
        obj["triggerinternal"] = (msg.triggerinternal);
        obj["triggerfps"] = (msg.triggerfps);
        obj["channelname"] = (msg.channelname);
        obj["devicewaitms"] = (msg.devicewaitms);
        obj["spinrate"] = (msg.spinrate);
        obj["outputtype"] = (msg.outputtype);
        obj["compressconf"] = (msg.compressconf);
        return obj;
    }
    ApollodriverscameraconfigConfig from_json_ApollodriverscameraconfigConfig (nlohmann::json obj) {
        ApollodriverscameraconfigConfig msg;
        if(obj.contains("cameradev"))
        {
            msg.cameradev = (obj["cameradev"].is_string()?(obj["cameradev"].get<std::string>().c_str()):obj["cameradev"].get<std::string>());
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("pixelformat"))
        {
            msg.pixelformat = (obj["pixelformat"].is_string()?(obj["pixelformat"].get<std::string>().c_str()):obj["pixelformat"].get<std::string>());
        }
        if(obj.contains("iomethod"))
        {
            msg.iomethod = (obj["iomethod"].is_string()?atoi(obj["iomethod"].get<std::string>().c_str()):obj["iomethod"].get<int>());
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
        if(obj.contains("triggerinternal"))
        {
            msg.triggerinternal = (obj["triggerinternal"].is_string()?atoi(obj["triggerinternal"].get<std::string>().c_str()):obj["triggerinternal"].get<uint32_t>());
        }
        if(obj.contains("triggerfps"))
        {
            msg.triggerfps = (obj["triggerfps"].is_string()?atoi(obj["triggerfps"].get<std::string>().c_str()):obj["triggerfps"].get<uint32_t>());
        }
        if(obj.contains("channelname"))
        {
            msg.channelname = (obj["channelname"].is_string()?(obj["channelname"].get<std::string>().c_str()):obj["channelname"].get<std::string>());
        }
        if(obj.contains("devicewaitms"))
        {
            msg.devicewaitms = (obj["devicewaitms"].is_string()?atoi(obj["devicewaitms"].get<std::string>().c_str()):obj["devicewaitms"].get<uint32_t>());
        }
        if(obj.contains("spinrate"))
        {
            msg.spinrate = (obj["spinrate"].is_string()?atoi(obj["spinrate"].get<std::string>().c_str()):obj["spinrate"].get<uint32_t>());
        }
        if(obj.contains("outputtype"))
        {
            msg.outputtype = (obj["outputtype"].is_string()?atoi(obj["outputtype"].get<std::string>().c_str()):obj["outputtype"].get<int>());
        }
        if(obj.contains("compressconf"))
        {
            msg.compressconf = (obj["compressconf"].is_string()?atoi(obj["compressconf"].get<std::string>().c_str()):obj["compressconf"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriverscameraconfigConfig from_json<ApollodriverscameraconfigConfig>(nlohmann::json obj){
        return from_json_ApollodriverscameraconfigConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscameraconfigConfig &dt)
    {
        dt=from_json_ApollodriverscameraconfigConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverscameraconfigConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscameraconfigConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
