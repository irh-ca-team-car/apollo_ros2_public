#include "adapter/serialization/apollo_msgs/apolloplanning_internal_cost_components.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalCostComponents &msg) {
        nlohmann::json obj;
        nlohmann::json arr_costcomponent;
        for (auto it = msg.costcomponent.begin(); it != msg.costcomponent.end(); ++it) {
            arr_costcomponent.push_back((*it));
        }
        obj["costcomponent"] = arr_costcomponent;
        return obj;
    }
    ApolloplanningInternalCostComponents from_json_ApolloplanningInternalCostComponents (nlohmann::json obj) {
        ApolloplanningInternalCostComponents msg;
        if(obj.contains("costcomponent"))
        {
            if(obj["costcomponent"].is_array())
            {
                for (auto& element : obj["costcomponent"])
                {
                    msg.costcomponent.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.costcomponent.push_back((obj["costcomponent"].is_string()?atof(obj["costcomponent"].get<std::string>().c_str()):obj["costcomponent"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalCostComponents from_json<ApolloplanningInternalCostComponents>(nlohmann::json obj){
        return from_json_ApolloplanningInternalCostComponents(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalCostComponents &dt)
    {
        dt=from_json_ApolloplanningInternalCostComponents(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalCostComponents & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalCostComponents & dt)
    {
        os << to_json(dt);
        return os;
    }
}
