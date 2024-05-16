#include "adapter/serialization/apollo_msgs/apolloperceptioninference_repeated_list.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRepeatedList &msg) {
        nlohmann::json obj;
        obj["listpath"] = (msg.listpath);
        obj["numrepeat"] = (msg.numrepeat);
        return obj;
    }
    ApolloperceptioninferenceRepeatedList from_json_ApolloperceptioninferenceRepeatedList (nlohmann::json obj) {
        ApolloperceptioninferenceRepeatedList msg;
        if(obj.contains("listpath"))
        {
            msg.listpath = (obj["listpath"].is_string()?(obj["listpath"].get<std::string>().c_str()):obj["listpath"].get<std::string>());
        }
        if(obj.contains("numrepeat"))
        {
            msg.numrepeat = (obj["numrepeat"].is_string()?atoi(obj["numrepeat"].get<std::string>().c_str()):obj["numrepeat"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceRepeatedList from_json<ApolloperceptioninferenceRepeatedList>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceRepeatedList(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRepeatedList &dt)
    {
        dt=from_json_ApolloperceptioninferenceRepeatedList(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRepeatedList & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRepeatedList & dt)
    {
        os << to_json(dt);
        return os;
    }
}
