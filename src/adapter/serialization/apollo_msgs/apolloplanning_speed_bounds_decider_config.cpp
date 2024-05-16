#include "adapter/serialization/apollo_msgs/apolloplanning_speed_bounds_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpeedBoundsDeciderConfig &msg) {
        nlohmann::json obj;
        obj["totaltime"] = (msg.totaltime);
        obj["boundarybuffer"] = (msg.boundarybuffer);
        obj["maxcentricaccelerationlimit"] = (msg.maxcentricaccelerationlimit);
        obj["minimalkappa"] = (msg.minimalkappa);
        obj["pointextension"] = (msg.pointextension);
        obj["lowestspeed"] = (msg.lowestspeed);
        obj["collisionsafetyrange"] = (msg.collisionsafetyrange);
        obj["staticobsnudgespeedratio"] = (msg.staticobsnudgespeedratio);
        obj["dynamicobsnudgespeedratio"] = (msg.dynamicobsnudgespeedratio);
        return obj;
    }
    ApolloplanningSpeedBoundsDeciderConfig from_json_ApolloplanningSpeedBoundsDeciderConfig (nlohmann::json obj) {
        ApolloplanningSpeedBoundsDeciderConfig msg;
        if(obj.contains("totaltime"))
        {
            msg.totaltime = (obj["totaltime"].is_string()?atof(obj["totaltime"].get<std::string>().c_str()):obj["totaltime"].get<double>());
        }
        if(obj.contains("boundarybuffer"))
        {
            msg.boundarybuffer = (obj["boundarybuffer"].is_string()?atof(obj["boundarybuffer"].get<std::string>().c_str()):obj["boundarybuffer"].get<double>());
        }
        if(obj.contains("maxcentricaccelerationlimit"))
        {
            msg.maxcentricaccelerationlimit = (obj["maxcentricaccelerationlimit"].is_string()?atof(obj["maxcentricaccelerationlimit"].get<std::string>().c_str()):obj["maxcentricaccelerationlimit"].get<double>());
        }
        if(obj.contains("minimalkappa"))
        {
            msg.minimalkappa = (obj["minimalkappa"].is_string()?atof(obj["minimalkappa"].get<std::string>().c_str()):obj["minimalkappa"].get<double>());
        }
        if(obj.contains("pointextension"))
        {
            msg.pointextension = (obj["pointextension"].is_string()?atof(obj["pointextension"].get<std::string>().c_str()):obj["pointextension"].get<double>());
        }
        if(obj.contains("lowestspeed"))
        {
            msg.lowestspeed = (obj["lowestspeed"].is_string()?atof(obj["lowestspeed"].get<std::string>().c_str()):obj["lowestspeed"].get<double>());
        }
        if(obj.contains("collisionsafetyrange"))
        {
            msg.collisionsafetyrange = (obj["collisionsafetyrange"].is_string()?atof(obj["collisionsafetyrange"].get<std::string>().c_str()):obj["collisionsafetyrange"].get<double>());
        }
        if(obj.contains("staticobsnudgespeedratio"))
        {
            msg.staticobsnudgespeedratio = (obj["staticobsnudgespeedratio"].is_string()?atof(obj["staticobsnudgespeedratio"].get<std::string>().c_str()):obj["staticobsnudgespeedratio"].get<double>());
        }
        if(obj.contains("dynamicobsnudgespeedratio"))
        {
            msg.dynamicobsnudgespeedratio = (obj["dynamicobsnudgespeedratio"].is_string()?atof(obj["dynamicobsnudgespeedratio"].get<std::string>().c_str()):obj["dynamicobsnudgespeedratio"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningSpeedBoundsDeciderConfig from_json<ApolloplanningSpeedBoundsDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningSpeedBoundsDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpeedBoundsDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningSpeedBoundsDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpeedBoundsDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpeedBoundsDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
