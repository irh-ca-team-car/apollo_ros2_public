#include "adapter/serialization/apollo_msgs/apollolocalization_corrected_imu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationCorrectedImu &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["imu"] = to_json(msg.imu);
        return obj;
    }
    ApollolocalizationCorrectedImu from_json_ApollolocalizationCorrectedImu (nlohmann::json obj) {
        ApollolocalizationCorrectedImu msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("imu"))
        {
            msg.imu = from_json_ApollolocalizationPose(obj["imu"]);
        }
        return msg;
    }
    template <>
    ApollolocalizationCorrectedImu from_json<ApollolocalizationCorrectedImu>(nlohmann::json obj){
        return from_json_ApollolocalizationCorrectedImu(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationCorrectedImu &dt)
    {
        dt=from_json_ApollolocalizationCorrectedImu(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationCorrectedImu & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationCorrectedImu & dt)
    {
        os << to_json(dt);
        return os;
    }
}
