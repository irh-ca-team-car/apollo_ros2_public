#include "adapter/serialization/apollo_msgs/apolloplanning_planning_semantic_map_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningSemanticMapConfig &msg) {
        nlohmann::json obj;
        obj["resolution"] = (msg.resolution);
        obj["height"] = (msg.height);
        obj["width"] = (msg.width);
        obj["egoidxx"] = (msg.egoidxx);
        obj["egoidxy"] = (msg.egoidxy);
        obj["maxranddeltaphi"] = (msg.maxranddeltaphi);
        obj["maxegofuturehorizon"] = (msg.maxegofuturehorizon);
        obj["maxegopasthorizon"] = (msg.maxegopasthorizon);
        obj["maxobsfuturehorizon"] = (msg.maxobsfuturehorizon);
        obj["maxobspasthorizon"] = (msg.maxobspasthorizon);
        obj["basemappadding"] = (msg.basemappadding);
        obj["citydrivingmaxspeed"] = (msg.citydrivingmaxspeed);
        return obj;
    }
    ApolloplanningPlanningSemanticMapConfig from_json_ApolloplanningPlanningSemanticMapConfig (nlohmann::json obj) {
        ApolloplanningPlanningSemanticMapConfig msg;
        if(obj.contains("resolution"))
        {
            msg.resolution = (obj["resolution"].is_string()?atof(obj["resolution"].get<std::string>().c_str()):obj["resolution"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<int>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<int>());
        }
        if(obj.contains("egoidxx"))
        {
            msg.egoidxx = (obj["egoidxx"].is_string()?atoi(obj["egoidxx"].get<std::string>().c_str()):obj["egoidxx"].get<int>());
        }
        if(obj.contains("egoidxy"))
        {
            msg.egoidxy = (obj["egoidxy"].is_string()?atoi(obj["egoidxy"].get<std::string>().c_str()):obj["egoidxy"].get<int>());
        }
        if(obj.contains("maxranddeltaphi"))
        {
            msg.maxranddeltaphi = (obj["maxranddeltaphi"].is_string()?atof(obj["maxranddeltaphi"].get<std::string>().c_str()):obj["maxranddeltaphi"].get<double>());
        }
        if(obj.contains("maxegofuturehorizon"))
        {
            msg.maxegofuturehorizon = (obj["maxegofuturehorizon"].is_string()?atof(obj["maxegofuturehorizon"].get<std::string>().c_str()):obj["maxegofuturehorizon"].get<double>());
        }
        if(obj.contains("maxegopasthorizon"))
        {
            msg.maxegopasthorizon = (obj["maxegopasthorizon"].is_string()?atof(obj["maxegopasthorizon"].get<std::string>().c_str()):obj["maxegopasthorizon"].get<double>());
        }
        if(obj.contains("maxobsfuturehorizon"))
        {
            msg.maxobsfuturehorizon = (obj["maxobsfuturehorizon"].is_string()?atof(obj["maxobsfuturehorizon"].get<std::string>().c_str()):obj["maxobsfuturehorizon"].get<double>());
        }
        if(obj.contains("maxobspasthorizon"))
        {
            msg.maxobspasthorizon = (obj["maxobspasthorizon"].is_string()?atof(obj["maxobspasthorizon"].get<std::string>().c_str()):obj["maxobspasthorizon"].get<double>());
        }
        if(obj.contains("basemappadding"))
        {
            msg.basemappadding = (obj["basemappadding"].is_string()?atoi(obj["basemappadding"].get<std::string>().c_str()):obj["basemappadding"].get<int>());
        }
        if(obj.contains("citydrivingmaxspeed"))
        {
            msg.citydrivingmaxspeed = (obj["citydrivingmaxspeed"].is_string()?atof(obj["citydrivingmaxspeed"].get<std::string>().c_str()):obj["citydrivingmaxspeed"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningSemanticMapConfig from_json<ApolloplanningPlanningSemanticMapConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningSemanticMapConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningSemanticMapConfig &dt)
    {
        dt=from_json_ApolloplanningPlanningSemanticMapConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningSemanticMapConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningSemanticMapConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
