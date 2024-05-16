#include "adapter/serialization/apollo_msgs/apollocanbus_scu3303.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScu3303 &msg) {
        nlohmann::json obj;
        obj["vin15"] = (msg.vin15);
        obj["vin14"] = (msg.vin14);
        obj["vin13"] = (msg.vin13);
        obj["vin12"] = (msg.vin12);
        obj["vin11"] = (msg.vin11);
        obj["vin10"] = (msg.vin10);
        obj["vin09"] = (msg.vin09);
        obj["vin08"] = (msg.vin08);
        return obj;
    }
    ApollocanbusScu3303 from_json_ApollocanbusScu3303 (nlohmann::json obj) {
        ApollocanbusScu3303 msg;
        if(obj.contains("vin15"))
        {
            msg.vin15 = (obj["vin15"].is_string()?atoi(obj["vin15"].get<std::string>().c_str()):obj["vin15"].get<int>());
        }
        if(obj.contains("vin14"))
        {
            msg.vin14 = (obj["vin14"].is_string()?atoi(obj["vin14"].get<std::string>().c_str()):obj["vin14"].get<int>());
        }
        if(obj.contains("vin13"))
        {
            msg.vin13 = (obj["vin13"].is_string()?atoi(obj["vin13"].get<std::string>().c_str()):obj["vin13"].get<int>());
        }
        if(obj.contains("vin12"))
        {
            msg.vin12 = (obj["vin12"].is_string()?atoi(obj["vin12"].get<std::string>().c_str()):obj["vin12"].get<int>());
        }
        if(obj.contains("vin11"))
        {
            msg.vin11 = (obj["vin11"].is_string()?atoi(obj["vin11"].get<std::string>().c_str()):obj["vin11"].get<int>());
        }
        if(obj.contains("vin10"))
        {
            msg.vin10 = (obj["vin10"].is_string()?atoi(obj["vin10"].get<std::string>().c_str()):obj["vin10"].get<int>());
        }
        if(obj.contains("vin09"))
        {
            msg.vin09 = (obj["vin09"].is_string()?atoi(obj["vin09"].get<std::string>().c_str()):obj["vin09"].get<int>());
        }
        if(obj.contains("vin08"))
        {
            msg.vin08 = (obj["vin08"].is_string()?atoi(obj["vin08"].get<std::string>().c_str()):obj["vin08"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScu3303 from_json<ApollocanbusScu3303>(nlohmann::json obj){
        return from_json_ApollocanbusScu3303(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScu3303 &dt)
    {
        dt=from_json_ApollocanbusScu3303(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScu3303 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScu3303 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
