#include "adapter/serialization/apollo_msgs/apollodrivers_esr_valid25d1.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrValid25d1 &msg) {
        nlohmann::json obj;
        obj["cantxvalidmrsn"] = (msg.cantxvalidmrsn);
        obj["cantxvalidmrrangerate"] = (msg.cantxvalidmrrangerate);
        obj["cantxvalidmrrange"] = (msg.cantxvalidmrrange);
        obj["cantxvalidmrpower"] = (msg.cantxvalidmrpower);
        obj["cantxvalidmrangle"] = (msg.cantxvalidmrangle);
        return obj;
    }
    ApollodriversEsrValid25d1 from_json_ApollodriversEsrValid25d1 (nlohmann::json obj) {
        ApollodriversEsrValid25d1 msg;
        if(obj.contains("cantxvalidmrsn"))
        {
            msg.cantxvalidmrsn = (obj["cantxvalidmrsn"].is_string()?atoi(obj["cantxvalidmrsn"].get<std::string>().c_str()):obj["cantxvalidmrsn"].get<int>());
        }
        if(obj.contains("cantxvalidmrrangerate"))
        {
            msg.cantxvalidmrrangerate = (obj["cantxvalidmrrangerate"].is_string()?atof(obj["cantxvalidmrrangerate"].get<std::string>().c_str()):obj["cantxvalidmrrangerate"].get<double>());
        }
        if(obj.contains("cantxvalidmrrange"))
        {
            msg.cantxvalidmrrange = (obj["cantxvalidmrrange"].is_string()?atof(obj["cantxvalidmrrange"].get<std::string>().c_str()):obj["cantxvalidmrrange"].get<double>());
        }
        if(obj.contains("cantxvalidmrpower"))
        {
            msg.cantxvalidmrpower = (obj["cantxvalidmrpower"].is_string()?atoi(obj["cantxvalidmrpower"].get<std::string>().c_str()):obj["cantxvalidmrpower"].get<int>());
        }
        if(obj.contains("cantxvalidmrangle"))
        {
            msg.cantxvalidmrangle = (obj["cantxvalidmrangle"].is_string()?atof(obj["cantxvalidmrangle"].get<std::string>().c_str()):obj["cantxvalidmrangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrValid25d1 from_json<ApollodriversEsrValid25d1>(nlohmann::json obj){
        return from_json_ApollodriversEsrValid25d1(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrValid25d1 &dt)
    {
        dt=from_json_ApollodriversEsrValid25d1(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrValid25d1 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrValid25d1 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
