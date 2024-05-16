#include "adapter/serialization/apollo_msgs/apollolocalization_msf_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationMsfStatus &msg) {
        nlohmann::json obj;
        obj["locallidarconsistency"] = (msg.locallidarconsistency);
        obj["gnssconsistency"] = (msg.gnssconsistency);
        obj["locallidarstatus"] = (msg.locallidarstatus);
        obj["locallidarquality"] = (msg.locallidarquality);
        obj["gnsspospositiontype"] = (msg.gnsspospositiontype);
        obj["msfrunningstatus"] = (msg.msfrunningstatus);
        return obj;
    }
    ApollolocalizationMsfStatus from_json_ApollolocalizationMsfStatus (nlohmann::json obj) {
        ApollolocalizationMsfStatus msg;
        if(obj.contains("locallidarconsistency"))
        {
            msg.locallidarconsistency = (obj["locallidarconsistency"].is_string()?atoi(obj["locallidarconsistency"].get<std::string>().c_str()):obj["locallidarconsistency"].get<int>());
        }
        if(obj.contains("gnssconsistency"))
        {
            msg.gnssconsistency = (obj["gnssconsistency"].is_string()?atoi(obj["gnssconsistency"].get<std::string>().c_str()):obj["gnssconsistency"].get<int>());
        }
        if(obj.contains("locallidarstatus"))
        {
            msg.locallidarstatus = (obj["locallidarstatus"].is_string()?atoi(obj["locallidarstatus"].get<std::string>().c_str()):obj["locallidarstatus"].get<int>());
        }
        if(obj.contains("locallidarquality"))
        {
            msg.locallidarquality = (obj["locallidarquality"].is_string()?atoi(obj["locallidarquality"].get<std::string>().c_str()):obj["locallidarquality"].get<int>());
        }
        if(obj.contains("gnsspospositiontype"))
        {
            msg.gnsspospositiontype = (obj["gnsspospositiontype"].is_string()?atoi(obj["gnsspospositiontype"].get<std::string>().c_str()):obj["gnsspospositiontype"].get<int>());
        }
        if(obj.contains("msfrunningstatus"))
        {
            msg.msfrunningstatus = (obj["msfrunningstatus"].is_string()?atoi(obj["msfrunningstatus"].get<std::string>().c_str()):obj["msfrunningstatus"].get<int>());
        }
        return msg;
    }
    template <>
    ApollolocalizationMsfStatus from_json<ApollolocalizationMsfStatus>(nlohmann::json obj){
        return from_json_ApollolocalizationMsfStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationMsfStatus &dt)
    {
        dt=from_json_ApollolocalizationMsfStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationMsfStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationMsfStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
