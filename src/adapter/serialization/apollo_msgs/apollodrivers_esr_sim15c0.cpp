#include "adapter/serialization/apollo_msgs/apollodrivers_esr_sim15c0.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrSim15c0 &msg) {
        nlohmann::json obj;
        obj["canrxsimtrackid"] = (msg.canrxsimtrackid);
        obj["canrxsimstatus"] = (msg.canrxsimstatus);
        obj["canrxsimrangerate"] = (msg.canrxsimrangerate);
        obj["canrxsimrangeaccel"] = (msg.canrxsimrangeaccel);
        obj["canrxsimrange"] = (msg.canrxsimrange);
        obj["canrxsimlatrate"] = (msg.canrxsimlatrate);
        obj["canrxsimlatpos"] = (msg.canrxsimlatpos);
        obj["canrxsimfunction"] = (msg.canrxsimfunction);
        obj["canrxsimangle"] = (msg.canrxsimangle);
        return obj;
    }
    ApollodriversEsrSim15c0 from_json_ApollodriversEsrSim15c0 (nlohmann::json obj) {
        ApollodriversEsrSim15c0 msg;
        if(obj.contains("canrxsimtrackid"))
        {
            msg.canrxsimtrackid = (obj["canrxsimtrackid"].is_string()?atoi(obj["canrxsimtrackid"].get<std::string>().c_str()):obj["canrxsimtrackid"].get<int>());
        }
        if(obj.contains("canrxsimstatus"))
        {
            msg.canrxsimstatus = (obj["canrxsimstatus"].is_string()?atoi(obj["canrxsimstatus"].get<std::string>().c_str()):obj["canrxsimstatus"].get<int>());
        }
        if(obj.contains("canrxsimrangerate"))
        {
            msg.canrxsimrangerate = (obj["canrxsimrangerate"].is_string()?atof(obj["canrxsimrangerate"].get<std::string>().c_str()):obj["canrxsimrangerate"].get<double>());
        }
        if(obj.contains("canrxsimrangeaccel"))
        {
            msg.canrxsimrangeaccel = (obj["canrxsimrangeaccel"].is_string()?atof(obj["canrxsimrangeaccel"].get<std::string>().c_str()):obj["canrxsimrangeaccel"].get<double>());
        }
        if(obj.contains("canrxsimrange"))
        {
            msg.canrxsimrange = (obj["canrxsimrange"].is_string()?atoi(obj["canrxsimrange"].get<std::string>().c_str()):obj["canrxsimrange"].get<int>());
        }
        if(obj.contains("canrxsimlatrate"))
        {
            msg.canrxsimlatrate = (obj["canrxsimlatrate"].is_string()?atof(obj["canrxsimlatrate"].get<std::string>().c_str()):obj["canrxsimlatrate"].get<double>());
        }
        if(obj.contains("canrxsimlatpos"))
        {
            msg.canrxsimlatpos = (obj["canrxsimlatpos"].is_string()?atof(obj["canrxsimlatpos"].get<std::string>().c_str()):obj["canrxsimlatpos"].get<double>());
        }
        if(obj.contains("canrxsimfunction"))
        {
            msg.canrxsimfunction = (obj["canrxsimfunction"].is_string()?atoi(obj["canrxsimfunction"].get<std::string>().c_str()):obj["canrxsimfunction"].get<int>());
        }
        if(obj.contains("canrxsimangle"))
        {
            msg.canrxsimangle = (obj["canrxsimangle"].is_string()?atof(obj["canrxsimangle"].get<std::string>().c_str()):obj["canrxsimangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrSim15c0 from_json<ApollodriversEsrSim15c0>(nlohmann::json obj){
        return from_json_ApollodriversEsrSim15c0(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrSim15c0 &dt)
    {
        dt=from_json_ApollodriversEsrSim15c0(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrSim15c0 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrSim15c0 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
