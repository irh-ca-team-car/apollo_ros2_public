#include "adapter/serialization/apollo_msgs/apolloplanning_path_reference_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathReferenceDeciderConfig &msg) {
        nlohmann::json obj;
        obj["minpathreferencelength"] = (msg.minpathreferencelength);
        obj["weightxrefpathreference"] = (msg.weightxrefpathreference);
        return obj;
    }
    ApolloplanningPathReferenceDeciderConfig from_json_ApolloplanningPathReferenceDeciderConfig (nlohmann::json obj) {
        ApolloplanningPathReferenceDeciderConfig msg;
        if(obj.contains("minpathreferencelength"))
        {
            msg.minpathreferencelength = (obj["minpathreferencelength"].is_string()?atoi(obj["minpathreferencelength"].get<std::string>().c_str()):obj["minpathreferencelength"].get<uint32_t>());
        }
        if(obj.contains("weightxrefpathreference"))
        {
            msg.weightxrefpathreference = (obj["weightxrefpathreference"].is_string()?atof(obj["weightxrefpathreference"].get<std::string>().c_str()):obj["weightxrefpathreference"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPathReferenceDeciderConfig from_json<ApolloplanningPathReferenceDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPathReferenceDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathReferenceDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningPathReferenceDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathReferenceDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathReferenceDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
