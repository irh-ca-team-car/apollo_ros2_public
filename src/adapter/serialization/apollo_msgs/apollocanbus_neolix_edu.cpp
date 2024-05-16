#include "adapter/serialization/apollo_msgs/apollocanbus_neolix_edu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusNeolixEdu &msg) {
        nlohmann::json obj;
        obj["aebsystemstate11"] = to_json(msg.aebsystemstate11);
        obj["vcuvehiclefaultresponse201"] = to_json(msg.vcuvehiclefaultresponse201);
        obj["vcupowerstatus214"] = to_json(msg.vcupowerstatus214);
        obj["adslighthorncommand310"] = to_json(msg.adslighthorncommand310);
        obj["adsbrakecommand46"] = to_json(msg.adsbrakecommand46);
        obj["vcubrakereport47"] = to_json(msg.vcubrakereport47);
        obj["vcuepsreport57"] = to_json(msg.vcuepsreport57);
        obj["adsepscommand56"] = to_json(msg.adsepscommand56);
        obj["adsdrivecommand50"] = to_json(msg.adsdrivecommand50);
        obj["vcudrivereport52"] = to_json(msg.vcudrivereport52);
        obj["adsdiagnosis628"] = to_json(msg.adsdiagnosis628);
        obj["vcunm401"] = to_json(msg.vcunm401);
        obj["vcuvehiclestatusreport101"] = to_json(msg.vcuvehiclestatusreport101);
        obj["vcuvehicleinforesponse502"] = to_json(msg.vcuvehicleinforesponse502);
        obj["aebdiagnosis1626"] = to_json(msg.aebdiagnosis1626);
        obj["aebdiagresp718"] = to_json(msg.aebdiagresp718);
        obj["pas1stdata311"] = to_json(msg.pas1stdata311);
        obj["pas2nddata312"] = to_json(msg.pas2nddata312);
        obj["aebwheelimpulse355"] = to_json(msg.aebwheelimpulse355);
        obj["aebrearwheelspeed354"] = to_json(msg.aebrearwheelspeed354);
        obj["aebfrontwheelspeed353"] = to_json(msg.aebfrontwheelspeed353);
        return obj;
    }
    ApollocanbusNeolixEdu from_json_ApollocanbusNeolixEdu (nlohmann::json obj) {
        ApollocanbusNeolixEdu msg;
        if(obj.contains("aebsystemstate11"))
        {
            msg.aebsystemstate11 = from_json_ApollocanbusAebSystemstate11(obj["aebsystemstate11"]);
        }
        if(obj.contains("vcuvehiclefaultresponse201"))
        {
            msg.vcuvehiclefaultresponse201 = from_json_ApollocanbusVcuVehicleFaultResponse201(obj["vcuvehiclefaultresponse201"]);
        }
        if(obj.contains("vcupowerstatus214"))
        {
            msg.vcupowerstatus214 = from_json_ApollocanbusVcuPowerstatus214(obj["vcupowerstatus214"]);
        }
        if(obj.contains("adslighthorncommand310"))
        {
            msg.adslighthorncommand310 = from_json_ApollocanbusAdsLightHornCommand310(obj["adslighthorncommand310"]);
        }
        if(obj.contains("adsbrakecommand46"))
        {
            msg.adsbrakecommand46 = from_json_ApollocanbusAdsBrakeCommand46(obj["adsbrakecommand46"]);
        }
        if(obj.contains("vcubrakereport47"))
        {
            msg.vcubrakereport47 = from_json_ApollocanbusVcuBrakeReport47(obj["vcubrakereport47"]);
        }
        if(obj.contains("vcuepsreport57"))
        {
            msg.vcuepsreport57 = from_json_ApollocanbusVcuEpsReport57(obj["vcuepsreport57"]);
        }
        if(obj.contains("adsepscommand56"))
        {
            msg.adsepscommand56 = from_json_ApollocanbusAdsEpsCommand56(obj["adsepscommand56"]);
        }
        if(obj.contains("adsdrivecommand50"))
        {
            msg.adsdrivecommand50 = from_json_ApollocanbusAdsDriveCommand50(obj["adsdrivecommand50"]);
        }
        if(obj.contains("vcudrivereport52"))
        {
            msg.vcudrivereport52 = from_json_ApollocanbusVcuDriveReport52(obj["vcudrivereport52"]);
        }
        if(obj.contains("adsdiagnosis628"))
        {
            msg.adsdiagnosis628 = from_json_ApollocanbusAdsDiagnosis628(obj["adsdiagnosis628"]);
        }
        if(obj.contains("vcunm401"))
        {
            msg.vcunm401 = from_json_ApollocanbusVcuNm401(obj["vcunm401"]);
        }
        if(obj.contains("vcuvehiclestatusreport101"))
        {
            msg.vcuvehiclestatusreport101 = from_json_ApollocanbusVcuVehicleStatusReport101(obj["vcuvehiclestatusreport101"]);
        }
        if(obj.contains("vcuvehicleinforesponse502"))
        {
            msg.vcuvehicleinforesponse502 = from_json_ApollocanbusVcuVehicleInfoResponse502(obj["vcuvehicleinforesponse502"]);
        }
        if(obj.contains("aebdiagnosis1626"))
        {
            msg.aebdiagnosis1626 = from_json_ApollocanbusAebDiagnosis1626(obj["aebdiagnosis1626"]);
        }
        if(obj.contains("aebdiagresp718"))
        {
            msg.aebdiagresp718 = from_json_ApollocanbusAebDiagresp718(obj["aebdiagresp718"]);
        }
        if(obj.contains("pas1stdata311"))
        {
            msg.pas1stdata311 = from_json_ApollocanbusPas1stData311(obj["pas1stdata311"]);
        }
        if(obj.contains("pas2nddata312"))
        {
            msg.pas2nddata312 = from_json_ApollocanbusPas2ndData312(obj["pas2nddata312"]);
        }
        if(obj.contains("aebwheelimpulse355"))
        {
            msg.aebwheelimpulse355 = from_json_ApollocanbusAebWheelimpulse355(obj["aebwheelimpulse355"]);
        }
        if(obj.contains("aebrearwheelspeed354"))
        {
            msg.aebrearwheelspeed354 = from_json_ApollocanbusAebRearwheelspeed354(obj["aebrearwheelspeed354"]);
        }
        if(obj.contains("aebfrontwheelspeed353"))
        {
            msg.aebfrontwheelspeed353 = from_json_ApollocanbusAebFrontwheelspeed353(obj["aebfrontwheelspeed353"]);
        }
        return msg;
    }
    template <>
    ApollocanbusNeolixEdu from_json<ApollocanbusNeolixEdu>(nlohmann::json obj){
        return from_json_ApollocanbusNeolixEdu(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusNeolixEdu &dt)
    {
        dt=from_json_ApollocanbusNeolixEdu(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusNeolixEdu & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusNeolixEdu & dt)
    {
        os << to_json(dt);
        return os;
    }
}
