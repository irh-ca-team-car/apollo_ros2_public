#include "adapter/serialization/apollo_msgs/apolloplanning_object_follow.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectFollow &msg) {
        nlohmann::json obj;
        obj["distances"] = (msg.distances);
        obj["fencepoint"] = to_json(msg.fencepoint);
        obj["fenceheading"] = (msg.fenceheading);
        return obj;
    }
    ApolloplanningObjectFollow from_json_ApolloplanningObjectFollow (nlohmann::json obj) {
        ApolloplanningObjectFollow msg;
        if(obj.contains("distances"))
        {
            msg.distances = (obj["distances"].is_string()?atof(obj["distances"].get<std::string>().c_str()):obj["distances"].get<double>());
        }
        if(obj.contains("fencepoint"))
        {
            msg.fencepoint = from_json_ApollocommonPointENU(obj["fencepoint"]);
        }
        if(obj.contains("fenceheading"))
        {
            msg.fenceheading = (obj["fenceheading"].is_string()?atof(obj["fenceheading"].get<std::string>().c_str()):obj["fenceheading"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningObjectFollow from_json<ApolloplanningObjectFollow>(nlohmann::json obj){
        return from_json_ApolloplanningObjectFollow(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectFollow &dt)
    {
        dt=from_json_ApolloplanningObjectFollow(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectFollow & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectFollow & dt)
    {
        os << to_json(dt);
        return os;
    }
}
