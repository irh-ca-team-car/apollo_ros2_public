#include "adapter/serialization/apollo_msgs/apollocanbus_park_command104.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkCommand104 &msg) {
        nlohmann::json obj;
        obj["checksum104"] = (msg.checksum104);
        obj["parktarget"] = (msg.parktarget);
        obj["parkenctrl"] = (msg.parkenctrl);
        return obj;
    }
    ApollocanbusParkCommand104 from_json_ApollocanbusParkCommand104 (nlohmann::json obj) {
        ApollocanbusParkCommand104 msg;
        if(obj.contains("checksum104"))
        {
            msg.checksum104 = (obj["checksum104"].is_string()?atoi(obj["checksum104"].get<std::string>().c_str()):obj["checksum104"].get<int>());
        }
        if(obj.contains("parktarget"))
        {
            msg.parktarget = (obj["parktarget"].is_string()?atoi(obj["parktarget"].get<std::string>().c_str()):obj["parktarget"].get<int>());
        }
        if(obj.contains("parkenctrl"))
        {
            msg.parkenctrl = (obj["parkenctrl"].is_string()?atoi(obj["parkenctrl"].get<std::string>().c_str()):obj["parkenctrl"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusParkCommand104 from_json<ApollocanbusParkCommand104>(nlohmann::json obj){
        return from_json_ApollocanbusParkCommand104(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkCommand104 &dt)
    {
        dt=from_json_ApollocanbusParkCommand104(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkCommand104 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkCommand104 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
