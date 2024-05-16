#include "adapter/serialization/apollo_msgs/apollocanbus_pc_bcs202.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcBcs202 &msg) {
        nlohmann::json obj;
        obj["pcbrkpedreq"] = (msg.pcbrkpedreq);
        obj["pcbrkpedenable"] = (msg.pcbrkpedenable);
        return obj;
    }
    ApollocanbusPcBcs202 from_json_ApollocanbusPcBcs202 (nlohmann::json obj) {
        ApollocanbusPcBcs202 msg;
        if(obj.contains("pcbrkpedreq"))
        {
            msg.pcbrkpedreq = (obj["pcbrkpedreq"].is_string()?atof(obj["pcbrkpedreq"].get<std::string>().c_str()):obj["pcbrkpedreq"].get<double>());
        }
        if(obj.contains("pcbrkpedenable"))
        {
            msg.pcbrkpedenable = (obj["pcbrkpedenable"].is_string()?atoi(obj["pcbrkpedenable"].get<std::string>().c_str()):obj["pcbrkpedenable"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusPcBcs202 from_json<ApollocanbusPcBcs202>(nlohmann::json obj){
        return from_json_ApollocanbusPcBcs202(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcBcs202 &dt)
    {
        dt=from_json_ApollocanbusPcBcs202(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcBcs202 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcBcs202 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
