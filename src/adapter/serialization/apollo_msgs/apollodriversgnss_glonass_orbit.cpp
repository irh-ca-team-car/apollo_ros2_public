#include "adapter/serialization/apollo_msgs/apollodriversgnss_glonass_orbit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGlonassOrbit &msg) {
        nlohmann::json obj;
        obj["gnsstype"] = (msg.gnsstype);
        obj["slotprn"] = (msg.slotprn);
        obj["gnsstimetype"] = (msg.gnsstimetype);
        obj["toe"] = (msg.toe);
        obj["year"] = (msg.year);
        obj["month"] = (msg.month);
        obj["day"] = (msg.day);
        obj["hour"] = (msg.hour);
        obj["minute"] = (msg.minute);
        obj["seconds"] = (msg.seconds);
        obj["frequencyno"] = (msg.frequencyno);
        obj["weeknum"] = (msg.weeknum);
        obj["weekseconds"] = (msg.weekseconds);
        obj["tk"] = (msg.tk);
        obj["clockoffset"] = (msg.clockoffset);
        obj["clockdrift"] = (msg.clockdrift);
        obj["health"] = (msg.health);
        obj["positionx"] = (msg.positionx);
        obj["positiony"] = (msg.positiony);
        obj["positionz"] = (msg.positionz);
        obj["velocityx"] = (msg.velocityx);
        obj["velocityy"] = (msg.velocityy);
        obj["velocityz"] = (msg.velocityz);
        obj["acceleratex"] = (msg.acceleratex);
        obj["acceleratey"] = (msg.acceleratey);
        obj["acceleratez"] = (msg.acceleratez);
        obj["inforage"] = (msg.inforage);
        obj["satprn"] = (msg.satprn);
        return obj;
    }
    ApollodriversgnssGlonassOrbit from_json_ApollodriversgnssGlonassOrbit (nlohmann::json obj) {
        ApollodriversgnssGlonassOrbit msg;
        if(obj.contains("gnsstype"))
        {
            msg.gnsstype = (obj["gnsstype"].is_string()?atoi(obj["gnsstype"].get<std::string>().c_str()):obj["gnsstype"].get<int>());
        }
        if(obj.contains("slotprn"))
        {
            msg.slotprn = (obj["slotprn"].is_string()?atoi(obj["slotprn"].get<std::string>().c_str()):obj["slotprn"].get<uint32_t>());
        }
        if(obj.contains("gnsstimetype"))
        {
            msg.gnsstimetype = (obj["gnsstimetype"].is_string()?atoi(obj["gnsstimetype"].get<std::string>().c_str()):obj["gnsstimetype"].get<int>());
        }
        if(obj.contains("toe"))
        {
            msg.toe = (obj["toe"].is_string()?atof(obj["toe"].get<std::string>().c_str()):obj["toe"].get<double>());
        }
        if(obj.contains("year"))
        {
            msg.year = (obj["year"].is_string()?atoi(obj["year"].get<std::string>().c_str()):obj["year"].get<uint32_t>());
        }
        if(obj.contains("month"))
        {
            msg.month = (obj["month"].is_string()?atoi(obj["month"].get<std::string>().c_str()):obj["month"].get<uint32_t>());
        }
        if(obj.contains("day"))
        {
            msg.day = (obj["day"].is_string()?atoi(obj["day"].get<std::string>().c_str()):obj["day"].get<uint32_t>());
        }
        if(obj.contains("hour"))
        {
            msg.hour = (obj["hour"].is_string()?atoi(obj["hour"].get<std::string>().c_str()):obj["hour"].get<uint32_t>());
        }
        if(obj.contains("minute"))
        {
            msg.minute = (obj["minute"].is_string()?atoi(obj["minute"].get<std::string>().c_str()):obj["minute"].get<uint32_t>());
        }
        if(obj.contains("seconds"))
        {
            msg.seconds = (obj["seconds"].is_string()?atof(obj["seconds"].get<std::string>().c_str()):obj["seconds"].get<double>());
        }
        if(obj.contains("frequencyno"))
        {
            msg.frequencyno = (obj["frequencyno"].is_string()?atoi(obj["frequencyno"].get<std::string>().c_str()):obj["frequencyno"].get<int>());
        }
        if(obj.contains("weeknum"))
        {
            msg.weeknum = (obj["weeknum"].is_string()?atoi(obj["weeknum"].get<std::string>().c_str()):obj["weeknum"].get<uint32_t>());
        }
        if(obj.contains("weekseconds"))
        {
            msg.weekseconds = (obj["weekseconds"].is_string()?atof(obj["weekseconds"].get<std::string>().c_str()):obj["weekseconds"].get<double>());
        }
        if(obj.contains("tk"))
        {
            msg.tk = (obj["tk"].is_string()?atof(obj["tk"].get<std::string>().c_str()):obj["tk"].get<double>());
        }
        if(obj.contains("clockoffset"))
        {
            msg.clockoffset = (obj["clockoffset"].is_string()?atof(obj["clockoffset"].get<std::string>().c_str()):obj["clockoffset"].get<double>());
        }
        if(obj.contains("clockdrift"))
        {
            msg.clockdrift = (obj["clockdrift"].is_string()?atof(obj["clockdrift"].get<std::string>().c_str()):obj["clockdrift"].get<double>());
        }
        if(obj.contains("health"))
        {
            msg.health = (obj["health"].is_string()?atoi(obj["health"].get<std::string>().c_str()):obj["health"].get<uint32_t>());
        }
        if(obj.contains("positionx"))
        {
            msg.positionx = (obj["positionx"].is_string()?atof(obj["positionx"].get<std::string>().c_str()):obj["positionx"].get<double>());
        }
        if(obj.contains("positiony"))
        {
            msg.positiony = (obj["positiony"].is_string()?atof(obj["positiony"].get<std::string>().c_str()):obj["positiony"].get<double>());
        }
        if(obj.contains("positionz"))
        {
            msg.positionz = (obj["positionz"].is_string()?atof(obj["positionz"].get<std::string>().c_str()):obj["positionz"].get<double>());
        }
        if(obj.contains("velocityx"))
        {
            msg.velocityx = (obj["velocityx"].is_string()?atof(obj["velocityx"].get<std::string>().c_str()):obj["velocityx"].get<double>());
        }
        if(obj.contains("velocityy"))
        {
            msg.velocityy = (obj["velocityy"].is_string()?atof(obj["velocityy"].get<std::string>().c_str()):obj["velocityy"].get<double>());
        }
        if(obj.contains("velocityz"))
        {
            msg.velocityz = (obj["velocityz"].is_string()?atof(obj["velocityz"].get<std::string>().c_str()):obj["velocityz"].get<double>());
        }
        if(obj.contains("acceleratex"))
        {
            msg.acceleratex = (obj["acceleratex"].is_string()?atof(obj["acceleratex"].get<std::string>().c_str()):obj["acceleratex"].get<double>());
        }
        if(obj.contains("acceleratey"))
        {
            msg.acceleratey = (obj["acceleratey"].is_string()?atof(obj["acceleratey"].get<std::string>().c_str()):obj["acceleratey"].get<double>());
        }
        if(obj.contains("acceleratez"))
        {
            msg.acceleratez = (obj["acceleratez"].is_string()?atof(obj["acceleratez"].get<std::string>().c_str()):obj["acceleratez"].get<double>());
        }
        if(obj.contains("inforage"))
        {
            msg.inforage = (obj["inforage"].is_string()?atof(obj["inforage"].get<std::string>().c_str()):obj["inforage"].get<double>());
        }
        if(obj.contains("satprn"))
        {
            msg.satprn = (obj["satprn"].is_string()?atoi(obj["satprn"].get<std::string>().c_str()):obj["satprn"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssGlonassOrbit from_json<ApollodriversgnssGlonassOrbit>(nlohmann::json obj){
        return from_json_ApollodriversgnssGlonassOrbit(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGlonassOrbit &dt)
    {
        dt=from_json_ApollodriversgnssGlonassOrbit(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGlonassOrbit & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGlonassOrbit & dt)
    {
        os << to_json(dt);
        return os;
    }
}
