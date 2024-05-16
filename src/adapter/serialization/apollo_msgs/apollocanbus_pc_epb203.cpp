#include "adapter/serialization/apollo_msgs/apollocanbus_pc_epb203.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcEpb203 &msg) {
        nlohmann::json obj;
        obj["pcepbreq"] = (msg.pcepbreq);
        obj["pcepbenable"] = (msg.pcepbenable);
        return obj;
    }
    ApollocanbusPcEpb203 from_json_ApollocanbusPcEpb203 (nlohmann::json obj) {
        ApollocanbusPcEpb203 msg;
        if(obj.contains("pcepbreq"))
        {
            msg.pcepbreq = (obj["pcepbreq"].is_string()?atoi(obj["pcepbreq"].get<std::string>().c_str()):obj["pcepbreq"].get<int>());
        }
        if(obj.contains("pcepbenable"))
        {
            msg.pcepbenable = (obj["pcepbenable"].is_string()?atoi(obj["pcepbenable"].get<std::string>().c_str()):obj["pcepbenable"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusPcEpb203 from_json<ApollocanbusPcEpb203>(nlohmann::json obj){
        return from_json_ApollocanbusPcEpb203(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcEpb203 &dt)
    {
        dt=from_json_ApollocanbusPcEpb203(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcEpb203 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcEpb203 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
