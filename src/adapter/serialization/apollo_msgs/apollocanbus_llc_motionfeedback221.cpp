#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motionfeedback221.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcMotionfeedback221 &msg) {
        nlohmann::json obj;
        obj["llcfbkvehiclespeed"] = (msg.llcfbkvehiclespeed);
        obj["llcmotionfeedback2counter"] = (msg.llcmotionfeedback2counter);
        obj["llcmotionfeedback2checksum"] = (msg.llcmotionfeedback2checksum);
        obj["llcfbksteeringrate"] = (msg.llcfbksteeringrate);
        obj["llcfbksteeringangle"] = (msg.llcfbksteeringangle);
        return obj;
    }
    ApollocanbusLlcMotionfeedback221 from_json_ApollocanbusLlcMotionfeedback221 (nlohmann::json obj) {
        ApollocanbusLlcMotionfeedback221 msg;
        if(obj.contains("llcfbkvehiclespeed"))
        {
            msg.llcfbkvehiclespeed = (obj["llcfbkvehiclespeed"].is_string()?atof(obj["llcfbkvehiclespeed"].get<std::string>().c_str()):obj["llcfbkvehiclespeed"].get<double>());
        }
        if(obj.contains("llcmotionfeedback2counter"))
        {
            msg.llcmotionfeedback2counter = (obj["llcmotionfeedback2counter"].is_string()?atoi(obj["llcmotionfeedback2counter"].get<std::string>().c_str()):obj["llcmotionfeedback2counter"].get<int>());
        }
        if(obj.contains("llcmotionfeedback2checksum"))
        {
            msg.llcmotionfeedback2checksum = (obj["llcmotionfeedback2checksum"].is_string()?atoi(obj["llcmotionfeedback2checksum"].get<std::string>().c_str()):obj["llcmotionfeedback2checksum"].get<int>());
        }
        if(obj.contains("llcfbksteeringrate"))
        {
            msg.llcfbksteeringrate = (obj["llcfbksteeringrate"].is_string()?atof(obj["llcfbksteeringrate"].get<std::string>().c_str()):obj["llcfbksteeringrate"].get<double>());
        }
        if(obj.contains("llcfbksteeringangle"))
        {
            msg.llcfbksteeringangle = (obj["llcfbksteeringangle"].is_string()?atof(obj["llcfbksteeringangle"].get<std::string>().c_str()):obj["llcfbksteeringangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcMotionfeedback221 from_json<ApollocanbusLlcMotionfeedback221>(nlohmann::json obj){
        return from_json_ApollocanbusLlcMotionfeedback221(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcMotionfeedback221 &dt)
    {
        dt=from_json_ApollocanbusLlcMotionfeedback221(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcMotionfeedback221 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcMotionfeedback221 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
