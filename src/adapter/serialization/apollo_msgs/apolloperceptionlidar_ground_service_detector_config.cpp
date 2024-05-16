#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_ground_service_detector_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarGroundServiceDetectorConfig &msg) {
        nlohmann::json obj;
        obj["groundthreshold"] = (msg.groundthreshold);
        return obj;
    }
    ApolloperceptionlidarGroundServiceDetectorConfig from_json_ApolloperceptionlidarGroundServiceDetectorConfig (nlohmann::json obj) {
        ApolloperceptionlidarGroundServiceDetectorConfig msg;
        if(obj.contains("groundthreshold"))
        {
            msg.groundthreshold = (obj["groundthreshold"].is_string()?atof(obj["groundthreshold"].get<std::string>().c_str()):obj["groundthreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarGroundServiceDetectorConfig from_json<ApolloperceptionlidarGroundServiceDetectorConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarGroundServiceDetectorConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarGroundServiceDetectorConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarGroundServiceDetectorConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarGroundServiceDetectorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarGroundServiceDetectorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
