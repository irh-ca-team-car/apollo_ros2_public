#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_lane_detection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLaneDetection &msg) {
        nlohmann::json obj;
        obj["cameranames"] = (msg.cameranames);
        obj["inputcamerachannelnames"] = (msg.inputcamerachannelnames);
        obj["timestampoffset"] = (msg.timestampoffset);
        obj["cameralaneperceptionconfdir"] = (msg.cameralaneperceptionconfdir);
        obj["cameralaneperceptionconffile"] = (msg.cameralaneperceptionconffile);
        obj["framecapacity"] = (msg.framecapacity);
        obj["imagechannelnum"] = (msg.imagechannelnum);
        obj["enableundistortion"] = (msg.enableundistortion);
        obj["enablevisualization"] = (msg.enablevisualization);
        obj["outputlaneschannelname"] = (msg.outputlaneschannelname);
        obj["defaultcamerapitch"] = (msg.defaultcamerapitch);
        obj["defaultcameraheight"] = (msg.defaultcameraheight);
        obj["lanecalibrationworkingsensorname"] = (msg.lanecalibrationworkingsensorname);
        obj["calibratormethod"] = (msg.calibratormethod);
        obj["calibservicename"] = (msg.calibservicename);
        obj["runcalibservice"] = (msg.runcalibservice);
        obj["tsdiff"] = (msg.tsdiff);
        obj["visualdebugfolder"] = (msg.visualdebugfolder);
        obj["visualcamera"] = (msg.visualcamera);
        obj["writevisualimg"] = (msg.writevisualimg);
        return obj;
    }
    ApolloperceptiononboardLaneDetection from_json_ApolloperceptiononboardLaneDetection (nlohmann::json obj) {
        ApolloperceptiononboardLaneDetection msg;
        if(obj.contains("cameranames"))
        {
            msg.cameranames = (obj["cameranames"].is_string()?(obj["cameranames"].get<std::string>().c_str()):obj["cameranames"].get<std::string>());
        }
        if(obj.contains("inputcamerachannelnames"))
        {
            msg.inputcamerachannelnames = (obj["inputcamerachannelnames"].is_string()?(obj["inputcamerachannelnames"].get<std::string>().c_str()):obj["inputcamerachannelnames"].get<std::string>());
        }
        if(obj.contains("timestampoffset"))
        {
            msg.timestampoffset = (obj["timestampoffset"].is_string()?atof(obj["timestampoffset"].get<std::string>().c_str()):obj["timestampoffset"].get<double>());
        }
        if(obj.contains("cameralaneperceptionconfdir"))
        {
            msg.cameralaneperceptionconfdir = (obj["cameralaneperceptionconfdir"].is_string()?(obj["cameralaneperceptionconfdir"].get<std::string>().c_str()):obj["cameralaneperceptionconfdir"].get<std::string>());
        }
        if(obj.contains("cameralaneperceptionconffile"))
        {
            msg.cameralaneperceptionconffile = (obj["cameralaneperceptionconffile"].is_string()?(obj["cameralaneperceptionconffile"].get<std::string>().c_str()):obj["cameralaneperceptionconffile"].get<std::string>());
        }
        if(obj.contains("framecapacity"))
        {
            msg.framecapacity = (obj["framecapacity"].is_string()?atoi(obj["framecapacity"].get<std::string>().c_str()):obj["framecapacity"].get<int>());
        }
        if(obj.contains("imagechannelnum"))
        {
            msg.imagechannelnum = (obj["imagechannelnum"].is_string()?atoi(obj["imagechannelnum"].get<std::string>().c_str()):obj["imagechannelnum"].get<int>());
        }
        if(obj.contains("enableundistortion"))
        {
            msg.enableundistortion = (obj["enableundistortion"].is_string()?(bool)atoi(obj["enableundistortion"].get<std::string>().c_str()):obj["enableundistortion"].get<bool>());
        }
        if(obj.contains("enablevisualization"))
        {
            msg.enablevisualization = (obj["enablevisualization"].is_string()?(bool)atoi(obj["enablevisualization"].get<std::string>().c_str()):obj["enablevisualization"].get<bool>());
        }
        if(obj.contains("outputlaneschannelname"))
        {
            msg.outputlaneschannelname = (obj["outputlaneschannelname"].is_string()?(obj["outputlaneschannelname"].get<std::string>().c_str()):obj["outputlaneschannelname"].get<std::string>());
        }
        if(obj.contains("defaultcamerapitch"))
        {
            msg.defaultcamerapitch = (obj["defaultcamerapitch"].is_string()?atof(obj["defaultcamerapitch"].get<std::string>().c_str()):obj["defaultcamerapitch"].get<double>());
        }
        if(obj.contains("defaultcameraheight"))
        {
            msg.defaultcameraheight = (obj["defaultcameraheight"].is_string()?atof(obj["defaultcameraheight"].get<std::string>().c_str()):obj["defaultcameraheight"].get<double>());
        }
        if(obj.contains("lanecalibrationworkingsensorname"))
        {
            msg.lanecalibrationworkingsensorname = (obj["lanecalibrationworkingsensorname"].is_string()?(obj["lanecalibrationworkingsensorname"].get<std::string>().c_str()):obj["lanecalibrationworkingsensorname"].get<std::string>());
        }
        if(obj.contains("calibratormethod"))
        {
            msg.calibratormethod = (obj["calibratormethod"].is_string()?(obj["calibratormethod"].get<std::string>().c_str()):obj["calibratormethod"].get<std::string>());
        }
        if(obj.contains("calibservicename"))
        {
            msg.calibservicename = (obj["calibservicename"].is_string()?(obj["calibservicename"].get<std::string>().c_str()):obj["calibservicename"].get<std::string>());
        }
        if(obj.contains("runcalibservice"))
        {
            msg.runcalibservice = (obj["runcalibservice"].is_string()?(bool)atoi(obj["runcalibservice"].get<std::string>().c_str()):obj["runcalibservice"].get<bool>());
        }
        if(obj.contains("tsdiff"))
        {
            msg.tsdiff = (obj["tsdiff"].is_string()?atof(obj["tsdiff"].get<std::string>().c_str()):obj["tsdiff"].get<double>());
        }
        if(obj.contains("visualdebugfolder"))
        {
            msg.visualdebugfolder = (obj["visualdebugfolder"].is_string()?(obj["visualdebugfolder"].get<std::string>().c_str()):obj["visualdebugfolder"].get<std::string>());
        }
        if(obj.contains("visualcamera"))
        {
            msg.visualcamera = (obj["visualcamera"].is_string()?(obj["visualcamera"].get<std::string>().c_str()):obj["visualcamera"].get<std::string>());
        }
        if(obj.contains("writevisualimg"))
        {
            msg.writevisualimg = (obj["writevisualimg"].is_string()?(bool)atoi(obj["writevisualimg"].get<std::string>().c_str()):obj["writevisualimg"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardLaneDetection from_json<ApolloperceptiononboardLaneDetection>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardLaneDetection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLaneDetection &dt)
    {
        dt=from_json_ApolloperceptiononboardLaneDetection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLaneDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLaneDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
