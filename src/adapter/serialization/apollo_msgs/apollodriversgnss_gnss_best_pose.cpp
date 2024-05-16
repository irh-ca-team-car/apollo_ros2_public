#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss_best_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnssBestPose &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["measurementtime"] = (msg.measurementtime);
        obj["solstatus"] = (msg.solstatus);
        obj["soltype"] = (msg.soltype);
        obj["latitude"] = (msg.latitude);
        obj["longitude"] = (msg.longitude);
        obj["heightmsl"] = (msg.heightmsl);
        obj["undulation"] = (msg.undulation);
        obj["datumid"] = (msg.datumid);
        obj["latitudestddev"] = (msg.latitudestddev);
        obj["longitudestddev"] = (msg.longitudestddev);
        obj["heightstddev"] = (msg.heightstddev);
        obj["basestationid"] = to_json(msg.basestationid);
        obj["differentialage"] = (msg.differentialage);
        obj["solutionage"] = (msg.solutionage);
        obj["numsatstracked"] = (msg.numsatstracked);
        obj["numsatsinsolution"] = (msg.numsatsinsolution);
        obj["numsatsl1"] = (msg.numsatsl1);
        obj["numsatsmulti"] = (msg.numsatsmulti);
        obj["reserved"] = (msg.reserved);
        obj["extendedsolutionstatus"] = (msg.extendedsolutionstatus);
        obj["galileobeidouusedmask"] = (msg.galileobeidouusedmask);
        obj["gpsglonassusedmask"] = (msg.gpsglonassusedmask);
        return obj;
    }
    ApollodriversgnssGnssBestPose from_json_ApollodriversgnssGnssBestPose (nlohmann::json obj) {
        ApollodriversgnssGnssBestPose msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("solstatus"))
        {
            msg.solstatus = (obj["solstatus"].is_string()?atoi(obj["solstatus"].get<std::string>().c_str()):obj["solstatus"].get<int>());
        }
        if(obj.contains("soltype"))
        {
            msg.soltype = (obj["soltype"].is_string()?atoi(obj["soltype"].get<std::string>().c_str()):obj["soltype"].get<int>());
        }
        if(obj.contains("latitude"))
        {
            msg.latitude = (obj["latitude"].is_string()?atof(obj["latitude"].get<std::string>().c_str()):obj["latitude"].get<double>());
        }
        if(obj.contains("longitude"))
        {
            msg.longitude = (obj["longitude"].is_string()?atof(obj["longitude"].get<std::string>().c_str()):obj["longitude"].get<double>());
        }
        if(obj.contains("heightmsl"))
        {
            msg.heightmsl = (obj["heightmsl"].is_string()?atof(obj["heightmsl"].get<std::string>().c_str()):obj["heightmsl"].get<double>());
        }
        if(obj.contains("undulation"))
        {
            msg.undulation = (obj["undulation"].is_string()?(float)atof(obj["undulation"].get<std::string>().c_str()):obj["undulation"].get<float>());
        }
        if(obj.contains("datumid"))
        {
            msg.datumid = (obj["datumid"].is_string()?atoi(obj["datumid"].get<std::string>().c_str()):obj["datumid"].get<int>());
        }
        if(obj.contains("latitudestddev"))
        {
            msg.latitudestddev = (obj["latitudestddev"].is_string()?(float)atof(obj["latitudestddev"].get<std::string>().c_str()):obj["latitudestddev"].get<float>());
        }
        if(obj.contains("longitudestddev"))
        {
            msg.longitudestddev = (obj["longitudestddev"].is_string()?(float)atof(obj["longitudestddev"].get<std::string>().c_str()):obj["longitudestddev"].get<float>());
        }
        if(obj.contains("heightstddev"))
        {
            msg.heightstddev = (obj["heightstddev"].is_string()?(float)atof(obj["heightstddev"].get<std::string>().c_str()):obj["heightstddev"].get<float>());
        }
        if(obj.contains("basestationid"))
        {
            msg.basestationid = from_json_Bytes(obj["basestationid"]);
        }
        if(obj.contains("differentialage"))
        {
            msg.differentialage = (obj["differentialage"].is_string()?(float)atof(obj["differentialage"].get<std::string>().c_str()):obj["differentialage"].get<float>());
        }
        if(obj.contains("solutionage"))
        {
            msg.solutionage = (obj["solutionage"].is_string()?(float)atof(obj["solutionage"].get<std::string>().c_str()):obj["solutionage"].get<float>());
        }
        if(obj.contains("numsatstracked"))
        {
            msg.numsatstracked = (obj["numsatstracked"].is_string()?atoi(obj["numsatstracked"].get<std::string>().c_str()):obj["numsatstracked"].get<uint32_t>());
        }
        if(obj.contains("numsatsinsolution"))
        {
            msg.numsatsinsolution = (obj["numsatsinsolution"].is_string()?atoi(obj["numsatsinsolution"].get<std::string>().c_str()):obj["numsatsinsolution"].get<uint32_t>());
        }
        if(obj.contains("numsatsl1"))
        {
            msg.numsatsl1 = (obj["numsatsl1"].is_string()?atoi(obj["numsatsl1"].get<std::string>().c_str()):obj["numsatsl1"].get<uint32_t>());
        }
        if(obj.contains("numsatsmulti"))
        {
            msg.numsatsmulti = (obj["numsatsmulti"].is_string()?atoi(obj["numsatsmulti"].get<std::string>().c_str()):obj["numsatsmulti"].get<uint32_t>());
        }
        if(obj.contains("reserved"))
        {
            msg.reserved = (obj["reserved"].is_string()?atoi(obj["reserved"].get<std::string>().c_str()):obj["reserved"].get<uint32_t>());
        }
        if(obj.contains("extendedsolutionstatus"))
        {
            msg.extendedsolutionstatus = (obj["extendedsolutionstatus"].is_string()?atoi(obj["extendedsolutionstatus"].get<std::string>().c_str()):obj["extendedsolutionstatus"].get<uint32_t>());
        }
        if(obj.contains("galileobeidouusedmask"))
        {
            msg.galileobeidouusedmask = (obj["galileobeidouusedmask"].is_string()?atoi(obj["galileobeidouusedmask"].get<std::string>().c_str()):obj["galileobeidouusedmask"].get<uint32_t>());
        }
        if(obj.contains("gpsglonassusedmask"))
        {
            msg.gpsglonassusedmask = (obj["gpsglonassusedmask"].is_string()?atoi(obj["gpsglonassusedmask"].get<std::string>().c_str()):obj["gpsglonassusedmask"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssGnssBestPose from_json<ApollodriversgnssGnssBestPose>(nlohmann::json obj){
        return from_json_ApollodriversgnssGnssBestPose(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnssBestPose &dt)
    {
        dt=from_json_ApollodriversgnssGnssBestPose(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnssBestPose & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnssBestPose & dt)
    {
        os << to_json(dt);
        return os;
    }
}
