#include "adapter/serialization/apollo_msgs/apollobridge_udp_bridge_receiver_remote_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollobridgeUDPBridgeReceiverRemoteInfo &msg) {
        nlohmann::json obj;
        obj["topicname"] = (msg.topicname);
        obj["bindport"] = (msg.bindport);
        obj["protoname"] = (msg.protoname);
        obj["enabletimeout"] = (msg.enabletimeout);
        return obj;
    }
    ApollobridgeUDPBridgeReceiverRemoteInfo from_json_ApollobridgeUDPBridgeReceiverRemoteInfo (nlohmann::json obj) {
        ApollobridgeUDPBridgeReceiverRemoteInfo msg;
        if(obj.contains("topicname"))
        {
            msg.topicname = (obj["topicname"].is_string()?(obj["topicname"].get<std::string>().c_str()):obj["topicname"].get<std::string>());
        }
        if(obj.contains("bindport"))
        {
            msg.bindport = (obj["bindport"].is_string()?atoi(obj["bindport"].get<std::string>().c_str()):obj["bindport"].get<int>());
        }
        if(obj.contains("protoname"))
        {
            msg.protoname = (obj["protoname"].is_string()?(obj["protoname"].get<std::string>().c_str()):obj["protoname"].get<std::string>());
        }
        if(obj.contains("enabletimeout"))
        {
            msg.enabletimeout = (obj["enabletimeout"].is_string()?(bool)atoi(obj["enabletimeout"].get<std::string>().c_str()):obj["enabletimeout"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollobridgeUDPBridgeReceiverRemoteInfo from_json<ApollobridgeUDPBridgeReceiverRemoteInfo>(nlohmann::json obj){
        return from_json_ApollobridgeUDPBridgeReceiverRemoteInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollobridgeUDPBridgeReceiverRemoteInfo &dt)
    {
        dt=from_json_ApollobridgeUDPBridgeReceiverRemoteInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollobridgeUDPBridgeReceiverRemoteInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollobridgeUDPBridgeReceiverRemoteInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
