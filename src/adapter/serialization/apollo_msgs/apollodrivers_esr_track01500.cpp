#include "adapter/serialization/apollo_msgs/apollodrivers_esr_track01500.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrTrack01500 &msg) {
        nlohmann::json obj;
        obj["cantxtrackgroupingchanged"] = (msg.cantxtrackgroupingchanged);
        obj["cantxtrackoncoming"] = (msg.cantxtrackoncoming);
        obj["cantxtracklatrate"] = (msg.cantxtracklatrate);
        obj["cantxtrackbridgeobject"] = (msg.cantxtrackbridgeobject);
        obj["cantxtrackwidth"] = (msg.cantxtrackwidth);
        obj["cantxtrackstatus"] = (msg.cantxtrackstatus);
        obj["cantxtrackrollingcount"] = (msg.cantxtrackrollingcount);
        obj["cantxtrackrangerate"] = (msg.cantxtrackrangerate);
        obj["cantxtrackrangeaccel"] = (msg.cantxtrackrangeaccel);
        obj["cantxtrackrange"] = (msg.cantxtrackrange);
        obj["cantxtrackmedrangemode"] = (msg.cantxtrackmedrangemode);
        obj["cantxtrackangle"] = (msg.cantxtrackangle);
        return obj;
    }
    ApollodriversEsrTrack01500 from_json_ApollodriversEsrTrack01500 (nlohmann::json obj) {
        ApollodriversEsrTrack01500 msg;
        if(obj.contains("cantxtrackgroupingchanged"))
        {
            msg.cantxtrackgroupingchanged = (obj["cantxtrackgroupingchanged"].is_string()?atoi(obj["cantxtrackgroupingchanged"].get<std::string>().c_str()):obj["cantxtrackgroupingchanged"].get<int>());
        }
        if(obj.contains("cantxtrackoncoming"))
        {
            msg.cantxtrackoncoming = (obj["cantxtrackoncoming"].is_string()?atoi(obj["cantxtrackoncoming"].get<std::string>().c_str()):obj["cantxtrackoncoming"].get<int>());
        }
        if(obj.contains("cantxtracklatrate"))
        {
            msg.cantxtracklatrate = (obj["cantxtracklatrate"].is_string()?atof(obj["cantxtracklatrate"].get<std::string>().c_str()):obj["cantxtracklatrate"].get<double>());
        }
        if(obj.contains("cantxtrackbridgeobject"))
        {
            msg.cantxtrackbridgeobject = (obj["cantxtrackbridgeobject"].is_string()?atoi(obj["cantxtrackbridgeobject"].get<std::string>().c_str()):obj["cantxtrackbridgeobject"].get<int>());
        }
        if(obj.contains("cantxtrackwidth"))
        {
            msg.cantxtrackwidth = (obj["cantxtrackwidth"].is_string()?atof(obj["cantxtrackwidth"].get<std::string>().c_str()):obj["cantxtrackwidth"].get<double>());
        }
        if(obj.contains("cantxtrackstatus"))
        {
            msg.cantxtrackstatus = (obj["cantxtrackstatus"].is_string()?atoi(obj["cantxtrackstatus"].get<std::string>().c_str()):obj["cantxtrackstatus"].get<int>());
        }
        if(obj.contains("cantxtrackrollingcount"))
        {
            msg.cantxtrackrollingcount = (obj["cantxtrackrollingcount"].is_string()?(bool)atoi(obj["cantxtrackrollingcount"].get<std::string>().c_str()):obj["cantxtrackrollingcount"].get<bool>());
        }
        if(obj.contains("cantxtrackrangerate"))
        {
            msg.cantxtrackrangerate = (obj["cantxtrackrangerate"].is_string()?atof(obj["cantxtrackrangerate"].get<std::string>().c_str()):obj["cantxtrackrangerate"].get<double>());
        }
        if(obj.contains("cantxtrackrangeaccel"))
        {
            msg.cantxtrackrangeaccel = (obj["cantxtrackrangeaccel"].is_string()?atof(obj["cantxtrackrangeaccel"].get<std::string>().c_str()):obj["cantxtrackrangeaccel"].get<double>());
        }
        if(obj.contains("cantxtrackrange"))
        {
            msg.cantxtrackrange = (obj["cantxtrackrange"].is_string()?atof(obj["cantxtrackrange"].get<std::string>().c_str()):obj["cantxtrackrange"].get<double>());
        }
        if(obj.contains("cantxtrackmedrangemode"))
        {
            msg.cantxtrackmedrangemode = (obj["cantxtrackmedrangemode"].is_string()?atoi(obj["cantxtrackmedrangemode"].get<std::string>().c_str()):obj["cantxtrackmedrangemode"].get<int>());
        }
        if(obj.contains("cantxtrackangle"))
        {
            msg.cantxtrackangle = (obj["cantxtrackangle"].is_string()?atof(obj["cantxtrackangle"].get<std::string>().c_str()):obj["cantxtrackangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrTrack01500 from_json<ApollodriversEsrTrack01500>(nlohmann::json obj){
        return from_json_ApollodriversEsrTrack01500(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrTrack01500 &dt)
    {
        dt=from_json_ApollodriversEsrTrack01500(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrTrack01500 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrTrack01500 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
