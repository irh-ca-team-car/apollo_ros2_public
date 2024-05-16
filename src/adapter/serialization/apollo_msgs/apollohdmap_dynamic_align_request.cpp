#include "adapter/serialization/apollo_msgs/apollohdmap_dynamic_align_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapDynamicAlignRequest &msg) {
        nlohmann::json obj;
        obj["cmd"] = (msg.cmd);
        return obj;
    }
    ApollohdmapDynamicAlignRequest from_json_ApollohdmapDynamicAlignRequest (nlohmann::json obj) {
        ApollohdmapDynamicAlignRequest msg;
        if(obj.contains("cmd"))
        {
            msg.cmd = (obj["cmd"].is_string()?atoi(obj["cmd"].get<std::string>().c_str()):obj["cmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapDynamicAlignRequest from_json<ApollohdmapDynamicAlignRequest>(nlohmann::json obj){
        return from_json_ApollohdmapDynamicAlignRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapDynamicAlignRequest &dt)
    {
        dt=from_json_ApollohdmapDynamicAlignRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapDynamicAlignRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapDynamicAlignRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
