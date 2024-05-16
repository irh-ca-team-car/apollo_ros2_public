#include "adapter/serialization/apollo_msgs/apolloplanning_dp_st_speed_optimizer_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDpStSpeedOptimizerConfig &msg) {
        nlohmann::json obj;
        obj["unitt"] = (msg.unitt);
        obj["densedimensions"] = (msg.densedimensions);
        obj["denseunits"] = (msg.denseunits);
        obj["sparseunits"] = (msg.sparseunits);
        obj["speedweight"] = (msg.speedweight);
        obj["accelweight"] = (msg.accelweight);
        obj["jerkweight"] = (msg.jerkweight);
        obj["obstacleweight"] = (msg.obstacleweight);
        obj["referenceweight"] = (msg.referenceweight);
        obj["godownbuffer"] = (msg.godownbuffer);
        obj["goupbuffer"] = (msg.goupbuffer);
        obj["defaultobstaclecost"] = (msg.defaultobstaclecost);
        obj["defaultspeedcost"] = (msg.defaultspeedcost);
        obj["exceedspeedpenalty"] = (msg.exceedspeedpenalty);
        obj["lowspeedpenalty"] = (msg.lowspeedpenalty);
        obj["referencespeedpenalty"] = (msg.referencespeedpenalty);
        obj["keepclearlowspeedpenalty"] = (msg.keepclearlowspeedpenalty);
        obj["accelpenalty"] = (msg.accelpenalty);
        obj["decelpenalty"] = (msg.decelpenalty);
        obj["positivejerkcoeff"] = (msg.positivejerkcoeff);
        obj["negativejerkcoeff"] = (msg.negativejerkcoeff);
        obj["maxacceleration"] = (msg.maxacceleration);
        obj["maxdeceleration"] = (msg.maxdeceleration);
        obj["safetimebuffer"] = (msg.safetimebuffer);
        obj["safedistance"] = (msg.safedistance);
        obj["spatialpotentialpenalty"] = (msg.spatialpotentialpenalty);
        obj["islanechanging"] = (msg.islanechanging);
        return obj;
    }
    ApolloplanningDpStSpeedOptimizerConfig from_json_ApolloplanningDpStSpeedOptimizerConfig (nlohmann::json obj) {
        ApolloplanningDpStSpeedOptimizerConfig msg;
        if(obj.contains("unitt"))
        {
            msg.unitt = (obj["unitt"].is_string()?atof(obj["unitt"].get<std::string>().c_str()):obj["unitt"].get<double>());
        }
        if(obj.contains("densedimensions"))
        {
            msg.densedimensions = (obj["densedimensions"].is_string()?atoi(obj["densedimensions"].get<std::string>().c_str()):obj["densedimensions"].get<int>());
        }
        if(obj.contains("denseunits"))
        {
            msg.denseunits = (obj["denseunits"].is_string()?atof(obj["denseunits"].get<std::string>().c_str()):obj["denseunits"].get<double>());
        }
        if(obj.contains("sparseunits"))
        {
            msg.sparseunits = (obj["sparseunits"].is_string()?atof(obj["sparseunits"].get<std::string>().c_str()):obj["sparseunits"].get<double>());
        }
        if(obj.contains("speedweight"))
        {
            msg.speedweight = (obj["speedweight"].is_string()?atof(obj["speedweight"].get<std::string>().c_str()):obj["speedweight"].get<double>());
        }
        if(obj.contains("accelweight"))
        {
            msg.accelweight = (obj["accelweight"].is_string()?atof(obj["accelweight"].get<std::string>().c_str()):obj["accelweight"].get<double>());
        }
        if(obj.contains("jerkweight"))
        {
            msg.jerkweight = (obj["jerkweight"].is_string()?atof(obj["jerkweight"].get<std::string>().c_str()):obj["jerkweight"].get<double>());
        }
        if(obj.contains("obstacleweight"))
        {
            msg.obstacleweight = (obj["obstacleweight"].is_string()?atof(obj["obstacleweight"].get<std::string>().c_str()):obj["obstacleweight"].get<double>());
        }
        if(obj.contains("referenceweight"))
        {
            msg.referenceweight = (obj["referenceweight"].is_string()?atof(obj["referenceweight"].get<std::string>().c_str()):obj["referenceweight"].get<double>());
        }
        if(obj.contains("godownbuffer"))
        {
            msg.godownbuffer = (obj["godownbuffer"].is_string()?atof(obj["godownbuffer"].get<std::string>().c_str()):obj["godownbuffer"].get<double>());
        }
        if(obj.contains("goupbuffer"))
        {
            msg.goupbuffer = (obj["goupbuffer"].is_string()?atof(obj["goupbuffer"].get<std::string>().c_str()):obj["goupbuffer"].get<double>());
        }
        if(obj.contains("defaultobstaclecost"))
        {
            msg.defaultobstaclecost = (obj["defaultobstaclecost"].is_string()?atof(obj["defaultobstaclecost"].get<std::string>().c_str()):obj["defaultobstaclecost"].get<double>());
        }
        if(obj.contains("defaultspeedcost"))
        {
            msg.defaultspeedcost = (obj["defaultspeedcost"].is_string()?atof(obj["defaultspeedcost"].get<std::string>().c_str()):obj["defaultspeedcost"].get<double>());
        }
        if(obj.contains("exceedspeedpenalty"))
        {
            msg.exceedspeedpenalty = (obj["exceedspeedpenalty"].is_string()?atof(obj["exceedspeedpenalty"].get<std::string>().c_str()):obj["exceedspeedpenalty"].get<double>());
        }
        if(obj.contains("lowspeedpenalty"))
        {
            msg.lowspeedpenalty = (obj["lowspeedpenalty"].is_string()?atof(obj["lowspeedpenalty"].get<std::string>().c_str()):obj["lowspeedpenalty"].get<double>());
        }
        if(obj.contains("referencespeedpenalty"))
        {
            msg.referencespeedpenalty = (obj["referencespeedpenalty"].is_string()?atof(obj["referencespeedpenalty"].get<std::string>().c_str()):obj["referencespeedpenalty"].get<double>());
        }
        if(obj.contains("keepclearlowspeedpenalty"))
        {
            msg.keepclearlowspeedpenalty = (obj["keepclearlowspeedpenalty"].is_string()?atof(obj["keepclearlowspeedpenalty"].get<std::string>().c_str()):obj["keepclearlowspeedpenalty"].get<double>());
        }
        if(obj.contains("accelpenalty"))
        {
            msg.accelpenalty = (obj["accelpenalty"].is_string()?atof(obj["accelpenalty"].get<std::string>().c_str()):obj["accelpenalty"].get<double>());
        }
        if(obj.contains("decelpenalty"))
        {
            msg.decelpenalty = (obj["decelpenalty"].is_string()?atof(obj["decelpenalty"].get<std::string>().c_str()):obj["decelpenalty"].get<double>());
        }
        if(obj.contains("positivejerkcoeff"))
        {
            msg.positivejerkcoeff = (obj["positivejerkcoeff"].is_string()?atof(obj["positivejerkcoeff"].get<std::string>().c_str()):obj["positivejerkcoeff"].get<double>());
        }
        if(obj.contains("negativejerkcoeff"))
        {
            msg.negativejerkcoeff = (obj["negativejerkcoeff"].is_string()?atof(obj["negativejerkcoeff"].get<std::string>().c_str()):obj["negativejerkcoeff"].get<double>());
        }
        if(obj.contains("maxacceleration"))
        {
            msg.maxacceleration = (obj["maxacceleration"].is_string()?atof(obj["maxacceleration"].get<std::string>().c_str()):obj["maxacceleration"].get<double>());
        }
        if(obj.contains("maxdeceleration"))
        {
            msg.maxdeceleration = (obj["maxdeceleration"].is_string()?atof(obj["maxdeceleration"].get<std::string>().c_str()):obj["maxdeceleration"].get<double>());
        }
        if(obj.contains("safetimebuffer"))
        {
            msg.safetimebuffer = (obj["safetimebuffer"].is_string()?atof(obj["safetimebuffer"].get<std::string>().c_str()):obj["safetimebuffer"].get<double>());
        }
        if(obj.contains("safedistance"))
        {
            msg.safedistance = (obj["safedistance"].is_string()?atof(obj["safedistance"].get<std::string>().c_str()):obj["safedistance"].get<double>());
        }
        if(obj.contains("spatialpotentialpenalty"))
        {
            msg.spatialpotentialpenalty = (obj["spatialpotentialpenalty"].is_string()?atof(obj["spatialpotentialpenalty"].get<std::string>().c_str()):obj["spatialpotentialpenalty"].get<double>());
        }
        if(obj.contains("islanechanging"))
        {
            msg.islanechanging = (obj["islanechanging"].is_string()?(bool)atoi(obj["islanechanging"].get<std::string>().c_str()):obj["islanechanging"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningDpStSpeedOptimizerConfig from_json<ApolloplanningDpStSpeedOptimizerConfig>(nlohmann::json obj){
        return from_json_ApolloplanningDpStSpeedOptimizerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDpStSpeedOptimizerConfig &dt)
    {
        dt=from_json_ApolloplanningDpStSpeedOptimizerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDpStSpeedOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDpStSpeedOptimizerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
