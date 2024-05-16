#include "adapter/serialization/apollo_msgs/apollolocalization_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationPose &msg) {
        nlohmann::json obj;
        obj["position"] = to_json(msg.position);
        obj["orientation"] = to_json(msg.orientation);
        obj["linearvelocity"] = to_json(msg.linearvelocity);
        obj["linearacceleration"] = to_json(msg.linearacceleration);
        obj["angularvelocity"] = to_json(msg.angularvelocity);
        obj["heading"] = (msg.heading);
        obj["linearaccelerationvrf"] = to_json(msg.linearaccelerationvrf);
        obj["angularvelocityvrf"] = to_json(msg.angularvelocityvrf);
        obj["eulerangles"] = to_json(msg.eulerangles);
        return obj;
    }
    ApollolocalizationPose from_json_ApollolocalizationPose (nlohmann::json obj) {
        ApollolocalizationPose msg;
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPointENU(obj["position"]);
        }
        if(obj.contains("orientation"))
        {
            msg.orientation = from_json_ApollocommonQuaternion(obj["orientation"]);
        }
        if(obj.contains("linearvelocity"))
        {
            msg.linearvelocity = from_json_ApollocommonPoint3D(obj["linearvelocity"]);
        }
        if(obj.contains("linearacceleration"))
        {
            msg.linearacceleration = from_json_ApollocommonPoint3D(obj["linearacceleration"]);
        }
        if(obj.contains("angularvelocity"))
        {
            msg.angularvelocity = from_json_ApollocommonPoint3D(obj["angularvelocity"]);
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("linearaccelerationvrf"))
        {
            msg.linearaccelerationvrf = from_json_ApollocommonPoint3D(obj["linearaccelerationvrf"]);
        }
        if(obj.contains("angularvelocityvrf"))
        {
            msg.angularvelocityvrf = from_json_ApollocommonPoint3D(obj["angularvelocityvrf"]);
        }
        if(obj.contains("eulerangles"))
        {
            msg.eulerangles = from_json_ApollocommonPoint3D(obj["eulerangles"]);
        }
        return msg;
    }
    template <>
    ApollolocalizationPose from_json<ApollolocalizationPose>(nlohmann::json obj){
        return from_json_ApollolocalizationPose(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationPose &dt)
    {
        dt=from_json_ApollolocalizationPose(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationPose & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationPose & dt)
    {
        os << to_json(dt);
        return os;
    }
}
