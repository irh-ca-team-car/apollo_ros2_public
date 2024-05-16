#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_lidar_dst_type_fusion_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionLidarDstTypeFusionParam &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["reliability"] = (msg.reliability);
        obj["reliabilityforunknown"] = (msg.reliabilityforunknown);
        return obj;
    }
    ApolloperceptionfusionLidarDstTypeFusionParam from_json_ApolloperceptionfusionLidarDstTypeFusionParam (nlohmann::json obj) {
        ApolloperceptionfusionLidarDstTypeFusionParam msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("reliability"))
        {
            msg.reliability = (obj["reliability"].is_string()?atof(obj["reliability"].get<std::string>().c_str()):obj["reliability"].get<double>());
        }
        if(obj.contains("reliabilityforunknown"))
        {
            msg.reliabilityforunknown = (obj["reliabilityforunknown"].is_string()?atof(obj["reliabilityforunknown"].get<std::string>().c_str()):obj["reliabilityforunknown"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionfusionLidarDstTypeFusionParam from_json<ApolloperceptionfusionLidarDstTypeFusionParam>(nlohmann::json obj){
        return from_json_ApolloperceptionfusionLidarDstTypeFusionParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionLidarDstTypeFusionParam &dt)
    {
        dt=from_json_ApolloperceptionfusionLidarDstTypeFusionParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionLidarDstTypeFusionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionLidarDstTypeFusionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
