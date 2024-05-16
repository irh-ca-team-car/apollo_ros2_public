#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_eps_report57.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuEpsReport57 &msg) {
        nlohmann::json obj;
        obj["driveenableresp"] = (msg.driveenableresp);
        obj["controlmoderesp"] = (msg.controlmoderesp);
        obj["vcuepsreport"] = (msg.vcuepsreport);
        obj["vcurealangle"] = (msg.vcurealangle);
        obj["vcurealanglevalid"] = (msg.vcurealanglevalid);
        obj["vcutargetanglevalid"] = (msg.vcutargetanglevalid);
        obj["vcutargetangle"] = (msg.vcutargetangle);
        obj["vcuepsreptalivecounter"] = (msg.vcuepsreptalivecounter);
        obj["vcuepsreptchecksum"] = (msg.vcuepsreptchecksum);
        return obj;
    }
    ApollocanbusVcuEpsReport57 from_json_ApollocanbusVcuEpsReport57 (nlohmann::json obj) {
        ApollocanbusVcuEpsReport57 msg;
        if(obj.contains("driveenableresp"))
        {
            msg.driveenableresp = (obj["driveenableresp"].is_string()?(bool)atoi(obj["driveenableresp"].get<std::string>().c_str()):obj["driveenableresp"].get<bool>());
        }
        if(obj.contains("controlmoderesp"))
        {
            msg.controlmoderesp = (obj["controlmoderesp"].is_string()?atoi(obj["controlmoderesp"].get<std::string>().c_str()):obj["controlmoderesp"].get<int>());
        }
        if(obj.contains("vcuepsreport"))
        {
            msg.vcuepsreport = (obj["vcuepsreport"].is_string()?(bool)atoi(obj["vcuepsreport"].get<std::string>().c_str()):obj["vcuepsreport"].get<bool>());
        }
        if(obj.contains("vcurealangle"))
        {
            msg.vcurealangle = (obj["vcurealangle"].is_string()?atof(obj["vcurealangle"].get<std::string>().c_str()):obj["vcurealangle"].get<double>());
        }
        if(obj.contains("vcurealanglevalid"))
        {
            msg.vcurealanglevalid = (obj["vcurealanglevalid"].is_string()?(bool)atoi(obj["vcurealanglevalid"].get<std::string>().c_str()):obj["vcurealanglevalid"].get<bool>());
        }
        if(obj.contains("vcutargetanglevalid"))
        {
            msg.vcutargetanglevalid = (obj["vcutargetanglevalid"].is_string()?(bool)atoi(obj["vcutargetanglevalid"].get<std::string>().c_str()):obj["vcutargetanglevalid"].get<bool>());
        }
        if(obj.contains("vcutargetangle"))
        {
            msg.vcutargetangle = (obj["vcutargetangle"].is_string()?atof(obj["vcutargetangle"].get<std::string>().c_str()):obj["vcutargetangle"].get<double>());
        }
        if(obj.contains("vcuepsreptalivecounter"))
        {
            msg.vcuepsreptalivecounter = (obj["vcuepsreptalivecounter"].is_string()?atoi(obj["vcuepsreptalivecounter"].get<std::string>().c_str()):obj["vcuepsreptalivecounter"].get<int>());
        }
        if(obj.contains("vcuepsreptchecksum"))
        {
            msg.vcuepsreptchecksum = (obj["vcuepsreptchecksum"].is_string()?atoi(obj["vcuepsreptchecksum"].get<std::string>().c_str()):obj["vcuepsreptchecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuEpsReport57 from_json<ApollocanbusVcuEpsReport57>(nlohmann::json obj){
        return from_json_ApollocanbusVcuEpsReport57(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuEpsReport57 &dt)
    {
        dt=from_json_ApollocanbusVcuEpsReport57(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuEpsReport57 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuEpsReport57 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
