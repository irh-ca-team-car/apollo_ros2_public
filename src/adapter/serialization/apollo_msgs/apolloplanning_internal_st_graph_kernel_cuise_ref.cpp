#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_kernel_cuise_ref.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphKernelCuiseRef &msg) {
        nlohmann::json obj;
        nlohmann::json arr_t;
        for (auto it = msg.t.begin(); it != msg.t.end(); ++it) {
            arr_t.push_back((*it));
        }
        obj["t"] = arr_t;
        nlohmann::json arr_cruiselines;
        for (auto it = msg.cruiselines.begin(); it != msg.cruiselines.end(); ++it) {
            arr_cruiselines.push_back((*it));
        }
        obj["cruiselines"] = arr_cruiselines;
        return obj;
    }
    ApolloplanningInternalSTGraphKernelCuiseRef from_json_ApolloplanningInternalSTGraphKernelCuiseRef (nlohmann::json obj) {
        ApolloplanningInternalSTGraphKernelCuiseRef msg;
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
        if(obj.contains("cruiselines"))
        {
            if(obj["cruiselines"].is_array())
            {
                for (auto& element : obj["cruiselines"])
                {
                    msg.cruiselines.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.cruiselines.push_back((obj["cruiselines"].is_string()?atof(obj["cruiselines"].get<std::string>().c_str()):obj["cruiselines"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSTGraphKernelCuiseRef from_json<ApolloplanningInternalSTGraphKernelCuiseRef>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSTGraphKernelCuiseRef(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphKernelCuiseRef &dt)
    {
        dt=from_json_ApolloplanningInternalSTGraphKernelCuiseRef(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphKernelCuiseRef & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphKernelCuiseRef & dt)
    {
        os << to_json(dt);
        return os;
    }
}
