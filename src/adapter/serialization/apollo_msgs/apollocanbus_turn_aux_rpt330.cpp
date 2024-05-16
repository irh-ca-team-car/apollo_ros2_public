#include "adapter/serialization/apollo_msgs/apollocanbus_turn_aux_rpt330.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnAuxRpt330 &msg) {
        nlohmann::json obj;
        obj["passblinkerbulbonisvalid"] = (msg.passblinkerbulbonisvalid);
        obj["passblinkerbulbon"] = (msg.passblinkerbulbon);
        obj["driverblinkerbulbonisvalid"] = (msg.driverblinkerbulbonisvalid);
        obj["driverblinkerbulbon"] = (msg.driverblinkerbulbon);
        return obj;
    }
    ApollocanbusTurnAuxRpt330 from_json_ApollocanbusTurnAuxRpt330 (nlohmann::json obj) {
        ApollocanbusTurnAuxRpt330 msg;
        if(obj.contains("passblinkerbulbonisvalid"))
        {
            msg.passblinkerbulbonisvalid = (obj["passblinkerbulbonisvalid"].is_string()?(bool)atoi(obj["passblinkerbulbonisvalid"].get<std::string>().c_str()):obj["passblinkerbulbonisvalid"].get<bool>());
        }
        if(obj.contains("passblinkerbulbon"))
        {
            msg.passblinkerbulbon = (obj["passblinkerbulbon"].is_string()?(bool)atoi(obj["passblinkerbulbon"].get<std::string>().c_str()):obj["passblinkerbulbon"].get<bool>());
        }
        if(obj.contains("driverblinkerbulbonisvalid"))
        {
            msg.driverblinkerbulbonisvalid = (obj["driverblinkerbulbonisvalid"].is_string()?(bool)atoi(obj["driverblinkerbulbonisvalid"].get<std::string>().c_str()):obj["driverblinkerbulbonisvalid"].get<bool>());
        }
        if(obj.contains("driverblinkerbulbon"))
        {
            msg.driverblinkerbulbon = (obj["driverblinkerbulbon"].is_string()?(bool)atoi(obj["driverblinkerbulbon"].get<std::string>().c_str()):obj["driverblinkerbulbon"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusTurnAuxRpt330 from_json<ApollocanbusTurnAuxRpt330>(nlohmann::json obj){
        return from_json_ApollocanbusTurnAuxRpt330(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnAuxRpt330 &dt)
    {
        dt=from_json_ApollocanbusTurnAuxRpt330(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnAuxRpt330 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnAuxRpt330 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
