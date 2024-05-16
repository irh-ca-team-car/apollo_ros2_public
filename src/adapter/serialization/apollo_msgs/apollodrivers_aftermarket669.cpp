#include "adapter/serialization/apollo_msgs/apollodrivers_aftermarket669.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversAftermarket669 &msg) {
        nlohmann::json obj;
        obj["laneconfleft"] = (msg.laneconfleft);
        obj["ldwavailabilityleft"] = (msg.ldwavailabilityleft);
        obj["lanetypeleft"] = (msg.lanetypeleft);
        obj["distancetolanel"] = (msg.distancetolanel);
        obj["laneconfright"] = (msg.laneconfright);
        obj["ldwavailabilityright"] = (msg.ldwavailabilityright);
        obj["lanetyperight"] = (msg.lanetyperight);
        obj["distancetolaner"] = (msg.distancetolaner);
        return obj;
    }
    ApollodriversAftermarket669 from_json_ApollodriversAftermarket669 (nlohmann::json obj) {
        ApollodriversAftermarket669 msg;
        if(obj.contains("laneconfleft"))
        {
            msg.laneconfleft = (obj["laneconfleft"].is_string()?atoi(obj["laneconfleft"].get<std::string>().c_str()):obj["laneconfleft"].get<int>());
        }
        if(obj.contains("ldwavailabilityleft"))
        {
            msg.ldwavailabilityleft = (obj["ldwavailabilityleft"].is_string()?(bool)atoi(obj["ldwavailabilityleft"].get<std::string>().c_str()):obj["ldwavailabilityleft"].get<bool>());
        }
        if(obj.contains("lanetypeleft"))
        {
            msg.lanetypeleft = (obj["lanetypeleft"].is_string()?atoi(obj["lanetypeleft"].get<std::string>().c_str()):obj["lanetypeleft"].get<int>());
        }
        if(obj.contains("distancetolanel"))
        {
            msg.distancetolanel = (obj["distancetolanel"].is_string()?atof(obj["distancetolanel"].get<std::string>().c_str()):obj["distancetolanel"].get<double>());
        }
        if(obj.contains("laneconfright"))
        {
            msg.laneconfright = (obj["laneconfright"].is_string()?atoi(obj["laneconfright"].get<std::string>().c_str()):obj["laneconfright"].get<int>());
        }
        if(obj.contains("ldwavailabilityright"))
        {
            msg.ldwavailabilityright = (obj["ldwavailabilityright"].is_string()?(bool)atoi(obj["ldwavailabilityright"].get<std::string>().c_str()):obj["ldwavailabilityright"].get<bool>());
        }
        if(obj.contains("lanetyperight"))
        {
            msg.lanetyperight = (obj["lanetyperight"].is_string()?atoi(obj["lanetyperight"].get<std::string>().c_str()):obj["lanetyperight"].get<int>());
        }
        if(obj.contains("distancetolaner"))
        {
            msg.distancetolaner = (obj["distancetolaner"].is_string()?atof(obj["distancetolaner"].get<std::string>().c_str()):obj["distancetolaner"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversAftermarket669 from_json<ApollodriversAftermarket669>(nlohmann::json obj){
        return from_json_ApollodriversAftermarket669(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversAftermarket669 &dt)
    {
        dt=from_json_ApollodriversAftermarket669(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversAftermarket669 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversAftermarket669 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
