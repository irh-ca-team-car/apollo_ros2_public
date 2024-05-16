#include "adapter/serialization/apollo_msgs/apolloplanning_navi_obstacle_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNaviObstacleDeciderConfig &msg) {
        nlohmann::json obj;
        obj["minnudgedistance"] = (msg.minnudgedistance);
        obj["maxnudgedistance"] = (msg.maxnudgedistance);
        obj["maxallownudgespeed"] = (msg.maxallownudgespeed);
        obj["safedistance"] = (msg.safedistance);
        obj["nudgeallowtolerance"] = (msg.nudgeallowtolerance);
        obj["cyclesnumber"] = (msg.cyclesnumber);
        obj["judgediscoeff"] = (msg.judgediscoeff);
        obj["basisdisvalue"] = (msg.basisdisvalue);
        obj["lateralvelocityvalue"] = (msg.lateralvelocityvalue);
        obj["speeddeciderdetectrange"] = (msg.speeddeciderdetectrange);
        obj["maxkeepnudgecycles"] = (msg.maxkeepnudgecycles);
        return obj;
    }
    ApolloplanningNaviObstacleDeciderConfig from_json_ApolloplanningNaviObstacleDeciderConfig (nlohmann::json obj) {
        ApolloplanningNaviObstacleDeciderConfig msg;
        if(obj.contains("minnudgedistance"))
        {
            msg.minnudgedistance = (obj["minnudgedistance"].is_string()?atof(obj["minnudgedistance"].get<std::string>().c_str()):obj["minnudgedistance"].get<double>());
        }
        if(obj.contains("maxnudgedistance"))
        {
            msg.maxnudgedistance = (obj["maxnudgedistance"].is_string()?atof(obj["maxnudgedistance"].get<std::string>().c_str()):obj["maxnudgedistance"].get<double>());
        }
        if(obj.contains("maxallownudgespeed"))
        {
            msg.maxallownudgespeed = (obj["maxallownudgespeed"].is_string()?atof(obj["maxallownudgespeed"].get<std::string>().c_str()):obj["maxallownudgespeed"].get<double>());
        }
        if(obj.contains("safedistance"))
        {
            msg.safedistance = (obj["safedistance"].is_string()?atof(obj["safedistance"].get<std::string>().c_str()):obj["safedistance"].get<double>());
        }
        if(obj.contains("nudgeallowtolerance"))
        {
            msg.nudgeallowtolerance = (obj["nudgeallowtolerance"].is_string()?atof(obj["nudgeallowtolerance"].get<std::string>().c_str()):obj["nudgeallowtolerance"].get<double>());
        }
        if(obj.contains("cyclesnumber"))
        {
            msg.cyclesnumber = (obj["cyclesnumber"].is_string()?atoi(obj["cyclesnumber"].get<std::string>().c_str()):obj["cyclesnumber"].get<uint32_t>());
        }
        if(obj.contains("judgediscoeff"))
        {
            msg.judgediscoeff = (obj["judgediscoeff"].is_string()?atof(obj["judgediscoeff"].get<std::string>().c_str()):obj["judgediscoeff"].get<double>());
        }
        if(obj.contains("basisdisvalue"))
        {
            msg.basisdisvalue = (obj["basisdisvalue"].is_string()?atof(obj["basisdisvalue"].get<std::string>().c_str()):obj["basisdisvalue"].get<double>());
        }
        if(obj.contains("lateralvelocityvalue"))
        {
            msg.lateralvelocityvalue = (obj["lateralvelocityvalue"].is_string()?atof(obj["lateralvelocityvalue"].get<std::string>().c_str()):obj["lateralvelocityvalue"].get<double>());
        }
        if(obj.contains("speeddeciderdetectrange"))
        {
            msg.speeddeciderdetectrange = (obj["speeddeciderdetectrange"].is_string()?atof(obj["speeddeciderdetectrange"].get<std::string>().c_str()):obj["speeddeciderdetectrange"].get<double>());
        }
        if(obj.contains("maxkeepnudgecycles"))
        {
            msg.maxkeepnudgecycles = (obj["maxkeepnudgecycles"].is_string()?atoi(obj["maxkeepnudgecycles"].get<std::string>().c_str()):obj["maxkeepnudgecycles"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloplanningNaviObstacleDeciderConfig from_json<ApolloplanningNaviObstacleDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningNaviObstacleDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNaviObstacleDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningNaviObstacleDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNaviObstacleDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNaviObstacleDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
