#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_lane_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigationLaneConfig &msg) {
        nlohmann::json obj;
        obj["minlanemarkerquality"] = (msg.minlanemarkerquality);
        obj["lanesource"] = (msg.lanesource);
        obj["maxlenfromnavigationline"] = (msg.maxlenfromnavigationline);
        obj["minlenfornavigationlane"] = (msg.minlenfornavigationlane);
        obj["maxlenfornavigationlane"] = (msg.maxlenfornavigationlane);
        obj["rationavigationlanelentospeed"] = (msg.rationavigationlanelentospeed);
        obj["maxdistancetonavigationline"] = (msg.maxdistancetonavigationline);
        obj["minviewrangetouselanemarker"] = (msg.minviewrangetouselanemarker);
        obj["minlanehalfwidth"] = (msg.minlanehalfwidth);
        obj["maxlanehalfwidth"] = (msg.maxlanehalfwidth);
        obj["lanemarkerweight"] = (msg.lanemarkerweight);
        return obj;
    }
    ApollorelativeMapNavigationLaneConfig from_json_ApollorelativeMapNavigationLaneConfig (nlohmann::json obj) {
        ApollorelativeMapNavigationLaneConfig msg;
        if(obj.contains("minlanemarkerquality"))
        {
            msg.minlanemarkerquality = (obj["minlanemarkerquality"].is_string()?atof(obj["minlanemarkerquality"].get<std::string>().c_str()):obj["minlanemarkerquality"].get<double>());
        }
        if(obj.contains("lanesource"))
        {
            msg.lanesource = (obj["lanesource"].is_string()?atoi(obj["lanesource"].get<std::string>().c_str()):obj["lanesource"].get<int>());
        }
        if(obj.contains("maxlenfromnavigationline"))
        {
            msg.maxlenfromnavigationline = (obj["maxlenfromnavigationline"].is_string()?atof(obj["maxlenfromnavigationline"].get<std::string>().c_str()):obj["maxlenfromnavigationline"].get<double>());
        }
        if(obj.contains("minlenfornavigationlane"))
        {
            msg.minlenfornavigationlane = (obj["minlenfornavigationlane"].is_string()?atof(obj["minlenfornavigationlane"].get<std::string>().c_str()):obj["minlenfornavigationlane"].get<double>());
        }
        if(obj.contains("maxlenfornavigationlane"))
        {
            msg.maxlenfornavigationlane = (obj["maxlenfornavigationlane"].is_string()?atof(obj["maxlenfornavigationlane"].get<std::string>().c_str()):obj["maxlenfornavigationlane"].get<double>());
        }
        if(obj.contains("rationavigationlanelentospeed"))
        {
            msg.rationavigationlanelentospeed = (obj["rationavigationlanelentospeed"].is_string()?atof(obj["rationavigationlanelentospeed"].get<std::string>().c_str()):obj["rationavigationlanelentospeed"].get<double>());
        }
        if(obj.contains("maxdistancetonavigationline"))
        {
            msg.maxdistancetonavigationline = (obj["maxdistancetonavigationline"].is_string()?atof(obj["maxdistancetonavigationline"].get<std::string>().c_str()):obj["maxdistancetonavigationline"].get<double>());
        }
        if(obj.contains("minviewrangetouselanemarker"))
        {
            msg.minviewrangetouselanemarker = (obj["minviewrangetouselanemarker"].is_string()?atof(obj["minviewrangetouselanemarker"].get<std::string>().c_str()):obj["minviewrangetouselanemarker"].get<double>());
        }
        if(obj.contains("minlanehalfwidth"))
        {
            msg.minlanehalfwidth = (obj["minlanehalfwidth"].is_string()?atof(obj["minlanehalfwidth"].get<std::string>().c_str()):obj["minlanehalfwidth"].get<double>());
        }
        if(obj.contains("maxlanehalfwidth"))
        {
            msg.maxlanehalfwidth = (obj["maxlanehalfwidth"].is_string()?atof(obj["maxlanehalfwidth"].get<std::string>().c_str()):obj["maxlanehalfwidth"].get<double>());
        }
        if(obj.contains("lanemarkerweight"))
        {
            msg.lanemarkerweight = (obj["lanemarkerweight"].is_string()?atof(obj["lanemarkerweight"].get<std::string>().c_str()):obj["lanemarkerweight"].get<double>());
        }
        return msg;
    }
    template <>
    ApollorelativeMapNavigationLaneConfig from_json<ApollorelativeMapNavigationLaneConfig>(nlohmann::json obj){
        return from_json_ApollorelativeMapNavigationLaneConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigationLaneConfig &dt)
    {
        dt=from_json_ApollorelativeMapNavigationLaneConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigationLaneConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigationLaneConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
