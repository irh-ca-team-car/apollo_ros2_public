#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_ccrf_type_fusion_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarCcrfTypeFusionConfig &msg) {
        nlohmann::json obj;
        obj["classifierspropertyfilepath"] = (msg.classifierspropertyfilepath);
        obj["transitionpropertyfilepath"] = (msg.transitionpropertyfilepath);
        obj["transitionmatrixalpha"] = (msg.transitionmatrixalpha);
        return obj;
    }
    ApolloperceptionlidarCcrfTypeFusionConfig from_json_ApolloperceptionlidarCcrfTypeFusionConfig (nlohmann::json obj) {
        ApolloperceptionlidarCcrfTypeFusionConfig msg;
        if(obj.contains("classifierspropertyfilepath"))
        {
            msg.classifierspropertyfilepath = (obj["classifierspropertyfilepath"].is_string()?(obj["classifierspropertyfilepath"].get<std::string>().c_str()):obj["classifierspropertyfilepath"].get<std::string>());
        }
        if(obj.contains("transitionpropertyfilepath"))
        {
            msg.transitionpropertyfilepath = (obj["transitionpropertyfilepath"].is_string()?(obj["transitionpropertyfilepath"].get<std::string>().c_str()):obj["transitionpropertyfilepath"].get<std::string>());
        }
        if(obj.contains("transitionmatrixalpha"))
        {
            msg.transitionmatrixalpha = (obj["transitionmatrixalpha"].is_string()?(float)atof(obj["transitionmatrixalpha"].get<std::string>().c_str()):obj["transitionmatrixalpha"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarCcrfTypeFusionConfig from_json<ApolloperceptionlidarCcrfTypeFusionConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarCcrfTypeFusionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarCcrfTypeFusionConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarCcrfTypeFusionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarCcrfTypeFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarCcrfTypeFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
