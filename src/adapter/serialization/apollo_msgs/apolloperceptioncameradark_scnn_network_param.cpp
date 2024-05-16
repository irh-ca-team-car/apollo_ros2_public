#include "adapter/serialization/apollo_msgs/apolloperceptioncameradark_scnn_network_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradarkSCNNNetworkParam &msg) {
        nlohmann::json obj;
        obj["segblob"] = (msg.segblob);
        obj["vptblob"] = (msg.vptblob);
        obj["inputblob"] = (msg.inputblob);
        return obj;
    }
    ApolloperceptioncameradarkSCNNNetworkParam from_json_ApolloperceptioncameradarkSCNNNetworkParam (nlohmann::json obj) {
        ApolloperceptioncameradarkSCNNNetworkParam msg;
        if(obj.contains("segblob"))
        {
            msg.segblob = (obj["segblob"].is_string()?(obj["segblob"].get<std::string>().c_str()):obj["segblob"].get<std::string>());
        }
        if(obj.contains("vptblob"))
        {
            msg.vptblob = (obj["vptblob"].is_string()?(obj["vptblob"].get<std::string>().c_str()):obj["vptblob"].get<std::string>());
        }
        if(obj.contains("inputblob"))
        {
            msg.inputblob = (obj["inputblob"].is_string()?(obj["inputblob"].get<std::string>().c_str()):obj["inputblob"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameradarkSCNNNetworkParam from_json<ApolloperceptioncameradarkSCNNNetworkParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameradarkSCNNNetworkParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradarkSCNNNetworkParam &dt)
    {
        dt=from_json_ApolloperceptioncameradarkSCNNNetworkParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradarkSCNNNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradarkSCNNNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
