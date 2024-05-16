#include "adapter/serialization/apollo_msgs/apolloperceptioninference_roi_pooling_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceROIPoolingParameter &msg) {
        nlohmann::json obj;
        obj["pooledh"] = (msg.pooledh);
        obj["pooledw"] = (msg.pooledw);
        obj["spatialscale"] = (msg.spatialscale);
        obj["usefloor"] = (msg.usefloor);
        return obj;
    }
    ApolloperceptioninferenceROIPoolingParameter from_json_ApolloperceptioninferenceROIPoolingParameter (nlohmann::json obj) {
        ApolloperceptioninferenceROIPoolingParameter msg;
        if(obj.contains("pooledh"))
        {
            msg.pooledh = (obj["pooledh"].is_string()?atoi(obj["pooledh"].get<std::string>().c_str()):obj["pooledh"].get<uint32_t>());
        }
        if(obj.contains("pooledw"))
        {
            msg.pooledw = (obj["pooledw"].is_string()?atoi(obj["pooledw"].get<std::string>().c_str()):obj["pooledw"].get<uint32_t>());
        }
        if(obj.contains("spatialscale"))
        {
            msg.spatialscale = (obj["spatialscale"].is_string()?(float)atof(obj["spatialscale"].get<std::string>().c_str()):obj["spatialscale"].get<float>());
        }
        if(obj.contains("usefloor"))
        {
            msg.usefloor = (obj["usefloor"].is_string()?(bool)atoi(obj["usefloor"].get<std::string>().c_str()):obj["usefloor"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceROIPoolingParameter from_json<ApolloperceptioninferenceROIPoolingParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceROIPoolingParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceROIPoolingParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceROIPoolingParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceROIPoolingParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceROIPoolingParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
