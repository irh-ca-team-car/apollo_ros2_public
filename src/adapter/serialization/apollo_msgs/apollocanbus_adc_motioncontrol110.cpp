#include "adapter/serialization/apollo_msgs/apollocanbus_adc_motioncontrol110.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdcMotioncontrol110 &msg) {
        nlohmann::json obj;
        obj["adccmdsteerwheelangle"] = (msg.adccmdsteerwheelangle);
        obj["adccmdsteeringcontrolmode"] = (msg.adccmdsteeringcontrolmode);
        obj["adccmdparkingbrake"] = (msg.adccmdparkingbrake);
        obj["adccmdgear"] = (msg.adccmdgear);
        obj["adcmotioncontrol1checksum"] = (msg.adcmotioncontrol1checksum);
        obj["adccmdbrakepercentage"] = (msg.adccmdbrakepercentage);
        obj["adccmdthrottleposition"] = (msg.adccmdthrottleposition);
        obj["adcmotioncontrol1counter"] = (msg.adcmotioncontrol1counter);
        obj["adccmdautonomyrequest"] = (msg.adccmdautonomyrequest);
        obj["adccmdlongitudinalcontrolmode"] = (msg.adccmdlongitudinalcontrolmode);
        return obj;
    }
    ApollocanbusAdcMotioncontrol110 from_json_ApollocanbusAdcMotioncontrol110 (nlohmann::json obj) {
        ApollocanbusAdcMotioncontrol110 msg;
        if(obj.contains("adccmdsteerwheelangle"))
        {
            msg.adccmdsteerwheelangle = (obj["adccmdsteerwheelangle"].is_string()?atof(obj["adccmdsteerwheelangle"].get<std::string>().c_str()):obj["adccmdsteerwheelangle"].get<double>());
        }
        if(obj.contains("adccmdsteeringcontrolmode"))
        {
            msg.adccmdsteeringcontrolmode = (obj["adccmdsteeringcontrolmode"].is_string()?atoi(obj["adccmdsteeringcontrolmode"].get<std::string>().c_str()):obj["adccmdsteeringcontrolmode"].get<int>());
        }
        if(obj.contains("adccmdparkingbrake"))
        {
            msg.adccmdparkingbrake = (obj["adccmdparkingbrake"].is_string()?(bool)atoi(obj["adccmdparkingbrake"].get<std::string>().c_str()):obj["adccmdparkingbrake"].get<bool>());
        }
        if(obj.contains("adccmdgear"))
        {
            msg.adccmdgear = (obj["adccmdgear"].is_string()?atoi(obj["adccmdgear"].get<std::string>().c_str()):obj["adccmdgear"].get<int>());
        }
        if(obj.contains("adcmotioncontrol1checksum"))
        {
            msg.adcmotioncontrol1checksum = (obj["adcmotioncontrol1checksum"].is_string()?atoi(obj["adcmotioncontrol1checksum"].get<std::string>().c_str()):obj["adcmotioncontrol1checksum"].get<int>());
        }
        if(obj.contains("adccmdbrakepercentage"))
        {
            msg.adccmdbrakepercentage = (obj["adccmdbrakepercentage"].is_string()?atof(obj["adccmdbrakepercentage"].get<std::string>().c_str()):obj["adccmdbrakepercentage"].get<double>());
        }
        if(obj.contains("adccmdthrottleposition"))
        {
            msg.adccmdthrottleposition = (obj["adccmdthrottleposition"].is_string()?atof(obj["adccmdthrottleposition"].get<std::string>().c_str()):obj["adccmdthrottleposition"].get<double>());
        }
        if(obj.contains("adcmotioncontrol1counter"))
        {
            msg.adcmotioncontrol1counter = (obj["adcmotioncontrol1counter"].is_string()?atoi(obj["adcmotioncontrol1counter"].get<std::string>().c_str()):obj["adcmotioncontrol1counter"].get<int>());
        }
        if(obj.contains("adccmdautonomyrequest"))
        {
            msg.adccmdautonomyrequest = (obj["adccmdautonomyrequest"].is_string()?atoi(obj["adccmdautonomyrequest"].get<std::string>().c_str()):obj["adccmdautonomyrequest"].get<int>());
        }
        if(obj.contains("adccmdlongitudinalcontrolmode"))
        {
            msg.adccmdlongitudinalcontrolmode = (obj["adccmdlongitudinalcontrolmode"].is_string()?atoi(obj["adccmdlongitudinalcontrolmode"].get<std::string>().c_str()):obj["adccmdlongitudinalcontrolmode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdcMotioncontrol110 from_json<ApollocanbusAdcMotioncontrol110>(nlohmann::json obj){
        return from_json_ApollocanbusAdcMotioncontrol110(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdcMotioncontrol110 &dt)
    {
        dt=from_json_ApollocanbusAdcMotioncontrol110(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdcMotioncontrol110 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdcMotioncontrol110 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
