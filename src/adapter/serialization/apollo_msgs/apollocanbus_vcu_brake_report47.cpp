#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_brake_report47.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuBrakeReport47 &msg) {
        nlohmann::json obj;
        obj["brakeenableresp"] = (msg.brakeenableresp);
        obj["controlmoderesp"] = (msg.controlmoderesp);
        obj["vcurealbrakevalid"] = (msg.vcurealbrakevalid);
        obj["vcurealbrake"] = (msg.vcurealbrake);
        obj["vcurealparkingstatus"] = (msg.vcurealparkingstatus);
        obj["vcurealparkingvalid"] = (msg.vcurealparkingvalid);
        obj["rampauxiliaryindication"] = (msg.rampauxiliaryindication);
        obj["vehicleslope"] = (msg.vehicleslope);
        obj["vcubrakereptalivecounter"] = (msg.vcubrakereptalivecounter);
        obj["vcubrakereptchecksum"] = (msg.vcubrakereptchecksum);
        return obj;
    }
    ApollocanbusVcuBrakeReport47 from_json_ApollocanbusVcuBrakeReport47 (nlohmann::json obj) {
        ApollocanbusVcuBrakeReport47 msg;
        if(obj.contains("brakeenableresp"))
        {
            msg.brakeenableresp = (obj["brakeenableresp"].is_string()?(bool)atoi(obj["brakeenableresp"].get<std::string>().c_str()):obj["brakeenableresp"].get<bool>());
        }
        if(obj.contains("controlmoderesp"))
        {
            msg.controlmoderesp = (obj["controlmoderesp"].is_string()?atoi(obj["controlmoderesp"].get<std::string>().c_str()):obj["controlmoderesp"].get<int>());
        }
        if(obj.contains("vcurealbrakevalid"))
        {
            msg.vcurealbrakevalid = (obj["vcurealbrakevalid"].is_string()?(bool)atoi(obj["vcurealbrakevalid"].get<std::string>().c_str()):obj["vcurealbrakevalid"].get<bool>());
        }
        if(obj.contains("vcurealbrake"))
        {
            msg.vcurealbrake = (obj["vcurealbrake"].is_string()?atoi(obj["vcurealbrake"].get<std::string>().c_str()):obj["vcurealbrake"].get<int>());
        }
        if(obj.contains("vcurealparkingstatus"))
        {
            msg.vcurealparkingstatus = (obj["vcurealparkingstatus"].is_string()?atoi(obj["vcurealparkingstatus"].get<std::string>().c_str()):obj["vcurealparkingstatus"].get<int>());
        }
        if(obj.contains("vcurealparkingvalid"))
        {
            msg.vcurealparkingvalid = (obj["vcurealparkingvalid"].is_string()?(bool)atoi(obj["vcurealparkingvalid"].get<std::string>().c_str()):obj["vcurealparkingvalid"].get<bool>());
        }
        if(obj.contains("rampauxiliaryindication"))
        {
            msg.rampauxiliaryindication = (obj["rampauxiliaryindication"].is_string()?(bool)atoi(obj["rampauxiliaryindication"].get<std::string>().c_str()):obj["rampauxiliaryindication"].get<bool>());
        }
        if(obj.contains("vehicleslope"))
        {
            msg.vehicleslope = (obj["vehicleslope"].is_string()?atof(obj["vehicleslope"].get<std::string>().c_str()):obj["vehicleslope"].get<double>());
        }
        if(obj.contains("vcubrakereptalivecounter"))
        {
            msg.vcubrakereptalivecounter = (obj["vcubrakereptalivecounter"].is_string()?atoi(obj["vcubrakereptalivecounter"].get<std::string>().c_str()):obj["vcubrakereptalivecounter"].get<int>());
        }
        if(obj.contains("vcubrakereptchecksum"))
        {
            msg.vcubrakereptchecksum = (obj["vcubrakereptchecksum"].is_string()?atoi(obj["vcubrakereptchecksum"].get<std::string>().c_str()):obj["vcubrakereptchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuBrakeReport47 from_json<ApollocanbusVcuBrakeReport47>(nlohmann::json obj){
        return from_json_ApollocanbusVcuBrakeReport47(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuBrakeReport47 &dt)
    {
        dt=from_json_ApollocanbusVcuBrakeReport47(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuBrakeReport47 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuBrakeReport47 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
