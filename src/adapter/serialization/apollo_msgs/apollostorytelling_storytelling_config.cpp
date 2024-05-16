#include "adapter/serialization/apollo_msgs/apollostorytelling_storytelling_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingStorytellingConfig &msg) {
        nlohmann::json obj;
        obj["topicconfig"] = to_json(msg.topicconfig);
        return obj;
    }
    ApollostorytellingStorytellingConfig from_json_ApollostorytellingStorytellingConfig (nlohmann::json obj) {
        ApollostorytellingStorytellingConfig msg;
        if(obj.contains("topicconfig"))
        {
            msg.topicconfig = from_json_ApollostorytellingTopicConfig(obj["topicconfig"]);
        }
        return msg;
    }
    template <>
    ApollostorytellingStorytellingConfig from_json<ApollostorytellingStorytellingConfig>(nlohmann::json obj){
        return from_json_ApollostorytellingStorytellingConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingStorytellingConfig &dt)
    {
        dt=from_json_ApollostorytellingStorytellingConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingStorytellingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingStorytellingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
