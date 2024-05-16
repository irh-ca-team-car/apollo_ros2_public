#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceRegionParameter &msg) {
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
        obj["dimensionscale"] = (msg.dimensionscale);
        obj["frontscale"] = (msg.frontscale);
        obj["rearscale"] = (msg.rearscale);
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
        obj["usel1loss"] = (msg.usel1loss);
        obj["usetwicesoftmax"] = (msg.usetwicesoftmax);
        obj["isanchornormalized"] = (msg.isanchornormalized);
        nlohmann::json arr_orienable;
        for (auto it = msg.orienable.begin(); it != msg.orienable.end(); ++it) {
            arr_orienable.push_back((*it));
        }
        obj["orienable"] = arr_orienable;
        obj["anchorfile"] = (msg.anchorfile);
        obj["usesideboxv2"] = (msg.usesideboxv2);
        obj["usesideboxv3"] = (msg.usesideboxv3);
        obj["oricycle"] = (msg.oricycle);
        return obj;
    }
    ApolloperceptioninferenceRegionParameter from_json_ApolloperceptioninferenceRegionParameter (nlohmann::json obj) {
        ApolloperceptioninferenceRegionParameter msg;
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
        if(obj.contains("dimensionscale"))
        {
            msg.dimensionscale = (obj["dimensionscale"].is_string()?(float)atof(obj["dimensionscale"].get<std::string>().c_str()):obj["dimensionscale"].get<float>());
        }
        if(obj.contains("frontscale"))
        {
            msg.frontscale = (obj["frontscale"].is_string()?(float)atof(obj["frontscale"].get<std::string>().c_str()):obj["frontscale"].get<float>());
        }
        if(obj.contains("rearscale"))
        {
            msg.rearscale = (obj["rearscale"].is_string()?(float)atof(obj["rearscale"].get<std::string>().c_str()):obj["rearscale"].get<float>());
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
            msg.classscale = (obj["classscale"].is_string()?(float)atof(obj["classscale"].get<std::string>().c_str()):obj["classscale"].get<float>());
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
        if(obj.contains("usel1loss"))
        {
            msg.usel1loss = (obj["usel1loss"].is_string()?(bool)atoi(obj["usel1loss"].get<std::string>().c_str()):obj["usel1loss"].get<bool>());
        }
        if(obj.contains("usetwicesoftmax"))
        {
            msg.usetwicesoftmax = (obj["usetwicesoftmax"].is_string()?(bool)atoi(obj["usetwicesoftmax"].get<std::string>().c_str()):obj["usetwicesoftmax"].get<bool>());
        }
        if(obj.contains("isanchornormalized"))
        {
            msg.isanchornormalized = (obj["isanchornormalized"].is_string()?(bool)atoi(obj["isanchornormalized"].get<std::string>().c_str()):obj["isanchornormalized"].get<bool>());
        }
        if(obj.contains("orienable"))
        {
            if(obj["orienable"].is_array())
            {
                for (auto& element : obj["orienable"])
                {
                    msg.orienable.push_back((element.is_string()?(bool)atoi(element.get<std::string>().c_str()):element.get<bool>()));
                }
            }
            else
            {
                msg.orienable.push_back((obj["orienable"].is_string()?(bool)atoi(obj["orienable"].get<std::string>().c_str()):obj["orienable"].get<bool>()));
            }
        }
        if(obj.contains("anchorfile"))
        {
            msg.anchorfile = (obj["anchorfile"].is_string()?(obj["anchorfile"].get<std::string>().c_str()):obj["anchorfile"].get<std::string>());
        }
        if(obj.contains("usesideboxv2"))
        {
            msg.usesideboxv2 = (obj["usesideboxv2"].is_string()?(bool)atoi(obj["usesideboxv2"].get<std::string>().c_str()):obj["usesideboxv2"].get<bool>());
        }
        if(obj.contains("usesideboxv3"))
        {
            msg.usesideboxv3 = (obj["usesideboxv3"].is_string()?(bool)atoi(obj["usesideboxv3"].get<std::string>().c_str()):obj["usesideboxv3"].get<bool>());
        }
        if(obj.contains("oricycle"))
        {
            msg.oricycle = (obj["oricycle"].is_string()?atoi(obj["oricycle"].get<std::string>().c_str()):obj["oricycle"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceRegionParameter from_json<ApolloperceptioninferenceRegionParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceRegionParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceRegionParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceRegionParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceRegionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceRegionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
