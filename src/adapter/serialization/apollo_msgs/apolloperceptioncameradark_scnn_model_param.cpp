#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_model_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradarkSCNNModelParam &msg) {
        nlohmann::json obj;
        obj["modelname"] = (msg.modelname);
        obj["protofile"] = (msg.protofile);
        obj["weightfile"] = (msg.weightfile);
        obj["inputoffsety"] = (msg.inputoffsety);
        obj["inputoffsetx"] = (msg.inputoffsetx);
        obj["cropheight"] = (msg.cropheight);
        obj["cropwidth"] = (msg.cropwidth);
        obj["resizeheight"] = (msg.resizeheight);
        obj["resizewidth"] = (msg.resizewidth);
        obj["meanb"] = (msg.meanb);
        obj["meang"] = (msg.meang);
        obj["meanr"] = (msg.meanr);
        obj["isbgr"] = (msg.isbgr);
        obj["confidencethreshold"] = (msg.confidencethreshold);
        obj["vptmeandx"] = (msg.vptmeandx);
        obj["vptmeandy"] = (msg.vptmeandy);
        obj["vptstddx"] = (msg.vptstddx);
        obj["vptstddy"] = (msg.vptstddy);
        obj["modeltype"] = (msg.modeltype);
        return obj;
    }
    ApolloperceptioncameradarkSCNNModelParam from_json_ApolloperceptioncameradarkSCNNModelParam (nlohmann::json obj) {
        ApolloperceptioncameradarkSCNNModelParam msg;
        if(obj.contains("modelname"))
        {
            msg.modelname = (obj["modelname"].is_string()?(obj["modelname"].get<std::string>().c_str()):obj["modelname"].get<std::string>());
        }
        if(obj.contains("protofile"))
        {
            msg.protofile = (obj["protofile"].is_string()?(obj["protofile"].get<std::string>().c_str()):obj["protofile"].get<std::string>());
        }
        if(obj.contains("weightfile"))
        {
            msg.weightfile = (obj["weightfile"].is_string()?(obj["weightfile"].get<std::string>().c_str()):obj["weightfile"].get<std::string>());
        }
        if(obj.contains("inputoffsety"))
        {
            msg.inputoffsety = (obj["inputoffsety"].is_string()?atoi(obj["inputoffsety"].get<std::string>().c_str()):obj["inputoffsety"].get<uint32_t>());
        }
        if(obj.contains("inputoffsetx"))
        {
            msg.inputoffsetx = (obj["inputoffsetx"].is_string()?atoi(obj["inputoffsetx"].get<std::string>().c_str()):obj["inputoffsetx"].get<uint32_t>());
        }
        if(obj.contains("cropheight"))
        {
            msg.cropheight = (obj["cropheight"].is_string()?atoi(obj["cropheight"].get<std::string>().c_str()):obj["cropheight"].get<uint32_t>());
        }
        if(obj.contains("cropwidth"))
        {
            msg.cropwidth = (obj["cropwidth"].is_string()?atoi(obj["cropwidth"].get<std::string>().c_str()):obj["cropwidth"].get<uint32_t>());
        }
        if(obj.contains("resizeheight"))
        {
            msg.resizeheight = (obj["resizeheight"].is_string()?atoi(obj["resizeheight"].get<std::string>().c_str()):obj["resizeheight"].get<uint32_t>());
        }
        if(obj.contains("resizewidth"))
        {
            msg.resizewidth = (obj["resizewidth"].is_string()?atoi(obj["resizewidth"].get<std::string>().c_str()):obj["resizewidth"].get<uint32_t>());
        }
        if(obj.contains("meanb"))
        {
            msg.meanb = (obj["meanb"].is_string()?atoi(obj["meanb"].get<std::string>().c_str()):obj["meanb"].get<uint32_t>());
        }
        if(obj.contains("meang"))
        {
            msg.meang = (obj["meang"].is_string()?atoi(obj["meang"].get<std::string>().c_str()):obj["meang"].get<uint32_t>());
        }
        if(obj.contains("meanr"))
        {
            msg.meanr = (obj["meanr"].is_string()?atoi(obj["meanr"].get<std::string>().c_str()):obj["meanr"].get<uint32_t>());
        }
        if(obj.contains("isbgr"))
        {
            msg.isbgr = (obj["isbgr"].is_string()?(bool)atoi(obj["isbgr"].get<std::string>().c_str()):obj["isbgr"].get<bool>());
        }
        if(obj.contains("confidencethreshold"))
        {
            msg.confidencethreshold = (obj["confidencethreshold"].is_string()?(float)atof(obj["confidencethreshold"].get<std::string>().c_str()):obj["confidencethreshold"].get<float>());
        }
        if(obj.contains("vptmeandx"))
        {
            msg.vptmeandx = (obj["vptmeandx"].is_string()?(float)atof(obj["vptmeandx"].get<std::string>().c_str()):obj["vptmeandx"].get<float>());
        }
        if(obj.contains("vptmeandy"))
        {
            msg.vptmeandy = (obj["vptmeandy"].is_string()?(float)atof(obj["vptmeandy"].get<std::string>().c_str()):obj["vptmeandy"].get<float>());
        }
        if(obj.contains("vptstddx"))
        {
            msg.vptstddx = (obj["vptstddx"].is_string()?(float)atof(obj["vptstddx"].get<std::string>().c_str()):obj["vptstddx"].get<float>());
        }
        if(obj.contains("vptstddy"))
        {
            msg.vptstddy = (obj["vptstddy"].is_string()?(float)atof(obj["vptstddy"].get<std::string>().c_str()):obj["vptstddy"].get<float>());
        }
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameradarkSCNNModelParam from_json<ApolloperceptioncameradarkSCNNModelParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameradarkSCNNModelParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradarkSCNNModelParam &dt)
    {
        dt=from_json_ApolloperceptioncameradarkSCNNModelParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradarkSCNNModelParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradarkSCNNModelParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
