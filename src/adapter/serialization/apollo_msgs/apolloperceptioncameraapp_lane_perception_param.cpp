#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_lane_perception_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappLanePerceptionParam &msg) {
        nlohmann::json obj;
        obj["lanedetectorparam"] = to_json(msg.lanedetectorparam);
        obj["lanepostprocessorparam"] = to_json(msg.lanepostprocessorparam);
        obj["lanetrackerparam"] = to_json(msg.lanetrackerparam);
        obj["gpuid"] = (msg.gpuid);
        return obj;
    }
    ApolloperceptioncameraappLanePerceptionParam from_json_ApolloperceptioncameraappLanePerceptionParam (nlohmann::json obj) {
        ApolloperceptioncameraappLanePerceptionParam msg;
        if(obj.contains("lanedetectorparam"))
        {
            msg.lanedetectorparam = from_json_ApolloperceptioncameraappDetectorParam(obj["lanedetectorparam"]);
        }
        if(obj.contains("lanepostprocessorparam"))
        {
            msg.lanepostprocessorparam = from_json_ApolloperceptioncameraappPluginParam(obj["lanepostprocessorparam"]);
        }
        if(obj.contains("lanetrackerparam"))
        {
            msg.lanetrackerparam = from_json_ApolloperceptioncameraappPluginParam(obj["lanetrackerparam"]);
        }
        if(obj.contains("gpuid"))
        {
            msg.gpuid = (obj["gpuid"].is_string()?atoi(obj["gpuid"].get<std::string>().c_str()):obj["gpuid"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappLanePerceptionParam from_json<ApolloperceptioncameraappLanePerceptionParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappLanePerceptionParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappLanePerceptionParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappLanePerceptionParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappLanePerceptionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappLanePerceptionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
