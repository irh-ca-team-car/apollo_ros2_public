#include "adapter/serialization/apollo_msgs/apolloperceptioncameratraffic_lightrecognition_recognize_box_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam &msg) {
        nlohmann::json obj;
        obj["verticalmodel"] = to_json(msg.verticalmodel);
        obj["quadratemodel"] = to_json(msg.quadratemodel);
        obj["horizontalmodel"] = to_json(msg.horizontalmodel);
        return obj;
    }
    ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam from_json_ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam (nlohmann::json obj) {
        ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam msg;
        if(obj.contains("verticalmodel"))
        {
            msg.verticalmodel = from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam(obj["verticalmodel"]);
        }
        if(obj.contains("quadratemodel"))
        {
            msg.quadratemodel = from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam(obj["quadratemodel"]);
        }
        if(obj.contains("horizontalmodel"))
        {
            msg.horizontalmodel = from_json_ApolloperceptioncameratrafficLightrecognitionClassifyParam(obj["horizontalmodel"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam from_json<ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrafficLightrecognitionRecognizeBoxParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
