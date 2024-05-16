#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_speed_constraint.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphSpeedConstraint &msg) {
        nlohmann::json obj;
        nlohmann::json arr_t;
        for (auto it = msg.t.begin(); it != msg.t.end(); ++it) {
            arr_t.push_back((*it));
        }
        obj["t"] = arr_t;
        nlohmann::json arr_lowerbound;
        for (auto it = msg.lowerbound.begin(); it != msg.lowerbound.end(); ++it) {
            arr_lowerbound.push_back((*it));
        }
        obj["lowerbound"] = arr_lowerbound;
        nlohmann::json arr_upperbound;
        for (auto it = msg.upperbound.begin(); it != msg.upperbound.end(); ++it) {
            arr_upperbound.push_back((*it));
        }
        obj["upperbound"] = arr_upperbound;
        return obj;
    }
    ApolloplanningInternalSTGraphSpeedConstraint from_json_ApolloplanningInternalSTGraphSpeedConstraint (nlohmann::json obj) {
        ApolloplanningInternalSTGraphSpeedConstraint msg;
        if(obj.contains("t"))
        {
            if(obj["t"].is_array())
            {
                for (auto& element : obj["t"])
                {
                    msg.t.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.t.push_back((obj["t"].is_string()?atof(obj["t"].get<std::string>().c_str()):obj["t"].get<double>()));
            }
        }
        if(obj.contains("lowerbound"))
        {
            if(obj["lowerbound"].is_array())
            {
                for (auto& element : obj["lowerbound"])
                {
                    msg.lowerbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.lowerbound.push_back((obj["lowerbound"].is_string()?atof(obj["lowerbound"].get<std::string>().c_str()):obj["lowerbound"].get<double>()));
            }
        }
        if(obj.contains("upperbound"))
        {
            if(obj["upperbound"].is_array())
            {
                for (auto& element : obj["upperbound"])
                {
                    msg.upperbound.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.upperbound.push_back((obj["upperbound"].is_string()?atof(obj["upperbound"].get<std::string>().c_str()):obj["upperbound"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSTGraphSpeedConstraint from_json<ApolloplanningInternalSTGraphSpeedConstraint>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSTGraphSpeedConstraint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphSpeedConstraint &dt)
    {
        dt=from_json_ApolloplanningInternalSTGraphSpeedConstraint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphSpeedConstraint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphSpeedConstraint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
