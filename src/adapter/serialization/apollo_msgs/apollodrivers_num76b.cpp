#include "adapter/serialization/apollo_msgs/apollodrivers_num76b.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversNum76b &msg) {
        nlohmann::json obj;
        obj["numofnextlanemarkreported"] = (msg.numofnextlanemarkreported);
        return obj;
    }
    ApollodriversNum76b from_json_ApollodriversNum76b (nlohmann::json obj) {
        ApollodriversNum76b msg;
        if(obj.contains("numofnextlanemarkreported"))
        {
            msg.numofnextlanemarkreported = (obj["numofnextlanemarkreported"].is_string()?atoi(obj["numofnextlanemarkreported"].get<std::string>().c_str()):obj["numofnextlanemarkreported"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversNum76b from_json<ApollodriversNum76b>(nlohmann::json obj){
        return from_json_ApollodriversNum76b(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversNum76b &dt)
    {
        dt=from_json_ApollodriversNum76b(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversNum76b & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversNum76b & dt)
    {
        os << to_json(dt);
        return os;
    }
}
