#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_drive_report52.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuDriveReport52 &msg) {
        nlohmann::json obj;
        obj["driveenableresp"] = (msg.driveenableresp);
        obj["controlmoderesp"] = (msg.controlmoderesp);
        obj["vcurealshift"] = (msg.vcurealshift);
        obj["vcurealshiftvalid"] = (msg.vcurealshiftvalid);
        obj["vcurealtorquevalid"] = (msg.vcurealtorquevalid);
        obj["vcurealtorque"] = (msg.vcurealtorque);
        obj["vculimitedtorquemode"] = (msg.vculimitedtorquemode);
        obj["vcudrivereptalivecounter"] = (msg.vcudrivereptalivecounter);
        obj["vcudrivereptchecksum"] = (msg.vcudrivereptchecksum);
        return obj;
    }
    ApollocanbusVcuDriveReport52 from_json_ApollocanbusVcuDriveReport52 (nlohmann::json obj) {
        ApollocanbusVcuDriveReport52 msg;
        if(obj.contains("driveenableresp"))
        {
            msg.driveenableresp = (obj["driveenableresp"].is_string()?(bool)atoi(obj["driveenableresp"].get<std::string>().c_str()):obj["driveenableresp"].get<bool>());
        }
        if(obj.contains("controlmoderesp"))
        {
            msg.controlmoderesp = (obj["controlmoderesp"].is_string()?atoi(obj["controlmoderesp"].get<std::string>().c_str()):obj["controlmoderesp"].get<int>());
        }
        if(obj.contains("vcurealshift"))
        {
            msg.vcurealshift = (obj["vcurealshift"].is_string()?atoi(obj["vcurealshift"].get<std::string>().c_str()):obj["vcurealshift"].get<int>());
        }
        if(obj.contains("vcurealshiftvalid"))
        {
            msg.vcurealshiftvalid = (obj["vcurealshiftvalid"].is_string()?(bool)atoi(obj["vcurealshiftvalid"].get<std::string>().c_str()):obj["vcurealshiftvalid"].get<bool>());
        }
        if(obj.contains("vcurealtorquevalid"))
        {
            msg.vcurealtorquevalid = (obj["vcurealtorquevalid"].is_string()?(bool)atoi(obj["vcurealtorquevalid"].get<std::string>().c_str()):obj["vcurealtorquevalid"].get<bool>());
        }
        if(obj.contains("vcurealtorque"))
        {
            msg.vcurealtorque = (obj["vcurealtorque"].is_string()?atof(obj["vcurealtorque"].get<std::string>().c_str()):obj["vcurealtorque"].get<double>());
        }
        if(obj.contains("vculimitedtorquemode"))
        {
            msg.vculimitedtorquemode = (obj["vculimitedtorquemode"].is_string()?(bool)atoi(obj["vculimitedtorquemode"].get<std::string>().c_str()):obj["vculimitedtorquemode"].get<bool>());
        }
        if(obj.contains("vcudrivereptalivecounter"))
        {
            msg.vcudrivereptalivecounter = (obj["vcudrivereptalivecounter"].is_string()?atoi(obj["vcudrivereptalivecounter"].get<std::string>().c_str()):obj["vcudrivereptalivecounter"].get<int>());
        }
        if(obj.contains("vcudrivereptchecksum"))
        {
            msg.vcudrivereptchecksum = (obj["vcudrivereptchecksum"].is_string()?atoi(obj["vcudrivereptchecksum"].get<std::string>().c_str()):obj["vcudrivereptchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuDriveReport52 from_json<ApollocanbusVcuDriveReport52>(nlohmann::json obj){
        return from_json_ApollocanbusVcuDriveReport52(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuDriveReport52 &dt)
    {
        dt=from_json_ApollocanbusVcuDriveReport52(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuDriveReport52 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuDriveReport52 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
