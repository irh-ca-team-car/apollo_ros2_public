#include "adapter/serialization/apollo_msgs/apollorelative_map_navigator_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigatorConfig &msg) {
        nlohmann::json obj;
        obj["enablenavigatordownsample"] = (msg.enablenavigatordownsample);
        obj["sampleparam"] = to_json(msg.sampleparam);
        return obj;
    }
    ApollorelativeMapNavigatorConfig from_json_ApollorelativeMapNavigatorConfig (nlohmann::json obj) {
        ApollorelativeMapNavigatorConfig msg;
        if(obj.contains("enablenavigatordownsample"))
        {
            msg.enablenavigatordownsample = (obj["enablenavigatordownsample"].is_string()?(bool)atoi(obj["enablenavigatordownsample"].get<std::string>().c_str()):obj["enablenavigatordownsample"].get<bool>());
        }
        if(obj.contains("sampleparam"))
        {
            msg.sampleparam = from_json_ApollorelativeMapSampleParam(obj["sampleparam"]);
        }
        return msg;
    }
    template <>
    ApollorelativeMapNavigatorConfig from_json<ApollorelativeMapNavigatorConfig>(nlohmann::json obj){
        return from_json_ApollorelativeMapNavigatorConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigatorConfig &dt)
    {
        dt=from_json_ApollorelativeMapNavigatorConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigatorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigatorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
