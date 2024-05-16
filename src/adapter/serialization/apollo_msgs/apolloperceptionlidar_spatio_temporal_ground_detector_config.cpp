#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_spatio_temporal_ground_detector_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarSpatioTemporalGroundDetectorConfig &msg) {
        nlohmann::json obj;
        obj["gridsize"] = (msg.gridsize);
        obj["groundthres"] = (msg.groundthres);
        obj["roiradx"] = (msg.roiradx);
        obj["roirady"] = (msg.roirady);
        obj["roiradz"] = (msg.roiradz);
        obj["nrsmoothiter"] = (msg.nrsmoothiter);
        obj["useroi"] = (msg.useroi);
        obj["usegroundservice"] = (msg.usegroundservice);
        return obj;
    }
    ApolloperceptionlidarSpatioTemporalGroundDetectorConfig from_json_ApolloperceptionlidarSpatioTemporalGroundDetectorConfig (nlohmann::json obj) {
        ApolloperceptionlidarSpatioTemporalGroundDetectorConfig msg;
        if(obj.contains("gridsize"))
        {
            msg.gridsize = (obj["gridsize"].is_string()?atoi(obj["gridsize"].get<std::string>().c_str()):obj["gridsize"].get<uint32_t>());
        }
        if(obj.contains("groundthres"))
        {
            msg.groundthres = (obj["groundthres"].is_string()?(float)atof(obj["groundthres"].get<std::string>().c_str()):obj["groundthres"].get<float>());
        }
        if(obj.contains("roiradx"))
        {
            msg.roiradx = (obj["roiradx"].is_string()?(float)atof(obj["roiradx"].get<std::string>().c_str()):obj["roiradx"].get<float>());
        }
        if(obj.contains("roirady"))
        {
            msg.roirady = (obj["roirady"].is_string()?(float)atof(obj["roirady"].get<std::string>().c_str()):obj["roirady"].get<float>());
        }
        if(obj.contains("roiradz"))
        {
            msg.roiradz = (obj["roiradz"].is_string()?(float)atof(obj["roiradz"].get<std::string>().c_str()):obj["roiradz"].get<float>());
        }
        if(obj.contains("nrsmoothiter"))
        {
            msg.nrsmoothiter = (obj["nrsmoothiter"].is_string()?atoi(obj["nrsmoothiter"].get<std::string>().c_str()):obj["nrsmoothiter"].get<uint32_t>());
        }
        if(obj.contains("useroi"))
        {
            msg.useroi = (obj["useroi"].is_string()?(bool)atoi(obj["useroi"].get<std::string>().c_str()):obj["useroi"].get<bool>());
        }
        if(obj.contains("usegroundservice"))
        {
            msg.usegroundservice = (obj["usegroundservice"].is_string()?(bool)atoi(obj["usegroundservice"].get<std::string>().c_str()):obj["usegroundservice"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarSpatioTemporalGroundDetectorConfig from_json<ApolloperceptionlidarSpatioTemporalGroundDetectorConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarSpatioTemporalGroundDetectorConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarSpatioTemporalGroundDetectorConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarSpatioTemporalGroundDetectorConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarSpatioTemporalGroundDetectorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarSpatioTemporalGroundDetectorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
