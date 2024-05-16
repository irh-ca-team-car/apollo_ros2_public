#include "adapter/serialization/apollo_msgs/apolloplanning_lane_change_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLaneChangeDeciderConfig &msg) {
        nlohmann::json obj;
        obj["enablelanechangeurgencycheck"] = (msg.enablelanechangeurgencycheck);
        obj["enableprioritizechangelane"] = (msg.enableprioritizechangelane);
        obj["enableremovechangelane"] = (msg.enableremovechangelane);
        obj["recklesschangelane"] = (msg.recklesschangelane);
        obj["changelanesuccessfreezetime"] = (msg.changelanesuccessfreezetime);
        obj["changelanefailfreezetime"] = (msg.changelanefailfreezetime);
        return obj;
    }
    ApolloplanningLaneChangeDeciderConfig from_json_ApolloplanningLaneChangeDeciderConfig (nlohmann::json obj) {
        ApolloplanningLaneChangeDeciderConfig msg;
        if(obj.contains("enablelanechangeurgencycheck"))
        {
            msg.enablelanechangeurgencycheck = (obj["enablelanechangeurgencycheck"].is_string()?(bool)atoi(obj["enablelanechangeurgencycheck"].get<std::string>().c_str()):obj["enablelanechangeurgencycheck"].get<bool>());
        }
        if(obj.contains("enableprioritizechangelane"))
        {
            msg.enableprioritizechangelane = (obj["enableprioritizechangelane"].is_string()?(bool)atoi(obj["enableprioritizechangelane"].get<std::string>().c_str()):obj["enableprioritizechangelane"].get<bool>());
        }
        if(obj.contains("enableremovechangelane"))
        {
            msg.enableremovechangelane = (obj["enableremovechangelane"].is_string()?(bool)atoi(obj["enableremovechangelane"].get<std::string>().c_str()):obj["enableremovechangelane"].get<bool>());
        }
        if(obj.contains("recklesschangelane"))
        {
            msg.recklesschangelane = (obj["recklesschangelane"].is_string()?(bool)atoi(obj["recklesschangelane"].get<std::string>().c_str()):obj["recklesschangelane"].get<bool>());
        }
        if(obj.contains("changelanesuccessfreezetime"))
        {
            msg.changelanesuccessfreezetime = (obj["changelanesuccessfreezetime"].is_string()?atof(obj["changelanesuccessfreezetime"].get<std::string>().c_str()):obj["changelanesuccessfreezetime"].get<double>());
        }
        if(obj.contains("changelanefailfreezetime"))
        {
            msg.changelanefailfreezetime = (obj["changelanefailfreezetime"].is_string()?atof(obj["changelanefailfreezetime"].get<std::string>().c_str()):obj["changelanefailfreezetime"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningLaneChangeDeciderConfig from_json<ApolloplanningLaneChangeDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningLaneChangeDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLaneChangeDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningLaneChangeDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLaneChangeDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLaneChangeDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
