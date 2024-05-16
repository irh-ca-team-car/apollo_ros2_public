#include "adapter/serialization/apollo_msgs/apollodrivers_acm_inst_req7e0.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversAcmInstReq7e0 &msg) {
        nlohmann::json obj;
        obj["commandctr"] = (msg.commandctr);
        obj["commandcode"] = (msg.commandcode);
        obj["ccword2"] = (msg.ccword2);
        obj["ccword1"] = (msg.ccword1);
        obj["ccbyte2"] = (msg.ccbyte2);
        obj["ccbyte1"] = (msg.ccbyte1);
        return obj;
    }
    ApollodriversAcmInstReq7e0 from_json_ApollodriversAcmInstReq7e0 (nlohmann::json obj) {
        ApollodriversAcmInstReq7e0 msg;
        if(obj.contains("commandctr"))
        {
            msg.commandctr = (obj["commandctr"].is_string()?atoi(obj["commandctr"].get<std::string>().c_str()):obj["commandctr"].get<int>());
        }
        if(obj.contains("commandcode"))
        {
            msg.commandcode = (obj["commandcode"].is_string()?atoi(obj["commandcode"].get<std::string>().c_str()):obj["commandcode"].get<int>());
        }
        if(obj.contains("ccword2"))
        {
            msg.ccword2 = (obj["ccword2"].is_string()?atoi(obj["ccword2"].get<std::string>().c_str()):obj["ccword2"].get<int>());
        }
        if(obj.contains("ccword1"))
        {
            msg.ccword1 = (obj["ccword1"].is_string()?atoi(obj["ccword1"].get<std::string>().c_str()):obj["ccword1"].get<int>());
        }
        if(obj.contains("ccbyte2"))
        {
            msg.ccbyte2 = (obj["ccbyte2"].is_string()?atoi(obj["ccbyte2"].get<std::string>().c_str()):obj["ccbyte2"].get<int>());
        }
        if(obj.contains("ccbyte1"))
        {
            msg.ccbyte1 = (obj["ccbyte1"].is_string()?atoi(obj["ccbyte1"].get<std::string>().c_str()):obj["ccbyte1"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversAcmInstReq7e0 from_json<ApollodriversAcmInstReq7e0>(nlohmann::json obj){
        return from_json_ApollodriversAcmInstReq7e0(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversAcmInstReq7e0 &dt)
    {
        dt=from_json_ApollodriversAcmInstReq7e0(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversAcmInstReq7e0 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversAcmInstReq7e0 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
