#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotation_group.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotationGroup &msg) {
        nlohmann::json obj;
        obj["grouplabel"] = (msg.grouplabel);
        nlohmann::json arr_annotation;
        for (auto it = msg.annotation.begin(); it != msg.annotation.end(); ++it) {
            arr_annotation.push_back(to_json(*it));
        }
        obj["annotation"] = arr_annotation;
        return obj;
    }
    ApolloperceptioninferenceAnnotationGroup from_json_ApolloperceptioninferenceAnnotationGroup (nlohmann::json obj) {
        ApolloperceptioninferenceAnnotationGroup msg;
        if(obj.contains("grouplabel"))
        {
            msg.grouplabel = (obj["grouplabel"].is_string()?atoi(obj["grouplabel"].get<std::string>().c_str()):obj["grouplabel"].get<int>());
        }
        if(obj.contains("annotation"))
        {
            if(obj["annotation"].is_array())
            {
                for (auto& element : obj["annotation"])
                {
                    msg.annotation.push_back(from_json_ApolloperceptioninferenceAnnotation(element));
                }
            }
            else
            {
                msg.annotation.push_back(from_json_ApolloperceptioninferenceAnnotation(obj["annotation"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceAnnotationGroup from_json<ApolloperceptioninferenceAnnotationGroup>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceAnnotationGroup(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotationGroup &dt)
    {
        dt=from_json_ApolloperceptioninferenceAnnotationGroup(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotationGroup & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotationGroup & dt)
    {
        os << to_json(dt);
        return os;
    }
}
