#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lighttracker_semantic_revise_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLighttrackerSemanticReviseParam &msg) {
        nlohmann::json obj;
        obj["revisetimesecond"] = (msg.revisetimesecond);
        obj["blinkthresholdsecond"] = (msg.blinkthresholdsecond);
        obj["hystereticthresholdcount"] = (msg.hystereticthresholdcount);
        return obj;
    }
    ApolloperceptioncameratrafficLighttrackerSemanticReviseParam from_json_ApolloperceptioncameratrafficLighttrackerSemanticReviseParam (nlohmann::json obj) {
        ApolloperceptioncameratrafficLighttrackerSemanticReviseParam msg;
        if(obj.contains("revisetimesecond"))
        {
            msg.revisetimesecond = (obj["revisetimesecond"].is_string()?(float)atof(obj["revisetimesecond"].get<std::string>().c_str()):obj["revisetimesecond"].get<float>());
        }
        if(obj.contains("blinkthresholdsecond"))
        {
            msg.blinkthresholdsecond = (obj["blinkthresholdsecond"].is_string()?(float)atof(obj["blinkthresholdsecond"].get<std::string>().c_str()):obj["blinkthresholdsecond"].get<float>());
        }
        if(obj.contains("hystereticthresholdcount"))
        {
            msg.hystereticthresholdcount = (obj["hystereticthresholdcount"].is_string()?atoi(obj["hystereticthresholdcount"].get<std::string>().c_str()):obj["hystereticthresholdcount"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrafficLighttrackerSemanticReviseParam from_json<ApolloperceptioncameratrafficLighttrackerSemanticReviseParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrafficLighttrackerSemanticReviseParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLighttrackerSemanticReviseParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrafficLighttrackerSemanticReviseParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLighttrackerSemanticReviseParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLighttrackerSemanticReviseParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
