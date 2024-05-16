#include "adapter/serialization/apollo_msgs/apollodriversrobosense_robosense_scan_packet.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversrobosenseRobosenseScanPacket &msg) {
        nlohmann::json obj;
        obj["stamp"] = (msg.stamp);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversrobosenseRobosenseScanPacket from_json_ApollodriversrobosenseRobosenseScanPacket (nlohmann::json obj) {
        ApollodriversrobosenseRobosenseScanPacket msg;
        if(obj.contains("stamp"))
        {
            msg.stamp = (obj["stamp"].is_string()?atol(obj["stamp"].get<std::string>().c_str()):obj["stamp"].get<uint64_t>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_Bytes(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollodriversrobosenseRobosenseScanPacket from_json<ApollodriversrobosenseRobosenseScanPacket>(nlohmann::json obj){
        return from_json_ApollodriversrobosenseRobosenseScanPacket(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversrobosenseRobosenseScanPacket &dt)
    {
        dt=from_json_ApollodriversrobosenseRobosenseScanPacket(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversrobosenseRobosenseScanPacket & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversrobosenseRobosenseScanPacket & dt)
    {
        os << to_json(dt);
        return os;
    }
}
