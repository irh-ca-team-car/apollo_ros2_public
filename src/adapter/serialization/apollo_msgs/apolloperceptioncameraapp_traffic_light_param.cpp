#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_traffic_light_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappTrafficLightParam &msg) {
        nlohmann::json obj;
        nlohmann::json arr_detectorparam;
        for (auto it = msg.detectorparam.begin(); it != msg.detectorparam.end(); ++it) {
            arr_detectorparam.push_back(to_json(*it));
        }
        obj["detectorparam"] = arr_detectorparam;
        obj["trackerparam"] = to_json(msg.trackerparam);
        obj["gpuid"] = (msg.gpuid);
        return obj;
    }
    ApolloperceptioncameraappTrafficLightParam from_json_ApolloperceptioncameraappTrafficLightParam (nlohmann::json obj) {
        ApolloperceptioncameraappTrafficLightParam msg;
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
        if(obj.contains("gpuid"))
        {
            msg.gpuid = (obj["gpuid"].is_string()?atoi(obj["gpuid"].get<std::string>().c_str()):obj["gpuid"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappTrafficLightParam from_json<ApolloperceptioncameraappTrafficLightParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappTrafficLightParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappTrafficLightParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappTrafficLightParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappTrafficLightParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappTrafficLightParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
