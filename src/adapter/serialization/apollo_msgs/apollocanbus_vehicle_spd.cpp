#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_spd.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleSpd &msg) {
        nlohmann::json obj;
        obj["isvehiclestandstill"] = (msg.isvehiclestandstill);
        obj["isvehiclespdvalid"] = (msg.isvehiclespdvalid);
        obj["vehiclespd"] = (msg.vehiclespd);
        obj["iswheelspdrrvalid"] = (msg.iswheelspdrrvalid);
        obj["wheeldirectionrr"] = (msg.wheeldirectionrr);
        obj["wheelspdrr"] = (msg.wheelspdrr);
        obj["iswheelspdrlvalid"] = (msg.iswheelspdrlvalid);
        obj["wheeldirectionrl"] = (msg.wheeldirectionrl);
        obj["wheelspdrl"] = (msg.wheelspdrl);
        obj["iswheelspdfrvalid"] = (msg.iswheelspdfrvalid);
        obj["wheeldirectionfr"] = (msg.wheeldirectionfr);
        obj["wheelspdfr"] = (msg.wheelspdfr);
        obj["iswheelspdflvalid"] = (msg.iswheelspdflvalid);
        obj["wheeldirectionfl"] = (msg.wheeldirectionfl);
        obj["wheelspdfl"] = (msg.wheelspdfl);
        obj["isyawratevalid"] = (msg.isyawratevalid);
        obj["yawrate"] = (msg.yawrate);
        obj["yawrateoffset"] = (msg.yawrateoffset);
        obj["isaxvalid"] = (msg.isaxvalid);
        obj["ax"] = (msg.ax);
        obj["axoffset"] = (msg.axoffset);
        obj["isayvalid"] = (msg.isayvalid);
        obj["ay"] = (msg.ay);
        obj["ayoffset"] = (msg.ayoffset);
        obj["latacc"] = (msg.latacc);
        obj["longacc"] = (msg.longacc);
        obj["vertacc"] = (msg.vertacc);
        obj["rollrate"] = (msg.rollrate);
        obj["accest"] = (msg.accest);
        obj["timestampsec"] = (msg.timestampsec);
        return obj;
    }
    ApollocanbusVehicleSpd from_json_ApollocanbusVehicleSpd (nlohmann::json obj) {
        ApollocanbusVehicleSpd msg;
        if(obj.contains("isvehiclestandstill"))
        {
            msg.isvehiclestandstill = (obj["isvehiclestandstill"].is_string()?(bool)atoi(obj["isvehiclestandstill"].get<std::string>().c_str()):obj["isvehiclestandstill"].get<bool>());
        }
        if(obj.contains("isvehiclespdvalid"))
        {
            msg.isvehiclespdvalid = (obj["isvehiclespdvalid"].is_string()?(bool)atoi(obj["isvehiclespdvalid"].get<std::string>().c_str()):obj["isvehiclespdvalid"].get<bool>());
        }
        if(obj.contains("vehiclespd"))
        {
            msg.vehiclespd = (obj["vehiclespd"].is_string()?atof(obj["vehiclespd"].get<std::string>().c_str()):obj["vehiclespd"].get<double>());
        }
        if(obj.contains("iswheelspdrrvalid"))
        {
            msg.iswheelspdrrvalid = (obj["iswheelspdrrvalid"].is_string()?(bool)atoi(obj["iswheelspdrrvalid"].get<std::string>().c_str()):obj["iswheelspdrrvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionrr"))
        {
            msg.wheeldirectionrr = (obj["wheeldirectionrr"].is_string()?atoi(obj["wheeldirectionrr"].get<std::string>().c_str()):obj["wheeldirectionrr"].get<int>());
        }
        if(obj.contains("wheelspdrr"))
        {
            msg.wheelspdrr = (obj["wheelspdrr"].is_string()?atof(obj["wheelspdrr"].get<std::string>().c_str()):obj["wheelspdrr"].get<double>());
        }
        if(obj.contains("iswheelspdrlvalid"))
        {
            msg.iswheelspdrlvalid = (obj["iswheelspdrlvalid"].is_string()?(bool)atoi(obj["iswheelspdrlvalid"].get<std::string>().c_str()):obj["iswheelspdrlvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionrl"))
        {
            msg.wheeldirectionrl = (obj["wheeldirectionrl"].is_string()?atoi(obj["wheeldirectionrl"].get<std::string>().c_str()):obj["wheeldirectionrl"].get<int>());
        }
        if(obj.contains("wheelspdrl"))
        {
            msg.wheelspdrl = (obj["wheelspdrl"].is_string()?atof(obj["wheelspdrl"].get<std::string>().c_str()):obj["wheelspdrl"].get<double>());
        }
        if(obj.contains("iswheelspdfrvalid"))
        {
            msg.iswheelspdfrvalid = (obj["iswheelspdfrvalid"].is_string()?(bool)atoi(obj["iswheelspdfrvalid"].get<std::string>().c_str()):obj["iswheelspdfrvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionfr"))
        {
            msg.wheeldirectionfr = (obj["wheeldirectionfr"].is_string()?atoi(obj["wheeldirectionfr"].get<std::string>().c_str()):obj["wheeldirectionfr"].get<int>());
        }
        if(obj.contains("wheelspdfr"))
        {
            msg.wheelspdfr = (obj["wheelspdfr"].is_string()?atof(obj["wheelspdfr"].get<std::string>().c_str()):obj["wheelspdfr"].get<double>());
        }
        if(obj.contains("iswheelspdflvalid"))
        {
            msg.iswheelspdflvalid = (obj["iswheelspdflvalid"].is_string()?(bool)atoi(obj["iswheelspdflvalid"].get<std::string>().c_str()):obj["iswheelspdflvalid"].get<bool>());
        }
        if(obj.contains("wheeldirectionfl"))
        {
            msg.wheeldirectionfl = (obj["wheeldirectionfl"].is_string()?atoi(obj["wheeldirectionfl"].get<std::string>().c_str()):obj["wheeldirectionfl"].get<int>());
        }
        if(obj.contains("wheelspdfl"))
        {
            msg.wheelspdfl = (obj["wheelspdfl"].is_string()?atof(obj["wheelspdfl"].get<std::string>().c_str()):obj["wheelspdfl"].get<double>());
        }
        if(obj.contains("isyawratevalid"))
        {
            msg.isyawratevalid = (obj["isyawratevalid"].is_string()?(bool)atoi(obj["isyawratevalid"].get<std::string>().c_str()):obj["isyawratevalid"].get<bool>());
        }
        if(obj.contains("yawrate"))
        {
            msg.yawrate = (obj["yawrate"].is_string()?atof(obj["yawrate"].get<std::string>().c_str()):obj["yawrate"].get<double>());
        }
        if(obj.contains("yawrateoffset"))
        {
            msg.yawrateoffset = (obj["yawrateoffset"].is_string()?atof(obj["yawrateoffset"].get<std::string>().c_str()):obj["yawrateoffset"].get<double>());
        }
        if(obj.contains("isaxvalid"))
        {
            msg.isaxvalid = (obj["isaxvalid"].is_string()?(bool)atoi(obj["isaxvalid"].get<std::string>().c_str()):obj["isaxvalid"].get<bool>());
        }
        if(obj.contains("ax"))
        {
            msg.ax = (obj["ax"].is_string()?atof(obj["ax"].get<std::string>().c_str()):obj["ax"].get<double>());
        }
        if(obj.contains("axoffset"))
        {
            msg.axoffset = (obj["axoffset"].is_string()?atof(obj["axoffset"].get<std::string>().c_str()):obj["axoffset"].get<double>());
        }
        if(obj.contains("isayvalid"))
        {
            msg.isayvalid = (obj["isayvalid"].is_string()?(bool)atoi(obj["isayvalid"].get<std::string>().c_str()):obj["isayvalid"].get<bool>());
        }
        if(obj.contains("ay"))
        {
            msg.ay = (obj["ay"].is_string()?atof(obj["ay"].get<std::string>().c_str()):obj["ay"].get<double>());
        }
        if(obj.contains("ayoffset"))
        {
            msg.ayoffset = (obj["ayoffset"].is_string()?atof(obj["ayoffset"].get<std::string>().c_str()):obj["ayoffset"].get<double>());
        }
        if(obj.contains("latacc"))
        {
            msg.latacc = (obj["latacc"].is_string()?atof(obj["latacc"].get<std::string>().c_str()):obj["latacc"].get<double>());
        }
        if(obj.contains("longacc"))
        {
            msg.longacc = (obj["longacc"].is_string()?atof(obj["longacc"].get<std::string>().c_str()):obj["longacc"].get<double>());
        }
        if(obj.contains("vertacc"))
        {
            msg.vertacc = (obj["vertacc"].is_string()?atof(obj["vertacc"].get<std::string>().c_str()):obj["vertacc"].get<double>());
        }
        if(obj.contains("rollrate"))
        {
            msg.rollrate = (obj["rollrate"].is_string()?atof(obj["rollrate"].get<std::string>().c_str()):obj["rollrate"].get<double>());
        }
        if(obj.contains("accest"))
        {
            msg.accest = (obj["accest"].is_string()?atof(obj["accest"].get<std::string>().c_str()):obj["accest"].get<double>());
        }
        if(obj.contains("timestampsec"))
        {
            msg.timestampsec = (obj["timestampsec"].is_string()?atof(obj["timestampsec"].get<std::string>().c_str()):obj["timestampsec"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehicleSpd from_json<ApollocanbusVehicleSpd>(nlohmann::json obj){
        return from_json_ApollocanbusVehicleSpd(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleSpd &dt)
    {
        dt=from_json_ApollocanbusVehicleSpd(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleSpd & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleSpd & dt)
    {
        os << to_json(dt);
        return os;
    }
}
