#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_perception_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappPerceptionParam &msg) {
        nlohmann::json obj;
        nlohmann::json arr_detectorparam;
        for (auto it = msg.detectorparam.begin(); it != msg.detectorparam.end(); ++it) {
            arr_detectorparam.push_back(to_json(*it));
        }
        obj["detectorparam"] = arr_detectorparam;
        obj["trackerparam"] = to_json(msg.trackerparam);
        obj["transformerparam"] = to_json(msg.transformerparam);
        obj["postprocessorparam"] = to_json(msg.postprocessorparam);
        obj["gpuid"] = (msg.gpuid);
        obj["cameraintrinsics"] = (msg.cameraintrinsics);
        obj["featureparam"] = to_json(msg.featureparam);
        nlohmann::json arr_laneparam;
        for (auto it = msg.laneparam.begin(); it != msg.laneparam.end(); ++it) {
            arr_laneparam.push_back(to_json(*it));
        }
        obj["laneparam"] = arr_laneparam;
        obj["calibrationserviceparam"] = to_json(msg.calibrationserviceparam);
        obj["debugparam"] = to_json(msg.debugparam);
        obj["objecttemplateparam"] = to_json(msg.objecttemplateparam);
        return obj;
    }
    ApolloperceptioncameraappPerceptionParam from_json_ApolloperceptioncameraappPerceptionParam (nlohmann::json obj) {
        ApolloperceptioncameraappPerceptionParam msg;
        if(obj.contains("detectorparam"))
        {
            if(obj["detectorparam"].is_array())
            {
                for (auto& element : obj["detectorparam"])
                {
                    msg.detectorparam.push_back(from_json_ApolloperceptioncameraappDetectorParam(element));
                }
            }
            else
            {
                msg.detectorparam.push_back(from_json_ApolloperceptioncameraappDetectorParam(obj["detectorparam"]));
            }
        }
        if(obj.contains("trackerparam"))
        {
            msg.trackerparam = from_json_ApolloperceptioncameraappTrackerParam(obj["trackerparam"]);
        }
        if(obj.contains("transformerparam"))
        {
            msg.transformerparam = from_json_ApolloperceptioncameraappTransformerParam(obj["transformerparam"]);
        }
        if(obj.contains("postprocessorparam"))
        {
            msg.postprocessorparam = from_json_ApolloperceptioncameraappPostprocessorParam(obj["postprocessorparam"]);
        }
        if(obj.contains("gpuid"))
        {
            msg.gpuid = (obj["gpuid"].is_string()?atoi(obj["gpuid"].get<std::string>().c_str()):obj["gpuid"].get<int>());
        }
        if(obj.contains("cameraintrinsics"))
        {
            msg.cameraintrinsics = (obj["cameraintrinsics"].is_string()?(obj["cameraintrinsics"].get<std::string>().c_str()):obj["cameraintrinsics"].get<std::string>());
        }
        if(obj.contains("featureparam"))
        {
            msg.featureparam = from_json_ApolloperceptioncameraappFeatureParam(obj["featureparam"]);
        }
        if(obj.contains("laneparam"))
        {
            if(obj["laneparam"].is_array())
            {
                for (auto& element : obj["laneparam"])
                {
                    msg.laneparam.push_back(from_json_ApolloperceptioncameraappLanePerceptionParam(element));
                }
            }
            else
            {
                msg.laneparam.push_back(from_json_ApolloperceptioncameraappLanePerceptionParam(obj["laneparam"]));
            }
        }
        if(obj.contains("calibrationserviceparam"))
        {
            msg.calibrationserviceparam = from_json_ApolloperceptioncameraappCalibrationServiceParam(obj["calibrationserviceparam"]);
        }
        if(obj.contains("debugparam"))
        {
            msg.debugparam = from_json_ApolloperceptioncameraappDebugParam(obj["debugparam"]);
        }
        if(obj.contains("objecttemplateparam"))
        {
            msg.objecttemplateparam = from_json_ApolloperceptioncameraappObjectTemplateParam(obj["objecttemplateparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappPerceptionParam from_json<ApolloperceptioncameraappPerceptionParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappPerceptionParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappPerceptionParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappPerceptionParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappPerceptionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappPerceptionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
