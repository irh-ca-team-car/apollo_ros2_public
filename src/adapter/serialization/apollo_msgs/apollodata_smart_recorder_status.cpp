#include "adapter/serialization/apollo_msgs/apollodata_smart_recorder_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSmartRecorderStatus &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["recordingstate"] = (msg.recordingstate);
        obj["statemessage"] = (msg.statemessage);
        return obj;
    }
    ApollodataSmartRecorderStatus from_json_ApollodataSmartRecorderStatus (nlohmann::json obj) {
        ApollodataSmartRecorderStatus msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("recordingstate"))
        {
            msg.recordingstate = (obj["recordingstate"].is_string()?atoi(obj["recordingstate"].get<std::string>().c_str()):obj["recordingstate"].get<int>());
        }
        if(obj.contains("statemessage"))
        {
            msg.statemessage = (obj["statemessage"].is_string()?(obj["statemessage"].get<std::string>().c_str()):obj["statemessage"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodataSmartRecorderStatus from_json<ApollodataSmartRecorderStatus>(nlohmann::json obj){
        return from_json_ApollodataSmartRecorderStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSmartRecorderStatus &dt)
    {
        dt=from_json_ApollodataSmartRecorderStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataSmartRecorderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSmartRecorderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
