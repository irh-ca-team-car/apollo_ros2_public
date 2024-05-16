#include "adapter/serialization/apollo_msgs/apollocommonadapter_adapter_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonadapterAdapterConfig &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["mode"] = (msg.mode);
        obj["messagehistorylimit"] = (msg.messagehistorylimit);
        obj["latch"] = (msg.latch);
        obj["topic"] = (msg.topic);
        return obj;
    }
    ApollocommonadapterAdapterConfig from_json_ApollocommonadapterAdapterConfig (nlohmann::json obj) {
        ApollocommonadapterAdapterConfig msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("mode"))
        {
            msg.mode = (obj["mode"].is_string()?atoi(obj["mode"].get<std::string>().c_str()):obj["mode"].get<int>());
        }
        if(obj.contains("messagehistorylimit"))
        {
            msg.messagehistorylimit = (obj["messagehistorylimit"].is_string()?atoi(obj["messagehistorylimit"].get<std::string>().c_str()):obj["messagehistorylimit"].get<int>());
        }
        if(obj.contains("latch"))
        {
            msg.latch = (obj["latch"].is_string()?(bool)atoi(obj["latch"].get<std::string>().c_str()):obj["latch"].get<bool>());
        }
        if(obj.contains("topic"))
        {
            msg.topic = (obj["topic"].is_string()?(obj["topic"].get<std::string>().c_str()):obj["topic"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocommonadapterAdapterConfig from_json<ApollocommonadapterAdapterConfig>(nlohmann::json obj){
        return from_json_ApollocommonadapterAdapterConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonadapterAdapterConfig &dt)
    {
        dt=from_json_ApollocommonadapterAdapterConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonadapterAdapterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonadapterAdapterConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
