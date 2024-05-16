#include "adapter/serialization/apollo_msgs/apollocanbus_date_time_rpt83.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDateTimeRpt83 &msg) {
        nlohmann::json obj;
        obj["timesecond"] = (msg.timesecond);
        obj["timeminute"] = (msg.timeminute);
        obj["timehour"] = (msg.timehour);
        obj["dateday"] = (msg.dateday);
        obj["datemonth"] = (msg.datemonth);
        obj["dateyear"] = (msg.dateyear);
        return obj;
    }
    ApollocanbusDateTimeRpt83 from_json_ApollocanbusDateTimeRpt83 (nlohmann::json obj) {
        ApollocanbusDateTimeRpt83 msg;
        if(obj.contains("timesecond"))
        {
            msg.timesecond = (obj["timesecond"].is_string()?atoi(obj["timesecond"].get<std::string>().c_str()):obj["timesecond"].get<int>());
        }
        if(obj.contains("timeminute"))
        {
            msg.timeminute = (obj["timeminute"].is_string()?atoi(obj["timeminute"].get<std::string>().c_str()):obj["timeminute"].get<int>());
        }
        if(obj.contains("timehour"))
        {
            msg.timehour = (obj["timehour"].is_string()?atoi(obj["timehour"].get<std::string>().c_str()):obj["timehour"].get<int>());
        }
        if(obj.contains("dateday"))
        {
            msg.dateday = (obj["dateday"].is_string()?atoi(obj["dateday"].get<std::string>().c_str()):obj["dateday"].get<int>());
        }
        if(obj.contains("datemonth"))
        {
            msg.datemonth = (obj["datemonth"].is_string()?atoi(obj["datemonth"].get<std::string>().c_str()):obj["datemonth"].get<int>());
        }
        if(obj.contains("dateyear"))
        {
            msg.dateyear = (obj["dateyear"].is_string()?atoi(obj["dateyear"].get<std::string>().c_str()):obj["dateyear"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusDateTimeRpt83 from_json<ApollocanbusDateTimeRpt83>(nlohmann::json obj){
        return from_json_ApollocanbusDateTimeRpt83(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDateTimeRpt83 &dt)
    {
        dt=from_json_ApollocanbusDateTimeRpt83(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDateTimeRpt83 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDateTimeRpt83 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
