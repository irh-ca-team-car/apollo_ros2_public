#include "adapter/serialization/apollo_msgs/apollodrivers_lka769.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLka769 &msg) {
        nlohmann::json obj;
        obj["headingangle"] = (msg.headingangle);
        obj["viewrange"] = (msg.viewrange);
        obj["viewrangeavailability"] = (msg.viewrangeavailability);
        return obj;
    }
    ApollodriversLka769 from_json_ApollodriversLka769 (nlohmann::json obj) {
        ApollodriversLka769 msg;
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
    ApollodriversLka769 from_json<ApollodriversLka769>(nlohmann::json obj){
        return from_json_ApollodriversLka769(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLka769 &dt)
    {
        dt=from_json_ApollodriversLka769(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLka769 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLka769 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
