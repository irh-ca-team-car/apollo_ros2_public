#include "adapter/serialization/apollo_msgs/apolloperceptioncamerayolo_yolo_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerayoloYoloParam &msg) {
        nlohmann::json obj;
        obj["modelparam"] = to_json(msg.modelparam);
        obj["netparam"] = to_json(msg.netparam);
        obj["nmsparam"] = to_json(msg.nmsparam);
        return obj;
    }
    ApolloperceptioncamerayoloYoloParam from_json_ApolloperceptioncamerayoloYoloParam (nlohmann::json obj) {
        ApolloperceptioncamerayoloYoloParam msg;
        if(obj.contains("modelparam"))
        {
            msg.modelparam = from_json_ApolloperceptioncamerayoloModelParam(obj["modelparam"]);
        }
        if(obj.contains("netparam"))
        {
            msg.netparam = from_json_ApolloperceptioncamerayoloNetworkParam(obj["netparam"]);
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioncamerayoloNMSParam(obj["nmsparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerayoloYoloParam from_json<ApolloperceptioncamerayoloYoloParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerayoloYoloParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerayoloYoloParam &dt)
    {
        dt=from_json_ApolloperceptioncamerayoloYoloParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerayoloYoloParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerayoloYoloParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
