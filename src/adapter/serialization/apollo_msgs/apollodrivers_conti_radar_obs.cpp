#include "adapter/serialization/apollo_msgs/apollodrivers_conti_radar_obs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversContiRadarObs &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["clusterortrack"] = (msg.clusterortrack);
        obj["obstacleid"] = (msg.obstacleid);
        obj["longitudedist"] = (msg.longitudedist);
        obj["lateraldist"] = (msg.lateraldist);
        obj["longitudevel"] = (msg.longitudevel);
        obj["lateralvel"] = (msg.lateralvel);
        obj["rcs"] = (msg.rcs);
        obj["dynprop"] = (msg.dynprop);
        obj["longitudedistrms"] = (msg.longitudedistrms);
        obj["lateraldistrms"] = (msg.lateraldistrms);
        obj["longitudevelrms"] = (msg.longitudevelrms);
        obj["lateralvelrms"] = (msg.lateralvelrms);
        obj["probexist"] = (msg.probexist);
        obj["measstate"] = (msg.measstate);
        obj["longitudeaccel"] = (msg.longitudeaccel);
        obj["lateralaccel"] = (msg.lateralaccel);
        obj["oritationangle"] = (msg.oritationangle);
        obj["longitudeaccelrms"] = (msg.longitudeaccelrms);
        obj["lateralaccelrms"] = (msg.lateralaccelrms);
        obj["oritationanglerms"] = (msg.oritationanglerms);
        obj["length"] = (msg.length);
        obj["width"] = (msg.width);
        obj["obstacleclass"] = (msg.obstacleclass);
        return obj;
    }
    ApollodriversContiRadarObs from_json_ApollodriversContiRadarObs (nlohmann::json obj) {
        ApollodriversContiRadarObs msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("clusterortrack"))
        {
            msg.clusterortrack = (obj["clusterortrack"].is_string()?(bool)atoi(obj["clusterortrack"].get<std::string>().c_str()):obj["clusterortrack"].get<bool>());
        }
        if(obj.contains("obstacleid"))
        {
            msg.obstacleid = (obj["obstacleid"].is_string()?atoi(obj["obstacleid"].get<std::string>().c_str()):obj["obstacleid"].get<int>());
        }
        if(obj.contains("longitudedist"))
        {
            msg.longitudedist = (obj["longitudedist"].is_string()?atof(obj["longitudedist"].get<std::string>().c_str()):obj["longitudedist"].get<double>());
        }
        if(obj.contains("lateraldist"))
        {
            msg.lateraldist = (obj["lateraldist"].is_string()?atof(obj["lateraldist"].get<std::string>().c_str()):obj["lateraldist"].get<double>());
        }
        if(obj.contains("longitudevel"))
        {
            msg.longitudevel = (obj["longitudevel"].is_string()?atof(obj["longitudevel"].get<std::string>().c_str()):obj["longitudevel"].get<double>());
        }
        if(obj.contains("lateralvel"))
        {
            msg.lateralvel = (obj["lateralvel"].is_string()?atof(obj["lateralvel"].get<std::string>().c_str()):obj["lateralvel"].get<double>());
        }
        if(obj.contains("rcs"))
        {
            msg.rcs = (obj["rcs"].is_string()?atof(obj["rcs"].get<std::string>().c_str()):obj["rcs"].get<double>());
        }
        if(obj.contains("dynprop"))
        {
            msg.dynprop = (obj["dynprop"].is_string()?atoi(obj["dynprop"].get<std::string>().c_str()):obj["dynprop"].get<int>());
        }
        if(obj.contains("longitudedistrms"))
        {
            msg.longitudedistrms = (obj["longitudedistrms"].is_string()?atof(obj["longitudedistrms"].get<std::string>().c_str()):obj["longitudedistrms"].get<double>());
        }
        if(obj.contains("lateraldistrms"))
        {
            msg.lateraldistrms = (obj["lateraldistrms"].is_string()?atof(obj["lateraldistrms"].get<std::string>().c_str()):obj["lateraldistrms"].get<double>());
        }
        if(obj.contains("longitudevelrms"))
        {
            msg.longitudevelrms = (obj["longitudevelrms"].is_string()?atof(obj["longitudevelrms"].get<std::string>().c_str()):obj["longitudevelrms"].get<double>());
        }
        if(obj.contains("lateralvelrms"))
        {
            msg.lateralvelrms = (obj["lateralvelrms"].is_string()?atof(obj["lateralvelrms"].get<std::string>().c_str()):obj["lateralvelrms"].get<double>());
        }
        if(obj.contains("probexist"))
        {
            msg.probexist = (obj["probexist"].is_string()?atof(obj["probexist"].get<std::string>().c_str()):obj["probexist"].get<double>());
        }
        if(obj.contains("measstate"))
        {
            msg.measstate = (obj["measstate"].is_string()?atoi(obj["measstate"].get<std::string>().c_str()):obj["measstate"].get<int>());
        }
        if(obj.contains("longitudeaccel"))
        {
            msg.longitudeaccel = (obj["longitudeaccel"].is_string()?atof(obj["longitudeaccel"].get<std::string>().c_str()):obj["longitudeaccel"].get<double>());
        }
        if(obj.contains("lateralaccel"))
        {
            msg.lateralaccel = (obj["lateralaccel"].is_string()?atof(obj["lateralaccel"].get<std::string>().c_str()):obj["lateralaccel"].get<double>());
        }
        if(obj.contains("oritationangle"))
        {
            msg.oritationangle = (obj["oritationangle"].is_string()?atof(obj["oritationangle"].get<std::string>().c_str()):obj["oritationangle"].get<double>());
        }
        if(obj.contains("longitudeaccelrms"))
        {
            msg.longitudeaccelrms = (obj["longitudeaccelrms"].is_string()?atof(obj["longitudeaccelrms"].get<std::string>().c_str()):obj["longitudeaccelrms"].get<double>());
        }
        if(obj.contains("lateralaccelrms"))
        {
            msg.lateralaccelrms = (obj["lateralaccelrms"].is_string()?atof(obj["lateralaccelrms"].get<std::string>().c_str()):obj["lateralaccelrms"].get<double>());
        }
        if(obj.contains("oritationanglerms"))
        {
            msg.oritationanglerms = (obj["oritationanglerms"].is_string()?atof(obj["oritationanglerms"].get<std::string>().c_str()):obj["oritationanglerms"].get<double>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        if(obj.contains("obstacleclass"))
        {
            msg.obstacleclass = (obj["obstacleclass"].is_string()?atoi(obj["obstacleclass"].get<std::string>().c_str()):obj["obstacleclass"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversContiRadarObs from_json<ApollodriversContiRadarObs>(nlohmann::json obj){
        return from_json_ApollodriversContiRadarObs(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversContiRadarObs &dt)
    {
        dt=from_json_ApollodriversContiRadarObs(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversContiRadarObs & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversContiRadarObs & dt)
    {
        os << to_json(dt);
        return os;
    }
}
