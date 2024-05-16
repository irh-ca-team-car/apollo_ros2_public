#include "adapter/serialization/apollo_msgs/apolloplanning_internal_st_graph_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSTGraphDebug &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_boundary;
        for (auto it = msg.boundary.begin(); it != msg.boundary.end(); ++it) {
            arr_boundary.push_back(to_json(*it));
        }
        obj["boundary"] = arr_boundary;
        nlohmann::json arr_speedlimit;
        for (auto it = msg.speedlimit.begin(); it != msg.speedlimit.end(); ++it) {
            arr_speedlimit.push_back(to_json(*it));
        }
        obj["speedlimit"] = arr_speedlimit;
        nlohmann::json arr_speedprofile;
        for (auto it = msg.speedprofile.begin(); it != msg.speedprofile.end(); ++it) {
            arr_speedprofile.push_back(to_json(*it));
        }
        obj["speedprofile"] = arr_speedprofile;
        obj["speedconstraint"] = to_json(msg.speedconstraint);
        obj["kernelcruiseref"] = to_json(msg.kernelcruiseref);
        obj["kernelfollowref"] = to_json(msg.kernelfollowref);
        return obj;
    }
    ApolloplanningInternalSTGraphDebug from_json_ApolloplanningInternalSTGraphDebug (nlohmann::json obj) {
        ApolloplanningInternalSTGraphDebug msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("boundary"))
        {
            if(obj["boundary"].is_array())
            {
                for (auto& element : obj["boundary"])
                {
                    msg.boundary.push_back(from_json_ApolloplanningInternalStGraphBoundaryDebug(element));
                }
            }
            else
            {
                msg.boundary.push_back(from_json_ApolloplanningInternalStGraphBoundaryDebug(obj["boundary"]));
            }
        }
        if(obj.contains("speedlimit"))
        {
            if(obj["speedlimit"].is_array())
            {
                for (auto& element : obj["speedlimit"])
                {
                    msg.speedlimit.push_back(from_json_ApollocommonSpeedPoint(element));
                }
            }
            else
            {
                msg.speedlimit.push_back(from_json_ApollocommonSpeedPoint(obj["speedlimit"]));
            }
        }
        if(obj.contains("speedprofile"))
        {
            if(obj["speedprofile"].is_array())
            {
                for (auto& element : obj["speedprofile"])
                {
                    msg.speedprofile.push_back(from_json_ApollocommonSpeedPoint(element));
                }
            }
            else
            {
                msg.speedprofile.push_back(from_json_ApollocommonSpeedPoint(obj["speedprofile"]));
            }
        }
        if(obj.contains("speedconstraint"))
        {
            msg.speedconstraint = from_json_ApolloplanningInternalSTGraphSpeedConstraint(obj["speedconstraint"]);
        }
        if(obj.contains("kernelcruiseref"))
        {
            msg.kernelcruiseref = from_json_ApolloplanningInternalSTGraphKernelCuiseRef(obj["kernelcruiseref"]);
        }
        if(obj.contains("kernelfollowref"))
        {
            msg.kernelfollowref = from_json_ApolloplanningInternalSTGraphKernelFollowRef(obj["kernelfollowref"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSTGraphDebug from_json<ApolloplanningInternalSTGraphDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSTGraphDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSTGraphDebug &dt)
    {
        dt=from_json_ApolloplanningInternalSTGraphDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSTGraphDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSTGraphDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
