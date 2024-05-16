#include "adapter/serialization/apollo_msgs/apollocanbus_chassis_detail.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusChassisDetail &msg) {
        nlohmann::json obj;
        obj["cartype"] = (msg.cartype);
        obj["basic"] = to_json(msg.basic);
        obj["safety"] = to_json(msg.safety);
        obj["gear"] = to_json(msg.gear);
        obj["ems"] = to_json(msg.ems);
        obj["esp"] = to_json(msg.esp);
        obj["gas"] = to_json(msg.gas);
        obj["epb"] = to_json(msg.epb);
        obj["brake"] = to_json(msg.brake);
        obj["deceleration"] = to_json(msg.deceleration);
        obj["vehiclespd"] = to_json(msg.vehiclespd);
        obj["eps"] = to_json(msg.eps);
        obj["light"] = to_json(msg.light);
        obj["battery"] = to_json(msg.battery);
        obj["checkresponse"] = to_json(msg.checkresponse);
        obj["license"] = to_json(msg.license);
        obj["surround"] = to_json(msg.surround);
        obj["gem"] = to_json(msg.gem);
        obj["lexus"] = to_json(msg.lexus);
        obj["transit"] = to_json(msg.transit);
        obj["ge3"] = to_json(msg.ge3);
        obj["wey"] = to_json(msg.wey);
        obj["zhongyun"] = to_json(msg.zhongyun);
        obj["ch"] = to_json(msg.ch);
        obj["devkit"] = to_json(msg.devkit);
        obj["neolixedu"] = to_json(msg.neolixedu);
        obj["vehicleid"] = to_json(msg.vehicleid);
        return obj;
    }
    ApollocanbusChassisDetail from_json_ApollocanbusChassisDetail (nlohmann::json obj) {
        ApollocanbusChassisDetail msg;
        if(obj.contains("cartype"))
        {
            msg.cartype = (obj["cartype"].is_string()?atoi(obj["cartype"].get<std::string>().c_str()):obj["cartype"].get<int>());
        }
        if(obj.contains("basic"))
        {
            msg.basic = from_json_ApollocanbusBasicInfo(obj["basic"]);
        }
        if(obj.contains("safety"))
        {
            msg.safety = from_json_ApollocanbusSafety(obj["safety"]);
        }
        if(obj.contains("gear"))
        {
            msg.gear = from_json_ApollocanbusGear(obj["gear"]);
        }
        if(obj.contains("ems"))
        {
            msg.ems = from_json_ApollocanbusEms(obj["ems"]);
        }
        if(obj.contains("esp"))
        {
            msg.esp = from_json_ApollocanbusEsp(obj["esp"]);
        }
        if(obj.contains("gas"))
        {
            msg.gas = from_json_ApollocanbusGas(obj["gas"]);
        }
        if(obj.contains("epb"))
        {
            msg.epb = from_json_ApollocanbusEpb(obj["epb"]);
        }
        if(obj.contains("brake"))
        {
            msg.brake = from_json_ApollocanbusBrake(obj["brake"]);
        }
        if(obj.contains("deceleration"))
        {
            msg.deceleration = from_json_ApollocanbusDeceleration(obj["deceleration"]);
        }
        if(obj.contains("vehiclespd"))
        {
            msg.vehiclespd = from_json_ApollocanbusVehicleSpd(obj["vehiclespd"]);
        }
        if(obj.contains("eps"))
        {
            msg.eps = from_json_ApollocanbusEps(obj["eps"]);
        }
        if(obj.contains("light"))
        {
            msg.light = from_json_ApollocanbusLight(obj["light"]);
        }
        if(obj.contains("battery"))
        {
            msg.battery = from_json_ApollocanbusBattery(obj["battery"]);
        }
        if(obj.contains("checkresponse"))
        {
            msg.checkresponse = from_json_ApollocanbusCheckResponseSignal(obj["checkresponse"]);
        }
        if(obj.contains("license"))
        {
            msg.license = from_json_ApollocanbusLicense(obj["license"]);
        }
        if(obj.contains("surround"))
        {
            msg.surround = from_json_ApollocanbusSurround(obj["surround"]);
        }
        if(obj.contains("gem"))
        {
            msg.gem = from_json_ApollocanbusGem(obj["gem"]);
        }
        if(obj.contains("lexus"))
        {
            msg.lexus = from_json_ApollocanbusLexus(obj["lexus"]);
        }
        if(obj.contains("transit"))
        {
            msg.transit = from_json_ApollocanbusTransit(obj["transit"]);
        }
        if(obj.contains("ge3"))
        {
            msg.ge3 = from_json_ApollocanbusGe3(obj["ge3"]);
        }
        if(obj.contains("wey"))
        {
            msg.wey = from_json_ApollocanbusWey(obj["wey"]);
        }
        if(obj.contains("zhongyun"))
        {
            msg.zhongyun = from_json_ApollocanbusZhongyun(obj["zhongyun"]);
        }
        if(obj.contains("ch"))
        {
            msg.ch = from_json_ApollocanbusCh(obj["ch"]);
        }
        if(obj.contains("devkit"))
        {
            msg.devkit = from_json_ApollocanbusDevkit(obj["devkit"]);
        }
        if(obj.contains("neolixedu"))
        {
            msg.neolixedu = from_json_ApollocanbusNeolixEdu(obj["neolixedu"]);
        }
        if(obj.contains("vehicleid"))
        {
            msg.vehicleid = from_json_ApollocommonVehicleID(obj["vehicleid"]);
        }
        return msg;
    }
    template <>
    ApollocanbusChassisDetail from_json<ApollocanbusChassisDetail>(nlohmann::json obj){
        return from_json_ApollocanbusChassisDetail(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusChassisDetail &dt)
    {
        dt=from_json_ApollocanbusChassisDetail(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusChassisDetail & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusChassisDetail & dt)
    {
        os << to_json(dt);
        return os;
    }
}
