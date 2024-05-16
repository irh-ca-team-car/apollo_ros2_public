#include "adapter/serialization/apollo_msgs/apolloplanning_navi_speed_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNaviSpeedDeciderConfig &msg) {
        nlohmann::json obj;
        obj["preferredaccel"] = (msg.preferredaccel);
        obj["preferreddecel"] = (msg.preferreddecel);
        obj["preferredjerk"] = (msg.preferredjerk);
        obj["maxaccel"] = (msg.maxaccel);
        obj["maxdecel"] = (msg.maxdecel);
        obj["obstaclebuffer"] = (msg.obstaclebuffer);
        obj["safedistancebase"] = (msg.safedistancebase);
        obj["safedistanceratio"] = (msg.safedistanceratio);
        obj["followingaccelratio"] = (msg.followingaccelratio);
        obj["softcentricaccellimit"] = (msg.softcentricaccellimit);
        obj["hardcentricaccellimit"] = (msg.hardcentricaccellimit);
        obj["hardspeedlimit"] = (msg.hardspeedlimit);
        obj["hardaccellimit"] = (msg.hardaccellimit);
        obj["enablesafepath"] = (msg.enablesafepath);
        obj["enableplanningstartpoint"] = (msg.enableplanningstartpoint);
        obj["enableaccelautocompensation"] = (msg.enableaccelautocompensation);
        obj["kappapreview"] = (msg.kappapreview);
        obj["kappathreshold"] = (msg.kappathreshold);
        return obj;
    }
    ApolloplanningNaviSpeedDeciderConfig from_json_ApolloplanningNaviSpeedDeciderConfig (nlohmann::json obj) {
        ApolloplanningNaviSpeedDeciderConfig msg;
        if(obj.contains("preferredaccel"))
        {
            msg.preferredaccel = (obj["preferredaccel"].is_string()?atof(obj["preferredaccel"].get<std::string>().c_str()):obj["preferredaccel"].get<double>());
        }
        if(obj.contains("preferreddecel"))
        {
            msg.preferreddecel = (obj["preferreddecel"].is_string()?atof(obj["preferreddecel"].get<std::string>().c_str()):obj["preferreddecel"].get<double>());
        }
        if(obj.contains("preferredjerk"))
        {
            msg.preferredjerk = (obj["preferredjerk"].is_string()?atof(obj["preferredjerk"].get<std::string>().c_str()):obj["preferredjerk"].get<double>());
        }
        if(obj.contains("maxaccel"))
        {
            msg.maxaccel = (obj["maxaccel"].is_string()?atof(obj["maxaccel"].get<std::string>().c_str()):obj["maxaccel"].get<double>());
        }
        if(obj.contains("maxdecel"))
        {
            msg.maxdecel = (obj["maxdecel"].is_string()?atof(obj["maxdecel"].get<std::string>().c_str()):obj["maxdecel"].get<double>());
        }
        if(obj.contains("obstaclebuffer"))
        {
            msg.obstaclebuffer = (obj["obstaclebuffer"].is_string()?atof(obj["obstaclebuffer"].get<std::string>().c_str()):obj["obstaclebuffer"].get<double>());
        }
        if(obj.contains("safedistancebase"))
        {
            msg.safedistancebase = (obj["safedistancebase"].is_string()?atof(obj["safedistancebase"].get<std::string>().c_str()):obj["safedistancebase"].get<double>());
        }
        if(obj.contains("safedistanceratio"))
        {
            msg.safedistanceratio = (obj["safedistanceratio"].is_string()?atof(obj["safedistanceratio"].get<std::string>().c_str()):obj["safedistanceratio"].get<double>());
        }
        if(obj.contains("followingaccelratio"))
        {
            msg.followingaccelratio = (obj["followingaccelratio"].is_string()?atof(obj["followingaccelratio"].get<std::string>().c_str()):obj["followingaccelratio"].get<double>());
        }
        if(obj.contains("softcentricaccellimit"))
        {
            msg.softcentricaccellimit = (obj["softcentricaccellimit"].is_string()?atof(obj["softcentricaccellimit"].get<std::string>().c_str()):obj["softcentricaccellimit"].get<double>());
        }
        if(obj.contains("hardcentricaccellimit"))
        {
            msg.hardcentricaccellimit = (obj["hardcentricaccellimit"].is_string()?atof(obj["hardcentricaccellimit"].get<std::string>().c_str()):obj["hardcentricaccellimit"].get<double>());
        }
        if(obj.contains("hardspeedlimit"))
        {
            msg.hardspeedlimit = (obj["hardspeedlimit"].is_string()?atof(obj["hardspeedlimit"].get<std::string>().c_str()):obj["hardspeedlimit"].get<double>());
        }
        if(obj.contains("hardaccellimit"))
        {
            msg.hardaccellimit = (obj["hardaccellimit"].is_string()?atof(obj["hardaccellimit"].get<std::string>().c_str()):obj["hardaccellimit"].get<double>());
        }
        if(obj.contains("enablesafepath"))
        {
            msg.enablesafepath = (obj["enablesafepath"].is_string()?(bool)atoi(obj["enablesafepath"].get<std::string>().c_str()):obj["enablesafepath"].get<bool>());
        }
        if(obj.contains("enableplanningstartpoint"))
        {
            msg.enableplanningstartpoint = (obj["enableplanningstartpoint"].is_string()?(bool)atoi(obj["enableplanningstartpoint"].get<std::string>().c_str()):obj["enableplanningstartpoint"].get<bool>());
        }
        if(obj.contains("enableaccelautocompensation"))
        {
            msg.enableaccelautocompensation = (obj["enableaccelautocompensation"].is_string()?(bool)atoi(obj["enableaccelautocompensation"].get<std::string>().c_str()):obj["enableaccelautocompensation"].get<bool>());
        }
        if(obj.contains("kappapreview"))
        {
            msg.kappapreview = (obj["kappapreview"].is_string()?atof(obj["kappapreview"].get<std::string>().c_str()):obj["kappapreview"].get<double>());
        }
        if(obj.contains("kappathreshold"))
        {
            msg.kappathreshold = (obj["kappathreshold"].is_string()?atof(obj["kappathreshold"].get<std::string>().c_str()):obj["kappathreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningNaviSpeedDeciderConfig from_json<ApolloplanningNaviSpeedDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningNaviSpeedDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNaviSpeedDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningNaviSpeedDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNaviSpeedDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNaviSpeedDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
