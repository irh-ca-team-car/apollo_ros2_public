#include "adapter/serialization/apollo_msgs/apollocanbus_accel_aux_rpt300.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelAuxRpt300 &msg) {
        nlohmann::json obj;
        obj["userinteractionisvalid"] = (msg.userinteractionisvalid);
        obj["userinteraction"] = (msg.userinteraction);
        obj["rawpedalforceisvalid"] = (msg.rawpedalforceisvalid);
        obj["rawpedalforce"] = (msg.rawpedalforce);
        obj["rawpedalposisvalid"] = (msg.rawpedalposisvalid);
        obj["rawpedalpos"] = (msg.rawpedalpos);
        return obj;
    }
    ApollocanbusAccelAuxRpt300 from_json_ApollocanbusAccelAuxRpt300 (nlohmann::json obj) {
        ApollocanbusAccelAuxRpt300 msg;
        if(obj.contains("userinteractionisvalid"))
        {
            msg.userinteractionisvalid = (obj["userinteractionisvalid"].is_string()?(bool)atoi(obj["userinteractionisvalid"].get<std::string>().c_str()):obj["userinteractionisvalid"].get<bool>());
        }
        if(obj.contains("userinteraction"))
        {
            msg.userinteraction = (obj["userinteraction"].is_string()?(bool)atoi(obj["userinteraction"].get<std::string>().c_str()):obj["userinteraction"].get<bool>());
        }
        if(obj.contains("rawpedalforceisvalid"))
        {
            msg.rawpedalforceisvalid = (obj["rawpedalforceisvalid"].is_string()?(bool)atoi(obj["rawpedalforceisvalid"].get<std::string>().c_str()):obj["rawpedalforceisvalid"].get<bool>());
        }
        if(obj.contains("rawpedalforce"))
        {
            msg.rawpedalforce = (obj["rawpedalforce"].is_string()?atof(obj["rawpedalforce"].get<std::string>().c_str()):obj["rawpedalforce"].get<double>());
        }
        if(obj.contains("rawpedalposisvalid"))
        {
            msg.rawpedalposisvalid = (obj["rawpedalposisvalid"].is_string()?(bool)atoi(obj["rawpedalposisvalid"].get<std::string>().c_str()):obj["rawpedalposisvalid"].get<bool>());
        }
        if(obj.contains("rawpedalpos"))
        {
            msg.rawpedalpos = (obj["rawpedalpos"].is_string()?atof(obj["rawpedalpos"].get<std::string>().c_str()):obj["rawpedalpos"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAccelAuxRpt300 from_json<ApollocanbusAccelAuxRpt300>(nlohmann::json obj){
        return from_json_ApollocanbusAccelAuxRpt300(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelAuxRpt300 &dt)
    {
        dt=from_json_ApollocanbusAccelAuxRpt300(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelAuxRpt300 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelAuxRpt300 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
