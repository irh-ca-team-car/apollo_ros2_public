#include "adapter/serialization/apollo_msgs/apolloperceptioninference_window_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceWindowDataParameter &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        obj["scale"] = (msg.scale);
        obj["meanfile"] = (msg.meanfile);
        obj["batchsize"] = (msg.batchsize);
        obj["cropsize"] = (msg.cropsize);
        obj["mirror"] = (msg.mirror);
        obj["fgthreshold"] = (msg.fgthreshold);
        obj["bgthreshold"] = (msg.bgthreshold);
        obj["fgfraction"] = (msg.fgfraction);
        obj["contextpad"] = (msg.contextpad);
        obj["cropmode"] = (msg.cropmode);
        obj["cacheimages"] = (msg.cacheimages);
        obj["rootfolder"] = (msg.rootfolder);
        return obj;
    }
    ApolloperceptioninferenceWindowDataParameter from_json_ApolloperceptioninferenceWindowDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceWindowDataParameter msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("meanfile"))
        {
            msg.meanfile = (obj["meanfile"].is_string()?(obj["meanfile"].get<std::string>().c_str()):obj["meanfile"].get<std::string>());
        }
        if(obj.contains("batchsize"))
        {
            msg.batchsize = (obj["batchsize"].is_string()?atoi(obj["batchsize"].get<std::string>().c_str()):obj["batchsize"].get<uint32_t>());
        }
        if(obj.contains("cropsize"))
        {
            msg.cropsize = (obj["cropsize"].is_string()?atoi(obj["cropsize"].get<std::string>().c_str()):obj["cropsize"].get<uint32_t>());
        }
        if(obj.contains("mirror"))
        {
            msg.mirror = (obj["mirror"].is_string()?(bool)atoi(obj["mirror"].get<std::string>().c_str()):obj["mirror"].get<bool>());
        }
        if(obj.contains("fgthreshold"))
        {
            msg.fgthreshold = (obj["fgthreshold"].is_string()?(float)atof(obj["fgthreshold"].get<std::string>().c_str()):obj["fgthreshold"].get<float>());
        }
        if(obj.contains("bgthreshold"))
        {
            msg.bgthreshold = (obj["bgthreshold"].is_string()?(float)atof(obj["bgthreshold"].get<std::string>().c_str()):obj["bgthreshold"].get<float>());
        }
        if(obj.contains("fgfraction"))
        {
            msg.fgfraction = (obj["fgfraction"].is_string()?(float)atof(obj["fgfraction"].get<std::string>().c_str()):obj["fgfraction"].get<float>());
        }
        if(obj.contains("contextpad"))
        {
            msg.contextpad = (obj["contextpad"].is_string()?atoi(obj["contextpad"].get<std::string>().c_str()):obj["contextpad"].get<uint32_t>());
        }
        if(obj.contains("cropmode"))
        {
            msg.cropmode = (obj["cropmode"].is_string()?(obj["cropmode"].get<std::string>().c_str()):obj["cropmode"].get<std::string>());
        }
        if(obj.contains("cacheimages"))
        {
            msg.cacheimages = (obj["cacheimages"].is_string()?(bool)atoi(obj["cacheimages"].get<std::string>().c_str()):obj["cacheimages"].get<bool>());
        }
        if(obj.contains("rootfolder"))
        {
            msg.rootfolder = (obj["rootfolder"].is_string()?(obj["rootfolder"].get<std::string>().c_str()):obj["rootfolder"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceWindowDataParameter from_json<ApolloperceptioninferenceWindowDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceWindowDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceWindowDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceWindowDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceWindowDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceWindowDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
