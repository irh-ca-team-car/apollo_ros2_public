#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_motion_filter_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfMotionFilterConfig &msg) {
        nlohmann::json obj;
        obj["useadaptive"] = (msg.useadaptive);
        obj["usebreakdown"] = (msg.usebreakdown);
        obj["useconvergenceboostup"] = (msg.useconvergenceboostup);
        obj["initvelocityvariance"] = (msg.initvelocityvariance);
        obj["initaccelerationvariance"] = (msg.initaccelerationvariance);
        obj["measuredvelocityvariance"] = (msg.measuredvelocityvariance);
        obj["predictvariancepersqrsec"] = (msg.predictvariancepersqrsec);
        obj["boostuphistorysizeminimum"] = (msg.boostuphistorysizeminimum);
        obj["boostuphistorysizemaximum"] = (msg.boostuphistorysizemaximum);
        obj["convergedconfidenceminimum"] = (msg.convergedconfidenceminimum);
        obj["noisemaximum"] = (msg.noisemaximum);
        obj["trustorientationrange"] = (msg.trustorientationrange);
        return obj;
    }
    ApolloperceptionlidarMlfMotionFilterConfig from_json_ApolloperceptionlidarMlfMotionFilterConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfMotionFilterConfig msg;
        if(obj.contains("useadaptive"))
        {
            msg.useadaptive = (obj["useadaptive"].is_string()?(bool)atoi(obj["useadaptive"].get<std::string>().c_str()):obj["useadaptive"].get<bool>());
        }
        if(obj.contains("usebreakdown"))
        {
            msg.usebreakdown = (obj["usebreakdown"].is_string()?(bool)atoi(obj["usebreakdown"].get<std::string>().c_str()):obj["usebreakdown"].get<bool>());
        }
        if(obj.contains("useconvergenceboostup"))
        {
            msg.useconvergenceboostup = (obj["useconvergenceboostup"].is_string()?(bool)atoi(obj["useconvergenceboostup"].get<std::string>().c_str()):obj["useconvergenceboostup"].get<bool>());
        }
        if(obj.contains("initvelocityvariance"))
        {
            msg.initvelocityvariance = (obj["initvelocityvariance"].is_string()?atof(obj["initvelocityvariance"].get<std::string>().c_str()):obj["initvelocityvariance"].get<double>());
        }
        if(obj.contains("initaccelerationvariance"))
        {
            msg.initaccelerationvariance = (obj["initaccelerationvariance"].is_string()?atof(obj["initaccelerationvariance"].get<std::string>().c_str()):obj["initaccelerationvariance"].get<double>());
        }
        if(obj.contains("measuredvelocityvariance"))
        {
            msg.measuredvelocityvariance = (obj["measuredvelocityvariance"].is_string()?atof(obj["measuredvelocityvariance"].get<std::string>().c_str()):obj["measuredvelocityvariance"].get<double>());
        }
        if(obj.contains("predictvariancepersqrsec"))
        {
            msg.predictvariancepersqrsec = (obj["predictvariancepersqrsec"].is_string()?atof(obj["predictvariancepersqrsec"].get<std::string>().c_str()):obj["predictvariancepersqrsec"].get<double>());
        }
        if(obj.contains("boostuphistorysizeminimum"))
        {
            msg.boostuphistorysizeminimum = (obj["boostuphistorysizeminimum"].is_string()?atoi(obj["boostuphistorysizeminimum"].get<std::string>().c_str()):obj["boostuphistorysizeminimum"].get<uint32_t>());
        }
        if(obj.contains("boostuphistorysizemaximum"))
        {
            msg.boostuphistorysizemaximum = (obj["boostuphistorysizemaximum"].is_string()?atoi(obj["boostuphistorysizemaximum"].get<std::string>().c_str()):obj["boostuphistorysizemaximum"].get<uint32_t>());
        }
        if(obj.contains("convergedconfidenceminimum"))
        {
            msg.convergedconfidenceminimum = (obj["convergedconfidenceminimum"].is_string()?atof(obj["convergedconfidenceminimum"].get<std::string>().c_str()):obj["convergedconfidenceminimum"].get<double>());
        }
        if(obj.contains("noisemaximum"))
        {
            msg.noisemaximum = (obj["noisemaximum"].is_string()?atof(obj["noisemaximum"].get<std::string>().c_str()):obj["noisemaximum"].get<double>());
        }
        if(obj.contains("trustorientationrange"))
        {
            msg.trustorientationrange = (obj["trustorientationrange"].is_string()?atof(obj["trustorientationrange"].get<std::string>().c_str()):obj["trustorientationrange"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfMotionFilterConfig from_json<ApolloperceptionlidarMlfMotionFilterConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfMotionFilterConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfMotionFilterConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfMotionFilterConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfMotionFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfMotionFilterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
