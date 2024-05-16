#include "adapter/serialization/apollo_msgs/apollodrivers_next76d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversNext76d &msg) {
        nlohmann::json obj;
        obj["headingangle"] = (msg.headingangle);
        obj["viewrange"] = (msg.viewrange);
        obj["viewrangeavailability"] = (msg.viewrangeavailability);
        return obj;
    }
    ApollodriversNext76d from_json_ApollodriversNext76d (nlohmann::json obj) {
        ApollodriversNext76d msg;
        if(obj.contains("headingangle"))
        {
            msg.headingangle = (obj["headingangle"].is_string()?atof(obj["headingangle"].get<std::string>().c_str()):obj["headingangle"].get<double>());
        }
        if(obj.contains("viewrange"))
        {
            msg.viewrange = (obj["viewrange"].is_string()?atof(obj["viewrange"].get<std::string>().c_str()):obj["viewrange"].get<double>());
        }
        if(obj.contains("viewrangeavailability"))
        {
            msg.viewrangeavailability = (obj["viewrangeavailability"].is_string()?(bool)atoi(obj["viewrangeavailability"].get<std::string>().c_str()):obj["viewrangeavailability"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversNext76d from_json<ApollodriversNext76d>(nlohmann::json obj){
        return from_json_ApollodriversNext76d(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversNext76d &dt)
    {
        dt=from_json_ApollodriversNext76d(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversNext76d & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversNext76d & dt)
    {
        os << to_json(dt);
        return os;
    }
}
