#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lightrecognition_classify_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLightrecognitionClassifyParam &msg) {
        nlohmann::json obj;
        obj["modelname"] = (msg.modelname);
        obj["modeltype"] = (msg.modeltype);
        obj["inputblob"] = (msg.inputblob);
        obj["outputblob"] = (msg.outputblob);
        obj["weightfile"] = (msg.weightfile);
        obj["protofile"] = (msg.protofile);
        obj["classifythreshold"] = (msg.classifythreshold);
        obj["classifyresizewidth"] = (msg.classifyresizewidth);
        obj["classifyresizeheight"] = (msg.classifyresizeheight);
        obj["scale"] = (msg.scale);
        obj["meanb"] = (msg.meanb);
        obj["meang"] = (msg.meang);
        obj["meanr"] = (msg.meanr);
        obj["isbgr"] = (msg.isbgr);
        return obj;
    }
    ApolloperceptioncameratrafficLightrecognitionClassifyParam from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam (nlohmann::json obj) {
        ApolloperceptioncameratrafficLightrecognitionClassifyParam msg;
        if(obj.contains("modelname"))
        {
            msg.modelname = (obj["modelname"].is_string()?(obj["modelname"].get<std::string>().c_str()):obj["modelname"].get<std::string>());
        }
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        if(obj.contains("inputblob"))
        {
            msg.inputblob = (obj["inputblob"].is_string()?(obj["inputblob"].get<std::string>().c_str()):obj["inputblob"].get<std::string>());
        }
        if(obj.contains("outputblob"))
        {
            msg.outputblob = (obj["outputblob"].is_string()?(obj["outputblob"].get<std::string>().c_str()):obj["outputblob"].get<std::string>());
        }
        if(obj.contains("weightfile"))
        {
            msg.weightfile = (obj["weightfile"].is_string()?(obj["weightfile"].get<std::string>().c_str()):obj["weightfile"].get<std::string>());
        }
        if(obj.contains("protofile"))
        {
            msg.protofile = (obj["protofile"].is_string()?(obj["protofile"].get<std::string>().c_str()):obj["protofile"].get<std::string>());
        }
        if(obj.contains("classifythreshold"))
        {
            msg.classifythreshold = (obj["classifythreshold"].is_string()?(float)atof(obj["classifythreshold"].get<std::string>().c_str()):obj["classifythreshold"].get<float>());
        }
        if(obj.contains("classifyresizewidth"))
        {
            msg.classifyresizewidth = (obj["classifyresizewidth"].is_string()?atoi(obj["classifyresizewidth"].get<std::string>().c_str()):obj["classifyresizewidth"].get<int>());
        }
        if(obj.contains("classifyresizeheight"))
        {
            msg.classifyresizeheight = (obj["classifyresizeheight"].is_string()?atoi(obj["classifyresizeheight"].get<std::string>().c_str()):obj["classifyresizeheight"].get<int>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("meanb"))
        {
            msg.meanb = (obj["meanb"].is_string()?(float)atof(obj["meanb"].get<std::string>().c_str()):obj["meanb"].get<float>());
        }
        if(obj.contains("meang"))
        {
            msg.meang = (obj["meang"].is_string()?(float)atof(obj["meang"].get<std::string>().c_str()):obj["meang"].get<float>());
        }
        if(obj.contains("meanr"))
        {
            msg.meanr = (obj["meanr"].is_string()?(float)atof(obj["meanr"].get<std::string>().c_str()):obj["meanr"].get<float>());
        }
        if(obj.contains("isbgr"))
        {
            msg.isbgr = (obj["isbgr"].is_string()?(bool)atoi(obj["isbgr"].get<std::string>().c_str()):obj["isbgr"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrafficLightrecognitionClassifyParam from_json<ApolloperceptioncameratrafficLightrecognitionClassifyParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLightrecognitionClassifyParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLightrecognitionClassifyParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLightrecognitionClassifyParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
