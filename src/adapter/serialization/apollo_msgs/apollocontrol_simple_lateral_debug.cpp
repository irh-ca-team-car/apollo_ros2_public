#include "adapter/serialization/apollo_msgs/apollocontrol_simple_lateral_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolSimpleLateralDebug &msg) {
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
        obj["lateralerrorfeedback"] = (msg.lateralerrorfeedback);
        obj["headingerrorfeedback"] = (msg.headingerrorfeedback);
        obj["currenttargetpoint"] = to_json(msg.currenttargetpoint);
        obj["steeranglefeedbackaugment"] = (msg.steeranglefeedbackaugment);
        obj["steermracdebug"] = to_json(msg.steermracdebug);
        obj["steermracenablestatus"] = (msg.steermracenablestatus);
        return obj;
    }
    ApollocontrolSimpleLateralDebug from_json_ApollocontrolSimpleLateralDebug (nlohmann::json obj) {
        ApollocontrolSimpleLateralDebug msg;
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
        if(obj.contains("lateralerrorfeedback"))
        {
            msg.lateralerrorfeedback = (obj["lateralerrorfeedback"].is_string()?atof(obj["lateralerrorfeedback"].get<std::string>().c_str()):obj["lateralerrorfeedback"].get<double>());
        }
        if(obj.contains("headingerrorfeedback"))
        {
            msg.headingerrorfeedback = (obj["headingerrorfeedback"].is_string()?atof(obj["headingerrorfeedback"].get<std::string>().c_str()):obj["headingerrorfeedback"].get<double>());
        }
        if(obj.contains("currenttargetpoint"))
        {
            msg.currenttargetpoint = from_json_ApollocommonTrajectoryPoint(obj["currenttargetpoint"]);
        }
        if(obj.contains("steeranglefeedbackaugment"))
        {
            msg.steeranglefeedbackaugment = (obj["steeranglefeedbackaugment"].is_string()?atof(obj["steeranglefeedbackaugment"].get<std::string>().c_str()):obj["steeranglefeedbackaugment"].get<double>());
        }
        if(obj.contains("steermracdebug"))
        {
            msg.steermracdebug = from_json_ApollocontrolMracDebug(obj["steermracdebug"]);
        }
        if(obj.contains("steermracenablestatus"))
        {
            msg.steermracenablestatus = (obj["steermracenablestatus"].is_string()?(bool)atoi(obj["steermracenablestatus"].get<std::string>().c_str()):obj["steermracenablestatus"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocontrolSimpleLateralDebug from_json<ApollocontrolSimpleLateralDebug>(nlohmann::json obj){
        return from_json_ApollocontrolSimpleLateralDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolSimpleLateralDebug &dt)
    {
        dt=from_json_ApollocontrolSimpleLateralDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolSimpleLateralDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolSimpleLateralDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
