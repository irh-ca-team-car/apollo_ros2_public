#include "adapter/serialization/apollo_msgs/apollocommon_status_pb.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonStatusPb &msg) {
        nlohmann::json obj;
        obj["errorcode"] = (msg.errorcode);
        obj["msg"] = (msg.msg);
        return obj;
    }
    ApollocommonStatusPb from_json_ApollocommonStatusPb (nlohmann::json obj) {
        ApollocommonStatusPb msg;
        if(obj.contains("errorcode"))
        {
            msg.errorcode = (obj["errorcode"].is_string()?atoi(obj["errorcode"].get<std::string>().c_str()):obj["errorcode"].get<int>());
        }
        if(obj.contains("msg"))
        {
            msg.msg = (obj["msg"].is_string()?(obj["msg"].get<std::string>().c_str()):obj["msg"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocommonStatusPb from_json<ApollocommonStatusPb>(nlohmann::json obj){
        return from_json_ApollocommonStatusPb(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonStatusPb &dt)
    {
        dt=from_json_ApollocommonStatusPb(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonStatusPb & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonStatusPb & dt)
    {
        os << to_json(dt);
        return os;
    }
}
