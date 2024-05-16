#include "adapter/serialization/apollo_msgs/apollocanbus_ge3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusGe3 &msg) {
        nlohmann::json obj;
        obj["pcbcm201"] = to_json(msg.pcbcm201);
        obj["scubcs3308"] = to_json(msg.scubcs3308);
        obj["pcepb203"] = to_json(msg.pcepb203);
        obj["pcbcs202"] = to_json(msg.pcbcs202);
        obj["pcvcu205"] = to_json(msg.pcvcu205);
        obj["pceps204"] = to_json(msg.pceps204);
        obj["scuvcu2313"] = to_json(msg.scuvcu2313);
        obj["scu1301"] = to_json(msg.scu1301);
        obj["scu2302"] = to_json(msg.scu2302);
        obj["scu3303"] = to_json(msg.scu3303);
        obj["scubcm304"] = to_json(msg.scubcm304);
        obj["scubcs1306"] = to_json(msg.scubcs1306);
        obj["scubcs2307"] = to_json(msg.scubcs2307);
        obj["scuepb310"] = to_json(msg.scuepb310);
        obj["scuvcu1312"] = to_json(msg.scuvcu1312);
        obj["scueps311"] = to_json(msg.scueps311);
        return obj;
    }
    ApollocanbusGe3 from_json_ApollocanbusGe3 (nlohmann::json obj) {
        ApollocanbusGe3 msg;
        if(obj.contains("pcbcm201"))
        {
            msg.pcbcm201 = from_json_ApollocanbusPcBcm201(obj["pcbcm201"]);
        }
        if(obj.contains("scubcs3308"))
        {
            msg.scubcs3308 = from_json_ApollocanbusScuBcs3308(obj["scubcs3308"]);
        }
        if(obj.contains("pcepb203"))
        {
            msg.pcepb203 = from_json_ApollocanbusPcEpb203(obj["pcepb203"]);
        }
        if(obj.contains("pcbcs202"))
        {
            msg.pcbcs202 = from_json_ApollocanbusPcBcs202(obj["pcbcs202"]);
        }
        if(obj.contains("pcvcu205"))
        {
            msg.pcvcu205 = from_json_ApollocanbusPcVcu205(obj["pcvcu205"]);
        }
        if(obj.contains("pceps204"))
        {
            msg.pceps204 = from_json_ApollocanbusPcEps204(obj["pceps204"]);
        }
        if(obj.contains("scuvcu2313"))
        {
            msg.scuvcu2313 = from_json_ApollocanbusScuVcu2313(obj["scuvcu2313"]);
        }
        if(obj.contains("scu1301"))
        {
            msg.scu1301 = from_json_ApollocanbusScu1301(obj["scu1301"]);
        }
        if(obj.contains("scu2302"))
        {
            msg.scu2302 = from_json_ApollocanbusScu2302(obj["scu2302"]);
        }
        if(obj.contains("scu3303"))
        {
            msg.scu3303 = from_json_ApollocanbusScu3303(obj["scu3303"]);
        }
        if(obj.contains("scubcm304"))
        {
            msg.scubcm304 = from_json_ApollocanbusScuBcm304(obj["scubcm304"]);
        }
        if(obj.contains("scubcs1306"))
        {
            msg.scubcs1306 = from_json_ApollocanbusScuBcs1306(obj["scubcs1306"]);
        }
        if(obj.contains("scubcs2307"))
        {
            msg.scubcs2307 = from_json_ApollocanbusScuBcs2307(obj["scubcs2307"]);
        }
        if(obj.contains("scuepb310"))
        {
            msg.scuepb310 = from_json_ApollocanbusScuEpb310(obj["scuepb310"]);
        }
        if(obj.contains("scuvcu1312"))
        {
            msg.scuvcu1312 = from_json_ApollocanbusScuVcu1312(obj["scuvcu1312"]);
        }
        if(obj.contains("scueps311"))
        {
            msg.scueps311 = from_json_ApollocanbusScuEps311(obj["scueps311"]);
        }
        return msg;
    }
    template <>
    ApollocanbusGe3 from_json<ApollocanbusGe3>(nlohmann::json obj){
        return from_json_ApollocanbusGe3(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusGe3 &dt)
    {
        dt=from_json_ApollocanbusGe3(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusGe3 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusGe3 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
