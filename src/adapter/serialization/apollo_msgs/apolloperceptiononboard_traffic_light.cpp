#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardTrafficLight &msg) {
        nlohmann::json obj;
        obj["tltf2frameid"] = (msg.tltf2frameid);
        obj["tltf2childframeid"] = (msg.tltf2childframeid);
        obj["tf2timeoutsecond"] = (msg.tf2timeoutsecond);
        obj["cameranames"] = (msg.cameranames);
        obj["camerachannelnames"] = (msg.camerachannelnames);
        obj["tlimagetimestampoffset"] = (msg.tlimagetimestampoffset);
        obj["maxprocessimagefps"] = (msg.maxprocessimagefps);
        obj["querytfintervalseconds"] = (msg.querytfintervalseconds);
        obj["validhdmapinterval"] = (msg.validhdmapinterval);
        obj["imagesystsdiffthreshold"] = (msg.imagesystsdiffthreshold);
        obj["syncintervalseconds"] = (msg.syncintervalseconds);
        obj["cameratrafficlightperceptionconfdir"] = (msg.cameratrafficlightperceptionconfdir);
        obj["cameratrafficlightperceptionconffile"] = (msg.cameratrafficlightperceptionconffile);
        obj["defaultimagebordersize"] = (msg.defaultimagebordersize);
        obj["trafficlightoutputchannelname"] = (msg.trafficlightoutputchannelname);
        obj["simulationchannelname"] = (msg.simulationchannelname);
        obj["v2xtrafficlightsinputchannelname"] = (msg.v2xtrafficlightsinputchannelname);
        obj["v2xsyncintervalseconds"] = (msg.v2xsyncintervalseconds);
        obj["maxv2xmsgbuffsize"] = (msg.maxv2xmsgbuffsize);
        return obj;
    }
    ApolloperceptiononboardTrafficLight from_json_ApolloperceptiononboardTrafficLight (nlohmann::json obj) {
        ApolloperceptiononboardTrafficLight msg;
        if(obj.contains("tltf2frameid"))
        {
            msg.tltf2frameid = (obj["tltf2frameid"].is_string()?(obj["tltf2frameid"].get<std::string>().c_str()):obj["tltf2frameid"].get<std::string>());
        }
        if(obj.contains("tltf2childframeid"))
        {
            msg.tltf2childframeid = (obj["tltf2childframeid"].is_string()?(obj["tltf2childframeid"].get<std::string>().c_str()):obj["tltf2childframeid"].get<std::string>());
        }
        if(obj.contains("tf2timeoutsecond"))
        {
            msg.tf2timeoutsecond = (obj["tf2timeoutsecond"].is_string()?atof(obj["tf2timeoutsecond"].get<std::string>().c_str()):obj["tf2timeoutsecond"].get<double>());
        }
        if(obj.contains("cameranames"))
        {
            msg.cameranames = (obj["cameranames"].is_string()?(obj["cameranames"].get<std::string>().c_str()):obj["cameranames"].get<std::string>());
        }
        if(obj.contains("camerachannelnames"))
        {
            msg.camerachannelnames = (obj["camerachannelnames"].is_string()?(obj["camerachannelnames"].get<std::string>().c_str()):obj["camerachannelnames"].get<std::string>());
        }
        if(obj.contains("tlimagetimestampoffset"))
        {
            msg.tlimagetimestampoffset = (obj["tlimagetimestampoffset"].is_string()?atof(obj["tlimagetimestampoffset"].get<std::string>().c_str()):obj["tlimagetimestampoffset"].get<double>());
        }
        if(obj.contains("maxprocessimagefps"))
        {
            msg.maxprocessimagefps = (obj["maxprocessimagefps"].is_string()?atoi(obj["maxprocessimagefps"].get<std::string>().c_str()):obj["maxprocessimagefps"].get<int>());
        }
        if(obj.contains("querytfintervalseconds"))
        {
            msg.querytfintervalseconds = (obj["querytfintervalseconds"].is_string()?atof(obj["querytfintervalseconds"].get<std::string>().c_str()):obj["querytfintervalseconds"].get<double>());
        }
        if(obj.contains("validhdmapinterval"))
        {
            msg.validhdmapinterval = (obj["validhdmapinterval"].is_string()?atof(obj["validhdmapinterval"].get<std::string>().c_str()):obj["validhdmapinterval"].get<double>());
        }
        if(obj.contains("imagesystsdiffthreshold"))
        {
            msg.imagesystsdiffthreshold = (obj["imagesystsdiffthreshold"].is_string()?atof(obj["imagesystsdiffthreshold"].get<std::string>().c_str()):obj["imagesystsdiffthreshold"].get<double>());
        }
        if(obj.contains("syncintervalseconds"))
        {
            msg.syncintervalseconds = (obj["syncintervalseconds"].is_string()?atof(obj["syncintervalseconds"].get<std::string>().c_str()):obj["syncintervalseconds"].get<double>());
        }
        if(obj.contains("cameratrafficlightperceptionconfdir"))
        {
            msg.cameratrafficlightperceptionconfdir = (obj["cameratrafficlightperceptionconfdir"].is_string()?(obj["cameratrafficlightperceptionconfdir"].get<std::string>().c_str()):obj["cameratrafficlightperceptionconfdir"].get<std::string>());
        }
        if(obj.contains("cameratrafficlightperceptionconffile"))
        {
            msg.cameratrafficlightperceptionconffile = (obj["cameratrafficlightperceptionconffile"].is_string()?(obj["cameratrafficlightperceptionconffile"].get<std::string>().c_str()):obj["cameratrafficlightperceptionconffile"].get<std::string>());
        }
        if(obj.contains("defaultimagebordersize"))
        {
            msg.defaultimagebordersize = (obj["defaultimagebordersize"].is_string()?atoi(obj["defaultimagebordersize"].get<std::string>().c_str()):obj["defaultimagebordersize"].get<int>());
        }
        if(obj.contains("trafficlightoutputchannelname"))
        {
            msg.trafficlightoutputchannelname = (obj["trafficlightoutputchannelname"].is_string()?(obj["trafficlightoutputchannelname"].get<std::string>().c_str()):obj["trafficlightoutputchannelname"].get<std::string>());
        }
        if(obj.contains("simulationchannelname"))
        {
            msg.simulationchannelname = (obj["simulationchannelname"].is_string()?(obj["simulationchannelname"].get<std::string>().c_str()):obj["simulationchannelname"].get<std::string>());
        }
        if(obj.contains("v2xtrafficlightsinputchannelname"))
        {
            msg.v2xtrafficlightsinputchannelname = (obj["v2xtrafficlightsinputchannelname"].is_string()?(obj["v2xtrafficlightsinputchannelname"].get<std::string>().c_str()):obj["v2xtrafficlightsinputchannelname"].get<std::string>());
        }
        if(obj.contains("v2xsyncintervalseconds"))
        {
            msg.v2xsyncintervalseconds = (obj["v2xsyncintervalseconds"].is_string()?atof(obj["v2xsyncintervalseconds"].get<std::string>().c_str()):obj["v2xsyncintervalseconds"].get<double>());
        }
        if(obj.contains("maxv2xmsgbuffsize"))
        {
            msg.maxv2xmsgbuffsize = (obj["maxv2xmsgbuffsize"].is_string()?atoi(obj["maxv2xmsgbuffsize"].get<std::string>().c_str()):obj["maxv2xmsgbuffsize"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardTrafficLight from_json<ApolloperceptiononboardTrafficLight>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardTrafficLight &dt)
    {
        dt=from_json_ApolloperceptiononboardTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
