#include "adapter/serialization/apollo_msgs/apollolocalization_localization_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationLocalizationConfig &msg) {
        nlohmann::json obj;
        obj["localizationtype"] = (msg.localizationtype);
        return obj;
    }
    ApollolocalizationLocalizationConfig from_json_ApollolocalizationLocalizationConfig (nlohmann::json obj) {
        ApollolocalizationLocalizationConfig msg;
        if(obj.contains("localizationtype"))
        {
            msg.localizationtype = (obj["localizationtype"].is_string()?atoi(obj["localizationtype"].get<std::string>().c_str()):obj["localizationtype"].get<int>());
        }
        return msg;
    }
    template <>
    ApollolocalizationLocalizationConfig from_json<ApollolocalizationLocalizationConfig>(nlohmann::json obj){
        return from_json_ApollolocalizationLocalizationConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationLocalizationConfig &dt)
    {
        dt=from_json_ApollolocalizationLocalizationConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationLocalizationConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationLocalizationConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
