#include "adapter/serialization/apollo_msgs/apolloperception_dst_existence_fusion_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionDstExistenceFusionConfig &msg) {
        nlohmann::json obj;
        obj["trackobjectmaxmatchdistance"] = (msg.trackobjectmaxmatchdistance);
        nlohmann::json arr_cameravaliddist;
        for (auto it = msg.cameravaliddist.begin(); it != msg.cameravaliddist.end(); ++it) {
            arr_cameravaliddist.push_back(to_json(*it));
        }
        obj["cameravaliddist"] = arr_cameravaliddist;
        return obj;
    }
    ApolloperceptionDstExistenceFusionConfig from_json_ApolloperceptionDstExistenceFusionConfig (nlohmann::json obj) {
        ApolloperceptionDstExistenceFusionConfig msg;
        if(obj.contains("trackobjectmaxmatchdistance"))
        {
            msg.trackobjectmaxmatchdistance = (obj["trackobjectmaxmatchdistance"].is_string()?atof(obj["trackobjectmaxmatchdistance"].get<std::string>().c_str()):obj["trackobjectmaxmatchdistance"].get<double>());
        }
        if(obj.contains("cameravaliddist"))
        {
            if(obj["cameravaliddist"].is_array())
            {
                for (auto& element : obj["cameravaliddist"])
                {
                    msg.cameravaliddist.push_back(from_json_ApolloperceptionCameraValidDist(element));
                }
            }
            else
            {
                msg.cameravaliddist.push_back(from_json_ApolloperceptionCameraValidDist(obj["cameravaliddist"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionDstExistenceFusionConfig from_json<ApolloperceptionDstExistenceFusionConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionDstExistenceFusionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionDstExistenceFusionConfig &dt)
    {
        dt=from_json_ApolloperceptionDstExistenceFusionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionDstExistenceFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionDstExistenceFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
