#include "adapter/serialization/apollo_msgs/apollocanbus_basic_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBasicInfo &msg) {
        nlohmann::json obj;
        obj["isautomode"] = (msg.isautomode);
        obj["powerstate"] = (msg.powerstate);
        obj["isairbagdeployed"] = (msg.isairbagdeployed);
        obj["odometer"] = (msg.odometer);
        obj["driverange"] = (msg.driverange);
        obj["issystemerror"] = (msg.issystemerror);
        obj["ishumaninterrupt"] = (msg.ishumaninterrupt);
        obj["acconbutton"] = (msg.acconbutton);
        obj["accoffbutton"] = (msg.accoffbutton);
        obj["accresbutton"] = (msg.accresbutton);
        obj["acccancelbutton"] = (msg.acccancelbutton);
        obj["acconoffbutton"] = (msg.acconoffbutton);
        obj["accrescancelbutton"] = (msg.accrescancelbutton);
        obj["accincspdbutton"] = (msg.accincspdbutton);
        obj["accdecspdbutton"] = (msg.accdecspdbutton);
        obj["accincgapbutton"] = (msg.accincgapbutton);
        obj["accdecgapbutton"] = (msg.accdecgapbutton);
        obj["lkabutton"] = (msg.lkabutton);
        obj["canbusfault"] = (msg.canbusfault);
        obj["latitude"] = (msg.latitude);
        obj["longitude"] = (msg.longitude);
        obj["gpsvalid"] = (msg.gpsvalid);
        obj["year"] = (msg.year);
        obj["month"] = (msg.month);
        obj["day"] = (msg.day);
        obj["hours"] = (msg.hours);
        obj["minutes"] = (msg.minutes);
        obj["seconds"] = (msg.seconds);
        obj["compassdirection"] = (msg.compassdirection);
        obj["pdop"] = (msg.pdop);
        obj["isgpsfault"] = (msg.isgpsfault);
        obj["isinferred"] = (msg.isinferred);
        obj["altitude"] = (msg.altitude);
        obj["heading"] = (msg.heading);
        obj["hdop"] = (msg.hdop);
        obj["vdop"] = (msg.vdop);
        obj["quality"] = (msg.quality);
        obj["numsatellites"] = (msg.numsatellites);
        obj["gpsspeed"] = (msg.gpsspeed);
        return obj;
    }
    ApollocanbusBasicInfo from_json_ApollocanbusBasicInfo (nlohmann::json obj) {
        ApollocanbusBasicInfo msg;
        if(obj.contains("isautomode"))
        {
            msg.isautomode = (obj["isautomode"].is_string()?(bool)atoi(obj["isautomode"].get<std::string>().c_str()):obj["isautomode"].get<bool>());
        }
        if(obj.contains("powerstate"))
        {
            msg.powerstate = (obj["powerstate"].is_string()?atoi(obj["powerstate"].get<std::string>().c_str()):obj["powerstate"].get<int>());
        }
        if(obj.contains("isairbagdeployed"))
        {
            msg.isairbagdeployed = (obj["isairbagdeployed"].is_string()?(bool)atoi(obj["isairbagdeployed"].get<std::string>().c_str()):obj["isairbagdeployed"].get<bool>());
        }
        if(obj.contains("odometer"))
        {
            msg.odometer = (obj["odometer"].is_string()?atof(obj["odometer"].get<std::string>().c_str()):obj["odometer"].get<double>());
        }
        if(obj.contains("driverange"))
        {
            msg.driverange = (obj["driverange"].is_string()?atof(obj["driverange"].get<std::string>().c_str()):obj["driverange"].get<double>());
        }
        if(obj.contains("issystemerror"))
        {
            msg.issystemerror = (obj["issystemerror"].is_string()?(bool)atoi(obj["issystemerror"].get<std::string>().c_str()):obj["issystemerror"].get<bool>());
        }
        if(obj.contains("ishumaninterrupt"))
        {
            msg.ishumaninterrupt = (obj["ishumaninterrupt"].is_string()?(bool)atoi(obj["ishumaninterrupt"].get<std::string>().c_str()):obj["ishumaninterrupt"].get<bool>());
        }
        if(obj.contains("acconbutton"))
        {
            msg.acconbutton = (obj["acconbutton"].is_string()?(bool)atoi(obj["acconbutton"].get<std::string>().c_str()):obj["acconbutton"].get<bool>());
        }
        if(obj.contains("accoffbutton"))
        {
            msg.accoffbutton = (obj["accoffbutton"].is_string()?(bool)atoi(obj["accoffbutton"].get<std::string>().c_str()):obj["accoffbutton"].get<bool>());
        }
        if(obj.contains("accresbutton"))
        {
            msg.accresbutton = (obj["accresbutton"].is_string()?(bool)atoi(obj["accresbutton"].get<std::string>().c_str()):obj["accresbutton"].get<bool>());
        }
        if(obj.contains("acccancelbutton"))
        {
            msg.acccancelbutton = (obj["acccancelbutton"].is_string()?(bool)atoi(obj["acccancelbutton"].get<std::string>().c_str()):obj["acccancelbutton"].get<bool>());
        }
        if(obj.contains("acconoffbutton"))
        {
            msg.acconoffbutton = (obj["acconoffbutton"].is_string()?(bool)atoi(obj["acconoffbutton"].get<std::string>().c_str()):obj["acconoffbutton"].get<bool>());
        }
        if(obj.contains("accrescancelbutton"))
        {
            msg.accrescancelbutton = (obj["accrescancelbutton"].is_string()?(bool)atoi(obj["accrescancelbutton"].get<std::string>().c_str()):obj["accrescancelbutton"].get<bool>());
        }
        if(obj.contains("accincspdbutton"))
        {
            msg.accincspdbutton = (obj["accincspdbutton"].is_string()?(bool)atoi(obj["accincspdbutton"].get<std::string>().c_str()):obj["accincspdbutton"].get<bool>());
        }
        if(obj.contains("accdecspdbutton"))
        {
            msg.accdecspdbutton = (obj["accdecspdbutton"].is_string()?(bool)atoi(obj["accdecspdbutton"].get<std::string>().c_str()):obj["accdecspdbutton"].get<bool>());
        }
        if(obj.contains("accincgapbutton"))
        {
            msg.accincgapbutton = (obj["accincgapbutton"].is_string()?(bool)atoi(obj["accincgapbutton"].get<std::string>().c_str()):obj["accincgapbutton"].get<bool>());
        }
        if(obj.contains("accdecgapbutton"))
        {
            msg.accdecgapbutton = (obj["accdecgapbutton"].is_string()?(bool)atoi(obj["accdecgapbutton"].get<std::string>().c_str()):obj["accdecgapbutton"].get<bool>());
        }
        if(obj.contains("lkabutton"))
        {
            msg.lkabutton = (obj["lkabutton"].is_string()?(bool)atoi(obj["lkabutton"].get<std::string>().c_str()):obj["lkabutton"].get<bool>());
        }
        if(obj.contains("canbusfault"))
        {
            msg.canbusfault = (obj["canbusfault"].is_string()?(bool)atoi(obj["canbusfault"].get<std::string>().c_str()):obj["canbusfault"].get<bool>());
        }
        if(obj.contains("latitude"))
        {
            msg.latitude = (obj["latitude"].is_string()?atof(obj["latitude"].get<std::string>().c_str()):obj["latitude"].get<double>());
        }
        if(obj.contains("longitude"))
        {
            msg.longitude = (obj["longitude"].is_string()?atof(obj["longitude"].get<std::string>().c_str()):obj["longitude"].get<double>());
        }
        if(obj.contains("gpsvalid"))
        {
            msg.gpsvalid = (obj["gpsvalid"].is_string()?(bool)atoi(obj["gpsvalid"].get<std::string>().c_str()):obj["gpsvalid"].get<bool>());
        }
        if(obj.contains("year"))
        {
            msg.year = (obj["year"].is_string()?atoi(obj["year"].get<std::string>().c_str()):obj["year"].get<int>());
        }
        if(obj.contains("month"))
        {
            msg.month = (obj["month"].is_string()?atoi(obj["month"].get<std::string>().c_str()):obj["month"].get<int>());
        }
        if(obj.contains("day"))
        {
            msg.day = (obj["day"].is_string()?atoi(obj["day"].get<std::string>().c_str()):obj["day"].get<int>());
        }
        if(obj.contains("hours"))
        {
            msg.hours = (obj["hours"].is_string()?atoi(obj["hours"].get<std::string>().c_str()):obj["hours"].get<int>());
        }
        if(obj.contains("minutes"))
        {
            msg.minutes = (obj["minutes"].is_string()?atoi(obj["minutes"].get<std::string>().c_str()):obj["minutes"].get<int>());
        }
        if(obj.contains("seconds"))
        {
            msg.seconds = (obj["seconds"].is_string()?atoi(obj["seconds"].get<std::string>().c_str()):obj["seconds"].get<int>());
        }
        if(obj.contains("compassdirection"))
        {
            msg.compassdirection = (obj["compassdirection"].is_string()?atof(obj["compassdirection"].get<std::string>().c_str()):obj["compassdirection"].get<double>());
        }
        if(obj.contains("pdop"))
        {
            msg.pdop = (obj["pdop"].is_string()?atof(obj["pdop"].get<std::string>().c_str()):obj["pdop"].get<double>());
        }
        if(obj.contains("isgpsfault"))
        {
            msg.isgpsfault = (obj["isgpsfault"].is_string()?(bool)atoi(obj["isgpsfault"].get<std::string>().c_str()):obj["isgpsfault"].get<bool>());
        }
        if(obj.contains("isinferred"))
        {
            msg.isinferred = (obj["isinferred"].is_string()?(bool)atoi(obj["isinferred"].get<std::string>().c_str()):obj["isinferred"].get<bool>());
        }
        if(obj.contains("altitude"))
        {
            msg.altitude = (obj["altitude"].is_string()?atof(obj["altitude"].get<std::string>().c_str()):obj["altitude"].get<double>());
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("hdop"))
        {
            msg.hdop = (obj["hdop"].is_string()?atof(obj["hdop"].get<std::string>().c_str()):obj["hdop"].get<double>());
        }
        if(obj.contains("vdop"))
        {
            msg.vdop = (obj["vdop"].is_string()?atof(obj["vdop"].get<std::string>().c_str()):obj["vdop"].get<double>());
        }
        if(obj.contains("quality"))
        {
            msg.quality = (obj["quality"].is_string()?atoi(obj["quality"].get<std::string>().c_str()):obj["quality"].get<int>());
        }
        if(obj.contains("numsatellites"))
        {
            msg.numsatellites = (obj["numsatellites"].is_string()?atoi(obj["numsatellites"].get<std::string>().c_str()):obj["numsatellites"].get<int>());
        }
        if(obj.contains("gpsspeed"))
        {
            msg.gpsspeed = (obj["gpsspeed"].is_string()?atof(obj["gpsspeed"].get<std::string>().c_str()):obj["gpsspeed"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusBasicInfo from_json<ApollocanbusBasicInfo>(nlohmann::json obj){
        return from_json_ApollocanbusBasicInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBasicInfo &dt)
    {
        dt=from_json_ApollocanbusBasicInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBasicInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBasicInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
