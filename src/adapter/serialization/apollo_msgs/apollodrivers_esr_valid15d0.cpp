#include "adapter/serialization/apollo_msgs/apollodrivers_esr_valid15d0.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrValid15d0 &msg) {
        nlohmann::json obj;
        obj["cantxvalidlrsn"] = (msg.cantxvalidlrsn);
        obj["cantxvalidlrrangerate"] = (msg.cantxvalidlrrangerate);
        obj["cantxvalidlrrange"] = (msg.cantxvalidlrrange);
        obj["cantxvalidlrpower"] = (msg.cantxvalidlrpower);
        obj["cantxvalidlrangle"] = (msg.cantxvalidlrangle);
        return obj;
    }
    ApollodriversEsrValid15d0 from_json_ApollodriversEsrValid15d0 (nlohmann::json obj) {
        ApollodriversEsrValid15d0 msg;
        if(obj.contains("cantxvalidlrsn"))
        {
            msg.cantxvalidlrsn = (obj["cantxvalidlrsn"].is_string()?atoi(obj["cantxvalidlrsn"].get<std::string>().c_str()):obj["cantxvalidlrsn"].get<int>());
        }
        if(obj.contains("cantxvalidlrrangerate"))
        {
            msg.cantxvalidlrrangerate = (obj["cantxvalidlrrangerate"].is_string()?atof(obj["cantxvalidlrrangerate"].get<std::string>().c_str()):obj["cantxvalidlrrangerate"].get<double>());
        }
        if(obj.contains("cantxvalidlrrange"))
        {
            msg.cantxvalidlrrange = (obj["cantxvalidlrrange"].is_string()?atof(obj["cantxvalidlrrange"].get<std::string>().c_str()):obj["cantxvalidlrrange"].get<double>());
        }
        if(obj.contains("cantxvalidlrpower"))
        {
            msg.cantxvalidlrpower = (obj["cantxvalidlrpower"].is_string()?atoi(obj["cantxvalidlrpower"].get<std::string>().c_str()):obj["cantxvalidlrpower"].get<int>());
        }
        if(obj.contains("cantxvalidlrangle"))
        {
            msg.cantxvalidlrangle = (obj["cantxvalidlrangle"].is_string()?atof(obj["cantxvalidlrangle"].get<std::string>().c_str()):obj["cantxvalidlrangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrValid15d0 from_json<ApollodriversEsrValid15d0>(nlohmann::json obj){
        return from_json_ApollodriversEsrValid15d0(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrValid15d0 &dt)
    {
        dt=from_json_ApollodriversEsrValid15d0(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrValid15d0 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrValid15d0 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
