#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_output_ssd_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDetectionOutputSSDParameter &msg) {
        nlohmann::json obj;
        obj["heatmapa"] = (msg.heatmapa);
        obj["minsizeh"] = (msg.minsizeh);
        obj["minsizew"] = (msg.minsizew);
        obj["minsizemode"] = (msg.minsizemode);
        obj["thresholdobjectness"] = (msg.thresholdobjectness);
        obj["genanchorparam"] = to_json(msg.genanchorparam);
        obj["refineoutofmapbbox"] = (msg.refineoutofmapbbox);
        obj["nmsparam"] = to_json(msg.nmsparam);
        obj["numclass"] = (msg.numclass);
        obj["rpnproposaloutputscore"] = (msg.rpnproposaloutputscore);
        obj["regressagnostic"] = (msg.regressagnostic);
        nlohmann::json arr_threshold;
        for (auto it = msg.threshold.begin(); it != msg.threshold.end(); ++it) {
            arr_threshold.push_back((*it));
        }
        obj["threshold"] = arr_threshold;
        return obj;
    }
    ApolloperceptioninferenceDetectionOutputSSDParameter from_json_ApolloperceptioninferenceDetectionOutputSSDParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDetectionOutputSSDParameter msg;
        if(obj.contains("heatmapa"))
        {
            msg.heatmapa = (obj["heatmapa"].is_string()?(float)atof(obj["heatmapa"].get<std::string>().c_str()):obj["heatmapa"].get<float>());
        }
        if(obj.contains("minsizeh"))
        {
            msg.minsizeh = (obj["minsizeh"].is_string()?(float)atof(obj["minsizeh"].get<std::string>().c_str()):obj["minsizeh"].get<float>());
        }
        if(obj.contains("minsizew"))
        {
            msg.minsizew = (obj["minsizew"].is_string()?(float)atof(obj["minsizew"].get<std::string>().c_str()):obj["minsizew"].get<float>());
        }
        if(obj.contains("minsizemode"))
        {
            msg.minsizemode = (obj["minsizemode"].is_string()?atoi(obj["minsizemode"].get<std::string>().c_str()):obj["minsizemode"].get<int>());
        }
        if(obj.contains("thresholdobjectness"))
        {
            msg.thresholdobjectness = (obj["thresholdobjectness"].is_string()?(float)atof(obj["thresholdobjectness"].get<std::string>().c_str()):obj["thresholdobjectness"].get<float>());
        }
        if(obj.contains("genanchorparam"))
        {
            msg.genanchorparam = from_json_ApolloperceptioninferenceGenAnchorParameter(obj["genanchorparam"]);
        }
        if(obj.contains("refineoutofmapbbox"))
        {
            msg.refineoutofmapbbox = (obj["refineoutofmapbbox"].is_string()?(bool)atoi(obj["refineoutofmapbbox"].get<std::string>().c_str()):obj["refineoutofmapbbox"].get<bool>());
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioninferenceNMSSSDParameter(obj["nmsparam"]);
        }
        if(obj.contains("numclass"))
        {
            msg.numclass = (obj["numclass"].is_string()?atoi(obj["numclass"].get<std::string>().c_str()):obj["numclass"].get<uint32_t>());
        }
        if(obj.contains("rpnproposaloutputscore"))
        {
            msg.rpnproposaloutputscore = (obj["rpnproposaloutputscore"].is_string()?(bool)atoi(obj["rpnproposaloutputscore"].get<std::string>().c_str()):obj["rpnproposaloutputscore"].get<bool>());
        }
        if(obj.contains("regressagnostic"))
        {
            msg.regressagnostic = (obj["regressagnostic"].is_string()?(bool)atoi(obj["regressagnostic"].get<std::string>().c_str()):obj["regressagnostic"].get<bool>());
        }
        if(obj.contains("threshold"))
        {
            if(obj["threshold"].is_array())
            {
                for (auto& element : obj["threshold"])
                {
                    msg.threshold.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.threshold.push_back((obj["threshold"].is_string()?(float)atof(obj["threshold"].get<std::string>().c_str()):obj["threshold"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDetectionOutputSSDParameter from_json<ApolloperceptioninferenceDetectionOutputSSDParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDetectionOutputSSDParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDetectionOutputSSDParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDetectionOutputSSDParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDetectionOutputSSDParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDetectionOutputSSDParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
