#include "adapter/serialization/apollo_msgs/apollodriversgnss_raw_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssRawData &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversgnssRawData from_json_ApollodriversgnssRawData (nlohmann::json obj) {
        ApollodriversgnssRawData msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_Bytes(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollodriversgnssRawData from_json<ApollodriversgnssRawData>(nlohmann::json obj){
        return from_json_ApollodriversgnssRawData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssRawData &dt)
    {
        dt=from_json_ApollodriversgnssRawData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssRawData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssRawData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
