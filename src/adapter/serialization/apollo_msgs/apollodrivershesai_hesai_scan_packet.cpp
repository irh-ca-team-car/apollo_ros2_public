#include "adapter/serialization/apollo_msgs/apollodrivershesai_hesai_scan_packet.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodrivershesaiHesaiScanPacket &msg) {
        nlohmann::json obj;
        obj["stamp"] = (msg.stamp);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodrivershesaiHesaiScanPacket from_json_ApollodrivershesaiHesaiScanPacket (nlohmann::json obj) {
        ApollodrivershesaiHesaiScanPacket msg;
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
    ApollodrivershesaiHesaiScanPacket from_json<ApollodrivershesaiHesaiScanPacket>(nlohmann::json obj){
        return from_json_ApollodrivershesaiHesaiScanPacket(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodrivershesaiHesaiScanPacket &dt)
    {
        dt=from_json_ApollodrivershesaiHesaiScanPacket(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodrivershesaiHesaiScanPacket & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodrivershesaiHesaiScanPacket & dt)
    {
        os << to_json(dt);
        return os;
    }
}
