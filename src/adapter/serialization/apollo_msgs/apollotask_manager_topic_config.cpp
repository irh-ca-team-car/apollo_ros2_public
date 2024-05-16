#include "adapter/serialization/apollo_msgs/apollotask_manager_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerTopicConfig &msg) {
        nlohmann::json obj;
        obj["routingrequesttopic"] = (msg.routingrequesttopic);
        obj["localizationposetopic"] = (msg.localizationposetopic);
        return obj;
    }
    ApollotaskManagerTopicConfig from_json_ApollotaskManagerTopicConfig (nlohmann::json obj) {
        ApollotaskManagerTopicConfig msg;
        if(obj.contains("routingrequesttopic"))
        {
            msg.routingrequesttopic = (obj["routingrequesttopic"].is_string()?(obj["routingrequesttopic"].get<std::string>().c_str()):obj["routingrequesttopic"].get<std::string>());
        }
        if(obj.contains("localizationposetopic"))
        {
            msg.localizationposetopic = (obj["localizationposetopic"].is_string()?(obj["localizationposetopic"].get<std::string>().c_str()):obj["localizationposetopic"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollotaskManagerTopicConfig from_json<ApollotaskManagerTopicConfig>(nlohmann::json obj){
        return from_json_ApollotaskManagerTopicConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerTopicConfig &dt)
    {
        dt=from_json_ApollotaskManagerTopicConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
