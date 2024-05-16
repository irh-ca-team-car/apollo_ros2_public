#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_fall_back_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceFallBackDeciderConfig &msg) {
        nlohmann::json obj;
        obj["openspacepredictiontimeperiod"] = (msg.openspacepredictiontimeperiod);
        obj["openspacefallbackcollisiondistance"] = (msg.openspacefallbackcollisiondistance);
        obj["openspacefallbackstopdistance"] = (msg.openspacefallbackstopdistance);
        obj["openspacefallbackcollisiontimebuffer"] = (msg.openspacefallbackcollisiontimebuffer);
        return obj;
    }
    ApolloplanningOpenSpaceFallBackDeciderConfig from_json_ApolloplanningOpenSpaceFallBackDeciderConfig (nlohmann::json obj) {
        ApolloplanningOpenSpaceFallBackDeciderConfig msg;
        if(obj.contains("openspacepredictiontimeperiod"))
        {
            msg.openspacepredictiontimeperiod = (obj["openspacepredictiontimeperiod"].is_string()?atof(obj["openspacepredictiontimeperiod"].get<std::string>().c_str()):obj["openspacepredictiontimeperiod"].get<double>());
        }
        if(obj.contains("openspacefallbackcollisiondistance"))
        {
            msg.openspacefallbackcollisiondistance = (obj["openspacefallbackcollisiondistance"].is_string()?atof(obj["openspacefallbackcollisiondistance"].get<std::string>().c_str()):obj["openspacefallbackcollisiondistance"].get<double>());
        }
        if(obj.contains("openspacefallbackstopdistance"))
        {
            msg.openspacefallbackstopdistance = (obj["openspacefallbackstopdistance"].is_string()?atof(obj["openspacefallbackstopdistance"].get<std::string>().c_str()):obj["openspacefallbackstopdistance"].get<double>());
        }
        if(obj.contains("openspacefallbackcollisiontimebuffer"))
        {
            msg.openspacefallbackcollisiontimebuffer = (obj["openspacefallbackcollisiontimebuffer"].is_string()?atof(obj["openspacefallbackcollisiontimebuffer"].get<std::string>().c_str()):obj["openspacefallbackcollisiontimebuffer"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpaceFallBackDeciderConfig from_json<ApolloplanningOpenSpaceFallBackDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpaceFallBackDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceFallBackDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningOpenSpaceFallBackDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceFallBackDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceFallBackDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
