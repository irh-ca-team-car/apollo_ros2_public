#include "adapter/serialization/apollo_msgs/apollodriversgnss_heading.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssHeading &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["measurementtime"] = (msg.measurementtime);
        obj["solutionstatus"] = (msg.solutionstatus);
        obj["positiontype"] = (msg.positiontype);
        obj["baselinelength"] = (msg.baselinelength);
        obj["heading"] = (msg.heading);
        obj["pitch"] = (msg.pitch);
        obj["reserved"] = (msg.reserved);
        obj["headingstddev"] = (msg.headingstddev);
        obj["pitchstddev"] = (msg.pitchstddev);
        obj["stationid"] = to_json(msg.stationid);
        obj["satellitetrackednumber"] = (msg.satellitetrackednumber);
        obj["satellitesoulutionnumber"] = (msg.satellitesoulutionnumber);
        obj["satellitenumberobs"] = (msg.satellitenumberobs);
        obj["satellitenumbermulti"] = (msg.satellitenumbermulti);
        obj["solutionsource"] = (msg.solutionsource);
        obj["extendedsolutionstatus"] = (msg.extendedsolutionstatus);
        obj["galileobeidousigmask"] = (msg.galileobeidousigmask);
        obj["gpsglonasssigmask"] = (msg.gpsglonasssigmask);
        return obj;
    }
    ApollodriversgnssHeading from_json_ApollodriversgnssHeading (nlohmann::json obj) {
        ApollodriversgnssHeading msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("solutionstatus"))
        {
            msg.solutionstatus = (obj["solutionstatus"].is_string()?atoi(obj["solutionstatus"].get<std::string>().c_str()):obj["solutionstatus"].get<uint32_t>());
        }
        if(obj.contains("positiontype"))
        {
            msg.positiontype = (obj["positiontype"].is_string()?atoi(obj["positiontype"].get<std::string>().c_str()):obj["positiontype"].get<uint32_t>());
        }
        if(obj.contains("baselinelength"))
        {
            msg.baselinelength = (obj["baselinelength"].is_string()?(float)atof(obj["baselinelength"].get<std::string>().c_str()):obj["baselinelength"].get<float>());
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?(float)atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<float>());
        }
        if(obj.contains("pitch"))
        {
            msg.pitch = (obj["pitch"].is_string()?(float)atof(obj["pitch"].get<std::string>().c_str()):obj["pitch"].get<float>());
        }
        if(obj.contains("reserved"))
        {
            msg.reserved = (obj["reserved"].is_string()?(float)atof(obj["reserved"].get<std::string>().c_str()):obj["reserved"].get<float>());
        }
        if(obj.contains("headingstddev"))
        {
            msg.headingstddev = (obj["headingstddev"].is_string()?(float)atof(obj["headingstddev"].get<std::string>().c_str()):obj["headingstddev"].get<float>());
        }
        if(obj.contains("pitchstddev"))
        {
            msg.pitchstddev = (obj["pitchstddev"].is_string()?(float)atof(obj["pitchstddev"].get<std::string>().c_str()):obj["pitchstddev"].get<float>());
        }
        if(obj.contains("stationid"))
        {
            msg.stationid = from_json_Bytes(obj["stationid"]);
        }
        if(obj.contains("satellitetrackednumber"))
        {
            msg.satellitetrackednumber = (obj["satellitetrackednumber"].is_string()?atoi(obj["satellitetrackednumber"].get<std::string>().c_str()):obj["satellitetrackednumber"].get<uint32_t>());
        }
        if(obj.contains("satellitesoulutionnumber"))
        {
            msg.satellitesoulutionnumber = (obj["satellitesoulutionnumber"].is_string()?atoi(obj["satellitesoulutionnumber"].get<std::string>().c_str()):obj["satellitesoulutionnumber"].get<uint32_t>());
        }
        if(obj.contains("satellitenumberobs"))
        {
            msg.satellitenumberobs = (obj["satellitenumberobs"].is_string()?atoi(obj["satellitenumberobs"].get<std::string>().c_str()):obj["satellitenumberobs"].get<uint32_t>());
        }
        if(obj.contains("satellitenumbermulti"))
        {
            msg.satellitenumbermulti = (obj["satellitenumbermulti"].is_string()?atoi(obj["satellitenumbermulti"].get<std::string>().c_str()):obj["satellitenumbermulti"].get<uint32_t>());
        }
        if(obj.contains("solutionsource"))
        {
            msg.solutionsource = (obj["solutionsource"].is_string()?atoi(obj["solutionsource"].get<std::string>().c_str()):obj["solutionsource"].get<uint32_t>());
        }
        if(obj.contains("extendedsolutionstatus"))
        {
            msg.extendedsolutionstatus = (obj["extendedsolutionstatus"].is_string()?atoi(obj["extendedsolutionstatus"].get<std::string>().c_str()):obj["extendedsolutionstatus"].get<uint32_t>());
        }
        if(obj.contains("galileobeidousigmask"))
        {
            msg.galileobeidousigmask = (obj["galileobeidousigmask"].is_string()?atoi(obj["galileobeidousigmask"].get<std::string>().c_str()):obj["galileobeidousigmask"].get<uint32_t>());
        }
        if(obj.contains("gpsglonasssigmask"))
        {
            msg.gpsglonasssigmask = (obj["gpsglonasssigmask"].is_string()?atoi(obj["gpsglonasssigmask"].get<std::string>().c_str()):obj["gpsglonasssigmask"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssHeading from_json<ApollodriversgnssHeading>(nlohmann::json obj){
        return from_json_ApollodriversgnssHeading(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssHeading &dt)
    {
        dt=from_json_ApollodriversgnssHeading(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssHeading & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssHeading & dt)
    {
        os << to_json(dt);
        return os;
    }
}
