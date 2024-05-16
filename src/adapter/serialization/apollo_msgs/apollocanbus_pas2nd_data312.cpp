#include "adapter/serialization/apollo_msgs/apollocanbus_pas2nd_data312.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPas2ndData312 &msg) {
        nlohmann::json obj;
        obj["pasb1status"] = (msg.pasb1status);
        obj["pasb2status"] = (msg.pasb2status);
        obj["pasb3status"] = (msg.pasb3status);
        obj["pasb4status"] = (msg.pasb4status);
        obj["pasdistance1"] = (msg.pasdistance1);
        obj["pasdistance2"] = (msg.pasdistance2);
        obj["pasdistance3"] = (msg.pasdistance3);
        obj["pasdistance4"] = (msg.pasdistance4);
        return obj;
    }
    ApollocanbusPas2ndData312 from_json_ApollocanbusPas2ndData312 (nlohmann::json obj) {
        ApollocanbusPas2ndData312 msg;
        if(obj.contains("pasb1status"))
        {
            msg.pasb1status = (obj["pasb1status"].is_string()?(bool)atoi(obj["pasb1status"].get<std::string>().c_str()):obj["pasb1status"].get<bool>());
        }
        if(obj.contains("pasb2status"))
        {
            msg.pasb2status = (obj["pasb2status"].is_string()?(bool)atoi(obj["pasb2status"].get<std::string>().c_str()):obj["pasb2status"].get<bool>());
        }
        if(obj.contains("pasb3status"))
        {
            msg.pasb3status = (obj["pasb3status"].is_string()?(bool)atoi(obj["pasb3status"].get<std::string>().c_str()):obj["pasb3status"].get<bool>());
        }
        if(obj.contains("pasb4status"))
        {
            msg.pasb4status = (obj["pasb4status"].is_string()?(bool)atoi(obj["pasb4status"].get<std::string>().c_str()):obj["pasb4status"].get<bool>());
        }
        if(obj.contains("pasdistance1"))
        {
            msg.pasdistance1 = (obj["pasdistance1"].is_string()?atof(obj["pasdistance1"].get<std::string>().c_str()):obj["pasdistance1"].get<double>());
        }
        if(obj.contains("pasdistance2"))
        {
            msg.pasdistance2 = (obj["pasdistance2"].is_string()?atof(obj["pasdistance2"].get<std::string>().c_str()):obj["pasdistance2"].get<double>());
        }
        if(obj.contains("pasdistance3"))
        {
            msg.pasdistance3 = (obj["pasdistance3"].is_string()?atof(obj["pasdistance3"].get<std::string>().c_str()):obj["pasdistance3"].get<double>());
        }
        if(obj.contains("pasdistance4"))
        {
            msg.pasdistance4 = (obj["pasdistance4"].is_string()?atof(obj["pasdistance4"].get<std::string>().c_str()):obj["pasdistance4"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusPas2ndData312 from_json<ApollocanbusPas2ndData312>(nlohmann::json obj){
        return from_json_ApollocanbusPas2ndData312(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPas2ndData312 &dt)
    {
        dt=from_json_ApollocanbusPas2ndData312(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPas2ndData312 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPas2ndData312 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
