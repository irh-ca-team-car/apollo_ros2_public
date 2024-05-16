#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_dst_type_fusion_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionDstTypeFusionConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_cameraparams;
        for (auto it = msg.cameraparams.begin(); it != msg.cameraparams.end(); ++it) {
            arr_cameraparams.push_back(to_json(*it));
        }
        obj["cameraparams"] = arr_cameraparams;
        nlohmann::json arr_lidarparams;
        for (auto it = msg.lidarparams.begin(); it != msg.lidarparams.end(); ++it) {
            arr_lidarparams.push_back(to_json(*it));
        }
        obj["lidarparams"] = arr_lidarparams;
        return obj;
    }
    ApolloperceptionfusionDstTypeFusionConfig from_json_ApolloperceptionfusionDstTypeFusionConfig (nlohmann::json obj) {
        ApolloperceptionfusionDstTypeFusionConfig msg;
        if(obj.contains("cameraparams"))
        {
            if(obj["cameraparams"].is_array())
            {
                for (auto& element : obj["cameraparams"])
                {
                    msg.cameraparams.push_back(from_json_ApolloperceptionfusionCameraDstTypeFusionParam(element));
                }
            }
            else
            {
                msg.cameraparams.push_back(from_json_ApolloperceptionfusionCameraDstTypeFusionParam(obj["cameraparams"]));
            }
        }
        if(obj.contains("lidarparams"))
        {
            if(obj["lidarparams"].is_array())
            {
                for (auto& element : obj["lidarparams"])
                {
                    msg.lidarparams.push_back(from_json_ApolloperceptionfusionLidarDstTypeFusionParam(element));
                }
            }
            else
            {
                msg.lidarparams.push_back(from_json_ApolloperceptionfusionLidarDstTypeFusionParam(obj["lidarparams"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionfusionDstTypeFusionConfig from_json<ApolloperceptionfusionDstTypeFusionConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionfusionDstTypeFusionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionDstTypeFusionConfig &dt)
    {
        dt=from_json_ApolloperceptionfusionDstTypeFusionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionDstTypeFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionDstTypeFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
