#include "adapter/serialization/apollo_msgs/apollocanbus_brake_rpt6c.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeRpt6c &msg) {
        nlohmann::json obj;
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["outputvalue"] = (msg.outputvalue);
        obj["brakeonoff"] = (msg.brakeonoff);
        return obj;
    }
    ApollocanbusBrakeRpt6c from_json_ApollocanbusBrakeRpt6c (nlohmann::json obj) {
        ApollocanbusBrakeRpt6c msg;
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atof(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<double>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atof(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<double>());
        }
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atof(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<double>());
        }
        if(obj.contains("brakeonoff"))
        {
            msg.brakeonoff = (obj["brakeonoff"].is_string()?atoi(obj["brakeonoff"].get<std::string>().c_str()):obj["brakeonoff"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeRpt6c from_json<ApollocanbusBrakeRpt6c>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeRpt6c(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeRpt6c &dt)
    {
        dt=from_json_ApollocanbusBrakeRpt6c(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeRpt6c & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeRpt6c & dt)
    {
        os << to_json(dt);
        return os;
    }
}
