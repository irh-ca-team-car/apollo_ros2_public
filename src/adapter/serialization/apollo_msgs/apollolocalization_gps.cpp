#include "adapter/serialization/apollo_msgs/apollolocalization_gps.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationGps &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["localization"] = to_json(msg.localization);
        return obj;
    }
    ApollolocalizationGps from_json_ApollolocalizationGps (nlohmann::json obj) {
        ApollolocalizationGps msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("localization"))
        {
            msg.localization = from_json_ApollolocalizationPose(obj["localization"]);
        }
        return msg;
    }
    template <>
    ApollolocalizationGps from_json<ApollolocalizationGps>(nlohmann::json obj){
        return from_json_ApollolocalizationGps(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationGps &dt)
    {
        dt=from_json_ApollolocalizationGps(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationGps & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationGps & dt)
    {
        os << to_json(dt);
        return os;
    }
}
