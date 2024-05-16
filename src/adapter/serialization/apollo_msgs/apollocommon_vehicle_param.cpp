#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleParam &msg) {
        nlohmann::json obj;
        obj["brand"] = (msg.brand);
        obj["vehicleid"] = to_json(msg.vehicleid);
        obj["frontedgetocenter"] = (msg.frontedgetocenter);
        obj["backedgetocenter"] = (msg.backedgetocenter);
        obj["leftedgetocenter"] = (msg.leftedgetocenter);
        obj["rightedgetocenter"] = (msg.rightedgetocenter);
        obj["length"] = (msg.length);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["minturnradius"] = (msg.minturnradius);
        obj["maxacceleration"] = (msg.maxacceleration);
        obj["maxdeceleration"] = (msg.maxdeceleration);
        obj["maxsteerangle"] = (msg.maxsteerangle);
        obj["maxsteeranglerate"] = (msg.maxsteeranglerate);
        obj["minsteeranglerate"] = (msg.minsteeranglerate);
        obj["steerratio"] = (msg.steerratio);
        obj["wheelbase"] = (msg.wheelbase);
        obj["wheelrollingradius"] = (msg.wheelrollingradius);
        obj["maxabsspeedwhenstopped"] = (msg.maxabsspeedwhenstopped);
        obj["brakedeadzone"] = (msg.brakedeadzone);
        obj["throttledeadzone"] = (msg.throttledeadzone);
        obj["steeringlatencyparam"] = to_json(msg.steeringlatencyparam);
        obj["throttlelatencyparam"] = to_json(msg.throttlelatencyparam);
        obj["brakelatencyparam"] = to_json(msg.brakelatencyparam);
        return obj;
    }
    ApollocommonVehicleParam from_json_ApollocommonVehicleParam (nlohmann::json obj) {
        ApollocommonVehicleParam msg;
        if(obj.contains("brand"))
        {
            msg.brand = (obj["brand"].is_string()?atoi(obj["brand"].get<std::string>().c_str()):obj["brand"].get<int>());
        }
        if(obj.contains("vehicleid"))
        {
            msg.vehicleid = from_json_ApollocommonVehicleID(obj["vehicleid"]);
        }
        if(obj.contains("frontedgetocenter"))
        {
            msg.frontedgetocenter = (obj["frontedgetocenter"].is_string()?atof(obj["frontedgetocenter"].get<std::string>().c_str()):obj["frontedgetocenter"].get<double>());
        }
        if(obj.contains("backedgetocenter"))
        {
            msg.backedgetocenter = (obj["backedgetocenter"].is_string()?atof(obj["backedgetocenter"].get<std::string>().c_str()):obj["backedgetocenter"].get<double>());
        }
        if(obj.contains("leftedgetocenter"))
        {
            msg.leftedgetocenter = (obj["leftedgetocenter"].is_string()?atof(obj["leftedgetocenter"].get<std::string>().c_str()):obj["leftedgetocenter"].get<double>());
        }
        if(obj.contains("rightedgetocenter"))
        {
            msg.rightedgetocenter = (obj["rightedgetocenter"].is_string()?atof(obj["rightedgetocenter"].get<std::string>().c_str()):obj["rightedgetocenter"].get<double>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atof(obj["height"].get<std::string>().c_str()):obj["height"].get<double>());
        }
        if(obj.contains("minturnradius"))
        {
            msg.minturnradius = (obj["minturnradius"].is_string()?atof(obj["minturnradius"].get<std::string>().c_str()):obj["minturnradius"].get<double>());
        }
        if(obj.contains("maxacceleration"))
        {
            msg.maxacceleration = (obj["maxacceleration"].is_string()?atof(obj["maxacceleration"].get<std::string>().c_str()):obj["maxacceleration"].get<double>());
        }
        if(obj.contains("maxdeceleration"))
        {
            msg.maxdeceleration = (obj["maxdeceleration"].is_string()?atof(obj["maxdeceleration"].get<std::string>().c_str()):obj["maxdeceleration"].get<double>());
        }
        if(obj.contains("maxsteerangle"))
        {
            msg.maxsteerangle = (obj["maxsteerangle"].is_string()?atof(obj["maxsteerangle"].get<std::string>().c_str()):obj["maxsteerangle"].get<double>());
        }
        if(obj.contains("maxsteeranglerate"))
        {
            msg.maxsteeranglerate = (obj["maxsteeranglerate"].is_string()?atof(obj["maxsteeranglerate"].get<std::string>().c_str()):obj["maxsteeranglerate"].get<double>());
        }
        if(obj.contains("minsteeranglerate"))
        {
            msg.minsteeranglerate = (obj["minsteeranglerate"].is_string()?atof(obj["minsteeranglerate"].get<std::string>().c_str()):obj["minsteeranglerate"].get<double>());
        }
        if(obj.contains("steerratio"))
        {
            msg.steerratio = (obj["steerratio"].is_string()?atof(obj["steerratio"].get<std::string>().c_str()):obj["steerratio"].get<double>());
        }
        if(obj.contains("wheelbase"))
        {
            msg.wheelbase = (obj["wheelbase"].is_string()?atof(obj["wheelbase"].get<std::string>().c_str()):obj["wheelbase"].get<double>());
        }
        if(obj.contains("wheelrollingradius"))
        {
            msg.wheelrollingradius = (obj["wheelrollingradius"].is_string()?atof(obj["wheelrollingradius"].get<std::string>().c_str()):obj["wheelrollingradius"].get<double>());
        }
        if(obj.contains("maxabsspeedwhenstopped"))
        {
            msg.maxabsspeedwhenstopped = (obj["maxabsspeedwhenstopped"].is_string()?(float)atof(obj["maxabsspeedwhenstopped"].get<std::string>().c_str()):obj["maxabsspeedwhenstopped"].get<float>());
        }
        if(obj.contains("brakedeadzone"))
        {
            msg.brakedeadzone = (obj["brakedeadzone"].is_string()?atof(obj["brakedeadzone"].get<std::string>().c_str()):obj["brakedeadzone"].get<double>());
        }
        if(obj.contains("throttledeadzone"))
        {
            msg.throttledeadzone = (obj["throttledeadzone"].is_string()?atof(obj["throttledeadzone"].get<std::string>().c_str()):obj["throttledeadzone"].get<double>());
        }
        if(obj.contains("steeringlatencyparam"))
        {
            msg.steeringlatencyparam = from_json_ApollocommonLatencyParam(obj["steeringlatencyparam"]);
        }
        if(obj.contains("throttlelatencyparam"))
        {
            msg.throttlelatencyparam = from_json_ApollocommonLatencyParam(obj["throttlelatencyparam"]);
        }
        if(obj.contains("brakelatencyparam"))
        {
            msg.brakelatencyparam = from_json_ApollocommonLatencyParam(obj["brakelatencyparam"]);
        }
        return msg;
    }
    template <>
    ApollocommonVehicleParam from_json<ApollocommonVehicleParam>(nlohmann::json obj){
        return from_json_ApollocommonVehicleParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleParam &dt)
    {
        dt=from_json_ApollocommonVehicleParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
