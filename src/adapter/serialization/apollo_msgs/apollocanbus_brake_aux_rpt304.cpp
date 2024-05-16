#include "adapter/serialization/apollo_msgs/apollocanbus_brake_aux_rpt304.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeAuxRpt304 &msg) {
        nlohmann::json obj;
        obj["brakeonoffisvalid"] = (msg.brakeonoffisvalid);
        obj["brakeonoff"] = (msg.brakeonoff);
        obj["userinteractionisvalid"] = (msg.userinteractionisvalid);
        obj["userinteraction"] = (msg.userinteraction);
        obj["rawbrakepressureisvalid"] = (msg.rawbrakepressureisvalid);
        obj["rawbrakepressure"] = (msg.rawbrakepressure);
        obj["rawpedalforceisvalid"] = (msg.rawpedalforceisvalid);
        obj["rawpedalforce"] = (msg.rawpedalforce);
        obj["rawpedalposisvalid"] = (msg.rawpedalposisvalid);
        obj["rawpedalpos"] = (msg.rawpedalpos);
        return obj;
    }
    ApollocanbusBrakeAuxRpt304 from_json_ApollocanbusBrakeAuxRpt304 (nlohmann::json obj) {
        ApollocanbusBrakeAuxRpt304 msg;
        if(obj.contains("brakeonoffisvalid"))
        {
            msg.brakeonoffisvalid = (obj["brakeonoffisvalid"].is_string()?(bool)atoi(obj["brakeonoffisvalid"].get<std::string>().c_str()):obj["brakeonoffisvalid"].get<bool>());
        }
        if(obj.contains("brakeonoff"))
        {
            msg.brakeonoff = (obj["brakeonoff"].is_string()?(bool)atoi(obj["brakeonoff"].get<std::string>().c_str()):obj["brakeonoff"].get<bool>());
        }
        if(obj.contains("userinteractionisvalid"))
        {
            msg.userinteractionisvalid = (obj["userinteractionisvalid"].is_string()?(bool)atoi(obj["userinteractionisvalid"].get<std::string>().c_str()):obj["userinteractionisvalid"].get<bool>());
        }
        if(obj.contains("userinteraction"))
        {
            msg.userinteraction = (obj["userinteraction"].is_string()?(bool)atoi(obj["userinteraction"].get<std::string>().c_str()):obj["userinteraction"].get<bool>());
        }
        if(obj.contains("rawbrakepressureisvalid"))
        {
            msg.rawbrakepressureisvalid = (obj["rawbrakepressureisvalid"].is_string()?(bool)atoi(obj["rawbrakepressureisvalid"].get<std::string>().c_str()):obj["rawbrakepressureisvalid"].get<bool>());
        }
        if(obj.contains("rawbrakepressure"))
        {
            msg.rawbrakepressure = (obj["rawbrakepressure"].is_string()?atof(obj["rawbrakepressure"].get<std::string>().c_str()):obj["rawbrakepressure"].get<double>());
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
    ApollocanbusBrakeAuxRpt304 from_json<ApollocanbusBrakeAuxRpt304>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeAuxRpt304(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeAuxRpt304 &dt)
    {
        dt=from_json_ApollocanbusBrakeAuxRpt304(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeAuxRpt304 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeAuxRpt304 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
