#include "adapter/serialization/apollo_msgs/apolloperceptioninference_normalized_b_box.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNormalizedBBox &msg) {
        nlohmann::json obj;
        obj["xmin"] = (msg.xmin);
        obj["ymin"] = (msg.ymin);
        obj["xmax"] = (msg.xmax);
        obj["ymax"] = (msg.ymax);
        obj["label"] = (msg.label);
        obj["difficult"] = (msg.difficult);
        obj["score"] = (msg.score);
        obj["size"] = (msg.size);
        return obj;
    }
    ApolloperceptioninferenceNormalizedBBox from_json_ApolloperceptioninferenceNormalizedBBox (nlohmann::json obj) {
        ApolloperceptioninferenceNormalizedBBox msg;
        if(obj.contains("xmin"))
        {
            msg.xmin = (obj["xmin"].is_string()?(float)atof(obj["xmin"].get<std::string>().c_str()):obj["xmin"].get<float>());
        }
        if(obj.contains("ymin"))
        {
            msg.ymin = (obj["ymin"].is_string()?(float)atof(obj["ymin"].get<std::string>().c_str()):obj["ymin"].get<float>());
        }
        if(obj.contains("xmax"))
        {
            msg.xmax = (obj["xmax"].is_string()?(float)atof(obj["xmax"].get<std::string>().c_str()):obj["xmax"].get<float>());
        }
        if(obj.contains("ymax"))
        {
            msg.ymax = (obj["ymax"].is_string()?(float)atof(obj["ymax"].get<std::string>().c_str()):obj["ymax"].get<float>());
        }
        if(obj.contains("label"))
        {
            msg.label = (obj["label"].is_string()?atoi(obj["label"].get<std::string>().c_str()):obj["label"].get<int>());
        }
        if(obj.contains("difficult"))
        {
            msg.difficult = (obj["difficult"].is_string()?(bool)atoi(obj["difficult"].get<std::string>().c_str()):obj["difficult"].get<bool>());
        }
        if(obj.contains("score"))
        {
            msg.score = (obj["score"].is_string()?(float)atof(obj["score"].get<std::string>().c_str()):obj["score"].get<float>());
        }
        if(obj.contains("size"))
        {
            msg.size = (obj["size"].is_string()?(float)atof(obj["size"].get<std::string>().c_str()):obj["size"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNormalizedBBox from_json<ApolloperceptioninferenceNormalizedBBox>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNormalizedBBox(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNormalizedBBox &dt)
    {
        dt=from_json_ApolloperceptioninferenceNormalizedBBox(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNormalizedBBox & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNormalizedBBox & dt)
    {
        os << to_json(dt);
        return os;
    }
}
