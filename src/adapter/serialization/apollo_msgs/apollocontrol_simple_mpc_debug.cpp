#include "adapter/serialization/apollo_msgs/apollocontrol_simple_mpc_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolSimpleMPCDebug &msg) {
        nlohmann::json obj;
        obj["lateralerror"] = (msg.lateralerror);
        obj["refheading"] = (msg.refheading);
        obj["heading"] = (msg.heading);
        obj["headingerror"] = (msg.headingerror);
        obj["headingerrorrate"] = (msg.headingerrorrate);
        obj["lateralerrorrate"] = (msg.lateralerrorrate);
        obj["curvature"] = (msg.curvature);
        obj["steerangle"] = (msg.steerangle);
        obj["steeranglefeedforward"] = (msg.steeranglefeedforward);
        obj["steeranglelateralcontribution"] = (msg.steeranglelateralcontribution);
        obj["steeranglelateralratecontribution"] = (msg.steeranglelateralratecontribution);
        obj["steerangleheadingcontribution"] = (msg.steerangleheadingcontribution);
        obj["steerangleheadingratecontribution"] = (msg.steerangleheadingratecontribution);
        obj["steeranglefeedback"] = (msg.steeranglefeedback);
        obj["steeringposition"] = (msg.steeringposition);
        obj["refspeed"] = (msg.refspeed);
        obj["steeranglelimited"] = (msg.steeranglelimited);
        obj["stationreference"] = (msg.stationreference);
        obj["stationerror"] = (msg.stationerror);
        obj["speedreference"] = (msg.speedreference);
        obj["speederror"] = (msg.speederror);
        obj["accelerationreference"] = (msg.accelerationreference);
        obj["isfullstop"] = (msg.isfullstop);
        obj["stationfeedback"] = (msg.stationfeedback);
        obj["speedfeedback"] = (msg.speedfeedback);
        obj["accelerationcmdcloseloop"] = (msg.accelerationcmdcloseloop);
        obj["accelerationcmd"] = (msg.accelerationcmd);
        obj["accelerationlookup"] = (msg.accelerationlookup);
        obj["speedlookup"] = (msg.speedlookup);
        obj["calibrationvalue"] = (msg.calibrationvalue);
        obj["steerunconstrainedcontroldiff"] = (msg.steerunconstrainedcontroldiff);
        obj["steeranglefeedforwardcompensation"] = (msg.steeranglefeedforwardcompensation);
        nlohmann::json arr_matrixqupdated;
        for (auto it = msg.matrixqupdated.begin(); it != msg.matrixqupdated.end(); ++it) {
            arr_matrixqupdated.push_back((*it));
        }
        obj["matrixqupdated"] = arr_matrixqupdated;
        nlohmann::json arr_matrixrupdated;
        for (auto it = msg.matrixrupdated.begin(); it != msg.matrixrupdated.end(); ++it) {
            arr_matrixrupdated.push_back((*it));
        }
        obj["matrixrupdated"] = arr_matrixrupdated;
        obj["lateralacceleration"] = (msg.lateralacceleration);
        obj["lateraljerk"] = (msg.lateraljerk);
        obj["refheadingrate"] = (msg.refheadingrate);
        obj["headingrate"] = (msg.headingrate);
        obj["refheadingacceleration"] = (msg.refheadingacceleration);
        obj["headingacceleration"] = (msg.headingacceleration);
        obj["headingerroracceleration"] = (msg.headingerroracceleration);
        obj["refheadingjerk"] = (msg.refheadingjerk);
        obj["headingjerk"] = (msg.headingjerk);
        obj["headingerrorjerk"] = (msg.headingerrorjerk);
        obj["accelerationfeedback"] = (msg.accelerationfeedback);
        obj["accelerationerror"] = (msg.accelerationerror);
        obj["jerkreference"] = (msg.jerkreference);
        obj["jerkfeedback"] = (msg.jerkfeedback);
        obj["jerkerror"] = (msg.jerkerror);
        return obj;
    }
    ApollocontrolSimpleMPCDebug from_json_ApollocontrolSimpleMPCDebug (nlohmann::json obj) {
        ApollocontrolSimpleMPCDebug msg;
        if(obj.contains("lateralerror"))
        {
            msg.lateralerror = (obj["lateralerror"].is_string()?atof(obj["lateralerror"].get<std::string>().c_str()):obj["lateralerror"].get<double>());
        }
        if(obj.contains("refheading"))
        {
            msg.refheading = (obj["refheading"].is_string()?atof(obj["refheading"].get<std::string>().c_str()):obj["refheading"].get<double>());
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("headingerror"))
        {
            msg.headingerror = (obj["headingerror"].is_string()?atof(obj["headingerror"].get<std::string>().c_str()):obj["headingerror"].get<double>());
        }
        if(obj.contains("headingerrorrate"))
        {
            msg.headingerrorrate = (obj["headingerrorrate"].is_string()?atof(obj["headingerrorrate"].get<std::string>().c_str()):obj["headingerrorrate"].get<double>());
        }
        if(obj.contains("lateralerrorrate"))
        {
            msg.lateralerrorrate = (obj["lateralerrorrate"].is_string()?atof(obj["lateralerrorrate"].get<std::string>().c_str()):obj["lateralerrorrate"].get<double>());
        }
        if(obj.contains("curvature"))
        {
            msg.curvature = (obj["curvature"].is_string()?atof(obj["curvature"].get<std::string>().c_str()):obj["curvature"].get<double>());
        }
        if(obj.contains("steerangle"))
        {
            msg.steerangle = (obj["steerangle"].is_string()?atof(obj["steerangle"].get<std::string>().c_str()):obj["steerangle"].get<double>());
        }
        if(obj.contains("steeranglefeedforward"))
        {
            msg.steeranglefeedforward = (obj["steeranglefeedforward"].is_string()?atof(obj["steeranglefeedforward"].get<std::string>().c_str()):obj["steeranglefeedforward"].get<double>());
        }
        if(obj.contains("steeranglelateralcontribution"))
        {
            msg.steeranglelateralcontribution = (obj["steeranglelateralcontribution"].is_string()?atof(obj["steeranglelateralcontribution"].get<std::string>().c_str()):obj["steeranglelateralcontribution"].get<double>());
        }
        if(obj.contains("steeranglelateralratecontribution"))
        {
            msg.steeranglelateralratecontribution = (obj["steeranglelateralratecontribution"].is_string()?atof(obj["steeranglelateralratecontribution"].get<std::string>().c_str()):obj["steeranglelateralratecontribution"].get<double>());
        }
        if(obj.contains("steerangleheadingcontribution"))
        {
            msg.steerangleheadingcontribution = (obj["steerangleheadingcontribution"].is_string()?atof(obj["steerangleheadingcontribution"].get<std::string>().c_str()):obj["steerangleheadingcontribution"].get<double>());
        }
        if(obj.contains("steerangleheadingratecontribution"))
        {
            msg.steerangleheadingratecontribution = (obj["steerangleheadingratecontribution"].is_string()?atof(obj["steerangleheadingratecontribution"].get<std::string>().c_str()):obj["steerangleheadingratecontribution"].get<double>());
        }
        if(obj.contains("steeranglefeedback"))
        {
            msg.steeranglefeedback = (obj["steeranglefeedback"].is_string()?atof(obj["steeranglefeedback"].get<std::string>().c_str()):obj["steeranglefeedback"].get<double>());
        }
        if(obj.contains("steeringposition"))
        {
            msg.steeringposition = (obj["steeringposition"].is_string()?atof(obj["steeringposition"].get<std::string>().c_str()):obj["steeringposition"].get<double>());
        }
        if(obj.contains("refspeed"))
        {
            msg.refspeed = (obj["refspeed"].is_string()?atof(obj["refspeed"].get<std::string>().c_str()):obj["refspeed"].get<double>());
        }
        if(obj.contains("steeranglelimited"))
        {
            msg.steeranglelimited = (obj["steeranglelimited"].is_string()?atof(obj["steeranglelimited"].get<std::string>().c_str()):obj["steeranglelimited"].get<double>());
        }
        if(obj.contains("stationreference"))
        {
            msg.stationreference = (obj["stationreference"].is_string()?atof(obj["stationreference"].get<std::string>().c_str()):obj["stationreference"].get<double>());
        }
        if(obj.contains("stationerror"))
        {
            msg.stationerror = (obj["stationerror"].is_string()?atof(obj["stationerror"].get<std::string>().c_str()):obj["stationerror"].get<double>());
        }
        if(obj.contains("speedreference"))
        {
            msg.speedreference = (obj["speedreference"].is_string()?atof(obj["speedreference"].get<std::string>().c_str()):obj["speedreference"].get<double>());
        }
        if(obj.contains("speederror"))
        {
            msg.speederror = (obj["speederror"].is_string()?atof(obj["speederror"].get<std::string>().c_str()):obj["speederror"].get<double>());
        }
        if(obj.contains("accelerationreference"))
        {
            msg.accelerationreference = (obj["accelerationreference"].is_string()?atof(obj["accelerationreference"].get<std::string>().c_str()):obj["accelerationreference"].get<double>());
        }
        if(obj.contains("isfullstop"))
        {
            msg.isfullstop = (obj["isfullstop"].is_string()?(bool)atoi(obj["isfullstop"].get<std::string>().c_str()):obj["isfullstop"].get<bool>());
        }
        if(obj.contains("stationfeedback"))
        {
            msg.stationfeedback = (obj["stationfeedback"].is_string()?atof(obj["stationfeedback"].get<std::string>().c_str()):obj["stationfeedback"].get<double>());
        }
        if(obj.contains("speedfeedback"))
        {
            msg.speedfeedback = (obj["speedfeedback"].is_string()?atof(obj["speedfeedback"].get<std::string>().c_str()):obj["speedfeedback"].get<double>());
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
        if(obj.contains("steerunconstrainedcontroldiff"))
        {
            msg.steerunconstrainedcontroldiff = (obj["steerunconstrainedcontroldiff"].is_string()?atof(obj["steerunconstrainedcontroldiff"].get<std::string>().c_str()):obj["steerunconstrainedcontroldiff"].get<double>());
        }
        if(obj.contains("steeranglefeedforwardcompensation"))
        {
            msg.steeranglefeedforwardcompensation = (obj["steeranglefeedforwardcompensation"].is_string()?atof(obj["steeranglefeedforwardcompensation"].get<std::string>().c_str()):obj["steeranglefeedforwardcompensation"].get<double>());
        }
        if(obj.contains("matrixqupdated"))
        {
            if(obj["matrixqupdated"].is_array())
            {
                for (auto& element : obj["matrixqupdated"])
                {
                    msg.matrixqupdated.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.matrixqupdated.push_back((obj["matrixqupdated"].is_string()?atof(obj["matrixqupdated"].get<std::string>().c_str()):obj["matrixqupdated"].get<double>()));
            }
        }
        if(obj.contains("matrixrupdated"))
        {
            if(obj["matrixrupdated"].is_array())
            {
                for (auto& element : obj["matrixrupdated"])
                {
                    msg.matrixrupdated.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.matrixrupdated.push_back((obj["matrixrupdated"].is_string()?atof(obj["matrixrupdated"].get<std::string>().c_str()):obj["matrixrupdated"].get<double>()));
            }
        }
        if(obj.contains("lateralacceleration"))
        {
            msg.lateralacceleration = (obj["lateralacceleration"].is_string()?atof(obj["lateralacceleration"].get<std::string>().c_str()):obj["lateralacceleration"].get<double>());
        }
        if(obj.contains("lateraljerk"))
        {
            msg.lateraljerk = (obj["lateraljerk"].is_string()?atof(obj["lateraljerk"].get<std::string>().c_str()):obj["lateraljerk"].get<double>());
        }
        if(obj.contains("refheadingrate"))
        {
            msg.refheadingrate = (obj["refheadingrate"].is_string()?atof(obj["refheadingrate"].get<std::string>().c_str()):obj["refheadingrate"].get<double>());
        }
        if(obj.contains("headingrate"))
        {
            msg.headingrate = (obj["headingrate"].is_string()?atof(obj["headingrate"].get<std::string>().c_str()):obj["headingrate"].get<double>());
        }
        if(obj.contains("refheadingacceleration"))
        {
            msg.refheadingacceleration = (obj["refheadingacceleration"].is_string()?atof(obj["refheadingacceleration"].get<std::string>().c_str()):obj["refheadingacceleration"].get<double>());
        }
        if(obj.contains("headingacceleration"))
        {
            msg.headingacceleration = (obj["headingacceleration"].is_string()?atof(obj["headingacceleration"].get<std::string>().c_str()):obj["headingacceleration"].get<double>());
        }
        if(obj.contains("headingerroracceleration"))
        {
            msg.headingerroracceleration = (obj["headingerroracceleration"].is_string()?atof(obj["headingerroracceleration"].get<std::string>().c_str()):obj["headingerroracceleration"].get<double>());
        }
        if(obj.contains("refheadingjerk"))
        {
            msg.refheadingjerk = (obj["refheadingjerk"].is_string()?atof(obj["refheadingjerk"].get<std::string>().c_str()):obj["refheadingjerk"].get<double>());
        }
        if(obj.contains("headingjerk"))
        {
            msg.headingjerk = (obj["headingjerk"].is_string()?atof(obj["headingjerk"].get<std::string>().c_str()):obj["headingjerk"].get<double>());
        }
        if(obj.contains("headingerrorjerk"))
        {
            msg.headingerrorjerk = (obj["headingerrorjerk"].is_string()?atof(obj["headingerrorjerk"].get<std::string>().c_str()):obj["headingerrorjerk"].get<double>());
        }
        if(obj.contains("accelerationfeedback"))
        {
            msg.accelerationfeedback = (obj["accelerationfeedback"].is_string()?atof(obj["accelerationfeedback"].get<std::string>().c_str()):obj["accelerationfeedback"].get<double>());
        }
        if(obj.contains("accelerationerror"))
        {
            msg.accelerationerror = (obj["accelerationerror"].is_string()?atof(obj["accelerationerror"].get<std::string>().c_str()):obj["accelerationerror"].get<double>());
        }
        if(obj.contains("jerkreference"))
        {
            msg.jerkreference = (obj["jerkreference"].is_string()?atof(obj["jerkreference"].get<std::string>().c_str()):obj["jerkreference"].get<double>());
        }
        if(obj.contains("jerkfeedback"))
        {
            msg.jerkfeedback = (obj["jerkfeedback"].is_string()?atof(obj["jerkfeedback"].get<std::string>().c_str()):obj["jerkfeedback"].get<double>());
        }
        if(obj.contains("jerkerror"))
        {
            msg.jerkerror = (obj["jerkerror"].is_string()?atof(obj["jerkerror"].get<std::string>().c_str()):obj["jerkerror"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolSimpleMPCDebug from_json<ApollocontrolSimpleMPCDebug>(nlohmann::json obj){
        return from_json_ApollocontrolSimpleMPCDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolSimpleMPCDebug &dt)
    {
        dt=from_json_ApollocontrolSimpleMPCDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolSimpleMPCDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolSimpleMPCDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
