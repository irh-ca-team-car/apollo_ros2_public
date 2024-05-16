#include "adapter/serialization/apollo_msgs/apolloplanning_scenario_pull_over_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningScenarioPullOverConfig &msg) {
        nlohmann::json obj;
        obj["startpulloverscenariodistance"] = (msg.startpulloverscenariodistance);
        obj["pullovermindistancebuffer"] = (msg.pullovermindistancebuffer);
        obj["maxdistancestopsearch"] = (msg.maxdistancestopsearch);
        obj["maxserrortoendpoint"] = (msg.maxserrortoendpoint);
        obj["maxlerrortoendpoint"] = (msg.maxlerrortoendpoint);
        obj["maxthetaerrortoendpoint"] = (msg.maxthetaerrortoendpoint);
        obj["maxdistanceerrortoendpoint"] = (msg.maxdistanceerrortoendpoint);
        obj["passdestinationthreshold"] = (msg.passdestinationthreshold);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["sdistancetostopforopenspaceparking"] = (msg.sdistancetostopforopenspaceparking);
        return obj;
    }
    ApolloplanningScenarioPullOverConfig from_json_ApolloplanningScenarioPullOverConfig (nlohmann::json obj) {
        ApolloplanningScenarioPullOverConfig msg;
        if(obj.contains("startpulloverscenariodistance"))
        {
            msg.startpulloverscenariodistance = (obj["startpulloverscenariodistance"].is_string()?atof(obj["startpulloverscenariodistance"].get<std::string>().c_str()):obj["startpulloverscenariodistance"].get<double>());
        }
        if(obj.contains("pullovermindistancebuffer"))
        {
            msg.pullovermindistancebuffer = (obj["pullovermindistancebuffer"].is_string()?atof(obj["pullovermindistancebuffer"].get<std::string>().c_str()):obj["pullovermindistancebuffer"].get<double>());
        }
        if(obj.contains("maxdistancestopsearch"))
        {
            msg.maxdistancestopsearch = (obj["maxdistancestopsearch"].is_string()?atof(obj["maxdistancestopsearch"].get<std::string>().c_str()):obj["maxdistancestopsearch"].get<double>());
        }
        if(obj.contains("maxserrortoendpoint"))
        {
            msg.maxserrortoendpoint = (obj["maxserrortoendpoint"].is_string()?atof(obj["maxserrortoendpoint"].get<std::string>().c_str()):obj["maxserrortoendpoint"].get<double>());
        }
        if(obj.contains("maxlerrortoendpoint"))
        {
            msg.maxlerrortoendpoint = (obj["maxlerrortoendpoint"].is_string()?atof(obj["maxlerrortoendpoint"].get<std::string>().c_str()):obj["maxlerrortoendpoint"].get<double>());
        }
        if(obj.contains("maxthetaerrortoendpoint"))
        {
            msg.maxthetaerrortoendpoint = (obj["maxthetaerrortoendpoint"].is_string()?atof(obj["maxthetaerrortoendpoint"].get<std::string>().c_str()):obj["maxthetaerrortoendpoint"].get<double>());
        }
        if(obj.contains("maxdistanceerrortoendpoint"))
        {
            msg.maxdistanceerrortoendpoint = (obj["maxdistanceerrortoendpoint"].is_string()?atof(obj["maxdistanceerrortoendpoint"].get<std::string>().c_str()):obj["maxdistanceerrortoendpoint"].get<double>());
        }
        if(obj.contains("passdestinationthreshold"))
        {
            msg.passdestinationthreshold = (obj["passdestinationthreshold"].is_string()?atof(obj["passdestinationthreshold"].get<std::string>().c_str()):obj["passdestinationthreshold"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("sdistancetostopforopenspaceparking"))
        {
            msg.sdistancetostopforopenspaceparking = (obj["sdistancetostopforopenspaceparking"].is_string()?atof(obj["sdistancetostopforopenspaceparking"].get<std::string>().c_str()):obj["sdistancetostopforopenspaceparking"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningScenarioPullOverConfig from_json<ApolloplanningScenarioPullOverConfig>(nlohmann::json obj){
        return from_json_ApolloplanningScenarioPullOverConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningScenarioPullOverConfig &dt)
    {
        dt=from_json_ApolloplanningScenarioPullOverConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningScenarioPullOverConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningScenarioPullOverConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
