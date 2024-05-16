#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle35f2.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle35f2 &msg) {
        nlohmann::json obj;
        obj["canrxservalignupdatesneed"] = (msg.canrxservalignupdatesneed);
        obj["canrxservaligntype"] = (msg.canrxservaligntype);
        obj["canrxservalignenable"] = (msg.canrxservalignenable);
        obj["canrxaalignavgctrtotal"] = (msg.canrxaalignavgctrtotal);
        obj["canrxautoalignconverged"] = (msg.canrxautoalignconverged);
        obj["canrxautoaligndisable"] = (msg.canrxautoaligndisable);
        obj["canrxanglemountingoffset"] = (msg.canrxanglemountingoffset);
        obj["canrxwheelslip"] = (msg.canrxwheelslip);
        obj["canrxradarheight"] = (msg.canrxradarheight);
        obj["canrxradarfovmr"] = (msg.canrxradarfovmr);
        obj["canrxradarfovlr"] = (msg.canrxradarfovlr);
        obj["canrxlongaccelvalidity"] = (msg.canrxlongaccelvalidity);
        obj["canrxlongaccel"] = (msg.canrxlongaccel);
        obj["canrxlataccelvalidity"] = (msg.canrxlataccelvalidity);
        obj["canrxlataccel"] = (msg.canrxlataccel);
        return obj;
    }
    ApollodriversVehicle35f2 from_json_ApollodriversVehicle35f2 (nlohmann::json obj) {
        ApollodriversVehicle35f2 msg;
        if(obj.contains("canrxservalignupdatesneed"))
        {
            msg.canrxservalignupdatesneed = (obj["canrxservalignupdatesneed"].is_string()?atoi(obj["canrxservalignupdatesneed"].get<std::string>().c_str()):obj["canrxservalignupdatesneed"].get<int>());
        }
        if(obj.contains("canrxservaligntype"))
        {
            msg.canrxservaligntype = (obj["canrxservaligntype"].is_string()?atoi(obj["canrxservaligntype"].get<std::string>().c_str()):obj["canrxservaligntype"].get<int>());
        }
        if(obj.contains("canrxservalignenable"))
        {
            msg.canrxservalignenable = (obj["canrxservalignenable"].is_string()?atoi(obj["canrxservalignenable"].get<std::string>().c_str()):obj["canrxservalignenable"].get<int>());
        }
        if(obj.contains("canrxaalignavgctrtotal"))
        {
            msg.canrxaalignavgctrtotal = (obj["canrxaalignavgctrtotal"].is_string()?atof(obj["canrxaalignavgctrtotal"].get<std::string>().c_str()):obj["canrxaalignavgctrtotal"].get<double>());
        }
        if(obj.contains("canrxautoalignconverged"))
        {
            msg.canrxautoalignconverged = (obj["canrxautoalignconverged"].is_string()?atoi(obj["canrxautoalignconverged"].get<std::string>().c_str()):obj["canrxautoalignconverged"].get<int>());
        }
        if(obj.contains("canrxautoaligndisable"))
        {
            msg.canrxautoaligndisable = (obj["canrxautoaligndisable"].is_string()?atoi(obj["canrxautoaligndisable"].get<std::string>().c_str()):obj["canrxautoaligndisable"].get<int>());
        }
        if(obj.contains("canrxanglemountingoffset"))
        {
            msg.canrxanglemountingoffset = (obj["canrxanglemountingoffset"].is_string()?atof(obj["canrxanglemountingoffset"].get<std::string>().c_str()):obj["canrxanglemountingoffset"].get<double>());
        }
        if(obj.contains("canrxwheelslip"))
        {
            msg.canrxwheelslip = (obj["canrxwheelslip"].is_string()?atoi(obj["canrxwheelslip"].get<std::string>().c_str()):obj["canrxwheelslip"].get<int>());
        }
        if(obj.contains("canrxradarheight"))
        {
            msg.canrxradarheight = (obj["canrxradarheight"].is_string()?atoi(obj["canrxradarheight"].get<std::string>().c_str()):obj["canrxradarheight"].get<int>());
        }
        if(obj.contains("canrxradarfovmr"))
        {
            msg.canrxradarfovmr = (obj["canrxradarfovmr"].is_string()?atoi(obj["canrxradarfovmr"].get<std::string>().c_str()):obj["canrxradarfovmr"].get<int>());
        }
        if(obj.contains("canrxradarfovlr"))
        {
            msg.canrxradarfovlr = (obj["canrxradarfovlr"].is_string()?atoi(obj["canrxradarfovlr"].get<std::string>().c_str()):obj["canrxradarfovlr"].get<int>());
        }
        if(obj.contains("canrxlongaccelvalidity"))
        {
            msg.canrxlongaccelvalidity = (obj["canrxlongaccelvalidity"].is_string()?atoi(obj["canrxlongaccelvalidity"].get<std::string>().c_str()):obj["canrxlongaccelvalidity"].get<int>());
        }
        if(obj.contains("canrxlongaccel"))
        {
            msg.canrxlongaccel = (obj["canrxlongaccel"].is_string()?atof(obj["canrxlongaccel"].get<std::string>().c_str()):obj["canrxlongaccel"].get<double>());
        }
        if(obj.contains("canrxlataccelvalidity"))
        {
            msg.canrxlataccelvalidity = (obj["canrxlataccelvalidity"].is_string()?atoi(obj["canrxlataccelvalidity"].get<std::string>().c_str()):obj["canrxlataccelvalidity"].get<int>());
        }
        if(obj.contains("canrxlataccel"))
        {
            msg.canrxlataccel = (obj["canrxlataccel"].is_string()?atof(obj["canrxlataccel"].get<std::string>().c_str()):obj["canrxlataccel"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversVehicle35f2 from_json<ApollodriversVehicle35f2>(nlohmann::json obj){
        return from_json_ApollodriversVehicle35f2(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle35f2 &dt)
    {
        dt=from_json_ApollodriversVehicle35f2(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle35f2 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle35f2 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
