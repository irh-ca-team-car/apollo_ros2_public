#include "adapter/serialization/apollo_msgs/apollocanbus_steering_aux_rpt32c.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringAuxRpt32c &msg) {
        nlohmann::json obj;
        obj["userinteractionisvalid"] = (msg.userinteractionisvalid);
        obj["userinteraction"] = (msg.userinteraction);
        obj["rotationrateisvalid"] = (msg.rotationrateisvalid);
        obj["rotationrate"] = (msg.rotationrate);
        obj["rawtorqueisvalid"] = (msg.rawtorqueisvalid);
        obj["rawtorque"] = (msg.rawtorque);
        obj["rawpositionisvalid"] = (msg.rawpositionisvalid);
        obj["rawposition"] = (msg.rawposition);
        return obj;
    }
    ApollocanbusSteeringAuxRpt32c from_json_ApollocanbusSteeringAuxRpt32c (nlohmann::json obj) {
        ApollocanbusSteeringAuxRpt32c msg;
        if(obj.contains("userinteractionisvalid"))
        {
            msg.userinteractionisvalid = (obj["userinteractionisvalid"].is_string()?(bool)atoi(obj["userinteractionisvalid"].get<std::string>().c_str()):obj["userinteractionisvalid"].get<bool>());
        }
        if(obj.contains("userinteraction"))
        {
            msg.userinteraction = (obj["userinteraction"].is_string()?(bool)atoi(obj["userinteraction"].get<std::string>().c_str()):obj["userinteraction"].get<bool>());
        }
        if(obj.contains("rotationrateisvalid"))
        {
            msg.rotationrateisvalid = (obj["rotationrateisvalid"].is_string()?(bool)atoi(obj["rotationrateisvalid"].get<std::string>().c_str()):obj["rotationrateisvalid"].get<bool>());
        }
        if(obj.contains("rotationrate"))
        {
            msg.rotationrate = (obj["rotationrate"].is_string()?atof(obj["rotationrate"].get<std::string>().c_str()):obj["rotationrate"].get<double>());
        }
        if(obj.contains("rawtorqueisvalid"))
        {
            msg.rawtorqueisvalid = (obj["rawtorqueisvalid"].is_string()?(bool)atoi(obj["rawtorqueisvalid"].get<std::string>().c_str()):obj["rawtorqueisvalid"].get<bool>());
        }
        if(obj.contains("rawtorque"))
        {
            msg.rawtorque = (obj["rawtorque"].is_string()?atof(obj["rawtorque"].get<std::string>().c_str()):obj["rawtorque"].get<double>());
        }
        if(obj.contains("rawpositionisvalid"))
        {
            msg.rawpositionisvalid = (obj["rawpositionisvalid"].is_string()?(bool)atoi(obj["rawpositionisvalid"].get<std::string>().c_str()):obj["rawpositionisvalid"].get<bool>());
        }
        if(obj.contains("rawposition"))
        {
            msg.rawposition = (obj["rawposition"].is_string()?atof(obj["rawposition"].get<std::string>().c_str()):obj["rawposition"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringAuxRpt32c from_json<ApollocanbusSteeringAuxRpt32c>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringAuxRpt32c(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringAuxRpt32c &dt)
    {
        dt=from_json_ApollocanbusSteeringAuxRpt32c(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringAuxRpt32c & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringAuxRpt32c & dt)
    {
        os << to_json(dt);
        return os;
    }
}
