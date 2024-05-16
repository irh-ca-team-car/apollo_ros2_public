#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotation.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotation &msg) {
        nlohmann::json obj;
        obj["instanceid"] = (msg.instanceid);
        obj["bbox"] = to_json(msg.bbox);
        obj["bbox3d"] = to_json(msg.bbox3d);
        obj["frontbbox"] = to_json(msg.frontbbox);
        obj["rearbbox"] = to_json(msg.rearbbox);
        return obj;
    }
    ApolloperceptioninferenceAnnotation from_json_ApolloperceptioninferenceAnnotation (nlohmann::json obj) {
        ApolloperceptioninferenceAnnotation msg;
        if(obj.contains("instanceid"))
        {
            msg.instanceid = (obj["instanceid"].is_string()?atoi(obj["instanceid"].get<std::string>().c_str()):obj["instanceid"].get<int>());
        }
        if(obj.contains("bbox"))
        {
            msg.bbox = from_json_ApolloperceptioninferenceNormalizedBBox(obj["bbox"]);
        }
        if(obj.contains("bbox3d"))
        {
            msg.bbox3d = from_json_ApolloperceptioninferenceBBox3D(obj["bbox3d"]);
        }
        if(obj.contains("frontbbox"))
        {
            msg.frontbbox = from_json_ApolloperceptioninferenceNormalizedBBox(obj["frontbbox"]);
        }
        if(obj.contains("rearbbox"))
        {
            msg.rearbbox = from_json_ApolloperceptioninferenceNormalizedBBox(obj["rearbbox"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceAnnotation from_json<ApolloperceptioninferenceAnnotation>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceAnnotation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotation &dt)
    {
        dt=from_json_ApolloperceptioninferenceAnnotation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
