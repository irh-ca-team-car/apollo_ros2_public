#include "adapter/serialization/apollo_msgs/matcher_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const MatcherConfig &msg) {
        nlohmann::json obj;
        obj["maxmatchdistance"] = (msg.maxmatchdistance);
        obj["boundmatchdistance"] = (msg.boundmatchdistance);
        return obj;
    }
    MatcherConfig from_json_MatcherConfig (nlohmann::json obj) {
        MatcherConfig msg;
        if(obj.contains("maxmatchdistance"))
        {
            msg.maxmatchdistance = (obj["maxmatchdistance"].is_string()?atof(obj["maxmatchdistance"].get<std::string>().c_str()):obj["maxmatchdistance"].get<double>());
        }
        if(obj.contains("boundmatchdistance"))
        {
            msg.boundmatchdistance = (obj["boundmatchdistance"].is_string()?atof(obj["boundmatchdistance"].get<std::string>().c_str()):obj["boundmatchdistance"].get<double>());
        }
        return msg;
    }
    template <>
    MatcherConfig from_json<MatcherConfig>(nlohmann::json obj){
        return from_json_MatcherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, MatcherConfig &dt)
    {
        dt=from_json_MatcherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const MatcherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const MatcherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
