#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonHeader &msg) {
        nlohmann::json obj;
        obj["timestampsec"] = (msg.timestampsec);
        obj["modulename"] = (msg.modulename);
        obj["sequencenum"] = (msg.sequencenum);
        obj["lidartimestamp"] = (msg.lidartimestamp);
        obj["cameratimestamp"] = (msg.cameratimestamp);
        obj["radartimestamp"] = (msg.radartimestamp);
        obj["version"] = (msg.version);
        obj["status"] = to_json(msg.status);
        obj["frameid"] = (msg.frameid);
        return obj;
    }
    ApollocommonHeader from_json_ApollocommonHeader (nlohmann::json obj) {
        ApollocommonHeader msg;
        if(obj.contains("timestampsec"))
        {
            msg.timestampsec = (obj["timestampsec"].is_string()?atof(obj["timestampsec"].get<std::string>().c_str()):obj["timestampsec"].get<double>());
        }
        if(obj.contains("modulename"))
        {
            msg.modulename = (obj["modulename"].is_string()?(obj["modulename"].get<std::string>().c_str()):obj["modulename"].get<std::string>());
        }
        if(obj.contains("sequencenum"))
        {
            msg.sequencenum = (obj["sequencenum"].is_string()?atoi(obj["sequencenum"].get<std::string>().c_str()):obj["sequencenum"].get<uint32_t>());
        }
        if(obj.contains("lidartimestamp"))
        {
            msg.lidartimestamp = (obj["lidartimestamp"].is_string()?atol(obj["lidartimestamp"].get<std::string>().c_str()):obj["lidartimestamp"].get<uint64_t>());
        }
        if(obj.contains("cameratimestamp"))
        {
            msg.cameratimestamp = (obj["cameratimestamp"].is_string()?atol(obj["cameratimestamp"].get<std::string>().c_str()):obj["cameratimestamp"].get<uint64_t>());
        }
        if(obj.contains("radartimestamp"))
        {
            msg.radartimestamp = (obj["radartimestamp"].is_string()?atol(obj["radartimestamp"].get<std::string>().c_str()):obj["radartimestamp"].get<uint64_t>());
        }
        if(obj.contains("version"))
        {
            msg.version = (obj["version"].is_string()?atoi(obj["version"].get<std::string>().c_str()):obj["version"].get<uint32_t>());
        }
        if(obj.contains("status"))
        {
            msg.status = from_json_ApollocommonStatusPb(obj["status"]);
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocommonHeader from_json<ApollocommonHeader>(nlohmann::json obj){
        return from_json_ApollocommonHeader(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonHeader &dt)
    {
        dt=from_json_ApollocommonHeader(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonHeader & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonHeader & dt)
    {
        os << to_json(dt);
        return os;
    }
}
