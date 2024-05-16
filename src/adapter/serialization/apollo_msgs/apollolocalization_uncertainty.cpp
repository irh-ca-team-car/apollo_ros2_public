#include "adapter/serialization/apollo_msgs/apollolocalization_uncertainty.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationUncertainty &msg) {
        nlohmann::json obj;
        obj["positionstddev"] = to_json(msg.positionstddev);
        obj["orientationstddev"] = to_json(msg.orientationstddev);
        obj["linearvelocitystddev"] = to_json(msg.linearvelocitystddev);
        obj["linearaccelerationstddev"] = to_json(msg.linearaccelerationstddev);
        obj["angularvelocitystddev"] = to_json(msg.angularvelocitystddev);
        return obj;
    }
    ApollolocalizationUncertainty from_json_ApollolocalizationUncertainty (nlohmann::json obj) {
        ApollolocalizationUncertainty msg;
        if(obj.contains("positionstddev"))
        {
            msg.positionstddev = from_json_ApollocommonPoint3D(obj["positionstddev"]);
        }
        if(obj.contains("orientationstddev"))
        {
            msg.orientationstddev = from_json_ApollocommonPoint3D(obj["orientationstddev"]);
        }
        if(obj.contains("linearvelocitystddev"))
        {
            msg.linearvelocitystddev = from_json_ApollocommonPoint3D(obj["linearvelocitystddev"]);
        }
        if(obj.contains("linearaccelerationstddev"))
        {
            msg.linearaccelerationstddev = from_json_ApollocommonPoint3D(obj["linearaccelerationstddev"]);
        }
        if(obj.contains("angularvelocitystddev"))
        {
            msg.angularvelocitystddev = from_json_ApollocommonPoint3D(obj["angularvelocitystddev"]);
        }
        return msg;
    }
    template <>
    ApollolocalizationUncertainty from_json<ApollolocalizationUncertainty>(nlohmann::json obj){
        return from_json_ApollolocalizationUncertainty(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationUncertainty &dt)
    {
        dt=from_json_ApollolocalizationUncertainty(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationUncertainty & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationUncertainty & dt)
    {
        os << to_json(dt);
        return os;
    }
}
