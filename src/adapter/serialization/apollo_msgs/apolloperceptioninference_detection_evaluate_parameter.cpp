#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_evaluate_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDetectionEvaluateParameter &msg) {
        nlohmann::json obj;
        obj["numclasses"] = (msg.numclasses);
        obj["backgroundlabelid"] = (msg.backgroundlabelid);
        obj["overlapthreshold"] = (msg.overlapthreshold);
        obj["evaluatedifficultgt"] = (msg.evaluatedifficultgt);
        obj["namesizefile"] = (msg.namesizefile);
        obj["resizeparam"] = to_json(msg.resizeparam);
        return obj;
    }
    ApolloperceptioninferenceDetectionEvaluateParameter from_json_ApolloperceptioninferenceDetectionEvaluateParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDetectionEvaluateParameter msg;
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<uint32_t>());
        }
        if(obj.contains("backgroundlabelid"))
        {
            msg.backgroundlabelid = (obj["backgroundlabelid"].is_string()?atoi(obj["backgroundlabelid"].get<std::string>().c_str()):obj["backgroundlabelid"].get<uint32_t>());
        }
        if(obj.contains("overlapthreshold"))
        {
            msg.overlapthreshold = (obj["overlapthreshold"].is_string()?(float)atof(obj["overlapthreshold"].get<std::string>().c_str()):obj["overlapthreshold"].get<float>());
        }
        if(obj.contains("evaluatedifficultgt"))
        {
            msg.evaluatedifficultgt = (obj["evaluatedifficultgt"].is_string()?(bool)atoi(obj["evaluatedifficultgt"].get<std::string>().c_str()):obj["evaluatedifficultgt"].get<bool>());
        }
        if(obj.contains("namesizefile"))
        {
            msg.namesizefile = (obj["namesizefile"].is_string()?(obj["namesizefile"].get<std::string>().c_str()):obj["namesizefile"].get<std::string>());
        }
        if(obj.contains("resizeparam"))
        {
            msg.resizeparam = from_json_ApolloperceptioninferenceResizeParameter(obj["resizeparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDetectionEvaluateParameter from_json<ApolloperceptioninferenceDetectionEvaluateParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDetectionEvaluateParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDetectionEvaluateParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDetectionEvaluateParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDetectionEvaluateParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDetectionEvaluateParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
