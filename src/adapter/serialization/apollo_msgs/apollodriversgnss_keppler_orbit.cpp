#include "adapter/serialization/apollo_msgs/apollodriversgnss_keppler_orbit.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssKepplerOrbit &msg) {
        nlohmann::json obj;
        obj["gnsstype"] = (msg.gnsstype);
        obj["satprn"] = (msg.satprn);
        obj["gnsstimetype"] = (msg.gnsstimetype);
        obj["year"] = (msg.year);
        obj["month"] = (msg.month);
        obj["day"] = (msg.day);
        obj["hour"] = (msg.hour);
        obj["minute"] = (msg.minute);
        obj["seconds"] = (msg.seconds);
        obj["weeknum"] = (msg.weeknum);
        obj["reserved"] = (msg.reserved);
        obj["af0"] = (msg.af0);
        obj["af1"] = (msg.af1);
        obj["af2"] = (msg.af2);
        obj["iode"] = (msg.iode);
        obj["deltan"] = (msg.deltan);
        obj["m0"] = (msg.m0);
        obj["e"] = (msg.e);
        obj["roota"] = (msg.roota);
        obj["toe"] = (msg.toe);
        obj["toc"] = (msg.toc);
        obj["cic"] = (msg.cic);
        obj["crc"] = (msg.crc);
        obj["cis"] = (msg.cis);
        obj["crs"] = (msg.crs);
        obj["cuc"] = (msg.cuc);
        obj["cus"] = (msg.cus);
        obj["omega0"] = (msg.omega0);
        obj["omega"] = (msg.omega);
        obj["i0"] = (msg.i0);
        obj["omegadot"] = (msg.omegadot);
        obj["idot"] = (msg.idot);
        obj["codesonl2channel"] = (msg.codesonl2channel);
        obj["l2pdataflag"] = (msg.l2pdataflag);
        obj["accuracy"] = (msg.accuracy);
        obj["health"] = (msg.health);
        obj["tgd"] = (msg.tgd);
        obj["iodc"] = (msg.iodc);
        return obj;
    }
    ApollodriversgnssKepplerOrbit from_json_ApollodriversgnssKepplerOrbit (nlohmann::json obj) {
        ApollodriversgnssKepplerOrbit msg;
        if(obj.contains("gnsstype"))
        {
            msg.gnsstype = (obj["gnsstype"].is_string()?atoi(obj["gnsstype"].get<std::string>().c_str()):obj["gnsstype"].get<int>());
        }
        if(obj.contains("satprn"))
        {
            msg.satprn = (obj["satprn"].is_string()?atoi(obj["satprn"].get<std::string>().c_str()):obj["satprn"].get<uint32_t>());
        }
        if(obj.contains("gnsstimetype"))
        {
            msg.gnsstimetype = (obj["gnsstimetype"].is_string()?atoi(obj["gnsstimetype"].get<std::string>().c_str()):obj["gnsstimetype"].get<int>());
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
        if(obj.contains("weeknum"))
        {
            msg.weeknum = (obj["weeknum"].is_string()?atoi(obj["weeknum"].get<std::string>().c_str()):obj["weeknum"].get<uint32_t>());
        }
        if(obj.contains("reserved"))
        {
            msg.reserved = (obj["reserved"].is_string()?atof(obj["reserved"].get<std::string>().c_str()):obj["reserved"].get<double>());
        }
        if(obj.contains("af0"))
        {
            msg.af0 = (obj["af0"].is_string()?atof(obj["af0"].get<std::string>().c_str()):obj["af0"].get<double>());
        }
        if(obj.contains("af1"))
        {
            msg.af1 = (obj["af1"].is_string()?atof(obj["af1"].get<std::string>().c_str()):obj["af1"].get<double>());
        }
        if(obj.contains("af2"))
        {
            msg.af2 = (obj["af2"].is_string()?atof(obj["af2"].get<std::string>().c_str()):obj["af2"].get<double>());
        }
        if(obj.contains("iode"))
        {
            msg.iode = (obj["iode"].is_string()?atof(obj["iode"].get<std::string>().c_str()):obj["iode"].get<double>());
        }
        if(obj.contains("deltan"))
        {
            msg.deltan = (obj["deltan"].is_string()?atof(obj["deltan"].get<std::string>().c_str()):obj["deltan"].get<double>());
        }
        if(obj.contains("m0"))
        {
            msg.m0 = (obj["m0"].is_string()?atof(obj["m0"].get<std::string>().c_str()):obj["m0"].get<double>());
        }
        if(obj.contains("e"))
        {
            msg.e = (obj["e"].is_string()?atof(obj["e"].get<std::string>().c_str()):obj["e"].get<double>());
        }
        if(obj.contains("roota"))
        {
            msg.roota = (obj["roota"].is_string()?atof(obj["roota"].get<std::string>().c_str()):obj["roota"].get<double>());
        }
        if(obj.contains("toe"))
        {
            msg.toe = (obj["toe"].is_string()?atof(obj["toe"].get<std::string>().c_str()):obj["toe"].get<double>());
        }
        if(obj.contains("toc"))
        {
            msg.toc = (obj["toc"].is_string()?atof(obj["toc"].get<std::string>().c_str()):obj["toc"].get<double>());
        }
        if(obj.contains("cic"))
        {
            msg.cic = (obj["cic"].is_string()?atof(obj["cic"].get<std::string>().c_str()):obj["cic"].get<double>());
        }
        if(obj.contains("crc"))
        {
            msg.crc = (obj["crc"].is_string()?atof(obj["crc"].get<std::string>().c_str()):obj["crc"].get<double>());
        }
        if(obj.contains("cis"))
        {
            msg.cis = (obj["cis"].is_string()?atof(obj["cis"].get<std::string>().c_str()):obj["cis"].get<double>());
        }
        if(obj.contains("crs"))
        {
            msg.crs = (obj["crs"].is_string()?atof(obj["crs"].get<std::string>().c_str()):obj["crs"].get<double>());
        }
        if(obj.contains("cuc"))
        {
            msg.cuc = (obj["cuc"].is_string()?atof(obj["cuc"].get<std::string>().c_str()):obj["cuc"].get<double>());
        }
        if(obj.contains("cus"))
        {
            msg.cus = (obj["cus"].is_string()?atof(obj["cus"].get<std::string>().c_str()):obj["cus"].get<double>());
        }
        if(obj.contains("omega0"))
        {
            msg.omega0 = (obj["omega0"].is_string()?atof(obj["omega0"].get<std::string>().c_str()):obj["omega0"].get<double>());
        }
        if(obj.contains("omega"))
        {
            msg.omega = (obj["omega"].is_string()?atof(obj["omega"].get<std::string>().c_str()):obj["omega"].get<double>());
        }
        if(obj.contains("i0"))
        {
            msg.i0 = (obj["i0"].is_string()?atof(obj["i0"].get<std::string>().c_str()):obj["i0"].get<double>());
        }
        if(obj.contains("omegadot"))
        {
            msg.omegadot = (obj["omegadot"].is_string()?atof(obj["omegadot"].get<std::string>().c_str()):obj["omegadot"].get<double>());
        }
        if(obj.contains("idot"))
        {
            msg.idot = (obj["idot"].is_string()?atof(obj["idot"].get<std::string>().c_str()):obj["idot"].get<double>());
        }
        if(obj.contains("codesonl2channel"))
        {
            msg.codesonl2channel = (obj["codesonl2channel"].is_string()?atof(obj["codesonl2channel"].get<std::string>().c_str()):obj["codesonl2channel"].get<double>());
        }
        if(obj.contains("l2pdataflag"))
        {
            msg.l2pdataflag = (obj["l2pdataflag"].is_string()?atoi(obj["l2pdataflag"].get<std::string>().c_str()):obj["l2pdataflag"].get<uint32_t>());
        }
        if(obj.contains("accuracy"))
        {
            msg.accuracy = (obj["accuracy"].is_string()?atoi(obj["accuracy"].get<std::string>().c_str()):obj["accuracy"].get<uint32_t>());
        }
        if(obj.contains("health"))
        {
            msg.health = (obj["health"].is_string()?atoi(obj["health"].get<std::string>().c_str()):obj["health"].get<uint32_t>());
        }
        if(obj.contains("tgd"))
        {
            msg.tgd = (obj["tgd"].is_string()?atof(obj["tgd"].get<std::string>().c_str()):obj["tgd"].get<double>());
        }
        if(obj.contains("iodc"))
        {
            msg.iodc = (obj["iodc"].is_string()?atof(obj["iodc"].get<std::string>().c_str()):obj["iodc"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssKepplerOrbit from_json<ApollodriversgnssKepplerOrbit>(nlohmann::json obj){
        return from_json_ApollodriversgnssKepplerOrbit(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssKepplerOrbit &dt)
    {
        dt=from_json_ApollodriversgnssKepplerOrbit(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssKepplerOrbit & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssKepplerOrbit & dt)
    {
        os << to_json(dt);
        return os;
    }
}
