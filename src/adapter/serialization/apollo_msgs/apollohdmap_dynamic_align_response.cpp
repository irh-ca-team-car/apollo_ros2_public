#include "adapter/serialization/apollo_msgs/apollohdmap_dynamic_align_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapDynamicAlignResponse &msg) {
        nlohmann::json obj;
        obj["code"] = (msg.code);
        obj["progress"] = (msg.progress);
        return obj;
    }
    ApollohdmapDynamicAlignResponse from_json_ApollohdmapDynamicAlignResponse (nlohmann::json obj) {
        ApollohdmapDynamicAlignResponse msg;
        if(obj.contains("code"))
        {
            msg.code = (obj["code"].is_string()?atoi(obj["code"].get<std::string>().c_str()):obj["code"].get<int>());
        }
        if(obj.contains("progress"))
        {
            msg.progress = (obj["progress"].is_string()?atof(obj["progress"].get<std::string>().c_str()):obj["progress"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapDynamicAlignResponse from_json<ApollohdmapDynamicAlignResponse>(nlohmann::json obj){
        return from_json_ApollohdmapDynamicAlignResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapDynamicAlignResponse &dt)
    {
        dt=from_json_ApollohdmapDynamicAlignResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapDynamicAlignResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapDynamicAlignResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
