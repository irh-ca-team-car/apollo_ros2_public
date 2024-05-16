#include "adapter/serialization/apollo_msgs/apollocanbus_pas1st_data311.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPas1stData311 &msg) {
        nlohmann::json obj;
        obj["pasdistance4"] = (msg.pasdistance4);
        obj["pasdistance3"] = (msg.pasdistance3);
        obj["pasf1status"] = (msg.pasf1status);
        obj["pasf2status"] = (msg.pasf2status);
        obj["pasf3status"] = (msg.pasf3status);
        obj["pasf4status"] = (msg.pasf4status);
        obj["pasdistance2"] = (msg.pasdistance2);
        obj["pasdistance1"] = (msg.pasdistance1);
        return obj;
    }
    ApollocanbusPas1stData311 from_json_ApollocanbusPas1stData311 (nlohmann::json obj) {
        ApollocanbusPas1stData311 msg;
        if(obj.contains("pasdistance4"))
        {
            msg.pasdistance4 = (obj["pasdistance4"].is_string()?atof(obj["pasdistance4"].get<std::string>().c_str()):obj["pasdistance4"].get<double>());
        }
        if(obj.contains("pasdistance3"))
        {
            msg.pasdistance3 = (obj["pasdistance3"].is_string()?atof(obj["pasdistance3"].get<std::string>().c_str()):obj["pasdistance3"].get<double>());
        }
        if(obj.contains("pasf1status"))
        {
            msg.pasf1status = (obj["pasf1status"].is_string()?(bool)atoi(obj["pasf1status"].get<std::string>().c_str()):obj["pasf1status"].get<bool>());
        }
        if(obj.contains("pasf2status"))
        {
            msg.pasf2status = (obj["pasf2status"].is_string()?(bool)atoi(obj["pasf2status"].get<std::string>().c_str()):obj["pasf2status"].get<bool>());
        }
        if(obj.contains("pasf3status"))
        {
            msg.pasf3status = (obj["pasf3status"].is_string()?(bool)atoi(obj["pasf3status"].get<std::string>().c_str()):obj["pasf3status"].get<bool>());
        }
        if(obj.contains("pasf4status"))
        {
            msg.pasf4status = (obj["pasf4status"].is_string()?(bool)atoi(obj["pasf4status"].get<std::string>().c_str()):obj["pasf4status"].get<bool>());
        }
        if(obj.contains("pasdistance2"))
        {
            msg.pasdistance2 = (obj["pasdistance2"].is_string()?atof(obj["pasdistance2"].get<std::string>().c_str()):obj["pasdistance2"].get<double>());
        }
        if(obj.contains("pasdistance1"))
        {
            msg.pasdistance1 = (obj["pasdistance1"].is_string()?atof(obj["pasdistance1"].get<std::string>().c_str()):obj["pasdistance1"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusPas1stData311 from_json<ApollocanbusPas1stData311>(nlohmann::json obj){
        return from_json_ApollocanbusPas1stData311(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPas1stData311 &dt)
    {
        dt=from_json_ApollocanbusPas1stData311(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPas1stData311 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPas1stData311 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
