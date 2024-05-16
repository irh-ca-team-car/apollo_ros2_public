#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_lidar_segmentation_component_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLidarSegmentationComponentConfig &msg) {
        nlohmann::json obj;
        obj["sensorname"] = (msg.sensorname);
        obj["enablehdmap"] = (msg.enablehdmap);
        obj["lidarquerytfoffset"] = (msg.lidarquerytfoffset);
        obj["lidar2novateltf2childframeid"] = (msg.lidar2novateltf2childframeid);
        obj["outputchannelname"] = (msg.outputchannelname);
        return obj;
    }
    ApolloperceptiononboardLidarSegmentationComponentConfig from_json_ApolloperceptiononboardLidarSegmentationComponentConfig (nlohmann::json obj) {
        ApolloperceptiononboardLidarSegmentationComponentConfig msg;
        if(obj.contains("sensorname"))
        {
            msg.sensorname = (obj["sensorname"].is_string()?(obj["sensorname"].get<std::string>().c_str()):obj["sensorname"].get<std::string>());
        }
        if(obj.contains("enablehdmap"))
        {
            msg.enablehdmap = (obj["enablehdmap"].is_string()?(bool)atoi(obj["enablehdmap"].get<std::string>().c_str()):obj["enablehdmap"].get<bool>());
        }
        if(obj.contains("lidarquerytfoffset"))
        {
            msg.lidarquerytfoffset = (obj["lidarquerytfoffset"].is_string()?atof(obj["lidarquerytfoffset"].get<std::string>().c_str()):obj["lidarquerytfoffset"].get<double>());
        }
        if(obj.contains("lidar2novateltf2childframeid"))
        {
            msg.lidar2novateltf2childframeid = (obj["lidar2novateltf2childframeid"].is_string()?(obj["lidar2novateltf2childframeid"].get<std::string>().c_str()):obj["lidar2novateltf2childframeid"].get<std::string>());
        }
        if(obj.contains("outputchannelname"))
        {
            msg.outputchannelname = (obj["outputchannelname"].is_string()?(obj["outputchannelname"].get<std::string>().c_str()):obj["outputchannelname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardLidarSegmentationComponentConfig from_json<ApolloperceptiononboardLidarSegmentationComponentConfig>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardLidarSegmentationComponentConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLidarSegmentationComponentConfig &dt)
    {
        dt=from_json_ApolloperceptiononboardLidarSegmentationComponentConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLidarSegmentationComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLidarSegmentationComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
