#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_data_packs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwDataPacks &msg) {
        nlohmann::json obj;
        obj["roadway"] = to_json(msg.roadway);
        obj["softstatus"] = (msg.softstatus);
        obj["steerstatus"] = (msg.steerstatus);
        obj["lens"] = to_json(msg.lens);
        return obj;
    }
    ApollodriversLdwDataPacks from_json_ApollodriversLdwDataPacks (nlohmann::json obj) {
        ApollodriversLdwDataPacks msg;
        if(obj.contains("roadway"))
        {
            msg.roadway = from_json_ApollodriversLdwRoadway(obj["roadway"]);
        }
        if(obj.contains("softstatus"))
        {
            msg.softstatus = (obj["softstatus"].is_string()?atoi(obj["softstatus"].get<std::string>().c_str()):obj["softstatus"].get<int>());
        }
        if(obj.contains("steerstatus"))
        {
            msg.steerstatus = (obj["steerstatus"].is_string()?atoi(obj["steerstatus"].get<std::string>().c_str()):obj["steerstatus"].get<int>());
        }
        if(obj.contains("lens"))
        {
            msg.lens = from_json_ApollodriversLdwLensInfo(obj["lens"]);
        }
        return msg;
    }
    template <>
    ApollodriversLdwDataPacks from_json<ApollodriversLdwDataPacks>(nlohmann::json obj){
        return from_json_ApollodriversLdwDataPacks(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwDataPacks &dt)
    {
        dt=from_json_ApollodriversLdwDataPacks(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwDataPacks & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwDataPacks & dt)
    {
        os << to_json(dt);
        return os;
    }
}
