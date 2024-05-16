#include "adapter/serialization/apollo_msgs/apollodriversgnss_stream_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssStreamStatus &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["insstreamtype"] = (msg.insstreamtype);
        obj["rtkstreamintype"] = (msg.rtkstreamintype);
        obj["rtkstreamouttype"] = (msg.rtkstreamouttype);
        return obj;
    }
    ApollodriversgnssStreamStatus from_json_ApollodriversgnssStreamStatus (nlohmann::json obj) {
        ApollodriversgnssStreamStatus msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("insstreamtype"))
        {
            msg.insstreamtype = (obj["insstreamtype"].is_string()?atoi(obj["insstreamtype"].get<std::string>().c_str()):obj["insstreamtype"].get<int>());
        }
        if(obj.contains("rtkstreamintype"))
        {
            msg.rtkstreamintype = (obj["rtkstreamintype"].is_string()?atoi(obj["rtkstreamintype"].get<std::string>().c_str()):obj["rtkstreamintype"].get<int>());
        }
        if(obj.contains("rtkstreamouttype"))
        {
            msg.rtkstreamouttype = (obj["rtkstreamouttype"].is_string()?atoi(obj["rtkstreamouttype"].get<std::string>().c_str()):obj["rtkstreamouttype"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssStreamStatus from_json<ApollodriversgnssStreamStatus>(nlohmann::json obj){
        return from_json_ApollodriversgnssStreamStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssStreamStatus &dt)
    {
        dt=from_json_ApollodriversgnssStreamStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssStreamStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssStreamStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
