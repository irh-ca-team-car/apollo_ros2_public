#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotated_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceAnnotatedDataParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_batchsampler;
        for (auto it = msg.batchsampler.begin(); it != msg.batchsampler.end(); ++it) {
            arr_batchsampler.push_back(to_json(*it));
        }
        obj["batchsampler"] = arr_batchsampler;
        obj["labelmapfile"] = (msg.labelmapfile);
        obj["annotype"] = (msg.annotype);
        obj["numclasses"] = (msg.numclasses);
        return obj;
    }
    ApolloperceptioninferenceAnnotatedDataParameter from_json_ApolloperceptioninferenceAnnotatedDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceAnnotatedDataParameter msg;
        if(obj.contains("batchsampler"))
        {
            if(obj["batchsampler"].is_array())
            {
                for (auto& element : obj["batchsampler"])
                {
                    msg.batchsampler.push_back(from_json_ApolloperceptioninferenceBatchSampler(element));
                }
            }
            else
            {
                msg.batchsampler.push_back(from_json_ApolloperceptioninferenceBatchSampler(obj["batchsampler"]));
            }
        }
        if(obj.contains("labelmapfile"))
        {
            msg.labelmapfile = (obj["labelmapfile"].is_string()?(obj["labelmapfile"].get<std::string>().c_str()):obj["labelmapfile"].get<std::string>());
        }
        if(obj.contains("annotype"))
        {
            msg.annotype = (obj["annotype"].is_string()?atoi(obj["annotype"].get<std::string>().c_str()):obj["annotype"].get<int>());
        }
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceAnnotatedDataParameter from_json<ApolloperceptioninferenceAnnotatedDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceAnnotatedDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceAnnotatedDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceAnnotatedDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceAnnotatedDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceAnnotatedDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
