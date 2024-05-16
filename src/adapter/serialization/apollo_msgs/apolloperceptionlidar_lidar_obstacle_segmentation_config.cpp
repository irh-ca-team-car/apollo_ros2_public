#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_lidar_obstacle_segmentation_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarLidarObstacleSegmentationConfig &msg) {
        nlohmann::json obj;
        obj["segmentor"] = (msg.segmentor);
        obj["usemapmanager"] = (msg.usemapmanager);
        obj["useobjectfilterbank"] = (msg.useobjectfilterbank);
        return obj;
    }
    ApolloperceptionlidarLidarObstacleSegmentationConfig from_json_ApolloperceptionlidarLidarObstacleSegmentationConfig (nlohmann::json obj) {
        ApolloperceptionlidarLidarObstacleSegmentationConfig msg;
        if(obj.contains("segmentor"))
        {
            msg.segmentor = (obj["segmentor"].is_string()?(obj["segmentor"].get<std::string>().c_str()):obj["segmentor"].get<std::string>());
        }
        if(obj.contains("usemapmanager"))
        {
            msg.usemapmanager = (obj["usemapmanager"].is_string()?(bool)atoi(obj["usemapmanager"].get<std::string>().c_str()):obj["usemapmanager"].get<bool>());
        }
        if(obj.contains("useobjectfilterbank"))
        {
            msg.useobjectfilterbank = (obj["useobjectfilterbank"].is_string()?(bool)atoi(obj["useobjectfilterbank"].get<std::string>().c_str()):obj["useobjectfilterbank"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarLidarObstacleSegmentationConfig from_json<ApolloperceptionlidarLidarObstacleSegmentationConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarLidarObstacleSegmentationConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarLidarObstacleSegmentationConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarLidarObstacleSegmentationConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarLidarObstacleSegmentationConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarLidarObstacleSegmentationConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
