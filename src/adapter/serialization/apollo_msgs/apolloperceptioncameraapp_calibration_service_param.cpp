#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_calibration_service_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappCalibrationServiceParam &msg) {
        nlohmann::json obj;
        obj["calibratormethod"] = (msg.calibratormethod);
        obj["pluginparam"] = to_json(msg.pluginparam);
        return obj;
    }
    ApolloperceptioncameraappCalibrationServiceParam from_json_ApolloperceptioncameraappCalibrationServiceParam (nlohmann::json obj) {
        ApolloperceptioncameraappCalibrationServiceParam msg;
        if(obj.contains("calibratormethod"))
        {
            msg.calibratormethod = (obj["calibratormethod"].is_string()?(obj["calibratormethod"].get<std::string>().c_str()):obj["calibratormethod"].get<std::string>());
        }
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappCalibrationServiceParam from_json<ApolloperceptioncameraappCalibrationServiceParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappCalibrationServiceParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappCalibrationServiceParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappCalibrationServiceParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappCalibrationServiceParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappCalibrationServiceParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
