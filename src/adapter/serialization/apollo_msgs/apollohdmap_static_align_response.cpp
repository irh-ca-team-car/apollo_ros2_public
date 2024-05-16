#include "adapter/serialization/apollo_msgs/apollohdmap_static_align_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapStaticAlignResponse &msg) {
        nlohmann::json obj;
        obj["code"] = (msg.code);
        obj["progress"] = (msg.progress);
        return obj;
    }
    ApollohdmapStaticAlignResponse from_json_ApollohdmapStaticAlignResponse (nlohmann::json obj) {
        ApollohdmapStaticAlignResponse msg;
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
    ApollohdmapStaticAlignResponse from_json<ApollohdmapStaticAlignResponse>(nlohmann::json obj){
        return from_json_ApollohdmapStaticAlignResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapStaticAlignResponse &dt)
    {
        dt=from_json_ApollohdmapStaticAlignResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapStaticAlignResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapStaticAlignResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
