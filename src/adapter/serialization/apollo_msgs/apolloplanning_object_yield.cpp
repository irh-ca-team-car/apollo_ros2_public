#include "adapter/serialization/apollo_msgs/apolloplanning_object_yield.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectYield &msg) {
        nlohmann::json obj;
        obj["distances"] = (msg.distances);
        obj["fencepoint"] = to_json(msg.fencepoint);
        obj["fenceheading"] = (msg.fenceheading);
        obj["timebuffer"] = (msg.timebuffer);
        return obj;
    }
    ApolloplanningObjectYield from_json_ApolloplanningObjectYield (nlohmann::json obj) {
        ApolloplanningObjectYield msg;
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
        if(obj.contains("timebuffer"))
        {
            msg.timebuffer = (obj["timebuffer"].is_string()?atof(obj["timebuffer"].get<std::string>().c_str()):obj["timebuffer"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningObjectYield from_json<ApolloplanningObjectYield>(nlohmann::json obj){
        return from_json_ApolloplanningObjectYield(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectYield &dt)
    {
        dt=from_json_ApolloplanningObjectYield(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectYield & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectYield & dt)
    {
        os << to_json(dt);
        return os;
    }
}
