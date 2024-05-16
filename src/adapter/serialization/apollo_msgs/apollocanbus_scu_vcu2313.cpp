#include "adapter/serialization/apollo_msgs/apollocanbus_scu_vcu2313.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuVcu2313 &msg) {
        nlohmann::json obj;
        obj["vcutorqposmax"] = (msg.vcutorqposmax);
        obj["vcutorqnegmax"] = (msg.vcutorqnegmax);
        obj["vcutorqact"] = (msg.vcutorqact);
        obj["vcuengspd"] = (msg.vcuengspd);
        return obj;
    }
    ApollocanbusScuVcu2313 from_json_ApollocanbusScuVcu2313 (nlohmann::json obj) {
        ApollocanbusScuVcu2313 msg;
        if(obj.contains("vcutorqposmax"))
        {
            msg.vcutorqposmax = (obj["vcutorqposmax"].is_string()?atof(obj["vcutorqposmax"].get<std::string>().c_str()):obj["vcutorqposmax"].get<double>());
        }
        if(obj.contains("vcutorqnegmax"))
        {
            msg.vcutorqnegmax = (obj["vcutorqnegmax"].is_string()?atof(obj["vcutorqnegmax"].get<std::string>().c_str()):obj["vcutorqnegmax"].get<double>());
        }
        if(obj.contains("vcutorqact"))
        {
            msg.vcutorqact = (obj["vcutorqact"].is_string()?atof(obj["vcutorqact"].get<std::string>().c_str()):obj["vcutorqact"].get<double>());
        }
        if(obj.contains("vcuengspd"))
        {
            msg.vcuengspd = (obj["vcuengspd"].is_string()?atoi(obj["vcuengspd"].get<std::string>().c_str()):obj["vcuengspd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuVcu2313 from_json<ApollocanbusScuVcu2313>(nlohmann::json obj){
        return from_json_ApollocanbusScuVcu2313(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuVcu2313 &dt)
    {
        dt=from_json_ApollocanbusScuVcu2313(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuVcu2313 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuVcu2313 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
