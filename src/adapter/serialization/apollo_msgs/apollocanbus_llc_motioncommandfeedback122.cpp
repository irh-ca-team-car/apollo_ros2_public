#include "adapter/serialization/apollo_msgs/apollocanbus_llc_motioncommandfeedback122.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcMotioncommandfeedback122 &msg) {
        nlohmann::json obj;
        obj["llcfbksteeringanglesetpoint"] = (msg.llcfbksteeringanglesetpoint);
        obj["llcfbkthrottlesetpoint"] = (msg.llcfbkthrottlesetpoint);
        obj["llcfbkbrakepercentsetpoint"] = (msg.llcfbkbrakepercentsetpoint);
        obj["llcmotioncommandfeedback1count"] = (msg.llcmotioncommandfeedback1count);
        obj["llcmotioncommandfeedback1check"] = (msg.llcmotioncommandfeedback1check);
        return obj;
    }
    ApollocanbusLlcMotioncommandfeedback122 from_json_ApollocanbusLlcMotioncommandfeedback122 (nlohmann::json obj) {
        ApollocanbusLlcMotioncommandfeedback122 msg;
        if(obj.contains("llcfbksteeringanglesetpoint"))
        {
            msg.llcfbksteeringanglesetpoint = (obj["llcfbksteeringanglesetpoint"].is_string()?atof(obj["llcfbksteeringanglesetpoint"].get<std::string>().c_str()):obj["llcfbksteeringanglesetpoint"].get<double>());
        }
        if(obj.contains("llcfbkthrottlesetpoint"))
        {
            msg.llcfbkthrottlesetpoint = (obj["llcfbkthrottlesetpoint"].is_string()?atof(obj["llcfbkthrottlesetpoint"].get<std::string>().c_str()):obj["llcfbkthrottlesetpoint"].get<double>());
        }
        if(obj.contains("llcfbkbrakepercentsetpoint"))
        {
            msg.llcfbkbrakepercentsetpoint = (obj["llcfbkbrakepercentsetpoint"].is_string()?atof(obj["llcfbkbrakepercentsetpoint"].get<std::string>().c_str()):obj["llcfbkbrakepercentsetpoint"].get<double>());
        }
        if(obj.contains("llcmotioncommandfeedback1count"))
        {
            msg.llcmotioncommandfeedback1count = (obj["llcmotioncommandfeedback1count"].is_string()?atoi(obj["llcmotioncommandfeedback1count"].get<std::string>().c_str()):obj["llcmotioncommandfeedback1count"].get<int>());
        }
        if(obj.contains("llcmotioncommandfeedback1check"))
        {
            msg.llcmotioncommandfeedback1check = (obj["llcmotioncommandfeedback1check"].is_string()?atoi(obj["llcmotioncommandfeedback1check"].get<std::string>().c_str()):obj["llcmotioncommandfeedback1check"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcMotioncommandfeedback122 from_json<ApollocanbusLlcMotioncommandfeedback122>(nlohmann::json obj){
        return from_json_ApollocanbusLlcMotioncommandfeedback122(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcMotioncommandfeedback122 &dt)
    {
        dt=from_json_ApollocanbusLlcMotioncommandfeedback122(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcMotioncommandfeedback122 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcMotioncommandfeedback122 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
