#include "adapter/serialization/apollo_msgs/apolloplanning_keep_clear_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningKeepClearConfig &msg) {
        nlohmann::json obj;
        obj["enablekeepclearzone"] = (msg.enablekeepclearzone);
        obj["enablejunction"] = (msg.enablejunction);
        obj["minpasssdistance"] = (msg.minpasssdistance);
        obj["alignwithtrafficsigntolerance"] = (msg.alignwithtrafficsigntolerance);
        return obj;
    }
    ApolloplanningKeepClearConfig from_json_ApolloplanningKeepClearConfig (nlohmann::json obj) {
        ApolloplanningKeepClearConfig msg;
        if(obj.contains("enablekeepclearzone"))
        {
            msg.enablekeepclearzone = (obj["enablekeepclearzone"].is_string()?(bool)atoi(obj["enablekeepclearzone"].get<std::string>().c_str()):obj["enablekeepclearzone"].get<bool>());
        }
        if(obj.contains("enablejunction"))
        {
            msg.enablejunction = (obj["enablejunction"].is_string()?(bool)atoi(obj["enablejunction"].get<std::string>().c_str()):obj["enablejunction"].get<bool>());
        }
        if(obj.contains("minpasssdistance"))
        {
            msg.minpasssdistance = (obj["minpasssdistance"].is_string()?atof(obj["minpasssdistance"].get<std::string>().c_str()):obj["minpasssdistance"].get<double>());
        }
        if(obj.contains("alignwithtrafficsigntolerance"))
        {
            msg.alignwithtrafficsigntolerance = (obj["alignwithtrafficsigntolerance"].is_string()?atof(obj["alignwithtrafficsigntolerance"].get<std::string>().c_str()):obj["alignwithtrafficsigntolerance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningKeepClearConfig from_json<ApolloplanningKeepClearConfig>(nlohmann::json obj){
        return from_json_ApolloplanningKeepClearConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningKeepClearConfig &dt)
    {
        dt=from_json_ApolloplanningKeepClearConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningKeepClearConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningKeepClearConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
