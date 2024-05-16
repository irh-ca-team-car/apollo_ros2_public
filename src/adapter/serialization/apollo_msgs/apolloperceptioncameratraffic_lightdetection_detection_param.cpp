#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lightdetection_detection_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLightdetectionDetectionParam &msg) {
        nlohmann::json obj;
        obj["mincropsize"] = (msg.mincropsize);
        obj["cropmethod"] = (msg.cropmethod);
        obj["meanb"] = (msg.meanb);
        obj["meang"] = (msg.meang);
        obj["meanr"] = (msg.meanr);
        obj["isbgr"] = (msg.isbgr);
        obj["cropscale"] = (msg.cropscale);
        obj["inputblobname"] = (msg.inputblobname);
        obj["imparamblobname"] = (msg.imparamblobname);
        obj["outputblobname"] = (msg.outputblobname);
        obj["modelname"] = (msg.modelname);
        obj["modeltype"] = (msg.modeltype);
        obj["protofile"] = (msg.protofile);
        obj["weightfile"] = (msg.weightfile);
        obj["maxbatchsize"] = (msg.maxbatchsize);
        return obj;
    }
    ApolloperceptioncameratrafficLightdetectionDetectionParam from_json_ApolloperceptioncameratrafficLightdetectionDetectionParam (nlohmann::json obj) {
        ApolloperceptioncameratrafficLightdetectionDetectionParam msg;
        if(obj.contains("mincropsize"))
        {
            msg.mincropsize = (obj["mincropsize"].is_string()?atoi(obj["mincropsize"].get<std::string>().c_str()):obj["mincropsize"].get<int>());
        }
        if(obj.contains("cropmethod"))
        {
            msg.cropmethod = (obj["cropmethod"].is_string()?atoi(obj["cropmethod"].get<std::string>().c_str()):obj["cropmethod"].get<int>());
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
        if(obj.contains("cropscale"))
        {
            msg.cropscale = (obj["cropscale"].is_string()?(float)atof(obj["cropscale"].get<std::string>().c_str()):obj["cropscale"].get<float>());
        }
        if(obj.contains("inputblobname"))
        {
            msg.inputblobname = (obj["inputblobname"].is_string()?(obj["inputblobname"].get<std::string>().c_str()):obj["inputblobname"].get<std::string>());
        }
        if(obj.contains("imparamblobname"))
        {
            msg.imparamblobname = (obj["imparamblobname"].is_string()?(obj["imparamblobname"].get<std::string>().c_str()):obj["imparamblobname"].get<std::string>());
        }
        if(obj.contains("outputblobname"))
        {
            msg.outputblobname = (obj["outputblobname"].is_string()?(obj["outputblobname"].get<std::string>().c_str()):obj["outputblobname"].get<std::string>());
        }
        if(obj.contains("modelname"))
        {
            msg.modelname = (obj["modelname"].is_string()?(obj["modelname"].get<std::string>().c_str()):obj["modelname"].get<std::string>());
        }
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        if(obj.contains("protofile"))
        {
            msg.protofile = (obj["protofile"].is_string()?(obj["protofile"].get<std::string>().c_str()):obj["protofile"].get<std::string>());
        }
        if(obj.contains("weightfile"))
        {
            msg.weightfile = (obj["weightfile"].is_string()?(obj["weightfile"].get<std::string>().c_str()):obj["weightfile"].get<std::string>());
        }
        if(obj.contains("maxbatchsize"))
        {
            msg.maxbatchsize = (obj["maxbatchsize"].is_string()?atoi(obj["maxbatchsize"].get<std::string>().c_str()):obj["maxbatchsize"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrafficLightdetectionDetectionParam from_json<ApolloperceptioncameratrafficLightdetectionDetectionParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrafficLightdetectionDetectionParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLightdetectionDetectionParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrafficLightdetectionDetectionParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLightdetectionDetectionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLightdetectionDetectionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
