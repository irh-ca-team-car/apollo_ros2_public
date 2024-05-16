#include "adapter/serialization/apollo_msgs/apolloplanning_object_motion_typemotion_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectMotionTypemotionTag &msg) {
        nlohmann::json obj;
        obj["staticc"] = (msg.staticc);
        obj["dynamic"] = (msg.dynamic);
        return obj;
    }
    ApolloplanningObjectMotionTypemotionTag from_json_ApolloplanningObjectMotionTypemotionTag (nlohmann::json obj) {
        ApolloplanningObjectMotionTypemotionTag msg;
        if(obj.contains("staticc"))
        {
            msg.staticc = (obj["staticc"].is_string()?atoi(obj["staticc"].get<std::string>().c_str()):obj["staticc"].get<int>());
        }
        if(obj.contains("dynamic"))
        {
            msg.dynamic = (obj["dynamic"].is_string()?atoi(obj["dynamic"].get<std::string>().c_str()):obj["dynamic"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningObjectMotionTypemotionTag from_json<ApolloplanningObjectMotionTypemotionTag>(nlohmann::json obj){
        return from_json_ApolloplanningObjectMotionTypemotionTag(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectMotionTypemotionTag &dt)
    {
        dt=from_json_ApolloplanningObjectMotionTypemotionTag(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectMotionTypemotionTag & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectMotionTypemotionTag & dt)
    {
        os << to_json(dt);
        return os;
    }
}
