#include "adapter/serialization/apollo_msgs/apollov2xftfusion_fusion_params.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionFusionParams &msg) {
        nlohmann::json obj;
        nlohmann::json arr_fusionparams;
        for (auto it = msg.fusionparams.begin(); it != msg.fusionparams.end(); ++it) {
            arr_fusionparams.push_back(to_json(*it));
        }
        obj["fusionparams"] = arr_fusionparams;
        obj["kmparams"] = to_json(msg.kmparams);
        obj["scoreparams"] = to_json(msg.scoreparams);
        return obj;
    }
    Apollov2xftfusionFusionParams from_json_Apollov2xftfusionFusionParams (nlohmann::json obj) {
        Apollov2xftfusionFusionParams msg;
        if(obj.contains("fusionparams"))
        {
            if(obj["fusionparams"].is_array())
            {
                for (auto& element : obj["fusionparams"])
                {
                    msg.fusionparams.push_back(from_json_Apollov2xftfusionSingleCameraParam(element));
                }
            }
            else
            {
                msg.fusionparams.push_back(from_json_Apollov2xftfusionSingleCameraParam(obj["fusionparams"]));
            }
        }
        if(obj.contains("kmparams"))
        {
            msg.kmparams = from_json_Apollov2xftfusionKMParams(obj["kmparams"]);
        }
        if(obj.contains("scoreparams"))
        {
            msg.scoreparams = from_json_Apollov2xftfusionScoreParams(obj["scoreparams"]);
        }
        return msg;
    }
    template <>
    Apollov2xftfusionFusionParams from_json<Apollov2xftfusionFusionParams>(nlohmann::json obj){
        return from_json_Apollov2xftfusionFusionParams(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionFusionParams &dt)
    {
        dt=from_json_Apollov2xftfusionFusionParams(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionFusionParams & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionFusionParams & dt)
    {
        os << to_json(dt);
        return os;
    }
}
