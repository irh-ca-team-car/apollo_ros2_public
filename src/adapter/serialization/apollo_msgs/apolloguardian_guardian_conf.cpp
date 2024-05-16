#include "adapter/serialization/apollo_msgs/apolloguardian_guardian_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloguardianGuardianConf &msg) {
        nlohmann::json obj;
        obj["guardianenable"] = (msg.guardianenable);
        obj["guardiancmdemergencystoppercentage"] = (msg.guardiancmdemergencystoppercentage);
        obj["guardiancmdsoftstoppercentage"] = (msg.guardiancmdsoftstoppercentage);
        return obj;
    }
    ApolloguardianGuardianConf from_json_ApolloguardianGuardianConf (nlohmann::json obj) {
        ApolloguardianGuardianConf msg;
        if(obj.contains("guardianenable"))
        {
            msg.guardianenable = (obj["guardianenable"].is_string()?(bool)atoi(obj["guardianenable"].get<std::string>().c_str()):obj["guardianenable"].get<bool>());
        }
        if(obj.contains("guardiancmdemergencystoppercentage"))
        {
            msg.guardiancmdemergencystoppercentage = (obj["guardiancmdemergencystoppercentage"].is_string()?atof(obj["guardiancmdemergencystoppercentage"].get<std::string>().c_str()):obj["guardiancmdemergencystoppercentage"].get<double>());
        }
        if(obj.contains("guardiancmdsoftstoppercentage"))
        {
            msg.guardiancmdsoftstoppercentage = (obj["guardiancmdsoftstoppercentage"].is_string()?atof(obj["guardiancmdsoftstoppercentage"].get<std::string>().c_str()):obj["guardiancmdsoftstoppercentage"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloguardianGuardianConf from_json<ApolloguardianGuardianConf>(nlohmann::json obj){
        return from_json_ApolloguardianGuardianConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloguardianGuardianConf &dt)
    {
        dt=from_json_ApolloguardianGuardianConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloguardianGuardianConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloguardianGuardianConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
