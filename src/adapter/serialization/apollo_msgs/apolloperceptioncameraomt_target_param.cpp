#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_target_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtTargetParam &msg) {
        nlohmann::json obj;
        obj["velocitythreshold"] = (msg.velocitythreshold);
        obj["velocityoutputdelay"] = (msg.velocityoutputdelay);
        obj["worldcenter"] = to_json(msg.worldcenter);
        obj["imagecenter"] = to_json(msg.imagecenter);
        obj["imagewhupdaterate"] = (msg.imagewhupdaterate);
        obj["worldlhwhistory"] = (msg.worldlhwhistory);
        obj["heightdiffratio"] = (msg.heightdiffratio);
        obj["worldstatehistory"] = (msg.worldstatehistory);
        obj["mincachedworldstatehistorysize"] = (msg.mincachedworldstatehistorysize);
        obj["mincachedvelocitysize"] = (msg.mincachedvelocitysize);
        obj["mincachedpositionsize"] = (msg.mincachedpositionsize);
        obj["calcavgpositionwindowsize"] = (msg.calcavgpositionwindowsize);
        obj["staticspeedthreshold"] = (msg.staticspeedthreshold);
        obj["staticspeedthresholdped"] = (msg.staticspeedthresholdped);
        obj["minmovingavgspeed"] = (msg.minmovingavgspeed);
        obj["minmovingavgspeedped"] = (msg.minmovingavgspeedped);
        obj["abnormalaccthreshold"] = (msg.abnormalaccthreshold);
        obj["abnormalaccthresholdped"] = (msg.abnormalaccthresholdped);
        obj["abnormalvelocityheadinganglethreshold"] = (msg.abnormalvelocityheadinganglethreshold);
        obj["clappingvelocity"] = (msg.clappingvelocity);
        obj["worldmeanvelocityduration"] = (msg.worldmeanvelocityduration);
        obj["trackedlife"] = (msg.trackedlife);
        obj["typefiltervar"] = (msg.typefiltervar);
        obj["largevelocityratio"] = (msg.largevelocityratio);
        obj["toolargevelocityratio"] = (msg.toolargevelocityratio);
        obj["meanfilterwindow"] = (msg.meanfilterwindow);
        obj["directionfilterratio"] = (msg.directionfilterratio);
        obj["displacementthetavar"] = (msg.displacementthetavar);
        obj["velocitythetavar"] = (msg.velocitythetavar);
        obj["stablemovingspeed"] = (msg.stablemovingspeed);
        return obj;
    }
    ApolloperceptioncameraomtTargetParam from_json_ApolloperceptioncameraomtTargetParam (nlohmann::json obj) {
        ApolloperceptioncameraomtTargetParam msg;
        if(obj.contains("velocitythreshold"))
        {
            msg.velocitythreshold = (obj["velocitythreshold"].is_string()?(float)atof(obj["velocitythreshold"].get<std::string>().c_str()):obj["velocitythreshold"].get<float>());
        }
        if(obj.contains("velocityoutputdelay"))
        {
            msg.velocityoutputdelay = (obj["velocityoutputdelay"].is_string()?atoi(obj["velocityoutputdelay"].get<std::string>().c_str()):obj["velocityoutputdelay"].get<int>());
        }
        if(obj.contains("worldcenter"))
        {
            msg.worldcenter = from_json_ApolloperceptioncameraomtKalmanParam(obj["worldcenter"]);
        }
        if(obj.contains("imagecenter"))
        {
            msg.imagecenter = from_json_ApolloperceptioncameraomtKalmanParam(obj["imagecenter"]);
        }
        if(obj.contains("imagewhupdaterate"))
        {
            msg.imagewhupdaterate = (obj["imagewhupdaterate"].is_string()?(float)atof(obj["imagewhupdaterate"].get<std::string>().c_str()):obj["imagewhupdaterate"].get<float>());
        }
        if(obj.contains("worldlhwhistory"))
        {
            msg.worldlhwhistory = (obj["worldlhwhistory"].is_string()?atoi(obj["worldlhwhistory"].get<std::string>().c_str()):obj["worldlhwhistory"].get<int>());
        }
        if(obj.contains("heightdiffratio"))
        {
            msg.heightdiffratio = (obj["heightdiffratio"].is_string()?(float)atof(obj["heightdiffratio"].get<std::string>().c_str()):obj["heightdiffratio"].get<float>());
        }
        if(obj.contains("worldstatehistory"))
        {
            msg.worldstatehistory = (obj["worldstatehistory"].is_string()?atoi(obj["worldstatehistory"].get<std::string>().c_str()):obj["worldstatehistory"].get<int>());
        }
        if(obj.contains("mincachedworldstatehistorysize"))
        {
            msg.mincachedworldstatehistorysize = (obj["mincachedworldstatehistorysize"].is_string()?atoi(obj["mincachedworldstatehistorysize"].get<std::string>().c_str()):obj["mincachedworldstatehistorysize"].get<int>());
        }
        if(obj.contains("mincachedvelocitysize"))
        {
            msg.mincachedvelocitysize = (obj["mincachedvelocitysize"].is_string()?atoi(obj["mincachedvelocitysize"].get<std::string>().c_str()):obj["mincachedvelocitysize"].get<int>());
        }
        if(obj.contains("mincachedpositionsize"))
        {
            msg.mincachedpositionsize = (obj["mincachedpositionsize"].is_string()?atoi(obj["mincachedpositionsize"].get<std::string>().c_str()):obj["mincachedpositionsize"].get<int>());
        }
        if(obj.contains("calcavgpositionwindowsize"))
        {
            msg.calcavgpositionwindowsize = (obj["calcavgpositionwindowsize"].is_string()?atoi(obj["calcavgpositionwindowsize"].get<std::string>().c_str()):obj["calcavgpositionwindowsize"].get<int>());
        }
        if(obj.contains("staticspeedthreshold"))
        {
            msg.staticspeedthreshold = (obj["staticspeedthreshold"].is_string()?(float)atof(obj["staticspeedthreshold"].get<std::string>().c_str()):obj["staticspeedthreshold"].get<float>());
        }
        if(obj.contains("staticspeedthresholdped"))
        {
            msg.staticspeedthresholdped = (obj["staticspeedthresholdped"].is_string()?(float)atof(obj["staticspeedthresholdped"].get<std::string>().c_str()):obj["staticspeedthresholdped"].get<float>());
        }
        if(obj.contains("minmovingavgspeed"))
        {
            msg.minmovingavgspeed = (obj["minmovingavgspeed"].is_string()?(float)atof(obj["minmovingavgspeed"].get<std::string>().c_str()):obj["minmovingavgspeed"].get<float>());
        }
        if(obj.contains("minmovingavgspeedped"))
        {
            msg.minmovingavgspeedped = (obj["minmovingavgspeedped"].is_string()?(float)atof(obj["minmovingavgspeedped"].get<std::string>().c_str()):obj["minmovingavgspeedped"].get<float>());
        }
        if(obj.contains("abnormalaccthreshold"))
        {
            msg.abnormalaccthreshold = (obj["abnormalaccthreshold"].is_string()?(float)atof(obj["abnormalaccthreshold"].get<std::string>().c_str()):obj["abnormalaccthreshold"].get<float>());
        }
        if(obj.contains("abnormalaccthresholdped"))
        {
            msg.abnormalaccthresholdped = (obj["abnormalaccthresholdped"].is_string()?(float)atof(obj["abnormalaccthresholdped"].get<std::string>().c_str()):obj["abnormalaccthresholdped"].get<float>());
        }
        if(obj.contains("abnormalvelocityheadinganglethreshold"))
        {
            msg.abnormalvelocityheadinganglethreshold = (obj["abnormalvelocityheadinganglethreshold"].is_string()?(float)atof(obj["abnormalvelocityheadinganglethreshold"].get<std::string>().c_str()):obj["abnormalvelocityheadinganglethreshold"].get<float>());
        }
        if(obj.contains("clappingvelocity"))
        {
            msg.clappingvelocity = (obj["clappingvelocity"].is_string()?(bool)atoi(obj["clappingvelocity"].get<std::string>().c_str()):obj["clappingvelocity"].get<bool>());
        }
        if(obj.contains("worldmeanvelocityduration"))
        {
            msg.worldmeanvelocityduration = (obj["worldmeanvelocityduration"].is_string()?atoi(obj["worldmeanvelocityduration"].get<std::string>().c_str()):obj["worldmeanvelocityduration"].get<int>());
        }
        if(obj.contains("trackedlife"))
        {
            msg.trackedlife = (obj["trackedlife"].is_string()?atoi(obj["trackedlife"].get<std::string>().c_str()):obj["trackedlife"].get<int>());
        }
        if(obj.contains("typefiltervar"))
        {
            msg.typefiltervar = (obj["typefiltervar"].is_string()?(float)atof(obj["typefiltervar"].get<std::string>().c_str()):obj["typefiltervar"].get<float>());
        }
        if(obj.contains("largevelocityratio"))
        {
            msg.largevelocityratio = (obj["largevelocityratio"].is_string()?(float)atof(obj["largevelocityratio"].get<std::string>().c_str()):obj["largevelocityratio"].get<float>());
        }
        if(obj.contains("toolargevelocityratio"))
        {
            msg.toolargevelocityratio = (obj["toolargevelocityratio"].is_string()?(float)atof(obj["toolargevelocityratio"].get<std::string>().c_str()):obj["toolargevelocityratio"].get<float>());
        }
        if(obj.contains("meanfilterwindow"))
        {
            msg.meanfilterwindow = (obj["meanfilterwindow"].is_string()?atoi(obj["meanfilterwindow"].get<std::string>().c_str()):obj["meanfilterwindow"].get<int>());
        }
        if(obj.contains("directionfilterratio"))
        {
            msg.directionfilterratio = (obj["directionfilterratio"].is_string()?(float)atof(obj["directionfilterratio"].get<std::string>().c_str()):obj["directionfilterratio"].get<float>());
        }
        if(obj.contains("displacementthetavar"))
        {
            msg.displacementthetavar = (obj["displacementthetavar"].is_string()?(float)atof(obj["displacementthetavar"].get<std::string>().c_str()):obj["displacementthetavar"].get<float>());
        }
        if(obj.contains("velocitythetavar"))
        {
            msg.velocitythetavar = (obj["velocitythetavar"].is_string()?(float)atof(obj["velocitythetavar"].get<std::string>().c_str()):obj["velocitythetavar"].get<float>());
        }
        if(obj.contains("stablemovingspeed"))
        {
            msg.stablemovingspeed = (obj["stablemovingspeed"].is_string()?(float)atof(obj["stablemovingspeed"].get<std::string>().c_str()):obj["stablemovingspeed"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraomtTargetParam from_json<ApolloperceptioncameraomtTargetParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraomtTargetParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtTargetParam &dt)
    {
        dt=from_json_ApolloperceptioncameraomtTargetParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtTargetParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtTargetParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
