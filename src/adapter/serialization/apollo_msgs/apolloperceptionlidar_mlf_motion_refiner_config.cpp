#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_motion_refiner_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfMotionRefinerConfig &msg) {
        nlohmann::json obj;
        obj["clapingaccelerationthreshold"] = (msg.clapingaccelerationthreshold);
        obj["clapingspeedthreshold"] = (msg.clapingspeedthreshold);
        return obj;
    }
    ApolloperceptionlidarMlfMotionRefinerConfig from_json_ApolloperceptionlidarMlfMotionRefinerConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfMotionRefinerConfig msg;
        if(obj.contains("clapingaccelerationthreshold"))
        {
            msg.clapingaccelerationthreshold = (obj["clapingaccelerationthreshold"].is_string()?atof(obj["clapingaccelerationthreshold"].get<std::string>().c_str()):obj["clapingaccelerationthreshold"].get<double>());
        }
        if(obj.contains("clapingspeedthreshold"))
        {
            msg.clapingspeedthreshold = (obj["clapingspeedthreshold"].is_string()?atof(obj["clapingspeedthreshold"].get<std::string>().c_str()):obj["clapingspeedthreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfMotionRefinerConfig from_json<ApolloperceptionlidarMlfMotionRefinerConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfMotionRefinerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfMotionRefinerConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfMotionRefinerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfMotionRefinerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfMotionRefinerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
