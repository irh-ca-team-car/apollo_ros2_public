#include "adapter/serialization/apollo_msgs/apolloperceptioninference_label_map.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLabelMap &msg) {
        nlohmann::json obj;
        nlohmann::json arr_item;
        for (auto it = msg.item.begin(); it != msg.item.end(); ++it) {
            arr_item.push_back(to_json(*it));
        }
        obj["item"] = arr_item;
        return obj;
    }
    ApolloperceptioninferenceLabelMap from_json_ApolloperceptioninferenceLabelMap (nlohmann::json obj) {
        ApolloperceptioninferenceLabelMap msg;
        if(obj.contains("item"))
        {
            if(obj["item"].is_array())
            {
                for (auto& element : obj["item"])
                {
                    msg.item.push_back(from_json_ApolloperceptioninferenceLabelMapItem(element));
                }
            }
            else
            {
                msg.item.push_back(from_json_ApolloperceptioninferenceLabelMapItem(obj["item"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceLabelMap from_json<ApolloperceptioninferenceLabelMap>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceLabelMap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLabelMap &dt)
    {
        dt=from_json_ApolloperceptioninferenceLabelMap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLabelMap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLabelMap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
