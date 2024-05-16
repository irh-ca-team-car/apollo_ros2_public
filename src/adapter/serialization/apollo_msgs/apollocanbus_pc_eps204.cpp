#include "adapter/serialization/apollo_msgs/apollocanbus_pc_eps204.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcEps204 &msg) {
        nlohmann::json obj;
        obj["pcsteerspdreq"] = (msg.pcsteerspdreq);
        obj["pcsteerenable"] = (msg.pcsteerenable);
        obj["pcsteerangreq"] = (msg.pcsteerangreq);
        return obj;
    }
    ApollocanbusPcEps204 from_json_ApollocanbusPcEps204 (nlohmann::json obj) {
        ApollocanbusPcEps204 msg;
        if(obj.contains("pcsteerspdreq"))
        {
            msg.pcsteerspdreq = (obj["pcsteerspdreq"].is_string()?atoi(obj["pcsteerspdreq"].get<std::string>().c_str()):obj["pcsteerspdreq"].get<int>());
        }
        if(obj.contains("pcsteerenable"))
        {
            msg.pcsteerenable = (obj["pcsteerenable"].is_string()?atoi(obj["pcsteerenable"].get<std::string>().c_str()):obj["pcsteerenable"].get<int>());
        }
        if(obj.contains("pcsteerangreq"))
        {
            msg.pcsteerangreq = (obj["pcsteerangreq"].is_string()?atof(obj["pcsteerangreq"].get<std::string>().c_str()):obj["pcsteerangreq"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusPcEps204 from_json<ApollocanbusPcEps204>(nlohmann::json obj){
        return from_json_ApollocanbusPcEps204(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcEps204 &dt)
    {
        dt=from_json_ApollocanbusPcEps204(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcEps204 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcEps204 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
