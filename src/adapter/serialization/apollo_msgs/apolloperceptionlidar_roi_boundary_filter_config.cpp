#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_roi_boundary_filter_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarROIBoundaryFilterConfig &msg) {
        nlohmann::json obj;
        obj["distancetoboundarythreshold"] = (msg.distancetoboundarythreshold);
        obj["confidencethreshold"] = (msg.confidencethreshold);
        obj["crossroithreshold"] = (msg.crossroithreshold);
        obj["insidethreshold"] = (msg.insidethreshold);
        return obj;
    }
    ApolloperceptionlidarROIBoundaryFilterConfig from_json_ApolloperceptionlidarROIBoundaryFilterConfig (nlohmann::json obj) {
        ApolloperceptionlidarROIBoundaryFilterConfig msg;
        if(obj.contains("distancetoboundarythreshold"))
        {
            msg.distancetoboundarythreshold = (obj["distancetoboundarythreshold"].is_string()?atof(obj["distancetoboundarythreshold"].get<std::string>().c_str()):obj["distancetoboundarythreshold"].get<double>());
        }
        if(obj.contains("confidencethreshold"))
        {
            msg.confidencethreshold = (obj["confidencethreshold"].is_string()?(float)atof(obj["confidencethreshold"].get<std::string>().c_str()):obj["confidencethreshold"].get<float>());
        }
        if(obj.contains("crossroithreshold"))
        {
            msg.crossroithreshold = (obj["crossroithreshold"].is_string()?(float)atof(obj["crossroithreshold"].get<std::string>().c_str()):obj["crossroithreshold"].get<float>());
        }
        if(obj.contains("insidethreshold"))
        {
            msg.insidethreshold = (obj["insidethreshold"].is_string()?atof(obj["insidethreshold"].get<std::string>().c_str()):obj["insidethreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarROIBoundaryFilterConfig from_json<ApolloperceptionlidarROIBoundaryFilterConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarROIBoundaryFilterConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarROIBoundaryFilterConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarROIBoundaryFilterConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarROIBoundaryFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarROIBoundaryFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
