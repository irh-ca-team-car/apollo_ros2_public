#include "adapter/serialization/apollo_msgs/apollolocalizationrtk_config_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationrtkConfigConfig &msg) {
        nlohmann::json obj;
        obj["localizationtopic"] = (msg.localizationtopic);
        obj["localizationstatustopic"] = (msg.localizationstatustopic);
        obj["imutopic"] = (msg.imutopic);
        obj["gpstopic"] = (msg.gpstopic);
        obj["gpsstatustopic"] = (msg.gpsstatustopic);
        obj["broadcasttfframeid"] = (msg.broadcasttfframeid);
        obj["broadcasttfchildframeid"] = (msg.broadcasttfchildframeid);
        obj["imulistmaxsize"] = (msg.imulistmaxsize);
        obj["gpsimutimediffthreshold"] = (msg.gpsimutimediffthreshold);
        obj["mapoffsetx"] = (msg.mapoffsetx);
        obj["mapoffsety"] = (msg.mapoffsety);
        obj["mapoffsetz"] = (msg.mapoffsetz);
        return obj;
    }
    ApollolocalizationrtkConfigConfig from_json_ApollolocalizationrtkConfigConfig (nlohmann::json obj) {
        ApollolocalizationrtkConfigConfig msg;
        if(obj.contains("localizationtopic"))
        {
            msg.localizationtopic = (obj["localizationtopic"].is_string()?(obj["localizationtopic"].get<std::string>().c_str()):obj["localizationtopic"].get<std::string>());
        }
        if(obj.contains("localizationstatustopic"))
        {
            msg.localizationstatustopic = (obj["localizationstatustopic"].is_string()?(obj["localizationstatustopic"].get<std::string>().c_str()):obj["localizationstatustopic"].get<std::string>());
        }
        if(obj.contains("imutopic"))
        {
            msg.imutopic = (obj["imutopic"].is_string()?(obj["imutopic"].get<std::string>().c_str()):obj["imutopic"].get<std::string>());
        }
        if(obj.contains("gpstopic"))
        {
            msg.gpstopic = (obj["gpstopic"].is_string()?(obj["gpstopic"].get<std::string>().c_str()):obj["gpstopic"].get<std::string>());
        }
        if(obj.contains("gpsstatustopic"))
        {
            msg.gpsstatustopic = (obj["gpsstatustopic"].is_string()?(obj["gpsstatustopic"].get<std::string>().c_str()):obj["gpsstatustopic"].get<std::string>());
        }
        if(obj.contains("broadcasttfframeid"))
        {
            msg.broadcasttfframeid = (obj["broadcasttfframeid"].is_string()?(obj["broadcasttfframeid"].get<std::string>().c_str()):obj["broadcasttfframeid"].get<std::string>());
        }
        if(obj.contains("broadcasttfchildframeid"))
        {
            msg.broadcasttfchildframeid = (obj["broadcasttfchildframeid"].is_string()?(obj["broadcasttfchildframeid"].get<std::string>().c_str()):obj["broadcasttfchildframeid"].get<std::string>());
        }
        if(obj.contains("imulistmaxsize"))
        {
            msg.imulistmaxsize = (obj["imulistmaxsize"].is_string()?atoi(obj["imulistmaxsize"].get<std::string>().c_str()):obj["imulistmaxsize"].get<int>());
        }
        if(obj.contains("gpsimutimediffthreshold"))
        {
            msg.gpsimutimediffthreshold = (obj["gpsimutimediffthreshold"].is_string()?atof(obj["gpsimutimediffthreshold"].get<std::string>().c_str()):obj["gpsimutimediffthreshold"].get<double>());
        }
        if(obj.contains("mapoffsetx"))
        {
            msg.mapoffsetx = (obj["mapoffsetx"].is_string()?atof(obj["mapoffsetx"].get<std::string>().c_str()):obj["mapoffsetx"].get<double>());
        }
        if(obj.contains("mapoffsety"))
        {
            msg.mapoffsety = (obj["mapoffsety"].is_string()?atof(obj["mapoffsety"].get<std::string>().c_str()):obj["mapoffsety"].get<double>());
        }
        if(obj.contains("mapoffsetz"))
        {
            msg.mapoffsetz = (obj["mapoffsetz"].is_string()?atof(obj["mapoffsetz"].get<std::string>().c_str()):obj["mapoffsetz"].get<double>());
        }
        return msg;
    }
    template <>
    ApollolocalizationrtkConfigConfig from_json<ApollolocalizationrtkConfigConfig>(nlohmann::json obj){
        return from_json_ApollolocalizationrtkConfigConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationrtkConfigConfig &dt)
    {
        dt=from_json_ApollolocalizationrtkConfigConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationrtkConfigConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationrtkConfigConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
