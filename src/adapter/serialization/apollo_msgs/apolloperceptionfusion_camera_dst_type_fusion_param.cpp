#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_camera_dst_type_fusion_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionCameraDstTypeFusionParam &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["validdist"] = (msg.validdist);
        obj["reliability"] = (msg.reliability);
        obj["reliabilityforunknown"] = (msg.reliabilityforunknown);
        return obj;
    }
    ApolloperceptionfusionCameraDstTypeFusionParam from_json_ApolloperceptionfusionCameraDstTypeFusionParam (nlohmann::json obj) {
        ApolloperceptionfusionCameraDstTypeFusionParam msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("validdist"))
        {
            msg.validdist = (obj["validdist"].is_string()?atof(obj["validdist"].get<std::string>().c_str()):obj["validdist"].get<double>());
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
    ApolloperceptionfusionCameraDstTypeFusionParam from_json<ApolloperceptionfusionCameraDstTypeFusionParam>(nlohmann::json obj){
        return from_json_ApolloperceptionfusionCameraDstTypeFusionParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionCameraDstTypeFusionParam &dt)
    {
        dt=from_json_ApolloperceptionfusionCameraDstTypeFusionParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionCameraDstTypeFusionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionCameraDstTypeFusionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
