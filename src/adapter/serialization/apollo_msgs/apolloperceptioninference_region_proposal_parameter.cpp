#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_proposal_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRegionProposalParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_anchorbox;
        for (auto it = msg.anchorbox.begin(); it != msg.anchorbox.end(); ++it) {
            arr_anchorbox.push_back(to_json(*it));
        }
        obj["anchorbox"] = arr_anchorbox;
        nlohmann::json arr_thresholds;
        for (auto it = msg.thresholds.begin(); it != msg.thresholds.end(); ++it) {
            arr_thresholds.push_back((*it));
        }
        obj["thresholds"] = arr_thresholds;
        obj["orientationscale"] = (msg.orientationscale);
        obj["objectscale"] = (msg.objectscale);
        obj["noobjectscale"] = (msg.noobjectscale);
        obj["classscale"] = (msg.classscale);
        obj["coordscale"] = (msg.coordscale);
        obj["jitter"] = (msg.jitter);
        obj["bias"] = (msg.bias);
        obj["rescore"] = (msg.rescore);
        obj["numclasses"] = (msg.numclasses);
        obj["biasmatch"] = (msg.biasmatch);
        obj["threshold"] = (msg.threshold);
        obj["trickyiter"] = (msg.trickyiter);
        obj["nmsparam"] = to_json(msg.nmsparam);
        obj["keeptopk"] = (msg.keeptopk);
        obj["posthreshold"] = (msg.posthreshold);
        obj["negthreshold"] = (msg.negthreshold);
        obj["negratio"] = (msg.negratio);
        return obj;
    }
    ApolloperceptioninferenceRegionProposalParameter from_json_ApolloperceptioninferenceRegionProposalParameter (nlohmann::json obj) {
        ApolloperceptioninferenceRegionProposalParameter msg;
        if(obj.contains("anchorbox"))
        {
            if(obj["anchorbox"].is_array())
            {
                for (auto& element : obj["anchorbox"])
                {
                    msg.anchorbox.push_back(from_json_ApolloperceptioninferenceAnchorBox(element));
                }
            }
            else
            {
                msg.anchorbox.push_back(from_json_ApolloperceptioninferenceAnchorBox(obj["anchorbox"]));
            }
        }
        if(obj.contains("thresholds"))
        {
            if(obj["thresholds"].is_array())
            {
                for (auto& element : obj["thresholds"])
                {
                    msg.thresholds.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.thresholds.push_back((obj["thresholds"].is_string()?(float)atof(obj["thresholds"].get<std::string>().c_str()):obj["thresholds"].get<float>()));
            }
        }
        if(obj.contains("orientationscale"))
        {
            msg.orientationscale = (obj["orientationscale"].is_string()?(float)atof(obj["orientationscale"].get<std::string>().c_str()):obj["orientationscale"].get<float>());
        }
        if(obj.contains("objectscale"))
        {
            msg.objectscale = (obj["objectscale"].is_string()?atoi(obj["objectscale"].get<std::string>().c_str()):obj["objectscale"].get<uint32_t>());
        }
        if(obj.contains("noobjectscale"))
        {
            msg.noobjectscale = (obj["noobjectscale"].is_string()?atoi(obj["noobjectscale"].get<std::string>().c_str()):obj["noobjectscale"].get<uint32_t>());
        }
        if(obj.contains("classscale"))
        {
            msg.classscale = (obj["classscale"].is_string()?atoi(obj["classscale"].get<std::string>().c_str()):obj["classscale"].get<uint32_t>());
        }
        if(obj.contains("coordscale"))
        {
            msg.coordscale = (obj["coordscale"].is_string()?atoi(obj["coordscale"].get<std::string>().c_str()):obj["coordscale"].get<uint32_t>());
        }
        if(obj.contains("jitter"))
        {
            msg.jitter = (obj["jitter"].is_string()?(float)atof(obj["jitter"].get<std::string>().c_str()):obj["jitter"].get<float>());
        }
        if(obj.contains("bias"))
        {
            msg.bias = (obj["bias"].is_string()?(float)atof(obj["bias"].get<std::string>().c_str()):obj["bias"].get<float>());
        }
        if(obj.contains("rescore"))
        {
            msg.rescore = (obj["rescore"].is_string()?(bool)atoi(obj["rescore"].get<std::string>().c_str()):obj["rescore"].get<bool>());
        }
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<uint32_t>());
        }
        if(obj.contains("biasmatch"))
        {
            msg.biasmatch = (obj["biasmatch"].is_string()?(bool)atoi(obj["biasmatch"].get<std::string>().c_str()):obj["biasmatch"].get<bool>());
        }
        if(obj.contains("threshold"))
        {
            msg.threshold = (obj["threshold"].is_string()?(float)atof(obj["threshold"].get<std::string>().c_str()):obj["threshold"].get<float>());
        }
        if(obj.contains("trickyiter"))
        {
            msg.trickyiter = (obj["trickyiter"].is_string()?atoi(obj["trickyiter"].get<std::string>().c_str()):obj["trickyiter"].get<uint32_t>());
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter(obj["nmsparam"]);
        }
        if(obj.contains("keeptopk"))
        {
            msg.keeptopk = (obj["keeptopk"].is_string()?atoi(obj["keeptopk"].get<std::string>().c_str()):obj["keeptopk"].get<int>());
        }
        if(obj.contains("posthreshold"))
        {
            msg.posthreshold = (obj["posthreshold"].is_string()?(float)atof(obj["posthreshold"].get<std::string>().c_str()):obj["posthreshold"].get<float>());
        }
        if(obj.contains("negthreshold"))
        {
            msg.negthreshold = (obj["negthreshold"].is_string()?(float)atof(obj["negthreshold"].get<std::string>().c_str()):obj["negthreshold"].get<float>());
        }
        if(obj.contains("negratio"))
        {
            msg.negratio = (obj["negratio"].is_string()?atoi(obj["negratio"].get<std::string>().c_str()):obj["negratio"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceRegionProposalParameter from_json<ApolloperceptioninferenceRegionProposalParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceRegionProposalParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRegionProposalParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceRegionProposalParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRegionProposalParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRegionProposalParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
