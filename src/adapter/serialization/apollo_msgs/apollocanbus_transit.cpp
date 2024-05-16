#include "adapter/serialization/apollo_msgs/apollocanbus_transit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTransit &msg) {
        nlohmann::json obj;
        obj["llcvehiclelimits24"] = to_json(msg.llcvehiclelimits24);
        obj["adcmotioncontrol110"] = to_json(msg.adcmotioncontrol110);
        obj["adcmotioncontrollimits112"] = to_json(msg.adcmotioncontrollimits112);
        obj["llcmotionfeedback120"] = to_json(msg.llcmotionfeedback120);
        obj["llcmotionfeedback221"] = to_json(msg.llcmotionfeedback221);
        obj["llcmotioncommandfeedback122"] = to_json(msg.llcmotioncommandfeedback122);
        obj["llcvehiclestatus25"] = to_json(msg.llcvehiclestatus25);
        obj["llcauxiliaryfeedback120"] = to_json(msg.llcauxiliaryfeedback120);
        obj["llcdiagfault620"] = to_json(msg.llcdiagfault620);
        obj["llcdiagsteeringcontrol722"] = to_json(msg.llcdiagsteeringcontrol722);
        obj["adcauxiliarycontrol110"] = to_json(msg.adcauxiliarycontrol110);
        obj["llcdiagbrakecontrol721"] = to_json(msg.llcdiagbrakecontrol721);
        return obj;
    }
    ApollocanbusTransit from_json_ApollocanbusTransit (nlohmann::json obj) {
        ApollocanbusTransit msg;
        if(obj.contains("llcvehiclelimits24"))
        {
            msg.llcvehiclelimits24 = from_json_ApollocanbusLlcVehiclelimits24(obj["llcvehiclelimits24"]);
        }
        if(obj.contains("adcmotioncontrol110"))
        {
            msg.adcmotioncontrol110 = from_json_ApollocanbusAdcMotioncontrol110(obj["adcmotioncontrol110"]);
        }
        if(obj.contains("adcmotioncontrollimits112"))
        {
            msg.adcmotioncontrollimits112 = from_json_ApollocanbusAdcMotioncontrollimits112(obj["adcmotioncontrollimits112"]);
        }
        if(obj.contains("llcmotionfeedback120"))
        {
            msg.llcmotionfeedback120 = from_json_ApollocanbusLlcMotionfeedback120(obj["llcmotionfeedback120"]);
        }
        if(obj.contains("llcmotionfeedback221"))
        {
            msg.llcmotionfeedback221 = from_json_ApollocanbusLlcMotionfeedback221(obj["llcmotionfeedback221"]);
        }
        if(obj.contains("llcmotioncommandfeedback122"))
        {
            msg.llcmotioncommandfeedback122 = from_json_ApollocanbusLlcMotioncommandfeedback122(obj["llcmotioncommandfeedback122"]);
        }
        if(obj.contains("llcvehiclestatus25"))
        {
            msg.llcvehiclestatus25 = from_json_ApollocanbusLlcVehiclestatus25(obj["llcvehiclestatus25"]);
        }
        if(obj.contains("llcauxiliaryfeedback120"))
        {
            msg.llcauxiliaryfeedback120 = from_json_ApollocanbusLlcAuxiliaryfeedback120(obj["llcauxiliaryfeedback120"]);
        }
        if(obj.contains("llcdiagfault620"))
        {
            msg.llcdiagfault620 = from_json_ApollocanbusLlcDiagFault620(obj["llcdiagfault620"]);
        }
        if(obj.contains("llcdiagsteeringcontrol722"))
        {
            msg.llcdiagsteeringcontrol722 = from_json_ApollocanbusLlcDiagSteeringcontrol722(obj["llcdiagsteeringcontrol722"]);
        }
        if(obj.contains("adcauxiliarycontrol110"))
        {
            msg.adcauxiliarycontrol110 = from_json_ApollocanbusAdcAuxiliarycontrol110(obj["adcauxiliarycontrol110"]);
        }
        if(obj.contains("llcdiagbrakecontrol721"))
        {
            msg.llcdiagbrakecontrol721 = from_json_ApollocanbusLlcDiagBrakecontrol721(obj["llcdiagbrakecontrol721"]);
        }
        return msg;
    }
    template <>
    ApollocanbusTransit from_json<ApollocanbusTransit>(nlohmann::json obj){
        return from_json_ApollocanbusTransit(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTransit &dt)
    {
        dt=from_json_ApollocanbusTransit(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTransit & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTransit & dt)
    {
        os << to_json(dt);
        return os;
    }
}
