#include "adapter/serialization/apollo_msgs/apollocanbus_ecu_status3517.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEcuStatus3517 &msg) {
        nlohmann::json obj;
        obj["ultrasounddist1"] = (msg.ultrasounddist1);
        obj["ultrasounddist2"] = (msg.ultrasounddist2);
        obj["ultrasounddist3"] = (msg.ultrasounddist3);
        obj["ultrasounddist4"] = (msg.ultrasounddist4);
        obj["ultrasounddist5"] = (msg.ultrasounddist5);
        obj["ultrasounddist6"] = (msg.ultrasounddist6);
        obj["ultrasounddist7"] = (msg.ultrasounddist7);
        obj["ultrasounddist8"] = (msg.ultrasounddist8);
        return obj;
    }
    ApollocanbusEcuStatus3517 from_json_ApollocanbusEcuStatus3517 (nlohmann::json obj) {
        ApollocanbusEcuStatus3517 msg;
        if(obj.contains("ultrasounddist1"))
        {
            msg.ultrasounddist1 = (obj["ultrasounddist1"].is_string()?atof(obj["ultrasounddist1"].get<std::string>().c_str()):obj["ultrasounddist1"].get<double>());
        }
        if(obj.contains("ultrasounddist2"))
        {
            msg.ultrasounddist2 = (obj["ultrasounddist2"].is_string()?atof(obj["ultrasounddist2"].get<std::string>().c_str()):obj["ultrasounddist2"].get<double>());
        }
        if(obj.contains("ultrasounddist3"))
        {
            msg.ultrasounddist3 = (obj["ultrasounddist3"].is_string()?atof(obj["ultrasounddist3"].get<std::string>().c_str()):obj["ultrasounddist3"].get<double>());
        }
        if(obj.contains("ultrasounddist4"))
        {
            msg.ultrasounddist4 = (obj["ultrasounddist4"].is_string()?atof(obj["ultrasounddist4"].get<std::string>().c_str()):obj["ultrasounddist4"].get<double>());
        }
        if(obj.contains("ultrasounddist5"))
        {
            msg.ultrasounddist5 = (obj["ultrasounddist5"].is_string()?atof(obj["ultrasounddist5"].get<std::string>().c_str()):obj["ultrasounddist5"].get<double>());
        }
        if(obj.contains("ultrasounddist6"))
        {
            msg.ultrasounddist6 = (obj["ultrasounddist6"].is_string()?atof(obj["ultrasounddist6"].get<std::string>().c_str()):obj["ultrasounddist6"].get<double>());
        }
        if(obj.contains("ultrasounddist7"))
        {
            msg.ultrasounddist7 = (obj["ultrasounddist7"].is_string()?atof(obj["ultrasounddist7"].get<std::string>().c_str()):obj["ultrasounddist7"].get<double>());
        }
        if(obj.contains("ultrasounddist8"))
        {
            msg.ultrasounddist8 = (obj["ultrasounddist8"].is_string()?atof(obj["ultrasounddist8"].get<std::string>().c_str()):obj["ultrasounddist8"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusEcuStatus3517 from_json<ApollocanbusEcuStatus3517>(nlohmann::json obj){
        return from_json_ApollocanbusEcuStatus3517(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEcuStatus3517 &dt)
    {
        dt=from_json_ApollocanbusEcuStatus3517(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEcuStatus3517 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEcuStatus3517 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
