#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_denseline_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradenselineDenselineParam &msg) {
        nlohmann::json obj;
        obj["modelparam"] = to_json(msg.modelparam);
        obj["netparam"] = to_json(msg.netparam);
        return obj;
    }
    ApolloperceptioncameradenselineDenselineParam from_json_ApolloperceptioncameradenselineDenselineParam (nlohmann::json obj) {
        ApolloperceptioncameradenselineDenselineParam msg;
        if(obj.contains("modelparam"))
        {
            msg.modelparam = from_json_ApolloperceptioncameradenselineModelParam(obj["modelparam"]);
        }
        if(obj.contains("netparam"))
        {
            msg.netparam = from_json_ApolloperceptioncameradenselineNetworkParam(obj["netparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameradenselineDenselineParam from_json<ApolloperceptioncameradenselineDenselineParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameradenselineDenselineParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradenselineDenselineParam &dt)
    {
        dt=from_json_ApolloperceptioncameradenselineDenselineParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradenselineDenselineParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradenselineDenselineParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
