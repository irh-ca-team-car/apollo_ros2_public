#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dataset_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDatasetParameter &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        obj["rootfolder"] = (msg.rootfolder);
        obj["weight"] = (msg.weight);
        obj["type"] = (msg.type);
        obj["shuffle"] = (msg.shuffle);
        nlohmann::json arr_repeatedlist;
        for (auto it = msg.repeatedlist.begin(); it != msg.repeatedlist.end(); ++it) {
            arr_repeatedlist.push_back(to_json(*it));
        }
        obj["repeatedlist"] = arr_repeatedlist;
        return obj;
    }
    ApolloperceptioninferenceDatasetParameter from_json_ApolloperceptioninferenceDatasetParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDatasetParameter msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        if(obj.contains("rootfolder"))
        {
            msg.rootfolder = (obj["rootfolder"].is_string()?(obj["rootfolder"].get<std::string>().c_str()):obj["rootfolder"].get<std::string>());
        }
        if(obj.contains("weight"))
        {
            msg.weight = (obj["weight"].is_string()?(float)atof(obj["weight"].get<std::string>().c_str()):obj["weight"].get<float>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("shuffle"))
        {
            msg.shuffle = (obj["shuffle"].is_string()?(bool)atoi(obj["shuffle"].get<std::string>().c_str()):obj["shuffle"].get<bool>());
        }
        if(obj.contains("repeatedlist"))
        {
            if(obj["repeatedlist"].is_array())
            {
                for (auto& element : obj["repeatedlist"])
                {
                    msg.repeatedlist.push_back(from_json_ApolloperceptioninferenceRepeatedList(element));
                }
            }
            else
            {
                msg.repeatedlist.push_back(from_json_ApolloperceptioninferenceRepeatedList(obj["repeatedlist"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDatasetParameter from_json<ApolloperceptioninferenceDatasetParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDatasetParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDatasetParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDatasetParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDatasetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDatasetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
