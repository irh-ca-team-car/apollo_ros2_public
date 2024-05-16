#include "adapter/serialization/apollo_msgs/apollodrivers_delphi_esr.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDelphiESR &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["esrstatus95e8"] = to_json(msg.esrstatus95e8);
        obj["esrstatus65e5"] = to_json(msg.esrstatus65e5);
        obj["esrstatus55e4"] = to_json(msg.esrstatus55e4);
        obj["esrstatus34e2"] = to_json(msg.esrstatus34e2);
        obj["esrstatus44e3"] = to_json(msg.esrstatus44e3);
        nlohmann::json arr_esrtrackmotionpower540;
        for (auto it = msg.esrtrackmotionpower540.begin(); it != msg.esrtrackmotionpower540.end(); ++it) {
            arr_esrtrackmotionpower540.push_back(to_json(*it));
        }
        obj["esrtrackmotionpower540"] = arr_esrtrackmotionpower540;
        obj["acminstreq7e0"] = to_json(msg.acminstreq7e0);
        nlohmann::json arr_esrtrack01500;
        for (auto it = msg.esrtrack01500.begin(); it != msg.esrtrack01500.end(); ++it) {
            arr_esrtrack01500.push_back(to_json(*it));
        }
        obj["esrtrack01500"] = arr_esrtrack01500;
        obj["esrvalid15d0"] = to_json(msg.esrvalid15d0);
        obj["esrvalid25d1"] = to_json(msg.esrvalid25d1);
        obj["acminstresp7e4"] = to_json(msg.acminstresp7e4);
        obj["vehicle24f1"] = to_json(msg.vehicle24f1);
        obj["vehicle14f0"] = to_json(msg.vehicle14f0);
        obj["esrsim15c0"] = to_json(msg.esrsim15c0);
        obj["esrstatus14e0"] = to_json(msg.esrstatus14e0);
        obj["esrstatus24e1"] = to_json(msg.esrstatus24e1);
        obj["esrstatus85e7"] = to_json(msg.esrstatus85e7);
        obj["esrstatus75e6"] = to_json(msg.esrstatus75e6);
        obj["vehicle35f2"] = to_json(msg.vehicle35f2);
        obj["vehicle45f3"] = to_json(msg.vehicle45f3);
        obj["vehicle55f4"] = to_json(msg.vehicle55f4);
        obj["vehicle65f5"] = to_json(msg.vehicle65f5);
        return obj;
    }
    ApollodriversDelphiESR from_json_ApollodriversDelphiESR (nlohmann::json obj) {
        ApollodriversDelphiESR msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("esrstatus95e8"))
        {
            msg.esrstatus95e8 = from_json_ApollodriversEsrStatus95e8(obj["esrstatus95e8"]);
        }
        if(obj.contains("esrstatus65e5"))
        {
            msg.esrstatus65e5 = from_json_ApollodriversEsrStatus65e5(obj["esrstatus65e5"]);
        }
        if(obj.contains("esrstatus55e4"))
        {
            msg.esrstatus55e4 = from_json_ApollodriversEsrStatus55e4(obj["esrstatus55e4"]);
        }
        if(obj.contains("esrstatus34e2"))
        {
            msg.esrstatus34e2 = from_json_ApollodriversEsrStatus34e2(obj["esrstatus34e2"]);
        }
        if(obj.contains("esrstatus44e3"))
        {
            msg.esrstatus44e3 = from_json_ApollodriversEsrStatus44e3(obj["esrstatus44e3"]);
        }
        if(obj.contains("esrtrackmotionpower540"))
        {
            if(obj["esrtrackmotionpower540"].is_array())
            {
                for (auto& element : obj["esrtrackmotionpower540"])
                {
                    msg.esrtrackmotionpower540.push_back(from_json_ApollodriversEsrTrackmotionpower540(element));
                }
            }
            else
            {
                msg.esrtrackmotionpower540.push_back(from_json_ApollodriversEsrTrackmotionpower540(obj["esrtrackmotionpower540"]));
            }
        }
        if(obj.contains("acminstreq7e0"))
        {
            msg.acminstreq7e0 = from_json_ApollodriversAcmInstReq7e0(obj["acminstreq7e0"]);
        }
        if(obj.contains("esrtrack01500"))
        {
            if(obj["esrtrack01500"].is_array())
            {
                for (auto& element : obj["esrtrack01500"])
                {
                    msg.esrtrack01500.push_back(from_json_ApollodriversEsrTrack01500(element));
                }
            }
            else
            {
                msg.esrtrack01500.push_back(from_json_ApollodriversEsrTrack01500(obj["esrtrack01500"]));
            }
        }
        if(obj.contains("esrvalid15d0"))
        {
            msg.esrvalid15d0 = from_json_ApollodriversEsrValid15d0(obj["esrvalid15d0"]);
        }
        if(obj.contains("esrvalid25d1"))
        {
            msg.esrvalid25d1 = from_json_ApollodriversEsrValid25d1(obj["esrvalid25d1"]);
        }
        if(obj.contains("acminstresp7e4"))
        {
            msg.acminstresp7e4 = from_json_ApollodriversAcmInstResp7e4(obj["acminstresp7e4"]);
        }
        if(obj.contains("vehicle24f1"))
        {
            msg.vehicle24f1 = from_json_ApollodriversVehicle24f1(obj["vehicle24f1"]);
        }
        if(obj.contains("vehicle14f0"))
        {
            msg.vehicle14f0 = from_json_ApollodriversVehicle14f0(obj["vehicle14f0"]);
        }
        if(obj.contains("esrsim15c0"))
        {
            msg.esrsim15c0 = from_json_ApollodriversEsrSim15c0(obj["esrsim15c0"]);
        }
        if(obj.contains("esrstatus14e0"))
        {
            msg.esrstatus14e0 = from_json_ApollodriversEsrStatus14e0(obj["esrstatus14e0"]);
        }
        if(obj.contains("esrstatus24e1"))
        {
            msg.esrstatus24e1 = from_json_ApollodriversEsrStatus24e1(obj["esrstatus24e1"]);
        }
        if(obj.contains("esrstatus85e7"))
        {
            msg.esrstatus85e7 = from_json_ApollodriversEsrStatus85e7(obj["esrstatus85e7"]);
        }
        if(obj.contains("esrstatus75e6"))
        {
            msg.esrstatus75e6 = from_json_ApollodriversEsrStatus75e6(obj["esrstatus75e6"]);
        }
        if(obj.contains("vehicle35f2"))
        {
            msg.vehicle35f2 = from_json_ApollodriversVehicle35f2(obj["vehicle35f2"]);
        }
        if(obj.contains("vehicle45f3"))
        {
            msg.vehicle45f3 = from_json_ApollodriversVehicle45f3(obj["vehicle45f3"]);
        }
        if(obj.contains("vehicle55f4"))
        {
            msg.vehicle55f4 = from_json_ApollodriversVehicle55f4(obj["vehicle55f4"]);
        }
        if(obj.contains("vehicle65f5"))
        {
            msg.vehicle65f5 = from_json_ApollodriversVehicle65f5(obj["vehicle65f5"]);
        }
        return msg;
    }
    template <>
    ApollodriversDelphiESR from_json<ApollodriversDelphiESR>(nlohmann::json obj){
        return from_json_ApollodriversDelphiESR(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDelphiESR &dt)
    {
        dt=from_json_ApollodriversDelphiESR(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversDelphiESR & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDelphiESR & dt)
    {
        os << to_json(dt);
        return os;
    }
}
