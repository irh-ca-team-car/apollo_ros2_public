#include "adapter/serialization/apollo_msgs/apolloplanning_reference_line_end_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningReferenceLineEndConfig &msg) {
        nlohmann::json obj;
        obj["stopdistance"] = (msg.stopdistance);
        obj["minreferencelineremainlength"] = (msg.minreferencelineremainlength);
        return obj;
    }
    ApolloplanningReferenceLineEndConfig from_json_ApolloplanningReferenceLineEndConfig (nlohmann::json obj) {
        ApolloplanningReferenceLineEndConfig msg;
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        if(obj.contains("minreferencelineremainlength"))
        {
            msg.minreferencelineremainlength = (obj["minreferencelineremainlength"].is_string()?atof(obj["minreferencelineremainlength"].get<std::string>().c_str()):obj["minreferencelineremainlength"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningReferenceLineEndConfig from_json<ApolloplanningReferenceLineEndConfig>(nlohmann::json obj){
        return from_json_ApolloplanningReferenceLineEndConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningReferenceLineEndConfig &dt)
    {
        dt=from_json_ApolloplanningReferenceLineEndConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningReferenceLineEndConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningReferenceLineEndConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
