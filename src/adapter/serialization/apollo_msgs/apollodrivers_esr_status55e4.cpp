#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status55e4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus55e4 &msg) {
        nlohmann::json obj;
        obj["cantxsupply10va2d"] = (msg.cantxsupply10va2d);
        obj["cantxtemp2a2d"] = (msg.cantxtemp2a2d);
        obj["cantxtemp1a2d"] = (msg.cantxtemp1a2d);
        obj["cantxswbatta2d"] = (msg.cantxswbatta2d);
        obj["cantxsupply5vdxa2d"] = (msg.cantxsupply5vdxa2d);
        obj["cantxsupply5vaa2d"] = (msg.cantxsupply5vaa2d);
        obj["cantxsupply3p3va2d"] = (msg.cantxsupply3p3va2d);
        obj["cantxignpa2d"] = (msg.cantxignpa2d);
        return obj;
    }
    ApollodriversEsrStatus55e4 from_json_ApollodriversEsrStatus55e4 (nlohmann::json obj) {
        ApollodriversEsrStatus55e4 msg;
        if(obj.contains("cantxsupply10va2d"))
        {
            msg.cantxsupply10va2d = (obj["cantxsupply10va2d"].is_string()?atoi(obj["cantxsupply10va2d"].get<std::string>().c_str()):obj["cantxsupply10va2d"].get<int>());
        }
        if(obj.contains("cantxtemp2a2d"))
        {
            msg.cantxtemp2a2d = (obj["cantxtemp2a2d"].is_string()?atoi(obj["cantxtemp2a2d"].get<std::string>().c_str()):obj["cantxtemp2a2d"].get<int>());
        }
        if(obj.contains("cantxtemp1a2d"))
        {
            msg.cantxtemp1a2d = (obj["cantxtemp1a2d"].is_string()?atoi(obj["cantxtemp1a2d"].get<std::string>().c_str()):obj["cantxtemp1a2d"].get<int>());
        }
        if(obj.contains("cantxswbatta2d"))
        {
            msg.cantxswbatta2d = (obj["cantxswbatta2d"].is_string()?atoi(obj["cantxswbatta2d"].get<std::string>().c_str()):obj["cantxswbatta2d"].get<int>());
        }
        if(obj.contains("cantxsupply5vdxa2d"))
        {
            msg.cantxsupply5vdxa2d = (obj["cantxsupply5vdxa2d"].is_string()?atoi(obj["cantxsupply5vdxa2d"].get<std::string>().c_str()):obj["cantxsupply5vdxa2d"].get<int>());
        }
        if(obj.contains("cantxsupply5vaa2d"))
        {
            msg.cantxsupply5vaa2d = (obj["cantxsupply5vaa2d"].is_string()?atoi(obj["cantxsupply5vaa2d"].get<std::string>().c_str()):obj["cantxsupply5vaa2d"].get<int>());
        }
        if(obj.contains("cantxsupply3p3va2d"))
        {
            msg.cantxsupply3p3va2d = (obj["cantxsupply3p3va2d"].is_string()?atoi(obj["cantxsupply3p3va2d"].get<std::string>().c_str()):obj["cantxsupply3p3va2d"].get<int>());
        }
        if(obj.contains("cantxignpa2d"))
        {
            msg.cantxignpa2d = (obj["cantxignpa2d"].is_string()?atoi(obj["cantxignpa2d"].get<std::string>().c_str()):obj["cantxignpa2d"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus55e4 from_json<ApollodriversEsrStatus55e4>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus55e4(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus55e4 &dt)
    {
        dt=from_json_ApollodriversEsrStatus55e4(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus55e4 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus55e4 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
