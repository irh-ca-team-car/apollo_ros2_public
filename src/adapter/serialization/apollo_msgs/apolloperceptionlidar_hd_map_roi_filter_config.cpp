#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_hd_map_roi_filter_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarHDMapRoiFilterConfig &msg) {
        nlohmann::json obj;
        obj["range"] = (msg.range);
        obj["cellsize"] = (msg.cellsize);
        obj["extenddist"] = (msg.extenddist);
        obj["noedgetable"] = (msg.noedgetable);
        obj["setroiservice"] = (msg.setroiservice);
        return obj;
    }
    ApolloperceptionlidarHDMapRoiFilterConfig from_json_ApolloperceptionlidarHDMapRoiFilterConfig (nlohmann::json obj) {
        ApolloperceptionlidarHDMapRoiFilterConfig msg;
        if(obj.contains("range"))
        {
            msg.range = (obj["range"].is_string()?atof(obj["range"].get<std::string>().c_str()):obj["range"].get<double>());
        }
        if(obj.contains("cellsize"))
        {
            msg.cellsize = (obj["cellsize"].is_string()?atof(obj["cellsize"].get<std::string>().c_str()):obj["cellsize"].get<double>());
        }
        if(obj.contains("extenddist"))
        {
            msg.extenddist = (obj["extenddist"].is_string()?atof(obj["extenddist"].get<std::string>().c_str()):obj["extenddist"].get<double>());
        }
        if(obj.contains("noedgetable"))
        {
            msg.noedgetable = (obj["noedgetable"].is_string()?(bool)atoi(obj["noedgetable"].get<std::string>().c_str()):obj["noedgetable"].get<bool>());
        }
        if(obj.contains("setroiservice"))
        {
            msg.setroiservice = (obj["setroiservice"].is_string()?(bool)atoi(obj["setroiservice"].get<std::string>().c_str()):obj["setroiservice"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarHDMapRoiFilterConfig from_json<ApolloperceptionlidarHDMapRoiFilterConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarHDMapRoiFilterConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarHDMapRoiFilterConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarHDMapRoiFilterConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarHDMapRoiFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarHDMapRoiFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
