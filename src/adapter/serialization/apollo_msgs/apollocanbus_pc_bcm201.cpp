#include "adapter/serialization/apollo_msgs/apollocanbus_pc_bcm201.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcBcm201 &msg) {
        nlohmann::json obj;
        obj["pcreverselampreq"] = (msg.pcreverselampreq);
        obj["pclowbeamreq"] = (msg.pclowbeamreq);
        obj["pchighbeamreq"] = (msg.pchighbeamreq);
        obj["pcrightturnlampreq"] = (msg.pcrightturnlampreq);
        obj["pcleftturnlampreq"] = (msg.pcleftturnlampreq);
        obj["pchornreq"] = (msg.pchornreq);
        obj["pchazardlampreq"] = (msg.pchazardlampreq);
        return obj;
    }
    ApollocanbusPcBcm201 from_json_ApollocanbusPcBcm201 (nlohmann::json obj) {
        ApollocanbusPcBcm201 msg;
        if(obj.contains("pcreverselampreq"))
        {
            msg.pcreverselampreq = (obj["pcreverselampreq"].is_string()?atoi(obj["pcreverselampreq"].get<std::string>().c_str()):obj["pcreverselampreq"].get<int>());
        }
        if(obj.contains("pclowbeamreq"))
        {
            msg.pclowbeamreq = (obj["pclowbeamreq"].is_string()?atoi(obj["pclowbeamreq"].get<std::string>().c_str()):obj["pclowbeamreq"].get<int>());
        }
        if(obj.contains("pchighbeamreq"))
        {
            msg.pchighbeamreq = (obj["pchighbeamreq"].is_string()?atoi(obj["pchighbeamreq"].get<std::string>().c_str()):obj["pchighbeamreq"].get<int>());
        }
        if(obj.contains("pcrightturnlampreq"))
        {
            msg.pcrightturnlampreq = (obj["pcrightturnlampreq"].is_string()?atoi(obj["pcrightturnlampreq"].get<std::string>().c_str()):obj["pcrightturnlampreq"].get<int>());
        }
        if(obj.contains("pcleftturnlampreq"))
        {
            msg.pcleftturnlampreq = (obj["pcleftturnlampreq"].is_string()?atoi(obj["pcleftturnlampreq"].get<std::string>().c_str()):obj["pcleftturnlampreq"].get<int>());
        }
        if(obj.contains("pchornreq"))
        {
            msg.pchornreq = (obj["pchornreq"].is_string()?atoi(obj["pchornreq"].get<std::string>().c_str()):obj["pchornreq"].get<int>());
        }
        if(obj.contains("pchazardlampreq"))
        {
            msg.pchazardlampreq = (obj["pchazardlampreq"].is_string()?atoi(obj["pchazardlampreq"].get<std::string>().c_str()):obj["pchazardlampreq"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusPcBcm201 from_json<ApollocanbusPcBcm201>(nlohmann::json obj){
        return from_json_ApollocanbusPcBcm201(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcBcm201 &dt)
    {
        dt=from_json_ApollocanbusPcBcm201(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcBcm201 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcBcm201 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
