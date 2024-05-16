#include "adapter/serialization/apollo_msgs/apollohdmap_channel_verify_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapChannelVerifyRequest &msg) {
        nlohmann::json obj;
        obj["cmd"] = (msg.cmd);
        obj["collectid"] = (msg.collectid);
        obj["path"] = (msg.path);
        return obj;
    }
    ApollohdmapChannelVerifyRequest from_json_ApollohdmapChannelVerifyRequest (nlohmann::json obj) {
        ApollohdmapChannelVerifyRequest msg;
        if(obj.contains("cmd"))
        {
            msg.cmd = (obj["cmd"].is_string()?atoi(obj["cmd"].get<std::string>().c_str()):obj["cmd"].get<int>());
        }
        if(obj.contains("collectid"))
        {
            msg.collectid = (obj["collectid"].is_string()?(obj["collectid"].get<std::string>().c_str()):obj["collectid"].get<std::string>());
        }
        if(obj.contains("path"))
        {
            msg.path = (obj["path"].is_string()?(obj["path"].get<std::string>().c_str()):obj["path"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollohdmapChannelVerifyRequest from_json<ApollohdmapChannelVerifyRequest>(nlohmann::json obj){
        return from_json_ApollohdmapChannelVerifyRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapChannelVerifyRequest &dt)
    {
        dt=from_json_ApollohdmapChannelVerifyRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapChannelVerifyRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapChannelVerifyRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
