#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_kernel_follow_ref.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphKernelFollowRef &msg) {
        nlohmann::json obj;
        nlohmann::json arr_t;
        for (auto it = msg.t.begin(); it != msg.t.end(); ++it) {
            arr_t.push_back((*it));
        }
        obj["t"] = arr_t;
        nlohmann::json arr_followlines;
        for (auto it = msg.followlines.begin(); it != msg.followlines.end(); ++it) {
            arr_followlines.push_back((*it));
        }
        obj["followlines"] = arr_followlines;
        return obj;
    }
    ApolloplanningInternalSTGraphKernelFollowRef from_json_ApolloplanningInternalSTGraphKernelFollowRef (nlohmann::json obj) {
        ApolloplanningInternalSTGraphKernelFollowRef msg;
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
        if(obj.contains("followlines"))
        {
            if(obj["followlines"].is_array())
            {
                for (auto& element : obj["followlines"])
                {
                    msg.followlines.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.followlines.push_back((obj["followlines"].is_string()?atof(obj["followlines"].get<std::string>().c_str()):obj["followlines"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSTGraphKernelFollowRef from_json<ApolloplanningInternalSTGraphKernelFollowRef>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSTGraphKernelFollowRef(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphKernelFollowRef &dt)
    {
        dt=from_json_ApolloplanningInternalSTGraphKernelFollowRef(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphKernelFollowRef & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphKernelFollowRef & dt)
    {
        os << to_json(dt);
        return os;
    }
}
