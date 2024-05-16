#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_velodyne_packet.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneVelodynePacket &msg) {
        nlohmann::json obj;
        obj["stamp"] = (msg.stamp);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversvelodyneVelodynePacket from_json_ApollodriversvelodyneVelodynePacket (nlohmann::json obj) {
        ApollodriversvelodyneVelodynePacket msg;
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
    ApollodriversvelodyneVelodynePacket from_json<ApollodriversvelodyneVelodynePacket>(nlohmann::json obj){
        return from_json_ApollodriversvelodyneVelodynePacket(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneVelodynePacket &dt)
    {
        dt=from_json_ApollodriversvelodyneVelodynePacket(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneVelodynePacket & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneVelodynePacket & dt)
    {
        os << to_json(dt);
        return os;
    }
}
