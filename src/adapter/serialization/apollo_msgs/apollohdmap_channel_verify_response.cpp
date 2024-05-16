#include "adapter/serialization/apollo_msgs/apollohdmap_channel_verify_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapChannelVerifyResponse &msg) {
        nlohmann::json obj;
        obj["code"] = (msg.code);
        obj["result"] = to_json(msg.result);
        return obj;
    }
    ApollohdmapChannelVerifyResponse from_json_ApollohdmapChannelVerifyResponse (nlohmann::json obj) {
        ApollohdmapChannelVerifyResponse msg;
        if(obj.contains("code"))
        {
            msg.code = (obj["code"].is_string()?atoi(obj["code"].get<std::string>().c_str()):obj["code"].get<int>());
        }
        if(obj.contains("result"))
        {
            msg.result = from_json_ApollohdmapVerifyResult(obj["result"]);
        }
        return msg;
    }
    template <>
    ApollohdmapChannelVerifyResponse from_json<ApollohdmapChannelVerifyResponse>(nlohmann::json obj){
        return from_json_ApollohdmapChannelVerifyResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapChannelVerifyResponse &dt)
    {
        dt=from_json_ApollohdmapChannelVerifyResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapChannelVerifyResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapChannelVerifyResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
