#include "adapter/serialization/apollo_msgs/apolloplanning_object_motion_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectMotionType &msg) {
        nlohmann::json obj;
        obj["motiontag"] = to_json(msg.motiontag);
        return obj;
    }
    ApolloplanningObjectMotionType from_json_ApolloplanningObjectMotionType (nlohmann::json obj) {
        ApolloplanningObjectMotionType msg;
        if(obj.contains("motiontag"))
        {
            msg.motiontag = from_json_ApolloplanningObjectMotionTypemotionTag(obj["motiontag"]);
        }
        return msg;
    }
    template <>
    ApolloplanningObjectMotionType from_json<ApolloplanningObjectMotionType>(nlohmann::json obj){
        return from_json_ApolloplanningObjectMotionType(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectMotionType &dt)
    {
        dt=from_json_ApolloplanningObjectMotionType(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectMotionType & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectMotionType & dt)
    {
        os << to_json(dt);
        return os;
    }
}
