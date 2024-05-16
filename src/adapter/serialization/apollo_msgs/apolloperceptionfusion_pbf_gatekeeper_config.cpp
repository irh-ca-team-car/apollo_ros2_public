#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_pbf_gatekeeper_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionPbfGatekeeperConfig &msg) {
        nlohmann::json obj;
        obj["publishifhaslidar"] = (msg.publishifhaslidar);
        obj["publishifhasradar"] = (msg.publishifhasradar);
        obj["publishifhascamera"] = (msg.publishifhascamera);
        obj["usecamera3d"] = (msg.usecamera3d);
        obj["minradarconfidentdistance"] = (msg.minradarconfidentdistance);
        obj["maxradarconfidentangle"] = (msg.maxradarconfidentangle);
        obj["mincamerapublishdistance"] = (msg.mincamerapublishdistance);
        obj["invisibleperiodthreshold"] = (msg.invisibleperiodthreshold);
        obj["toicthreshold"] = (msg.toicthreshold);
        obj["usetracktimepubstrategy"] = (msg.usetracktimepubstrategy);
        obj["pubtracktimethresh"] = (msg.pubtracktimethresh);
        obj["existencethreshold"] = (msg.existencethreshold);
        obj["radarexistencethreshold"] = (msg.radarexistencethreshold);
        return obj;
    }
    ApolloperceptionfusionPbfGatekeeperConfig from_json_ApolloperceptionfusionPbfGatekeeperConfig (nlohmann::json obj) {
        ApolloperceptionfusionPbfGatekeeperConfig msg;
        if(obj.contains("publishifhaslidar"))
        {
            msg.publishifhaslidar = (obj["publishifhaslidar"].is_string()?(bool)atoi(obj["publishifhaslidar"].get<std::string>().c_str()):obj["publishifhaslidar"].get<bool>());
        }
        if(obj.contains("publishifhasradar"))
        {
            msg.publishifhasradar = (obj["publishifhasradar"].is_string()?(bool)atoi(obj["publishifhasradar"].get<std::string>().c_str()):obj["publishifhasradar"].get<bool>());
        }
        if(obj.contains("publishifhascamera"))
        {
            msg.publishifhascamera = (obj["publishifhascamera"].is_string()?(bool)atoi(obj["publishifhascamera"].get<std::string>().c_str()):obj["publishifhascamera"].get<bool>());
        }
        if(obj.contains("usecamera3d"))
        {
            msg.usecamera3d = (obj["usecamera3d"].is_string()?(bool)atoi(obj["usecamera3d"].get<std::string>().c_str()):obj["usecamera3d"].get<bool>());
        }
        if(obj.contains("minradarconfidentdistance"))
        {
            msg.minradarconfidentdistance = (obj["minradarconfidentdistance"].is_string()?atof(obj["minradarconfidentdistance"].get<std::string>().c_str()):obj["minradarconfidentdistance"].get<double>());
        }
        if(obj.contains("maxradarconfidentangle"))
        {
            msg.maxradarconfidentangle = (obj["maxradarconfidentangle"].is_string()?atof(obj["maxradarconfidentangle"].get<std::string>().c_str()):obj["maxradarconfidentangle"].get<double>());
        }
        if(obj.contains("mincamerapublishdistance"))
        {
            msg.mincamerapublishdistance = (obj["mincamerapublishdistance"].is_string()?atof(obj["mincamerapublishdistance"].get<std::string>().c_str()):obj["mincamerapublishdistance"].get<double>());
        }
        if(obj.contains("invisibleperiodthreshold"))
        {
            msg.invisibleperiodthreshold = (obj["invisibleperiodthreshold"].is_string()?atof(obj["invisibleperiodthreshold"].get<std::string>().c_str()):obj["invisibleperiodthreshold"].get<double>());
        }
        if(obj.contains("toicthreshold"))
        {
            msg.toicthreshold = (obj["toicthreshold"].is_string()?atof(obj["toicthreshold"].get<std::string>().c_str()):obj["toicthreshold"].get<double>());
        }
        if(obj.contains("usetracktimepubstrategy"))
        {
            msg.usetracktimepubstrategy = (obj["usetracktimepubstrategy"].is_string()?(bool)atoi(obj["usetracktimepubstrategy"].get<std::string>().c_str()):obj["usetracktimepubstrategy"].get<bool>());
        }
        if(obj.contains("pubtracktimethresh"))
        {
            msg.pubtracktimethresh = (obj["pubtracktimethresh"].is_string()?atoi(obj["pubtracktimethresh"].get<std::string>().c_str()):obj["pubtracktimethresh"].get<int>());
        }
        if(obj.contains("existencethreshold"))
        {
            msg.existencethreshold = (obj["existencethreshold"].is_string()?atof(obj["existencethreshold"].get<std::string>().c_str()):obj["existencethreshold"].get<double>());
        }
        if(obj.contains("radarexistencethreshold"))
        {
            msg.radarexistencethreshold = (obj["radarexistencethreshold"].is_string()?atof(obj["radarexistencethreshold"].get<std::string>().c_str()):obj["radarexistencethreshold"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionfusionPbfGatekeeperConfig from_json<ApolloperceptionfusionPbfGatekeeperConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionfusionPbfGatekeeperConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionPbfGatekeeperConfig &dt)
    {
        dt=from_json_ApolloperceptionfusionPbfGatekeeperConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionPbfGatekeeperConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionPbfGatekeeperConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
