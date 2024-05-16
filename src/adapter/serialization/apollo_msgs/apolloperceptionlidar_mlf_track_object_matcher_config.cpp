#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_track_object_matcher_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfTrackObjectMatcherConfig &msg) {
        nlohmann::json obj;
        obj["foregroundmathcermethod"] = (msg.foregroundmathcermethod);
        obj["backgroundmatchermethod"] = (msg.backgroundmatchermethod);
        obj["boundvalue"] = (msg.boundvalue);
        obj["maxmatchdistance"] = (msg.maxmatchdistance);
        return obj;
    }
    ApolloperceptionlidarMlfTrackObjectMatcherConfig from_json_ApolloperceptionlidarMlfTrackObjectMatcherConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfTrackObjectMatcherConfig msg;
        if(obj.contains("foregroundmathcermethod"))
        {
            msg.foregroundmathcermethod = (obj["foregroundmathcermethod"].is_string()?(obj["foregroundmathcermethod"].get<std::string>().c_str()):obj["foregroundmathcermethod"].get<std::string>());
        }
        if(obj.contains("backgroundmatchermethod"))
        {
            msg.backgroundmatchermethod = (obj["backgroundmatchermethod"].is_string()?(obj["backgroundmatchermethod"].get<std::string>().c_str()):obj["backgroundmatchermethod"].get<std::string>());
        }
        if(obj.contains("boundvalue"))
        {
            msg.boundvalue = (obj["boundvalue"].is_string()?(float)atof(obj["boundvalue"].get<std::string>().c_str()):obj["boundvalue"].get<float>());
        }
        if(obj.contains("maxmatchdistance"))
        {
            msg.maxmatchdistance = (obj["maxmatchdistance"].is_string()?(float)atof(obj["maxmatchdistance"].get<std::string>().c_str()):obj["maxmatchdistance"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfTrackObjectMatcherConfig from_json<ApolloperceptionlidarMlfTrackObjectMatcherConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfTrackObjectMatcherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfTrackObjectMatcherConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfTrackObjectMatcherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfTrackObjectMatcherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfTrackObjectMatcherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
