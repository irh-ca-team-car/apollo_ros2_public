#include "adapter/serialization/apollo_msgs/apolloperceptioninference_label_map_item.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLabelMapItem &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["label"] = (msg.label);
        obj["displayname"] = (msg.displayname);
        return obj;
    }
    ApolloperceptioninferenceLabelMapItem from_json_ApolloperceptioninferenceLabelMapItem (nlohmann::json obj) {
        ApolloperceptioninferenceLabelMapItem msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("label"))
        {
            msg.label = (obj["label"].is_string()?atoi(obj["label"].get<std::string>().c_str()):obj["label"].get<int>());
        }
        if(obj.contains("displayname"))
        {
            msg.displayname = (obj["displayname"].is_string()?(obj["displayname"].get<std::string>().c_str()):obj["displayname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceLabelMapItem from_json<ApolloperceptioninferenceLabelMapItem>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceLabelMapItem(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLabelMapItem &dt)
    {
        dt=from_json_ApolloperceptioninferenceLabelMapItem(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLabelMapItem & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLabelMapItem & dt)
    {
        os << to_json(dt);
        return os;
    }
}
