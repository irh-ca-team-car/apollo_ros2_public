#include "adapter/serialization/apollo_msgs/apolloplanning_rule_based_stop_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRuleBasedStopDeciderConfig &msg) {
        nlohmann::json obj;
        obj["maxadcstopspeed"] = (msg.maxadcstopspeed);
        obj["maxvalidstopdistance"] = (msg.maxvalidstopdistance);
        obj["searchbeamlength"] = (msg.searchbeamlength);
        obj["searchbeamradiusintensity"] = (msg.searchbeamradiusintensity);
        obj["searchrange"] = (msg.searchrange);
        obj["isblockanglethreshold"] = (msg.isblockanglethreshold);
        obj["approachdistanceforlanechange"] = (msg.approachdistanceforlanechange);
        obj["urgentdistanceforlanechange"] = (msg.urgentdistanceforlanechange);
        return obj;
    }
    ApolloplanningRuleBasedStopDeciderConfig from_json_ApolloplanningRuleBasedStopDeciderConfig (nlohmann::json obj) {
        ApolloplanningRuleBasedStopDeciderConfig msg;
        if(obj.contains("maxadcstopspeed"))
        {
            msg.maxadcstopspeed = (obj["maxadcstopspeed"].is_string()?atof(obj["maxadcstopspeed"].get<std::string>().c_str()):obj["maxadcstopspeed"].get<double>());
        }
        if(obj.contains("maxvalidstopdistance"))
        {
            msg.maxvalidstopdistance = (obj["maxvalidstopdistance"].is_string()?atof(obj["maxvalidstopdistance"].get<std::string>().c_str()):obj["maxvalidstopdistance"].get<double>());
        }
        if(obj.contains("searchbeamlength"))
        {
            msg.searchbeamlength = (obj["searchbeamlength"].is_string()?atof(obj["searchbeamlength"].get<std::string>().c_str()):obj["searchbeamlength"].get<double>());
        }
        if(obj.contains("searchbeamradiusintensity"))
        {
            msg.searchbeamradiusintensity = (obj["searchbeamradiusintensity"].is_string()?atof(obj["searchbeamradiusintensity"].get<std::string>().c_str()):obj["searchbeamradiusintensity"].get<double>());
        }
        if(obj.contains("searchrange"))
        {
            msg.searchrange = (obj["searchrange"].is_string()?atof(obj["searchrange"].get<std::string>().c_str()):obj["searchrange"].get<double>());
        }
        if(obj.contains("isblockanglethreshold"))
        {
            msg.isblockanglethreshold = (obj["isblockanglethreshold"].is_string()?atof(obj["isblockanglethreshold"].get<std::string>().c_str()):obj["isblockanglethreshold"].get<double>());
        }
        if(obj.contains("approachdistanceforlanechange"))
        {
            msg.approachdistanceforlanechange = (obj["approachdistanceforlanechange"].is_string()?atof(obj["approachdistanceforlanechange"].get<std::string>().c_str()):obj["approachdistanceforlanechange"].get<double>());
        }
        if(obj.contains("urgentdistanceforlanechange"))
        {
            msg.urgentdistanceforlanechange = (obj["urgentdistanceforlanechange"].is_string()?atof(obj["urgentdistanceforlanechange"].get<std::string>().c_str()):obj["urgentdistanceforlanechange"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningRuleBasedStopDeciderConfig from_json<ApolloplanningRuleBasedStopDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningRuleBasedStopDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRuleBasedStopDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningRuleBasedStopDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRuleBasedStopDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRuleBasedStopDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
