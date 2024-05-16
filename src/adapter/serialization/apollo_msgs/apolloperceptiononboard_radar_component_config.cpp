#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_radar_component_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardRadarComponentConfig &msg) {
        nlohmann::json obj;
        obj["radarname"] = (msg.radarname);
        obj["tfchildframeid"] = (msg.tfchildframeid);
        obj["radarforwarddistance"] = (msg.radarforwarddistance);
        obj["radarpreprocessormethod"] = (msg.radarpreprocessormethod);
        obj["radarperceptionmethod"] = (msg.radarperceptionmethod);
        obj["radarpipelinename"] = (msg.radarpipelinename);
        obj["odometrychannelname"] = (msg.odometrychannelname);
        obj["outputchannelname"] = (msg.outputchannelname);
        return obj;
    }
    ApolloperceptiononboardRadarComponentConfig from_json_ApolloperceptiononboardRadarComponentConfig (nlohmann::json obj) {
        ApolloperceptiononboardRadarComponentConfig msg;
        if(obj.contains("radarname"))
        {
            msg.radarname = (obj["radarname"].is_string()?(obj["radarname"].get<std::string>().c_str()):obj["radarname"].get<std::string>());
        }
        if(obj.contains("tfchildframeid"))
        {
            msg.tfchildframeid = (obj["tfchildframeid"].is_string()?(obj["tfchildframeid"].get<std::string>().c_str()):obj["tfchildframeid"].get<std::string>());
        }
        if(obj.contains("radarforwarddistance"))
        {
            msg.radarforwarddistance = (obj["radarforwarddistance"].is_string()?atof(obj["radarforwarddistance"].get<std::string>().c_str()):obj["radarforwarddistance"].get<double>());
        }
        if(obj.contains("radarpreprocessormethod"))
        {
            msg.radarpreprocessormethod = (obj["radarpreprocessormethod"].is_string()?(obj["radarpreprocessormethod"].get<std::string>().c_str()):obj["radarpreprocessormethod"].get<std::string>());
        }
        if(obj.contains("radarperceptionmethod"))
        {
            msg.radarperceptionmethod = (obj["radarperceptionmethod"].is_string()?(obj["radarperceptionmethod"].get<std::string>().c_str()):obj["radarperceptionmethod"].get<std::string>());
        }
        if(obj.contains("radarpipelinename"))
        {
            msg.radarpipelinename = (obj["radarpipelinename"].is_string()?(obj["radarpipelinename"].get<std::string>().c_str()):obj["radarpipelinename"].get<std::string>());
        }
        if(obj.contains("odometrychannelname"))
        {
            msg.odometrychannelname = (obj["odometrychannelname"].is_string()?(obj["odometrychannelname"].get<std::string>().c_str()):obj["odometrychannelname"].get<std::string>());
        }
        if(obj.contains("outputchannelname"))
        {
            msg.outputchannelname = (obj["outputchannelname"].is_string()?(obj["outputchannelname"].get<std::string>().c_str()):obj["outputchannelname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardRadarComponentConfig from_json<ApolloperceptiononboardRadarComponentConfig>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardRadarComponentConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardRadarComponentConfig &dt)
    {
        dt=from_json_ApolloperceptiononboardRadarComponentConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardRadarComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardRadarComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
