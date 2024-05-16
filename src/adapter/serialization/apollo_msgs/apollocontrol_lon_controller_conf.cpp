#include "adapter/serialization/apollo_msgs/apollocontrol_lon_controller_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLonControllerConf &msg) {
        nlohmann::json obj;
        obj["ts"] = (msg.ts);
        obj["brakeminimumaction"] = (msg.brakeminimumaction);
        obj["throttleminimumaction"] = (msg.throttleminimumaction);
        obj["speedcontrollerinputlimit"] = (msg.speedcontrollerinputlimit);
        obj["stationerrorlimit"] = (msg.stationerrorlimit);
        obj["previewwindow"] = (msg.previewwindow);
        obj["standstillacceleration"] = (msg.standstillacceleration);
        obj["stationpidconf"] = to_json(msg.stationpidconf);
        obj["lowspeedpidconf"] = to_json(msg.lowspeedpidconf);
        obj["highspeedpidconf"] = to_json(msg.highspeedpidconf);
        obj["switchspeed"] = (msg.switchspeed);
        obj["reversestationpidconf"] = to_json(msg.reversestationpidconf);
        obj["reversespeedpidconf"] = to_json(msg.reversespeedpidconf);
        obj["pitchanglefilterconf"] = to_json(msg.pitchanglefilterconf);
        obj["reversestationleadlagconf"] = to_json(msg.reversestationleadlagconf);
        obj["reversespeedleadlagconf"] = to_json(msg.reversespeedleadlagconf);
        obj["calibrationtable"] = to_json(msg.calibrationtable);
        obj["enablereverseleadlagcompensation"] = (msg.enablereverseleadlagcompensation);
        obj["switchspeedwindow"] = (msg.switchspeedwindow);
        return obj;
    }
    ApollocontrolLonControllerConf from_json_ApollocontrolLonControllerConf (nlohmann::json obj) {
        ApollocontrolLonControllerConf msg;
        if(obj.contains("ts"))
        {
            msg.ts = (obj["ts"].is_string()?atof(obj["ts"].get<std::string>().c_str()):obj["ts"].get<double>());
        }
        if(obj.contains("brakeminimumaction"))
        {
            msg.brakeminimumaction = (obj["brakeminimumaction"].is_string()?atof(obj["brakeminimumaction"].get<std::string>().c_str()):obj["brakeminimumaction"].get<double>());
        }
        if(obj.contains("throttleminimumaction"))
        {
            msg.throttleminimumaction = (obj["throttleminimumaction"].is_string()?atof(obj["throttleminimumaction"].get<std::string>().c_str()):obj["throttleminimumaction"].get<double>());
        }
        if(obj.contains("speedcontrollerinputlimit"))
        {
            msg.speedcontrollerinputlimit = (obj["speedcontrollerinputlimit"].is_string()?atof(obj["speedcontrollerinputlimit"].get<std::string>().c_str()):obj["speedcontrollerinputlimit"].get<double>());
        }
        if(obj.contains("stationerrorlimit"))
        {
            msg.stationerrorlimit = (obj["stationerrorlimit"].is_string()?atof(obj["stationerrorlimit"].get<std::string>().c_str()):obj["stationerrorlimit"].get<double>());
        }
        if(obj.contains("previewwindow"))
        {
            msg.previewwindow = (obj["previewwindow"].is_string()?atof(obj["previewwindow"].get<std::string>().c_str()):obj["previewwindow"].get<double>());
        }
        if(obj.contains("standstillacceleration"))
        {
            msg.standstillacceleration = (obj["standstillacceleration"].is_string()?atof(obj["standstillacceleration"].get<std::string>().c_str()):obj["standstillacceleration"].get<double>());
        }
        if(obj.contains("stationpidconf"))
        {
            msg.stationpidconf = from_json_ApollocontrolPidConf(obj["stationpidconf"]);
        }
        if(obj.contains("lowspeedpidconf"))
        {
            msg.lowspeedpidconf = from_json_ApollocontrolPidConf(obj["lowspeedpidconf"]);
        }
        if(obj.contains("highspeedpidconf"))
        {
            msg.highspeedpidconf = from_json_ApollocontrolPidConf(obj["highspeedpidconf"]);
        }
        if(obj.contains("switchspeed"))
        {
            msg.switchspeed = (obj["switchspeed"].is_string()?atof(obj["switchspeed"].get<std::string>().c_str()):obj["switchspeed"].get<double>());
        }
        if(obj.contains("reversestationpidconf"))
        {
            msg.reversestationpidconf = from_json_ApollocontrolPidConf(obj["reversestationpidconf"]);
        }
        if(obj.contains("reversespeedpidconf"))
        {
            msg.reversespeedpidconf = from_json_ApollocontrolPidConf(obj["reversespeedpidconf"]);
        }
        if(obj.contains("pitchanglefilterconf"))
        {
            msg.pitchanglefilterconf = from_json_ApollocontrolFilterConf(obj["pitchanglefilterconf"]);
        }
        if(obj.contains("reversestationleadlagconf"))
        {
            msg.reversestationleadlagconf = from_json_ApollocontrolLeadlagConf(obj["reversestationleadlagconf"]);
        }
        if(obj.contains("reversespeedleadlagconf"))
        {
            msg.reversespeedleadlagconf = from_json_ApollocontrolLeadlagConf(obj["reversespeedleadlagconf"]);
        }
        if(obj.contains("calibrationtable"))
        {
            msg.calibrationtable = from_json_ApollocontrolcalibrationtableControlCalibrationTable(obj["calibrationtable"]);
        }
        if(obj.contains("enablereverseleadlagcompensation"))
        {
            msg.enablereverseleadlagcompensation = (obj["enablereverseleadlagcompensation"].is_string()?(bool)atoi(obj["enablereverseleadlagcompensation"].get<std::string>().c_str()):obj["enablereverseleadlagcompensation"].get<bool>());
        }
        if(obj.contains("switchspeedwindow"))
        {
            msg.switchspeedwindow = (obj["switchspeedwindow"].is_string()?atof(obj["switchspeedwindow"].get<std::string>().c_str()):obj["switchspeedwindow"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolLonControllerConf from_json<ApollocontrolLonControllerConf>(nlohmann::json obj){
        return from_json_ApollocontrolLonControllerConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLonControllerConf &dt)
    {
        dt=from_json_ApollocontrolLonControllerConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLonControllerConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLonControllerConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
