#include "adapter/serialization/apollo_msgs/apollocontrol_simple_longitudinal_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolSimpleLongitudinalDebug &msg) {
        nlohmann::json obj;
        obj["stationreference"] = (msg.stationreference);
        obj["stationerror"] = (msg.stationerror);
        obj["stationerrorlimited"] = (msg.stationerrorlimited);
        obj["previewstationerror"] = (msg.previewstationerror);
        obj["speedreference"] = (msg.speedreference);
        obj["speederror"] = (msg.speederror);
        obj["speedcontrollerinputlimited"] = (msg.speedcontrollerinputlimited);
        obj["previewspeedreference"] = (msg.previewspeedreference);
        obj["previewspeederror"] = (msg.previewspeederror);
        obj["previewaccelerationreference"] = (msg.previewaccelerationreference);
        obj["accelerationcmdcloseloop"] = (msg.accelerationcmdcloseloop);
        obj["accelerationcmd"] = (msg.accelerationcmd);
        obj["accelerationlookup"] = (msg.accelerationlookup);
        obj["speedlookup"] = (msg.speedlookup);
        obj["calibrationvalue"] = (msg.calibrationvalue);
        obj["throttlecmd"] = (msg.throttlecmd);
        obj["brakecmd"] = (msg.brakecmd);
        obj["isfullstop"] = (msg.isfullstop);
        obj["slopeoffsetcompensation"] = (msg.slopeoffsetcompensation);
        obj["currentstation"] = (msg.currentstation);
        obj["pathremain"] = (msg.pathremain);
        obj["pidsaturationstatus"] = (msg.pidsaturationstatus);
        obj["leadlagsaturationstatus"] = (msg.leadlagsaturationstatus);
        obj["speedoffset"] = (msg.speedoffset);
        obj["currentspeed"] = (msg.currentspeed);
        obj["accelerationreference"] = (msg.accelerationreference);
        obj["currentacceleration"] = (msg.currentacceleration);
        obj["accelerationerror"] = (msg.accelerationerror);
        obj["jerkreference"] = (msg.jerkreference);
        obj["currentjerk"] = (msg.currentjerk);
        obj["jerkerror"] = (msg.jerkerror);
        obj["currentmatchedpoint"] = to_json(msg.currentmatchedpoint);
        obj["currentreferencepoint"] = to_json(msg.currentreferencepoint);
        obj["previewreferencepoint"] = to_json(msg.previewreferencepoint);
        return obj;
    }
    ApollocontrolSimpleLongitudinalDebug from_json_ApollocontrolSimpleLongitudinalDebug (nlohmann::json obj) {
        ApollocontrolSimpleLongitudinalDebug msg;
        if(obj.contains("stationreference"))
        {
            msg.stationreference = (obj["stationreference"].is_string()?atof(obj["stationreference"].get<std::string>().c_str()):obj["stationreference"].get<double>());
        }
        if(obj.contains("stationerror"))
        {
            msg.stationerror = (obj["stationerror"].is_string()?atof(obj["stationerror"].get<std::string>().c_str()):obj["stationerror"].get<double>());
        }
        if(obj.contains("stationerrorlimited"))
        {
            msg.stationerrorlimited = (obj["stationerrorlimited"].is_string()?atof(obj["stationerrorlimited"].get<std::string>().c_str()):obj["stationerrorlimited"].get<double>());
        }
        if(obj.contains("previewstationerror"))
        {
            msg.previewstationerror = (obj["previewstationerror"].is_string()?atof(obj["previewstationerror"].get<std::string>().c_str()):obj["previewstationerror"].get<double>());
        }
        if(obj.contains("speedreference"))
        {
            msg.speedreference = (obj["speedreference"].is_string()?atof(obj["speedreference"].get<std::string>().c_str()):obj["speedreference"].get<double>());
        }
        if(obj.contains("speederror"))
        {
            msg.speederror = (obj["speederror"].is_string()?atof(obj["speederror"].get<std::string>().c_str()):obj["speederror"].get<double>());
        }
        if(obj.contains("speedcontrollerinputlimited"))
        {
            msg.speedcontrollerinputlimited = (obj["speedcontrollerinputlimited"].is_string()?atof(obj["speedcontrollerinputlimited"].get<std::string>().c_str()):obj["speedcontrollerinputlimited"].get<double>());
        }
        if(obj.contains("previewspeedreference"))
        {
            msg.previewspeedreference = (obj["previewspeedreference"].is_string()?atof(obj["previewspeedreference"].get<std::string>().c_str()):obj["previewspeedreference"].get<double>());
        }
        if(obj.contains("previewspeederror"))
        {
            msg.previewspeederror = (obj["previewspeederror"].is_string()?atof(obj["previewspeederror"].get<std::string>().c_str()):obj["previewspeederror"].get<double>());
        }
        if(obj.contains("previewaccelerationreference"))
        {
            msg.previewaccelerationreference = (obj["previewaccelerationreference"].is_string()?atof(obj["previewaccelerationreference"].get<std::string>().c_str()):obj["previewaccelerationreference"].get<double>());
        }
        if(obj.contains("accelerationcmdcloseloop"))
        {
            msg.accelerationcmdcloseloop = (obj["accelerationcmdcloseloop"].is_string()?atof(obj["accelerationcmdcloseloop"].get<std::string>().c_str()):obj["accelerationcmdcloseloop"].get<double>());
        }
        if(obj.contains("accelerationcmd"))
        {
            msg.accelerationcmd = (obj["accelerationcmd"].is_string()?atof(obj["accelerationcmd"].get<std::string>().c_str()):obj["accelerationcmd"].get<double>());
        }
        if(obj.contains("accelerationlookup"))
        {
            msg.accelerationlookup = (obj["accelerationlookup"].is_string()?atof(obj["accelerationlookup"].get<std::string>().c_str()):obj["accelerationlookup"].get<double>());
        }
        if(obj.contains("speedlookup"))
        {
            msg.speedlookup = (obj["speedlookup"].is_string()?atof(obj["speedlookup"].get<std::string>().c_str()):obj["speedlookup"].get<double>());
        }
        if(obj.contains("calibrationvalue"))
        {
            msg.calibrationvalue = (obj["calibrationvalue"].is_string()?atof(obj["calibrationvalue"].get<std::string>().c_str()):obj["calibrationvalue"].get<double>());
        }
        if(obj.contains("throttlecmd"))
        {
            msg.throttlecmd = (obj["throttlecmd"].is_string()?atof(obj["throttlecmd"].get<std::string>().c_str()):obj["throttlecmd"].get<double>());
        }
        if(obj.contains("brakecmd"))
        {
            msg.brakecmd = (obj["brakecmd"].is_string()?atof(obj["brakecmd"].get<std::string>().c_str()):obj["brakecmd"].get<double>());
        }
        if(obj.contains("isfullstop"))
        {
            msg.isfullstop = (obj["isfullstop"].is_string()?(bool)atoi(obj["isfullstop"].get<std::string>().c_str()):obj["isfullstop"].get<bool>());
        }
        if(obj.contains("slopeoffsetcompensation"))
        {
            msg.slopeoffsetcompensation = (obj["slopeoffsetcompensation"].is_string()?atof(obj["slopeoffsetcompensation"].get<std::string>().c_str()):obj["slopeoffsetcompensation"].get<double>());
        }
        if(obj.contains("currentstation"))
        {
            msg.currentstation = (obj["currentstation"].is_string()?atof(obj["currentstation"].get<std::string>().c_str()):obj["currentstation"].get<double>());
        }
        if(obj.contains("pathremain"))
        {
            msg.pathremain = (obj["pathremain"].is_string()?atof(obj["pathremain"].get<std::string>().c_str()):obj["pathremain"].get<double>());
        }
        if(obj.contains("pidsaturationstatus"))
        {
            msg.pidsaturationstatus = (obj["pidsaturationstatus"].is_string()?atoi(obj["pidsaturationstatus"].get<std::string>().c_str()):obj["pidsaturationstatus"].get<int>());
        }
        if(obj.contains("leadlagsaturationstatus"))
        {
            msg.leadlagsaturationstatus = (obj["leadlagsaturationstatus"].is_string()?atoi(obj["leadlagsaturationstatus"].get<std::string>().c_str()):obj["leadlagsaturationstatus"].get<int>());
        }
        if(obj.contains("speedoffset"))
        {
            msg.speedoffset = (obj["speedoffset"].is_string()?atof(obj["speedoffset"].get<std::string>().c_str()):obj["speedoffset"].get<double>());
        }
        if(obj.contains("currentspeed"))
        {
            msg.currentspeed = (obj["currentspeed"].is_string()?atof(obj["currentspeed"].get<std::string>().c_str()):obj["currentspeed"].get<double>());
        }
        if(obj.contains("accelerationreference"))
        {
            msg.accelerationreference = (obj["accelerationreference"].is_string()?atof(obj["accelerationreference"].get<std::string>().c_str()):obj["accelerationreference"].get<double>());
        }
        if(obj.contains("currentacceleration"))
        {
            msg.currentacceleration = (obj["currentacceleration"].is_string()?atof(obj["currentacceleration"].get<std::string>().c_str()):obj["currentacceleration"].get<double>());
        }
        if(obj.contains("accelerationerror"))
        {
            msg.accelerationerror = (obj["accelerationerror"].is_string()?atof(obj["accelerationerror"].get<std::string>().c_str()):obj["accelerationerror"].get<double>());
        }
        if(obj.contains("jerkreference"))
        {
            msg.jerkreference = (obj["jerkreference"].is_string()?atof(obj["jerkreference"].get<std::string>().c_str()):obj["jerkreference"].get<double>());
        }
        if(obj.contains("currentjerk"))
        {
            msg.currentjerk = (obj["currentjerk"].is_string()?atof(obj["currentjerk"].get<std::string>().c_str()):obj["currentjerk"].get<double>());
        }
        if(obj.contains("jerkerror"))
        {
            msg.jerkerror = (obj["jerkerror"].is_string()?atof(obj["jerkerror"].get<std::string>().c_str()):obj["jerkerror"].get<double>());
        }
        if(obj.contains("currentmatchedpoint"))
        {
            msg.currentmatchedpoint = from_json_ApollocommonTrajectoryPoint(obj["currentmatchedpoint"]);
        }
        if(obj.contains("currentreferencepoint"))
        {
            msg.currentreferencepoint = from_json_ApollocommonTrajectoryPoint(obj["currentreferencepoint"]);
        }
        if(obj.contains("previewreferencepoint"))
        {
            msg.previewreferencepoint = from_json_ApollocommonTrajectoryPoint(obj["previewreferencepoint"]);
        }
        return msg;
    }
    template <>
    ApollocontrolSimpleLongitudinalDebug from_json<ApollocontrolSimpleLongitudinalDebug>(nlohmann::json obj){
        return from_json_ApollocontrolSimpleLongitudinalDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolSimpleLongitudinalDebug &dt)
    {
        dt=from_json_ApollocontrolSimpleLongitudinalDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolSimpleLongitudinalDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolSimpleLongitudinalDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
