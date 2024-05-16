#include "adapter/serialization/apollo_msgs/apollocanbus_chassis_gps.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusChassisGPS &msg) {
        nlohmann::json obj;
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
    ApollocanbusChassisGPS from_json_ApollocanbusChassisGPS (nlohmann::json obj) {
        ApollocanbusChassisGPS msg;
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
    ApollocanbusChassisGPS from_json<ApollocanbusChassisGPS>(nlohmann::json obj){
        return from_json_ApollocanbusChassisGPS(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusChassisGPS &dt)
    {
        dt=from_json_ApollocanbusChassisGPS(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusChassisGPS & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusChassisGPS & dt)
    {
        os << to_json(dt);
        return os;
    }
}
