#include "adapter/serialization/apollo_msgs/apollov2xftfusion_score_params.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionScoreParams &msg) {
        nlohmann::json obj;
        obj["probscale"] = (msg.probscale);
        obj["maxmatchdistance"] = (msg.maxmatchdistance);
        obj["minscore"] = (msg.minscore);
        obj["usemahalanobisdistance"] = (msg.usemahalanobisdistance);
        obj["checktype"] = (msg.checktype);
        obj["confidencelevel"] = (msg.confidencelevel);
        return obj;
    }
    Apollov2xftfusionScoreParams from_json_Apollov2xftfusionScoreParams (nlohmann::json obj) {
        Apollov2xftfusionScoreParams msg;
        if(obj.contains("probscale"))
        {
            msg.probscale = (obj["probscale"].is_string()?atof(obj["probscale"].get<std::string>().c_str()):obj["probscale"].get<double>());
        }
        if(obj.contains("maxmatchdistance"))
        {
            msg.maxmatchdistance = (obj["maxmatchdistance"].is_string()?atof(obj["maxmatchdistance"].get<std::string>().c_str()):obj["maxmatchdistance"].get<double>());
        }
        if(obj.contains("minscore"))
        {
            msg.minscore = (obj["minscore"].is_string()?atof(obj["minscore"].get<std::string>().c_str()):obj["minscore"].get<double>());
        }
        if(obj.contains("usemahalanobisdistance"))
        {
            msg.usemahalanobisdistance = (obj["usemahalanobisdistance"].is_string()?(bool)atoi(obj["usemahalanobisdistance"].get<std::string>().c_str()):obj["usemahalanobisdistance"].get<bool>());
        }
        if(obj.contains("checktype"))
        {
            msg.checktype = (obj["checktype"].is_string()?(bool)atoi(obj["checktype"].get<std::string>().c_str()):obj["checktype"].get<bool>());
        }
        if(obj.contains("confidencelevel"))
        {
            msg.confidencelevel = (obj["confidencelevel"].is_string()?atoi(obj["confidencelevel"].get<std::string>().c_str()):obj["confidencelevel"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xftfusionScoreParams from_json<Apollov2xftfusionScoreParams>(nlohmann::json obj){
        return from_json_Apollov2xftfusionScoreParams(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionScoreParams &dt)
    {
        dt=from_json_Apollov2xftfusionScoreParams(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionScoreParams & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionScoreParams & dt)
    {
        os << to_json(dt);
        return os;
    }
}
