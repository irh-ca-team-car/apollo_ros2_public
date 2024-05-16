#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_smoke_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeSmokeParam &msg) {
        nlohmann::json obj;
        obj["modelparam"] = to_json(msg.modelparam);
        obj["netparam"] = to_json(msg.netparam);
        obj["nmsparam"] = to_json(msg.nmsparam);
        return obj;
    }
    ApolloperceptioncamerasmokeSmokeParam from_json_ApolloperceptioncamerasmokeSmokeParam (nlohmann::json obj) {
        ApolloperceptioncamerasmokeSmokeParam msg;
        if(obj.contains("modelparam"))
        {
            msg.modelparam = from_json_ApolloperceptioncamerasmokeModelParam(obj["modelparam"]);
        }
        if(obj.contains("netparam"))
        {
            msg.netparam = from_json_ApolloperceptioncamerasmokeNetworkParam(obj["netparam"]);
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioncamerasmokeNMSParam(obj["nmsparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerasmokeSmokeParam from_json<ApolloperceptioncamerasmokeSmokeParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerasmokeSmokeParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeSmokeParam &dt)
    {
        dt=from_json_ApolloperceptioncamerasmokeSmokeParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeSmokeParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeSmokeParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
