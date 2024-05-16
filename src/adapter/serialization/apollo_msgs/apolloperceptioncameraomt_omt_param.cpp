#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_omt_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtOmtParam &msg) {
        nlohmann::json obj;
        obj["imgcapability"] = (msg.imgcapability);
        obj["lostage"] = (msg.lostage);
        obj["reserveage"] = (msg.reserveage);
        obj["weightsamecamera"] = to_json(msg.weightsamecamera);
        obj["weightdiffcamera"] = to_json(msg.weightdiffcamera);
        obj["border"] = (msg.border);
        obj["targetthresh"] = (msg.targetthresh);
        obj["correcttype"] = (msg.correcttype);
        obj["targetparam"] = to_json(msg.targetparam);
        obj["mininitheightratio"] = (msg.mininitheightratio);
        obj["targetcombineiouthreshold"] = (msg.targetcombineiouthreshold);
        obj["fusiontargetthresh"] = (msg.fusiontargetthresh);
        obj["imagedisplacement"] = (msg.imagedisplacement);
        obj["abnormalmovement"] = (msg.abnormalmovement);
        obj["sametseps"] = (msg.sametseps);
        obj["reference"] = to_json(msg.reference);
        obj["typechangecost"] = (msg.typechangecost);
        return obj;
    }
    ApolloperceptioncameraomtOmtParam from_json_ApolloperceptioncameraomtOmtParam (nlohmann::json obj) {
        ApolloperceptioncameraomtOmtParam msg;
        if(obj.contains("imgcapability"))
        {
            msg.imgcapability = (obj["imgcapability"].is_string()?atoi(obj["imgcapability"].get<std::string>().c_str()):obj["imgcapability"].get<int>());
        }
        if(obj.contains("lostage"))
        {
            msg.lostage = (obj["lostage"].is_string()?atoi(obj["lostage"].get<std::string>().c_str()):obj["lostage"].get<int>());
        }
        if(obj.contains("reserveage"))
        {
            msg.reserveage = (obj["reserveage"].is_string()?atoi(obj["reserveage"].get<std::string>().c_str()):obj["reserveage"].get<int>());
        }
        if(obj.contains("weightsamecamera"))
        {
            msg.weightsamecamera = from_json_ApolloperceptioncameraomtWeightParam(obj["weightsamecamera"]);
        }
        if(obj.contains("weightdiffcamera"))
        {
            msg.weightdiffcamera = from_json_ApolloperceptioncameraomtWeightParam(obj["weightdiffcamera"]);
        }
        if(obj.contains("border"))
        {
            msg.border = (obj["border"].is_string()?(float)atof(obj["border"].get<std::string>().c_str()):obj["border"].get<float>());
        }
        if(obj.contains("targetthresh"))
        {
            msg.targetthresh = (obj["targetthresh"].is_string()?(float)atof(obj["targetthresh"].get<std::string>().c_str()):obj["targetthresh"].get<float>());
        }
        if(obj.contains("correcttype"))
        {
            msg.correcttype = (obj["correcttype"].is_string()?(bool)atoi(obj["correcttype"].get<std::string>().c_str()):obj["correcttype"].get<bool>());
        }
        if(obj.contains("targetparam"))
        {
            msg.targetparam = from_json_ApolloperceptioncameraomtTargetParam(obj["targetparam"]);
        }
        if(obj.contains("mininitheightratio"))
        {
            msg.mininitheightratio = (obj["mininitheightratio"].is_string()?(float)atof(obj["mininitheightratio"].get<std::string>().c_str()):obj["mininitheightratio"].get<float>());
        }
        if(obj.contains("targetcombineiouthreshold"))
        {
            msg.targetcombineiouthreshold = (obj["targetcombineiouthreshold"].is_string()?(float)atof(obj["targetcombineiouthreshold"].get<std::string>().c_str()):obj["targetcombineiouthreshold"].get<float>());
        }
        if(obj.contains("fusiontargetthresh"))
        {
            msg.fusiontargetthresh = (obj["fusiontargetthresh"].is_string()?(float)atof(obj["fusiontargetthresh"].get<std::string>().c_str()):obj["fusiontargetthresh"].get<float>());
        }
        if(obj.contains("imagedisplacement"))
        {
            msg.imagedisplacement = (obj["imagedisplacement"].is_string()?(float)atof(obj["imagedisplacement"].get<std::string>().c_str()):obj["imagedisplacement"].get<float>());
        }
        if(obj.contains("abnormalmovement"))
        {
            msg.abnormalmovement = (obj["abnormalmovement"].is_string()?(float)atof(obj["abnormalmovement"].get<std::string>().c_str()):obj["abnormalmovement"].get<float>());
        }
        if(obj.contains("sametseps"))
        {
            msg.sametseps = (obj["sametseps"].is_string()?atof(obj["sametseps"].get<std::string>().c_str()):obj["sametseps"].get<double>());
        }
        if(obj.contains("reference"))
        {
            msg.reference = from_json_ApolloperceptioncameraomtReferenceParam(obj["reference"]);
        }
        if(obj.contains("typechangecost"))
        {
            msg.typechangecost = (obj["typechangecost"].is_string()?(obj["typechangecost"].get<std::string>().c_str()):obj["typechangecost"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraomtOmtParam from_json<ApolloperceptioncameraomtOmtParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraomtOmtParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtOmtParam &dt)
    {
        dt=from_json_ApolloperceptioncameraomtOmtParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtOmtParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtOmtParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
