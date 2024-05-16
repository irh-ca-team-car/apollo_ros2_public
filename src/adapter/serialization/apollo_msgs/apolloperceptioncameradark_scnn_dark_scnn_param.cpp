#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_dark_scnn_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradarkSCNNDarkSCNNParam &msg) {
        nlohmann::json obj;
        obj["modelparam"] = to_json(msg.modelparam);
        obj["netparam"] = to_json(msg.netparam);
        return obj;
    }
    ApolloperceptioncameradarkSCNNDarkSCNNParam from_json_ApolloperceptioncameradarkSCNNDarkSCNNParam (nlohmann::json obj) {
        ApolloperceptioncameradarkSCNNDarkSCNNParam msg;
        if(obj.contains("modelparam"))
        {
            msg.modelparam = from_json_ApolloperceptioncameradarkSCNNModelParam(obj["modelparam"]);
        }
        if(obj.contains("netparam"))
        {
            msg.netparam = from_json_ApolloperceptioncameradarkSCNNNetworkParam(obj["netparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameradarkSCNNDarkSCNNParam from_json<ApolloperceptioncameradarkSCNNDarkSCNNParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameradarkSCNNDarkSCNNParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradarkSCNNDarkSCNNParam &dt)
    {
        dt=from_json_ApolloperceptioncameradarkSCNNDarkSCNNParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradarkSCNNDarkSCNNParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradarkSCNNDarkSCNNParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
