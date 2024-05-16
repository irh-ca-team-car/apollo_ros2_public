#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_pbf_tracker_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionPbfTrackerConfig &msg) {
        nlohmann::json obj;
        obj["typefusionmethod"] = (msg.typefusionmethod);
        obj["motionfusionmethod"] = (msg.motionfusionmethod);
        obj["shapefusionmethod"] = (msg.shapefusionmethod);
        obj["existencefusionmethod"] = (msg.existencefusionmethod);
        return obj;
    }
    ApolloperceptionfusionPbfTrackerConfig from_json_ApolloperceptionfusionPbfTrackerConfig (nlohmann::json obj) {
        ApolloperceptionfusionPbfTrackerConfig msg;
        if(obj.contains("typefusionmethod"))
        {
            msg.typefusionmethod = (obj["typefusionmethod"].is_string()?(obj["typefusionmethod"].get<std::string>().c_str()):obj["typefusionmethod"].get<std::string>());
        }
        if(obj.contains("motionfusionmethod"))
        {
            msg.motionfusionmethod = (obj["motionfusionmethod"].is_string()?(obj["motionfusionmethod"].get<std::string>().c_str()):obj["motionfusionmethod"].get<std::string>());
        }
        if(obj.contains("shapefusionmethod"))
        {
            msg.shapefusionmethod = (obj["shapefusionmethod"].is_string()?(obj["shapefusionmethod"].get<std::string>().c_str()):obj["shapefusionmethod"].get<std::string>());
        }
        if(obj.contains("existencefusionmethod"))
        {
            msg.existencefusionmethod = (obj["existencefusionmethod"].is_string()?(obj["existencefusionmethod"].get<std::string>().c_str()):obj["existencefusionmethod"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptionfusionPbfTrackerConfig from_json<ApolloperceptionfusionPbfTrackerConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionfusionPbfTrackerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionPbfTrackerConfig &dt)
    {
        dt=from_json_ApolloperceptionfusionPbfTrackerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionPbfTrackerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionPbfTrackerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
