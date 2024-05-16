#include "adapter/serialization/apollo_msgs/lane_feature_conv_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const LaneFeatureConvParameter &msg) {
        nlohmann::json obj;
        obj["conv1d0"] = to_json(msg.conv1d0);
        obj["activation1"] = to_json(msg.activation1);
        obj["conv1d2"] = to_json(msg.conv1d2);
        obj["activation3"] = to_json(msg.activation3);
        obj["conv1d4"] = to_json(msg.conv1d4);
        return obj;
    }
    LaneFeatureConvParameter from_json_LaneFeatureConvParameter (nlohmann::json obj) {
        LaneFeatureConvParameter msg;
        if(obj.contains("conv1d0"))
        {
            msg.conv1d0 = from_json_Conv1dParameter(obj["conv1d0"]);
        }
        if(obj.contains("activation1"))
        {
            msg.activation1 = from_json_ActivationParameter(obj["activation1"]);
        }
        if(obj.contains("conv1d2"))
        {
            msg.conv1d2 = from_json_Conv1dParameter(obj["conv1d2"]);
        }
        if(obj.contains("activation3"))
        {
            msg.activation3 = from_json_ActivationParameter(obj["activation3"]);
        }
        if(obj.contains("conv1d4"))
        {
            msg.conv1d4 = from_json_Conv1dParameter(obj["conv1d4"]);
        }
        return msg;
    }
    template <>
    LaneFeatureConvParameter from_json<LaneFeatureConvParameter>(nlohmann::json obj){
        return from_json_LaneFeatureConvParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, LaneFeatureConvParameter &dt)
    {
        dt=from_json_LaneFeatureConvParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const LaneFeatureConvParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const LaneFeatureConvParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
