#include "adapter/serialization/apollo_msgs/apolloplanning_object_side_pass.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectSidePass &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        return obj;
    }
    ApolloplanningObjectSidePass from_json_ApolloplanningObjectSidePass (nlohmann::json obj) {
        ApolloplanningObjectSidePass msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningObjectSidePass from_json<ApolloplanningObjectSidePass>(nlohmann::json obj){
        return from_json_ApolloplanningObjectSidePass(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectSidePass &dt)
    {
        dt=from_json_ApolloplanningObjectSidePass(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectSidePass & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectSidePass & dt)
    {
        os << to_json(dt);
        return os;
    }
}
