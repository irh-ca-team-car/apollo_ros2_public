#include "adapter/serialization/apollo_msgs/apollocanbus_scu_epb310.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuEpb310 &msg) {
        nlohmann::json obj;
        obj["epbintidx"] = (msg.epbintidx);
        obj["epbdrvmode"] = (msg.epbdrvmode);
        obj["epbsysst"] = (msg.epbsysst);
        obj["epbfaultst"] = (msg.epbfaultst);
        return obj;
    }
    ApollocanbusScuEpb310 from_json_ApollocanbusScuEpb310 (nlohmann::json obj) {
        ApollocanbusScuEpb310 msg;
        if(obj.contains("epbintidx"))
        {
            msg.epbintidx = (obj["epbintidx"].is_string()?atoi(obj["epbintidx"].get<std::string>().c_str()):obj["epbintidx"].get<int>());
        }
        if(obj.contains("epbdrvmode"))
        {
            msg.epbdrvmode = (obj["epbdrvmode"].is_string()?atoi(obj["epbdrvmode"].get<std::string>().c_str()):obj["epbdrvmode"].get<int>());
        }
        if(obj.contains("epbsysst"))
        {
            msg.epbsysst = (obj["epbsysst"].is_string()?atoi(obj["epbsysst"].get<std::string>().c_str()):obj["epbsysst"].get<int>());
        }
        if(obj.contains("epbfaultst"))
        {
            msg.epbfaultst = (obj["epbfaultst"].is_string()?atoi(obj["epbfaultst"].get<std::string>().c_str()):obj["epbfaultst"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuEpb310 from_json<ApollocanbusScuEpb310>(nlohmann::json obj){
        return from_json_ApollocanbusScuEpb310(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuEpb310 &dt)
    {
        dt=from_json_ApollocanbusScuEpb310(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuEpb310 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuEpb310 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
