#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotated_datum.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotatedDatum &msg) {
        nlohmann::json obj;
        obj["datum"] = to_json(msg.datum);
        obj["type"] = (msg.type);
        nlohmann::json arr_annotationgroup;
        for (auto it = msg.annotationgroup.begin(); it != msg.annotationgroup.end(); ++it) {
            arr_annotationgroup.push_back(to_json(*it));
        }
        obj["annotationgroup"] = arr_annotationgroup;
        return obj;
    }
    ApolloperceptioninferenceAnnotatedDatum from_json_ApolloperceptioninferenceAnnotatedDatum (nlohmann::json obj) {
        ApolloperceptioninferenceAnnotatedDatum msg;
        if(obj.contains("datum"))
        {
            msg.datum = from_json_ApolloperceptioninferenceDatum(obj["datum"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("annotationgroup"))
        {
            if(obj["annotationgroup"].is_array())
            {
                for (auto& element : obj["annotationgroup"])
                {
                    msg.annotationgroup.push_back(from_json_ApolloperceptioninferenceAnnotationGroup(element));
                }
            }
            else
            {
                msg.annotationgroup.push_back(from_json_ApolloperceptioninferenceAnnotationGroup(obj["annotationgroup"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceAnnotatedDatum from_json<ApolloperceptioninferenceAnnotatedDatum>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceAnnotatedDatum(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotatedDatum &dt)
    {
        dt=from_json_ApolloperceptioninferenceAnnotatedDatum(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotatedDatum & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotatedDatum & dt)
    {
        os << to_json(dt);
        return os;
    }
}
