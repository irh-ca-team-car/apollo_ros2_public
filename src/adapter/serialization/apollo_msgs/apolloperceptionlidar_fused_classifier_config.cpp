#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_fused_classifier_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarFusedClassifierConfig &msg) {
        nlohmann::json obj;
        obj["temporalwindow"] = (msg.temporalwindow);
        obj["enabletemporalfusion"] = (msg.enabletemporalfusion);
        obj["oneshotfusionmethod"] = (msg.oneshotfusionmethod);
        obj["sequencefusionmethod"] = (msg.sequencefusionmethod);
        obj["usetrackedobjects"] = (msg.usetrackedobjects);
        return obj;
    }
    ApolloperceptionlidarFusedClassifierConfig from_json_ApolloperceptionlidarFusedClassifierConfig (nlohmann::json obj) {
        ApolloperceptionlidarFusedClassifierConfig msg;
        if(obj.contains("temporalwindow"))
        {
            msg.temporalwindow = (obj["temporalwindow"].is_string()?atof(obj["temporalwindow"].get<std::string>().c_str()):obj["temporalwindow"].get<double>());
        }
        if(obj.contains("enabletemporalfusion"))
        {
            msg.enabletemporalfusion = (obj["enabletemporalfusion"].is_string()?(bool)atoi(obj["enabletemporalfusion"].get<std::string>().c_str()):obj["enabletemporalfusion"].get<bool>());
        }
        if(obj.contains("oneshotfusionmethod"))
        {
            msg.oneshotfusionmethod = (obj["oneshotfusionmethod"].is_string()?(obj["oneshotfusionmethod"].get<std::string>().c_str()):obj["oneshotfusionmethod"].get<std::string>());
        }
        if(obj.contains("sequencefusionmethod"))
        {
            msg.sequencefusionmethod = (obj["sequencefusionmethod"].is_string()?(obj["sequencefusionmethod"].get<std::string>().c_str()):obj["sequencefusionmethod"].get<std::string>());
        }
        if(obj.contains("usetrackedobjects"))
        {
            msg.usetrackedobjects = (obj["usetrackedobjects"].is_string()?(bool)atoi(obj["usetrackedobjects"].get<std::string>().c_str()):obj["usetrackedobjects"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarFusedClassifierConfig from_json<ApolloperceptionlidarFusedClassifierConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarFusedClassifierConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarFusedClassifierConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarFusedClassifierConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarFusedClassifierConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarFusedClassifierConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
