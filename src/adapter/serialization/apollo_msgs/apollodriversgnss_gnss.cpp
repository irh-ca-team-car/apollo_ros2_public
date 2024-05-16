#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnss &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["measurementtime"] = (msg.measurementtime);
        obj["velocitylatency"] = (msg.velocitylatency);
        obj["position"] = to_json(msg.position);
        obj["positionstddev"] = to_json(msg.positionstddev);
        obj["linearvelocity"] = to_json(msg.linearvelocity);
        obj["linearvelocitystddev"] = to_json(msg.linearvelocitystddev);
        obj["numsats"] = (msg.numsats);
        obj["type"] = (msg.type);
        obj["solutionstatus"] = (msg.solutionstatus);
        obj["positiontype"] = (msg.positiontype);
        return obj;
    }
    ApollodriversgnssGnss from_json_ApollodriversgnssGnss (nlohmann::json obj) {
        ApollodriversgnssGnss msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("velocitylatency"))
        {
            msg.velocitylatency = (obj["velocitylatency"].is_string()?(float)atof(obj["velocitylatency"].get<std::string>().c_str()):obj["velocitylatency"].get<float>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPointLLH(obj["position"]);
        }
        if(obj.contains("positionstddev"))
        {
            msg.positionstddev = from_json_ApollocommonPoint3D(obj["positionstddev"]);
        }
        if(obj.contains("linearvelocity"))
        {
            msg.linearvelocity = from_json_ApollocommonPoint3D(obj["linearvelocity"]);
        }
        if(obj.contains("linearvelocitystddev"))
        {
            msg.linearvelocitystddev = from_json_ApollocommonPoint3D(obj["linearvelocitystddev"]);
        }
        if(obj.contains("numsats"))
        {
            msg.numsats = (obj["numsats"].is_string()?atoi(obj["numsats"].get<std::string>().c_str()):obj["numsats"].get<int>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("solutionstatus"))
        {
            msg.solutionstatus = (obj["solutionstatus"].is_string()?atoi(obj["solutionstatus"].get<std::string>().c_str()):obj["solutionstatus"].get<uint32_t>());
        }
        if(obj.contains("positiontype"))
        {
            msg.positiontype = (obj["positiontype"].is_string()?atoi(obj["positiontype"].get<std::string>().c_str()):obj["positiontype"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssGnss from_json<ApollodriversgnssGnss>(nlohmann::json obj){
        return from_json_ApollodriversgnssGnss(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnss &dt)
    {
        dt=from_json_ApollodriversgnssGnss(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnss & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnss & dt)
    {
        os << to_json(dt);
        return os;
    }
}
