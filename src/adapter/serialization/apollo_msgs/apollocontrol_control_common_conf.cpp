#include "adapter/serialization/apollo_msgs/apollocontrol_control_common_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolControlCommonConf &msg) {
        nlohmann::json obj;
        obj["controltestduration"] = (msg.controltestduration);
        obj["enablecsvdebug"] = (msg.enablecsvdebug);
        obj["enablespeedstationpreview"] = (msg.enablespeedstationpreview);
        obj["iscontroltestmode"] = (msg.iscontroltestmode);
        obj["usepreviewspeedfortable"] = (msg.usepreviewspeedfortable);
        obj["enableinputtimestampcheck"] = (msg.enableinputtimestampcheck);
        obj["maxlocalizationmissnum"] = (msg.maxlocalizationmissnum);
        obj["maxchassismissnum"] = (msg.maxchassismissnum);
        obj["maxplanningmissnum"] = (msg.maxplanningmissnum);
        obj["maxaccelerationwhenstopped"] = (msg.maxaccelerationwhenstopped);
        obj["steeranglerate"] = (msg.steeranglerate);
        obj["enablegainscheduler"] = (msg.enablegainscheduler);
        obj["setsteerlimit"] = (msg.setsteerlimit);
        obj["enableslopeoffset"] = (msg.enableslopeoffset);
        obj["locksteerspeed"] = (msg.locksteerspeed);
        obj["enablenavigationmodeerrorfilter"] = (msg.enablenavigationmodeerrorfilter);
        obj["enablenavigationmodepositionupdate"] = (msg.enablenavigationmodepositionupdate);
        obj["enablepersistentestop"] = (msg.enablepersistentestop);
        obj["controlperiod"] = (msg.controlperiod);
        obj["maxplanningintervalsec"] = (msg.maxplanningintervalsec);
        obj["maxplanningdelaythreshold"] = (msg.maxplanningdelaythreshold);
        obj["drivingmode"] = (msg.drivingmode);
        obj["action"] = (msg.action);
        obj["softestopbrake"] = (msg.softestopbrake);
        obj["maxsteeringpercentageallowed"] = (msg.maxsteeringpercentageallowed);
        obj["maxstatusintervalsec"] = (msg.maxstatusintervalsec);
        obj["trajectoryperiod"] = (msg.trajectoryperiod);
        obj["chassisperiod"] = (msg.chassisperiod);
        obj["localizationperiod"] = (msg.localizationperiod);
        obj["minimumspeedresolution"] = (msg.minimumspeedresolution);
        obj["queryrelativetime"] = (msg.queryrelativetime);
        obj["minimumspeedprotection"] = (msg.minimumspeedprotection);
        obj["maxpathremainwhenstopped"] = (msg.maxpathremainwhenstopped);
        return obj;
    }
    ApollocontrolControlCommonConf from_json_ApollocontrolControlCommonConf (nlohmann::json obj) {
        ApollocontrolControlCommonConf msg;
        if(obj.contains("controltestduration"))
        {
            msg.controltestduration = (obj["controltestduration"].is_string()?atof(obj["controltestduration"].get<std::string>().c_str()):obj["controltestduration"].get<double>());
        }
        if(obj.contains("enablecsvdebug"))
        {
            msg.enablecsvdebug = (obj["enablecsvdebug"].is_string()?(bool)atoi(obj["enablecsvdebug"].get<std::string>().c_str()):obj["enablecsvdebug"].get<bool>());
        }
        if(obj.contains("enablespeedstationpreview"))
        {
            msg.enablespeedstationpreview = (obj["enablespeedstationpreview"].is_string()?(bool)atoi(obj["enablespeedstationpreview"].get<std::string>().c_str()):obj["enablespeedstationpreview"].get<bool>());
        }
        if(obj.contains("iscontroltestmode"))
        {
            msg.iscontroltestmode = (obj["iscontroltestmode"].is_string()?(bool)atoi(obj["iscontroltestmode"].get<std::string>().c_str()):obj["iscontroltestmode"].get<bool>());
        }
        if(obj.contains("usepreviewspeedfortable"))
        {
            msg.usepreviewspeedfortable = (obj["usepreviewspeedfortable"].is_string()?(bool)atoi(obj["usepreviewspeedfortable"].get<std::string>().c_str()):obj["usepreviewspeedfortable"].get<bool>());
        }
        if(obj.contains("enableinputtimestampcheck"))
        {
            msg.enableinputtimestampcheck = (obj["enableinputtimestampcheck"].is_string()?(bool)atoi(obj["enableinputtimestampcheck"].get<std::string>().c_str()):obj["enableinputtimestampcheck"].get<bool>());
        }
        if(obj.contains("maxlocalizationmissnum"))
        {
            msg.maxlocalizationmissnum = (obj["maxlocalizationmissnum"].is_string()?atoi(obj["maxlocalizationmissnum"].get<std::string>().c_str()):obj["maxlocalizationmissnum"].get<int>());
        }
        if(obj.contains("maxchassismissnum"))
        {
            msg.maxchassismissnum = (obj["maxchassismissnum"].is_string()?atoi(obj["maxchassismissnum"].get<std::string>().c_str()):obj["maxchassismissnum"].get<int>());
        }
        if(obj.contains("maxplanningmissnum"))
        {
            msg.maxplanningmissnum = (obj["maxplanningmissnum"].is_string()?atoi(obj["maxplanningmissnum"].get<std::string>().c_str()):obj["maxplanningmissnum"].get<int>());
        }
        if(obj.contains("maxaccelerationwhenstopped"))
        {
            msg.maxaccelerationwhenstopped = (obj["maxaccelerationwhenstopped"].is_string()?atof(obj["maxaccelerationwhenstopped"].get<std::string>().c_str()):obj["maxaccelerationwhenstopped"].get<double>());
        }
        if(obj.contains("steeranglerate"))
        {
            msg.steeranglerate = (obj["steeranglerate"].is_string()?atof(obj["steeranglerate"].get<std::string>().c_str()):obj["steeranglerate"].get<double>());
        }
        if(obj.contains("enablegainscheduler"))
        {
            msg.enablegainscheduler = (obj["enablegainscheduler"].is_string()?(bool)atoi(obj["enablegainscheduler"].get<std::string>().c_str()):obj["enablegainscheduler"].get<bool>());
        }
        if(obj.contains("setsteerlimit"))
        {
            msg.setsteerlimit = (obj["setsteerlimit"].is_string()?(bool)atoi(obj["setsteerlimit"].get<std::string>().c_str()):obj["setsteerlimit"].get<bool>());
        }
        if(obj.contains("enableslopeoffset"))
        {
            msg.enableslopeoffset = (obj["enableslopeoffset"].is_string()?(bool)atoi(obj["enableslopeoffset"].get<std::string>().c_str()):obj["enableslopeoffset"].get<bool>());
        }
        if(obj.contains("locksteerspeed"))
        {
            msg.locksteerspeed = (obj["locksteerspeed"].is_string()?atof(obj["locksteerspeed"].get<std::string>().c_str()):obj["locksteerspeed"].get<double>());
        }
        if(obj.contains("enablenavigationmodeerrorfilter"))
        {
            msg.enablenavigationmodeerrorfilter = (obj["enablenavigationmodeerrorfilter"].is_string()?(bool)atoi(obj["enablenavigationmodeerrorfilter"].get<std::string>().c_str()):obj["enablenavigationmodeerrorfilter"].get<bool>());
        }
        if(obj.contains("enablenavigationmodepositionupdate"))
        {
            msg.enablenavigationmodepositionupdate = (obj["enablenavigationmodepositionupdate"].is_string()?(bool)atoi(obj["enablenavigationmodepositionupdate"].get<std::string>().c_str()):obj["enablenavigationmodepositionupdate"].get<bool>());
        }
        if(obj.contains("enablepersistentestop"))
        {
            msg.enablepersistentestop = (obj["enablepersistentestop"].is_string()?(bool)atoi(obj["enablepersistentestop"].get<std::string>().c_str()):obj["enablepersistentestop"].get<bool>());
        }
        if(obj.contains("controlperiod"))
        {
            msg.controlperiod = (obj["controlperiod"].is_string()?atof(obj["controlperiod"].get<std::string>().c_str()):obj["controlperiod"].get<double>());
        }
        if(obj.contains("maxplanningintervalsec"))
        {
            msg.maxplanningintervalsec = (obj["maxplanningintervalsec"].is_string()?atof(obj["maxplanningintervalsec"].get<std::string>().c_str()):obj["maxplanningintervalsec"].get<double>());
        }
        if(obj.contains("maxplanningdelaythreshold"))
        {
            msg.maxplanningdelaythreshold = (obj["maxplanningdelaythreshold"].is_string()?atof(obj["maxplanningdelaythreshold"].get<std::string>().c_str()):obj["maxplanningdelaythreshold"].get<double>());
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        if(obj.contains("action"))
        {
            msg.action = (obj["action"].is_string()?atoi(obj["action"].get<std::string>().c_str()):obj["action"].get<int>());
        }
        if(obj.contains("softestopbrake"))
        {
            msg.softestopbrake = (obj["softestopbrake"].is_string()?atof(obj["softestopbrake"].get<std::string>().c_str()):obj["softestopbrake"].get<double>());
        }
        if(obj.contains("maxsteeringpercentageallowed"))
        {
            msg.maxsteeringpercentageallowed = (obj["maxsteeringpercentageallowed"].is_string()?atoi(obj["maxsteeringpercentageallowed"].get<std::string>().c_str()):obj["maxsteeringpercentageallowed"].get<int>());
        }
        if(obj.contains("maxstatusintervalsec"))
        {
            msg.maxstatusintervalsec = (obj["maxstatusintervalsec"].is_string()?atof(obj["maxstatusintervalsec"].get<std::string>().c_str()):obj["maxstatusintervalsec"].get<double>());
        }
        if(obj.contains("trajectoryperiod"))
        {
            msg.trajectoryperiod = (obj["trajectoryperiod"].is_string()?atof(obj["trajectoryperiod"].get<std::string>().c_str()):obj["trajectoryperiod"].get<double>());
        }
        if(obj.contains("chassisperiod"))
        {
            msg.chassisperiod = (obj["chassisperiod"].is_string()?atof(obj["chassisperiod"].get<std::string>().c_str()):obj["chassisperiod"].get<double>());
        }
        if(obj.contains("localizationperiod"))
        {
            msg.localizationperiod = (obj["localizationperiod"].is_string()?atof(obj["localizationperiod"].get<std::string>().c_str()):obj["localizationperiod"].get<double>());
        }
        if(obj.contains("minimumspeedresolution"))
        {
            msg.minimumspeedresolution = (obj["minimumspeedresolution"].is_string()?atof(obj["minimumspeedresolution"].get<std::string>().c_str()):obj["minimumspeedresolution"].get<double>());
        }
        if(obj.contains("queryrelativetime"))
        {
            msg.queryrelativetime = (obj["queryrelativetime"].is_string()?atof(obj["queryrelativetime"].get<std::string>().c_str()):obj["queryrelativetime"].get<double>());
        }
        if(obj.contains("minimumspeedprotection"))
        {
            msg.minimumspeedprotection = (obj["minimumspeedprotection"].is_string()?atof(obj["minimumspeedprotection"].get<std::string>().c_str()):obj["minimumspeedprotection"].get<double>());
        }
        if(obj.contains("maxpathremainwhenstopped"))
        {
            msg.maxpathremainwhenstopped = (obj["maxpathremainwhenstopped"].is_string()?atof(obj["maxpathremainwhenstopped"].get<std::string>().c_str()):obj["maxpathremainwhenstopped"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolControlCommonConf from_json<ApollocontrolControlCommonConf>(nlohmann::json obj){
        return from_json_ApollocontrolControlCommonConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolControlCommonConf &dt)
    {
        dt=from_json_ApollocontrolControlCommonConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolControlCommonConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolControlCommonConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
