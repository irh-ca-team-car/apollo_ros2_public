#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_output_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRegionOutputParameter &msg) {
        nlohmann::json obj;
        obj["numclasses"] = (msg.numclasses);
        obj["nmsparam"] = to_json(msg.nmsparam);
        obj["keeptopk"] = (msg.keeptopk);
        obj["confidencethreshold"] = (msg.confidencethreshold);
        nlohmann::json arr_anchorbox;
        for (auto it = msg.anchorbox.begin(); it != msg.anchorbox.end(); ++it) {
            arr_anchorbox.push_back(to_json(*it));
        }
        obj["anchorbox"] = arr_anchorbox;
        obj["nmstype"] = (msg.nmstype);
        obj["nmssigma"] = (msg.nmssigma);
        obj["isrpn"] = (msg.isrpn);
        return obj;
    }
    ApolloperceptioninferenceRegionOutputParameter from_json_ApolloperceptioninferenceRegionOutputParameter (nlohmann::json obj) {
        ApolloperceptioninferenceRegionOutputParameter msg;
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<uint32_t>());
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter(obj["nmsparam"]);
        }
        if(obj.contains("keeptopk"))
        {
            msg.keeptopk = (obj["keeptopk"].is_string()?atoi(obj["keeptopk"].get<std::string>().c_str()):obj["keeptopk"].get<int>());
        }
        if(obj.contains("confidencethreshold"))
        {
            msg.confidencethreshold = (obj["confidencethreshold"].is_string()?(float)atof(obj["confidencethreshold"].get<std::string>().c_str()):obj["confidencethreshold"].get<float>());
        }
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
        if(obj.contains("nmstype"))
        {
            msg.nmstype = (obj["nmstype"].is_string()?atoi(obj["nmstype"].get<std::string>().c_str()):obj["nmstype"].get<int>());
        }
        if(obj.contains("nmssigma"))
        {
            msg.nmssigma = (obj["nmssigma"].is_string()?(float)atof(obj["nmssigma"].get<std::string>().c_str()):obj["nmssigma"].get<float>());
        }
        if(obj.contains("isrpn"))
        {
            msg.isrpn = (obj["isrpn"].is_string()?(bool)atoi(obj["isrpn"].get<std::string>().c_str()):obj["isrpn"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceRegionOutputParameter from_json<ApolloperceptioninferenceRegionOutputParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceRegionOutputParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRegionOutputParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceRegionOutputParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRegionOutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRegionOutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
