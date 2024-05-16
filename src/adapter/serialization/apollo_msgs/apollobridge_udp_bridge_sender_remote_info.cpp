#include "adapter/serialization/apollo_msgs/apollobridge_udp_bridge_sender_remote_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollobridgeUDPBridgeSenderRemoteInfo &msg) {
        nlohmann::json obj;
        obj["remoteip"] = (msg.remoteip);
        obj["remoteport"] = (msg.remoteport);
        obj["protoname"] = (msg.protoname);
        return obj;
    }
    ApollobridgeUDPBridgeSenderRemoteInfo from_json_ApollobridgeUDPBridgeSenderRemoteInfo (nlohmann::json obj) {
        ApollobridgeUDPBridgeSenderRemoteInfo msg;
        if(obj.contains("remoteip"))
        {
            msg.remoteip = (obj["remoteip"].is_string()?(obj["remoteip"].get<std::string>().c_str()):obj["remoteip"].get<std::string>());
        }
        if(obj.contains("remoteport"))
        {
            msg.remoteport = (obj["remoteport"].is_string()?atoi(obj["remoteport"].get<std::string>().c_str()):obj["remoteport"].get<int>());
        }
        if(obj.contains("protoname"))
        {
            msg.protoname = (obj["protoname"].is_string()?(obj["protoname"].get<std::string>().c_str()):obj["protoname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollobridgeUDPBridgeSenderRemoteInfo from_json<ApollobridgeUDPBridgeSenderRemoteInfo>(nlohmann::json obj){
        return from_json_ApollobridgeUDPBridgeSenderRemoteInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollobridgeUDPBridgeSenderRemoteInfo &dt)
    {
        dt=from_json_ApollobridgeUDPBridgeSenderRemoteInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollobridgeUDPBridgeSenderRemoteInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollobridgeUDPBridgeSenderRemoteInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
