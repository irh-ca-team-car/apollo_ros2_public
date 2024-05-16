#include "adapter/serialization/apollo_msgs/apollocanbus_scu_bcs1306.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuBcs1306 &msg) {
        nlohmann::json obj;
        obj["bcsaebavailable"] = (msg.bcsaebavailable);
        obj["bcscddavailable"] = (msg.bcscddavailable);
        obj["bcsbrkpedact"] = (msg.bcsbrkpedact);
        obj["bcsintidx"] = (msg.bcsintidx);
        obj["bcsvdcfaultst"] = (msg.bcsvdcfaultst);
        obj["bcsvdcactivest"] = (msg.bcsvdcactivest);
        obj["bcsabsfaultst"] = (msg.bcsabsfaultst);
        obj["bcsabsactivest"] = (msg.bcsabsactivest);
        obj["bcsfaultst"] = (msg.bcsfaultst);
        obj["bcsdrvmode"] = (msg.bcsdrvmode);
        return obj;
    }
    ApollocanbusScuBcs1306 from_json_ApollocanbusScuBcs1306 (nlohmann::json obj) {
        ApollocanbusScuBcs1306 msg;
        if(obj.contains("bcsaebavailable"))
        {
            msg.bcsaebavailable = (obj["bcsaebavailable"].is_string()?atoi(obj["bcsaebavailable"].get<std::string>().c_str()):obj["bcsaebavailable"].get<int>());
        }
        if(obj.contains("bcscddavailable"))
        {
            msg.bcscddavailable = (obj["bcscddavailable"].is_string()?atoi(obj["bcscddavailable"].get<std::string>().c_str()):obj["bcscddavailable"].get<int>());
        }
        if(obj.contains("bcsbrkpedact"))
        {
            msg.bcsbrkpedact = (obj["bcsbrkpedact"].is_string()?atof(obj["bcsbrkpedact"].get<std::string>().c_str()):obj["bcsbrkpedact"].get<double>());
        }
        if(obj.contains("bcsintidx"))
        {
            msg.bcsintidx = (obj["bcsintidx"].is_string()?atoi(obj["bcsintidx"].get<std::string>().c_str()):obj["bcsintidx"].get<int>());
        }
        if(obj.contains("bcsvdcfaultst"))
        {
            msg.bcsvdcfaultst = (obj["bcsvdcfaultst"].is_string()?atoi(obj["bcsvdcfaultst"].get<std::string>().c_str()):obj["bcsvdcfaultst"].get<int>());
        }
        if(obj.contains("bcsvdcactivest"))
        {
            msg.bcsvdcactivest = (obj["bcsvdcactivest"].is_string()?atoi(obj["bcsvdcactivest"].get<std::string>().c_str()):obj["bcsvdcactivest"].get<int>());
        }
        if(obj.contains("bcsabsfaultst"))
        {
            msg.bcsabsfaultst = (obj["bcsabsfaultst"].is_string()?atoi(obj["bcsabsfaultst"].get<std::string>().c_str()):obj["bcsabsfaultst"].get<int>());
        }
        if(obj.contains("bcsabsactivest"))
        {
            msg.bcsabsactivest = (obj["bcsabsactivest"].is_string()?atoi(obj["bcsabsactivest"].get<std::string>().c_str()):obj["bcsabsactivest"].get<int>());
        }
        if(obj.contains("bcsfaultst"))
        {
            msg.bcsfaultst = (obj["bcsfaultst"].is_string()?atoi(obj["bcsfaultst"].get<std::string>().c_str()):obj["bcsfaultst"].get<int>());
        }
        if(obj.contains("bcsdrvmode"))
        {
            msg.bcsdrvmode = (obj["bcsdrvmode"].is_string()?atoi(obj["bcsdrvmode"].get<std::string>().c_str()):obj["bcsdrvmode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuBcs1306 from_json<ApollocanbusScuBcs1306>(nlohmann::json obj){
        return from_json_ApollocanbusScuBcs1306(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuBcs1306 &dt)
    {
        dt=from_json_ApollocanbusScuBcs1306(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuBcs1306 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuBcs1306 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
