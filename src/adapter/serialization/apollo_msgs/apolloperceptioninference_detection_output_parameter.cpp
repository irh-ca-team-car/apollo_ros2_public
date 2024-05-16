#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_output_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDetectionOutputParameter &msg) {
        nlohmann::json obj;
        obj["numclasses"] = (msg.numclasses);
        obj["sharelocation"] = (msg.sharelocation);
        obj["backgroundlabelid"] = (msg.backgroundlabelid);
        obj["nmsparam"] = to_json(msg.nmsparam);
        obj["saveoutputparam"] = to_json(msg.saveoutputparam);
        obj["codetype"] = (msg.codetype);
        obj["varianceencodedintarget"] = (msg.varianceencodedintarget);
        obj["keeptopk"] = (msg.keeptopk);
        obj["confidencethreshold"] = (msg.confidencethreshold);
        obj["visualize"] = (msg.visualize);
        obj["visualizethreshold"] = (msg.visualizethreshold);
        obj["savefile"] = (msg.savefile);
        return obj;
    }
    ApolloperceptioninferenceDetectionOutputParameter from_json_ApolloperceptioninferenceDetectionOutputParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDetectionOutputParameter msg;
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<uint32_t>());
        }
        if(obj.contains("sharelocation"))
        {
            msg.sharelocation = (obj["sharelocation"].is_string()?(bool)atoi(obj["sharelocation"].get<std::string>().c_str()):obj["sharelocation"].get<bool>());
        }
        if(obj.contains("backgroundlabelid"))
        {
            msg.backgroundlabelid = (obj["backgroundlabelid"].is_string()?atoi(obj["backgroundlabelid"].get<std::string>().c_str()):obj["backgroundlabelid"].get<int>());
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter(obj["nmsparam"]);
        }
        if(obj.contains("saveoutputparam"))
        {
            msg.saveoutputparam = from_json_ApolloperceptioninferenceSaveOutputParameter(obj["saveoutputparam"]);
        }
        if(obj.contains("codetype"))
        {
            msg.codetype = (obj["codetype"].is_string()?atoi(obj["codetype"].get<std::string>().c_str()):obj["codetype"].get<int>());
        }
        if(obj.contains("varianceencodedintarget"))
        {
            msg.varianceencodedintarget = (obj["varianceencodedintarget"].is_string()?(bool)atoi(obj["varianceencodedintarget"].get<std::string>().c_str()):obj["varianceencodedintarget"].get<bool>());
        }
        if(obj.contains("keeptopk"))
        {
            msg.keeptopk = (obj["keeptopk"].is_string()?atoi(obj["keeptopk"].get<std::string>().c_str()):obj["keeptopk"].get<int>());
        }
        if(obj.contains("confidencethreshold"))
        {
            msg.confidencethreshold = (obj["confidencethreshold"].is_string()?(float)atof(obj["confidencethreshold"].get<std::string>().c_str()):obj["confidencethreshold"].get<float>());
        }
        if(obj.contains("visualize"))
        {
            msg.visualize = (obj["visualize"].is_string()?(bool)atoi(obj["visualize"].get<std::string>().c_str()):obj["visualize"].get<bool>());
        }
        if(obj.contains("visualizethreshold"))
        {
            msg.visualizethreshold = (obj["visualizethreshold"].is_string()?(float)atof(obj["visualizethreshold"].get<std::string>().c_str()):obj["visualizethreshold"].get<float>());
        }
        if(obj.contains("savefile"))
        {
            msg.savefile = (obj["savefile"].is_string()?(obj["savefile"].get<std::string>().c_str()):obj["savefile"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDetectionOutputParameter from_json<ApolloperceptioninferenceDetectionOutputParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDetectionOutputParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDetectionOutputParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDetectionOutputParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDetectionOutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDetectionOutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
