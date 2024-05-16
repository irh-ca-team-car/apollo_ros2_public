#include "adapter/serialization/apollo_msgs/obs_feature_fc_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ObsFeatureFCParameter &msg) {
        nlohmann::json obj;
        obj["linear0"] = to_json(msg.linear0);
        obj["activation1"] = to_json(msg.activation1);
        obj["linear3"] = to_json(msg.linear3);
        obj["activation4"] = to_json(msg.activation4);
        return obj;
    }
    ObsFeatureFCParameter from_json_ObsFeatureFCParameter (nlohmann::json obj) {
        ObsFeatureFCParameter msg;
        if(obj.contains("linear0"))
        {
            msg.linear0 = from_json_DenseParameter(obj["linear0"]);
        }
        if(obj.contains("activation1"))
        {
            msg.activation1 = from_json_ActivationParameter(obj["activation1"]);
        }
        if(obj.contains("linear3"))
        {
            msg.linear3 = from_json_DenseParameter(obj["linear3"]);
        }
        if(obj.contains("activation4"))
        {
            msg.activation4 = from_json_ActivationParameter(obj["activation4"]);
        }
        return msg;
    }
    template <>
    ObsFeatureFCParameter from_json<ObsFeatureFCParameter>(nlohmann::json obj){
        return from_json_ObsFeatureFCParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ObsFeatureFCParameter &dt)
    {
        dt=from_json_ObsFeatureFCParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ObsFeatureFCParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ObsFeatureFCParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
