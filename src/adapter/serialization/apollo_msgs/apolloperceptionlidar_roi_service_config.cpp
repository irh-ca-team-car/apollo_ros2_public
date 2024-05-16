#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_roi_service_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarROIServiceConfig &msg) {
        nlohmann::json obj;
        obj["range"] = (msg.range);
        obj["cellsize"] = (msg.cellsize);
        return obj;
    }
    ApolloperceptionlidarROIServiceConfig from_json_ApolloperceptionlidarROIServiceConfig (nlohmann::json obj) {
        ApolloperceptionlidarROIServiceConfig msg;
        if(obj.contains("range"))
        {
            msg.range = (obj["range"].is_string()?atof(obj["range"].get<std::string>().c_str()):obj["range"].get<double>());
        }
        if(obj.contains("cellsize"))
        {
            msg.cellsize = (obj["cellsize"].is_string()?atof(obj["cellsize"].get<std::string>().c_str()):obj["cellsize"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarROIServiceConfig from_json<ApolloperceptionlidarROIServiceConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarROIServiceConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarROIServiceConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarROIServiceConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarROIServiceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarROIServiceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
