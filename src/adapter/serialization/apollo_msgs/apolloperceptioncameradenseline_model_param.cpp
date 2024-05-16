#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_model_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradenselineModelParam &msg) {
        nlohmann::json obj;
        obj["modelname"] = (msg.modelname);
        obj["protofile"] = (msg.protofile);
        obj["weightfile"] = (msg.weightfile);
        obj["resizescale"] = (msg.resizescale);
        obj["inputoffsety"] = (msg.inputoffsety);
        obj["inputoffsetx"] = (msg.inputoffsetx);
        obj["cropheight"] = (msg.cropheight);
        obj["cropwidth"] = (msg.cropwidth);
        obj["meanb"] = (msg.meanb);
        obj["meang"] = (msg.meang);
        obj["meanr"] = (msg.meanr);
        obj["isbgr"] = (msg.isbgr);
        obj["modeltype"] = (msg.modeltype);
        return obj;
    }
    ApolloperceptioncameradenselineModelParam from_json_ApolloperceptioncameradenselineModelParam (nlohmann::json obj) {
        ApolloperceptioncameradenselineModelParam msg;
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
        if(obj.contains("resizescale"))
        {
            msg.resizescale = (obj["resizescale"].is_string()?(float)atof(obj["resizescale"].get<std::string>().c_str()):obj["resizescale"].get<float>());
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
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameradenselineModelParam from_json<ApolloperceptioncameradenselineModelParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameradenselineModelParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradenselineModelParam &dt)
    {
        dt=from_json_ApolloperceptioncameradenselineModelParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradenselineModelParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradenselineModelParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
