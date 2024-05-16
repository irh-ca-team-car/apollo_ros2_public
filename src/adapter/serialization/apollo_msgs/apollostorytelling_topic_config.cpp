#include "adapter/serialization/apollo_msgs/apollostorytelling_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingTopicConfig &msg) {
        nlohmann::json obj;
        obj["planningtrajectorytopic"] = (msg.planningtrajectorytopic);
        obj["storytellingtopic"] = (msg.storytellingtopic);
        return obj;
    }
    ApollostorytellingTopicConfig from_json_ApollostorytellingTopicConfig (nlohmann::json obj) {
        ApollostorytellingTopicConfig msg;
        if(obj.contains("planningtrajectorytopic"))
        {
            msg.planningtrajectorytopic = (obj["planningtrajectorytopic"].is_string()?(obj["planningtrajectorytopic"].get<std::string>().c_str()):obj["planningtrajectorytopic"].get<std::string>());
        }
        if(obj.contains("storytellingtopic"))
        {
            msg.storytellingtopic = (obj["storytellingtopic"].is_string()?(obj["storytellingtopic"].get<std::string>().c_str()):obj["storytellingtopic"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollostorytellingTopicConfig from_json<ApollostorytellingTopicConfig>(nlohmann::json obj){
        return from_json_ApollostorytellingTopicConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingTopicConfig &dt)
    {
        dt=from_json_ApollostorytellingTopicConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
