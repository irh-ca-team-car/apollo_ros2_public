#include "adapter/serialization/apollo_msgs/apolloperceptioninference_save_output_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSaveOutputParameter &msg) {
        nlohmann::json obj;
        obj["outputdirectory"] = (msg.outputdirectory);
        obj["outputnameprefix"] = (msg.outputnameprefix);
        obj["outputformat"] = (msg.outputformat);
        obj["labelmapfile"] = (msg.labelmapfile);
        obj["namesizefile"] = (msg.namesizefile);
        obj["numtestimage"] = (msg.numtestimage);
        obj["resizeparam"] = to_json(msg.resizeparam);
        return obj;
    }
    ApolloperceptioninferenceSaveOutputParameter from_json_ApolloperceptioninferenceSaveOutputParameter (nlohmann::json obj) {
        ApolloperceptioninferenceSaveOutputParameter msg;
        if(obj.contains("outputdirectory"))
        {
            msg.outputdirectory = (obj["outputdirectory"].is_string()?(obj["outputdirectory"].get<std::string>().c_str()):obj["outputdirectory"].get<std::string>());
        }
        if(obj.contains("outputnameprefix"))
        {
            msg.outputnameprefix = (obj["outputnameprefix"].is_string()?(obj["outputnameprefix"].get<std::string>().c_str()):obj["outputnameprefix"].get<std::string>());
        }
        if(obj.contains("outputformat"))
        {
            msg.outputformat = (obj["outputformat"].is_string()?(obj["outputformat"].get<std::string>().c_str()):obj["outputformat"].get<std::string>());
        }
        if(obj.contains("labelmapfile"))
        {
            msg.labelmapfile = (obj["labelmapfile"].is_string()?(obj["labelmapfile"].get<std::string>().c_str()):obj["labelmapfile"].get<std::string>());
        }
        if(obj.contains("namesizefile"))
        {
            msg.namesizefile = (obj["namesizefile"].is_string()?(obj["namesizefile"].get<std::string>().c_str()):obj["namesizefile"].get<std::string>());
        }
        if(obj.contains("numtestimage"))
        {
            msg.numtestimage = (obj["numtestimage"].is_string()?atoi(obj["numtestimage"].get<std::string>().c_str()):obj["numtestimage"].get<uint32_t>());
        }
        if(obj.contains("resizeparam"))
        {
            msg.resizeparam = from_json_ApolloperceptioninferenceResizeParameter(obj["resizeparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSaveOutputParameter from_json<ApolloperceptioninferenceSaveOutputParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSaveOutputParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSaveOutputParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceSaveOutputParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSaveOutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSaveOutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
