#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_fusion_camera_detection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardFusionCameraDetection &msg) {
        nlohmann::json obj;
        obj["cameranames"] = (msg.cameranames);
        obj["inputcamerachannelnames"] = (msg.inputcamerachannelnames);
        obj["timestampoffset"] = (msg.timestampoffset);
        obj["cameraobstacleperceptionconfdir"] = (msg.cameraobstacleperceptionconfdir);
        obj["cameraobstacleperceptionconffile"] = (msg.cameraobstacleperceptionconffile);
        obj["framecapacity"] = (msg.framecapacity);
        obj["imagechannelnum"] = (msg.imagechannelnum);
        obj["enableundistortion"] = (msg.enableundistortion);
        obj["enablevisualization"] = (msg.enablevisualization);
        obj["outputobstacleschannelname"] = (msg.outputobstacleschannelname);
        obj["cameraperceptionvizmessagechannelname"] = (msg.cameraperceptionvizmessagechannelname);
        obj["prefusedchannelname"] = (msg.prefusedchannelname);
        obj["defaultcamerapitch"] = (msg.defaultcamerapitch);
        obj["defaultcameraheight"] = (msg.defaultcameraheight);
        obj["lanecalibrationworkingsensorname"] = (msg.lanecalibrationworkingsensorname);
        obj["calibratormethod"] = (msg.calibratormethod);
        obj["calibservicename"] = (msg.calibservicename);
        obj["runcalibservice"] = (msg.runcalibservice);
        obj["outputcameradebugmsg"] = (msg.outputcameradebugmsg);
        obj["cameradebugchannelname"] = (msg.cameradebugchannelname);
        obj["tsdiff"] = (msg.tsdiff);
        obj["outputfinalobstacles"] = (msg.outputfinalobstacles);
        obj["visualdebugfolder"] = (msg.visualdebugfolder);
        obj["visualcamera"] = (msg.visualcamera);
        obj["writevisualimg"] = (msg.writevisualimg);
        obj["minlanelinelengthforcipv"] = (msg.minlanelinelengthforcipv);
        obj["averagelanewidthinmeter"] = (msg.averagelanewidthinmeter);
        obj["maxvehiclewidthinmeter"] = (msg.maxvehiclewidthinmeter);
        obj["averageframerate"] = (msg.averageframerate);
        obj["imagebasedcipv"] = (msg.imagebasedcipv);
        obj["debuglevel"] = (msg.debuglevel);
        obj["enablecipv"] = (msg.enablecipv);
        obj["lidartype"] = (msg.lidartype);
        return obj;
    }
    ApolloperceptiononboardFusionCameraDetection from_json_ApolloperceptiononboardFusionCameraDetection (nlohmann::json obj) {
        ApolloperceptiononboardFusionCameraDetection msg;
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
        if(obj.contains("cameraobstacleperceptionconfdir"))
        {
            msg.cameraobstacleperceptionconfdir = (obj["cameraobstacleperceptionconfdir"].is_string()?(obj["cameraobstacleperceptionconfdir"].get<std::string>().c_str()):obj["cameraobstacleperceptionconfdir"].get<std::string>());
        }
        if(obj.contains("cameraobstacleperceptionconffile"))
        {
            msg.cameraobstacleperceptionconffile = (obj["cameraobstacleperceptionconffile"].is_string()?(obj["cameraobstacleperceptionconffile"].get<std::string>().c_str()):obj["cameraobstacleperceptionconffile"].get<std::string>());
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
        if(obj.contains("outputobstacleschannelname"))
        {
            msg.outputobstacleschannelname = (obj["outputobstacleschannelname"].is_string()?(obj["outputobstacleschannelname"].get<std::string>().c_str()):obj["outputobstacleschannelname"].get<std::string>());
        }
        if(obj.contains("cameraperceptionvizmessagechannelname"))
        {
            msg.cameraperceptionvizmessagechannelname = (obj["cameraperceptionvizmessagechannelname"].is_string()?(obj["cameraperceptionvizmessagechannelname"].get<std::string>().c_str()):obj["cameraperceptionvizmessagechannelname"].get<std::string>());
        }
        if(obj.contains("prefusedchannelname"))
        {
            msg.prefusedchannelname = (obj["prefusedchannelname"].is_string()?(obj["prefusedchannelname"].get<std::string>().c_str()):obj["prefusedchannelname"].get<std::string>());
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
        if(obj.contains("outputcameradebugmsg"))
        {
            msg.outputcameradebugmsg = (obj["outputcameradebugmsg"].is_string()?(bool)atoi(obj["outputcameradebugmsg"].get<std::string>().c_str()):obj["outputcameradebugmsg"].get<bool>());
        }
        if(obj.contains("cameradebugchannelname"))
        {
            msg.cameradebugchannelname = (obj["cameradebugchannelname"].is_string()?(obj["cameradebugchannelname"].get<std::string>().c_str()):obj["cameradebugchannelname"].get<std::string>());
        }
        if(obj.contains("tsdiff"))
        {
            msg.tsdiff = (obj["tsdiff"].is_string()?atof(obj["tsdiff"].get<std::string>().c_str()):obj["tsdiff"].get<double>());
        }
        if(obj.contains("outputfinalobstacles"))
        {
            msg.outputfinalobstacles = (obj["outputfinalobstacles"].is_string()?(bool)atoi(obj["outputfinalobstacles"].get<std::string>().c_str()):obj["outputfinalobstacles"].get<bool>());
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
        if(obj.contains("minlanelinelengthforcipv"))
        {
            msg.minlanelinelengthforcipv = (obj["minlanelinelengthforcipv"].is_string()?atof(obj["minlanelinelengthforcipv"].get<std::string>().c_str()):obj["minlanelinelengthforcipv"].get<double>());
        }
        if(obj.contains("averagelanewidthinmeter"))
        {
            msg.averagelanewidthinmeter = (obj["averagelanewidthinmeter"].is_string()?atof(obj["averagelanewidthinmeter"].get<std::string>().c_str()):obj["averagelanewidthinmeter"].get<double>());
        }
        if(obj.contains("maxvehiclewidthinmeter"))
        {
            msg.maxvehiclewidthinmeter = (obj["maxvehiclewidthinmeter"].is_string()?atof(obj["maxvehiclewidthinmeter"].get<std::string>().c_str()):obj["maxvehiclewidthinmeter"].get<double>());
        }
        if(obj.contains("averageframerate"))
        {
            msg.averageframerate = (obj["averageframerate"].is_string()?atof(obj["averageframerate"].get<std::string>().c_str()):obj["averageframerate"].get<double>());
        }
        if(obj.contains("imagebasedcipv"))
        {
            msg.imagebasedcipv = (obj["imagebasedcipv"].is_string()?(bool)atoi(obj["imagebasedcipv"].get<std::string>().c_str()):obj["imagebasedcipv"].get<bool>());
        }
        if(obj.contains("debuglevel"))
        {
            msg.debuglevel = (obj["debuglevel"].is_string()?atoi(obj["debuglevel"].get<std::string>().c_str()):obj["debuglevel"].get<int>());
        }
        if(obj.contains("enablecipv"))
        {
            msg.enablecipv = (obj["enablecipv"].is_string()?(bool)atoi(obj["enablecipv"].get<std::string>().c_str()):obj["enablecipv"].get<bool>());
        }
        if(obj.contains("lidartype"))
        {
            msg.lidartype = (obj["lidartype"].is_string()?(obj["lidartype"].get<std::string>().c_str()):obj["lidartype"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardFusionCameraDetection from_json<ApolloperceptiononboardFusionCameraDetection>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardFusionCameraDetection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardFusionCameraDetection &dt)
    {
        dt=from_json_ApolloperceptiononboardFusionCameraDetection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardFusionCameraDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardFusionCameraDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
}
