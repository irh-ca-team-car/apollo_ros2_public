#include "adapter/serialization/apollo_msgs/apollocanbus_lexus.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLexus &msg) {
        nlohmann::json obj;
        obj["hazardlightsrpt214"] = to_json(msg.hazardlightsrpt214);
        obj["steeringcmd12c"] = to_json(msg.steeringcmd12c);
        obj["dashcontrolsrightrpt210"] = to_json(msg.dashcontrolsrightrpt210);
        obj["dashcontrolsleftcmd10c"] = to_json(msg.dashcontrolsleftcmd10c);
        obj["steeringrpt22c"] = to_json(msg.steeringrpt22c);
        obj["turnauxrpt330"] = to_json(msg.turnauxrpt330);
        obj["headlightrpt218"] = to_json(msg.headlightrpt218);
        obj["hazardlightscmd114"] = to_json(msg.hazardlightscmd114);
        obj["dashcontrolsleftrpt20c"] = to_json(msg.dashcontrolsleftrpt20c);
        obj["headlightauxrpt318"] = to_json(msg.headlightauxrpt318);
        obj["dashcontrolsrightcmd110"] = to_json(msg.dashcontrolsrightcmd110);
        obj["wipercmd134"] = to_json(msg.wipercmd134);
        obj["wiperrpt234"] = to_json(msg.wiperrpt234);
        obj["turnrpt230"] = to_json(msg.turnrpt230);
        obj["headlightcmd118"] = to_json(msg.headlightcmd118);
        obj["doorrpt417"] = to_json(msg.doorrpt417);
        obj["componentrpt20"] = to_json(msg.componentrpt20);
        obj["wheelspeedrpt407"] = to_json(msg.wheelspeedrpt407);
        obj["steeringmotorrpt3406"] = to_json(msg.steeringmotorrpt3406);
        obj["steeringmotorrpt2405"] = to_json(msg.steeringmotorrpt2405);
        obj["steeringmotorrpt1404"] = to_json(msg.steeringmotorrpt1404);
        obj["brakemotorrpt3403"] = to_json(msg.brakemotorrpt3403);
        obj["brakemotorrpt2402"] = to_json(msg.brakemotorrpt2402);
        obj["brakemotorrpt1401"] = to_json(msg.brakemotorrpt1401);
        obj["wiperauxrpt334"] = to_json(msg.wiperauxrpt334);
        obj["shiftauxrpt328"] = to_json(msg.shiftauxrpt328);
        obj["accelrpt200"] = to_json(msg.accelrpt200);
        obj["brakerpt204"] = to_json(msg.brakerpt204);
        obj["horncmd11c"] = to_json(msg.horncmd11c);
        obj["globalrpt10"] = to_json(msg.globalrpt10);
        obj["accelauxrpt300"] = to_json(msg.accelauxrpt300);
        obj["cruisecontrolbuttonsrpt208"] = to_json(msg.cruisecontrolbuttonsrpt208);
        obj["vehiclespeedrpt400"] = to_json(msg.vehiclespeedrpt400);
        obj["brakeauxrpt304"] = to_json(msg.brakeauxrpt304);
        obj["mediacontrolscmd120"] = to_json(msg.mediacontrolscmd120);
        obj["cruisecontrolbuttonscmd108"] = to_json(msg.cruisecontrolbuttonscmd108);
        obj["parkingbrakecmd124"] = to_json(msg.parkingbrakecmd124);
        obj["hornrpt21c"] = to_json(msg.hornrpt21c);
        obj["shiftrpt228"] = to_json(msg.shiftrpt228);
        obj["shiftcmd128"] = to_json(msg.shiftcmd128);
        obj["accelcmd100"] = to_json(msg.accelcmd100);
        obj["parkingbrakerpt224"] = to_json(msg.parkingbrakerpt224);
        obj["brakecmd104"] = to_json(msg.brakecmd104);
        obj["mediacontrolsrpt220"] = to_json(msg.mediacontrolsrpt220);
        obj["steeringauxrpt32c"] = to_json(msg.steeringauxrpt32c);
        obj["latlonheadingrpt40e"] = to_json(msg.latlonheadingrpt40e);
        obj["yawraterpt40d"] = to_json(msg.yawraterpt40d);
        obj["datetimerpt40f"] = to_json(msg.datetimerpt40f);
        obj["vinrpt414"] = to_json(msg.vinrpt414);
        obj["occupancyrpt415"] = to_json(msg.occupancyrpt415);
        obj["interiorlightsrpt416"] = to_json(msg.interiorlightsrpt416);
        obj["turncmd130"] = to_json(msg.turncmd130);
        obj["detectedobjectrpt411"] = to_json(msg.detectedobjectrpt411);
        obj["vehspecificrpt1412"] = to_json(msg.vehspecificrpt1412);
        obj["vehdynamicsrpt413"] = to_json(msg.vehdynamicsrpt413);
        obj["rearlightsrpt418"] = to_json(msg.rearlightsrpt418);
        return obj;
    }
    ApollocanbusLexus from_json_ApollocanbusLexus (nlohmann::json obj) {
        ApollocanbusLexus msg;
        if(obj.contains("hazardlightsrpt214"))
        {
            msg.hazardlightsrpt214 = from_json_ApollocanbusHazardLightsRpt214(obj["hazardlightsrpt214"]);
        }
        if(obj.contains("steeringcmd12c"))
        {
            msg.steeringcmd12c = from_json_ApollocanbusSteeringCmd12c(obj["steeringcmd12c"]);
        }
        if(obj.contains("dashcontrolsrightrpt210"))
        {
            msg.dashcontrolsrightrpt210 = from_json_ApollocanbusDashControlsRightRpt210(obj["dashcontrolsrightrpt210"]);
        }
        if(obj.contains("dashcontrolsleftcmd10c"))
        {
            msg.dashcontrolsleftcmd10c = from_json_ApollocanbusDashControlsLeftCmd10c(obj["dashcontrolsleftcmd10c"]);
        }
        if(obj.contains("steeringrpt22c"))
        {
            msg.steeringrpt22c = from_json_ApollocanbusSteeringRpt22c(obj["steeringrpt22c"]);
        }
        if(obj.contains("turnauxrpt330"))
        {
            msg.turnauxrpt330 = from_json_ApollocanbusTurnAuxRpt330(obj["turnauxrpt330"]);
        }
        if(obj.contains("headlightrpt218"))
        {
            msg.headlightrpt218 = from_json_ApollocanbusHeadlightRpt218(obj["headlightrpt218"]);
        }
        if(obj.contains("hazardlightscmd114"))
        {
            msg.hazardlightscmd114 = from_json_ApollocanbusHazardLightsCmd114(obj["hazardlightscmd114"]);
        }
        if(obj.contains("dashcontrolsleftrpt20c"))
        {
            msg.dashcontrolsleftrpt20c = from_json_ApollocanbusDashControlsLeftRpt20c(obj["dashcontrolsleftrpt20c"]);
        }
        if(obj.contains("headlightauxrpt318"))
        {
            msg.headlightauxrpt318 = from_json_ApollocanbusHeadlightAuxRpt318(obj["headlightauxrpt318"]);
        }
        if(obj.contains("dashcontrolsrightcmd110"))
        {
            msg.dashcontrolsrightcmd110 = from_json_ApollocanbusDashControlsRightCmd110(obj["dashcontrolsrightcmd110"]);
        }
        if(obj.contains("wipercmd134"))
        {
            msg.wipercmd134 = from_json_ApollocanbusWiperCmd134(obj["wipercmd134"]);
        }
        if(obj.contains("wiperrpt234"))
        {
            msg.wiperrpt234 = from_json_ApollocanbusWiperRpt234(obj["wiperrpt234"]);
        }
        if(obj.contains("turnrpt230"))
        {
            msg.turnrpt230 = from_json_ApollocanbusTurnRpt230(obj["turnrpt230"]);
        }
        if(obj.contains("headlightcmd118"))
        {
            msg.headlightcmd118 = from_json_ApollocanbusHeadlightCmd118(obj["headlightcmd118"]);
        }
        if(obj.contains("doorrpt417"))
        {
            msg.doorrpt417 = from_json_ApollocanbusDoorRpt417(obj["doorrpt417"]);
        }
        if(obj.contains("componentrpt20"))
        {
            msg.componentrpt20 = from_json_ApollocanbusComponentRpt20(obj["componentrpt20"]);
        }
        if(obj.contains("wheelspeedrpt407"))
        {
            msg.wheelspeedrpt407 = from_json_ApollocanbusWheelSpeedRpt407(obj["wheelspeedrpt407"]);
        }
        if(obj.contains("steeringmotorrpt3406"))
        {
            msg.steeringmotorrpt3406 = from_json_ApollocanbusSteeringMotorRpt3406(obj["steeringmotorrpt3406"]);
        }
        if(obj.contains("steeringmotorrpt2405"))
        {
            msg.steeringmotorrpt2405 = from_json_ApollocanbusSteeringMotorRpt2405(obj["steeringmotorrpt2405"]);
        }
        if(obj.contains("steeringmotorrpt1404"))
        {
            msg.steeringmotorrpt1404 = from_json_ApollocanbusSteeringMotorRpt1404(obj["steeringmotorrpt1404"]);
        }
        if(obj.contains("brakemotorrpt3403"))
        {
            msg.brakemotorrpt3403 = from_json_ApollocanbusBrakeMotorRpt3403(obj["brakemotorrpt3403"]);
        }
        if(obj.contains("brakemotorrpt2402"))
        {
            msg.brakemotorrpt2402 = from_json_ApollocanbusBrakeMotorRpt2402(obj["brakemotorrpt2402"]);
        }
        if(obj.contains("brakemotorrpt1401"))
        {
            msg.brakemotorrpt1401 = from_json_ApollocanbusBrakeMotorRpt1401(obj["brakemotorrpt1401"]);
        }
        if(obj.contains("wiperauxrpt334"))
        {
            msg.wiperauxrpt334 = from_json_ApollocanbusWiperAuxRpt334(obj["wiperauxrpt334"]);
        }
        if(obj.contains("shiftauxrpt328"))
        {
            msg.shiftauxrpt328 = from_json_ApollocanbusShiftAuxRpt328(obj["shiftauxrpt328"]);
        }
        if(obj.contains("accelrpt200"))
        {
            msg.accelrpt200 = from_json_ApollocanbusAccelRpt200(obj["accelrpt200"]);
        }
        if(obj.contains("brakerpt204"))
        {
            msg.brakerpt204 = from_json_ApollocanbusBrakeRpt204(obj["brakerpt204"]);
        }
        if(obj.contains("horncmd11c"))
        {
            msg.horncmd11c = from_json_ApollocanbusHornCmd11c(obj["horncmd11c"]);
        }
        if(obj.contains("globalrpt10"))
        {
            msg.globalrpt10 = from_json_ApollocanbusGlobalRpt10(obj["globalrpt10"]);
        }
        if(obj.contains("accelauxrpt300"))
        {
            msg.accelauxrpt300 = from_json_ApollocanbusAccelAuxRpt300(obj["accelauxrpt300"]);
        }
        if(obj.contains("cruisecontrolbuttonsrpt208"))
        {
            msg.cruisecontrolbuttonsrpt208 = from_json_ApollocanbusCruiseControlButtonsRpt208(obj["cruisecontrolbuttonsrpt208"]);
        }
        if(obj.contains("vehiclespeedrpt400"))
        {
            msg.vehiclespeedrpt400 = from_json_ApollocanbusVehicleSpeedRpt400(obj["vehiclespeedrpt400"]);
        }
        if(obj.contains("brakeauxrpt304"))
        {
            msg.brakeauxrpt304 = from_json_ApollocanbusBrakeAuxRpt304(obj["brakeauxrpt304"]);
        }
        if(obj.contains("mediacontrolscmd120"))
        {
            msg.mediacontrolscmd120 = from_json_ApollocanbusMediaControlsCmd120(obj["mediacontrolscmd120"]);
        }
        if(obj.contains("cruisecontrolbuttonscmd108"))
        {
            msg.cruisecontrolbuttonscmd108 = from_json_ApollocanbusCruiseControlButtonsCmd108(obj["cruisecontrolbuttonscmd108"]);
        }
        if(obj.contains("parkingbrakecmd124"))
        {
            msg.parkingbrakecmd124 = from_json_ApollocanbusParkingBrakeCmd124(obj["parkingbrakecmd124"]);
        }
        if(obj.contains("hornrpt21c"))
        {
            msg.hornrpt21c = from_json_ApollocanbusHornRpt21c(obj["hornrpt21c"]);
        }
        if(obj.contains("shiftrpt228"))
        {
            msg.shiftrpt228 = from_json_ApollocanbusShiftRpt228(obj["shiftrpt228"]);
        }
        if(obj.contains("shiftcmd128"))
        {
            msg.shiftcmd128 = from_json_ApollocanbusShiftCmd128(obj["shiftcmd128"]);
        }
        if(obj.contains("accelcmd100"))
        {
            msg.accelcmd100 = from_json_ApollocanbusAccelCmd100(obj["accelcmd100"]);
        }
        if(obj.contains("parkingbrakerpt224"))
        {
            msg.parkingbrakerpt224 = from_json_ApollocanbusParkingBrakeRpt224(obj["parkingbrakerpt224"]);
        }
        if(obj.contains("brakecmd104"))
        {
            msg.brakecmd104 = from_json_ApollocanbusBrakeCmd104(obj["brakecmd104"]);
        }
        if(obj.contains("mediacontrolsrpt220"))
        {
            msg.mediacontrolsrpt220 = from_json_ApollocanbusMediaControlsRpt220(obj["mediacontrolsrpt220"]);
        }
        if(obj.contains("steeringauxrpt32c"))
        {
            msg.steeringauxrpt32c = from_json_ApollocanbusSteeringAuxRpt32c(obj["steeringauxrpt32c"]);
        }
        if(obj.contains("latlonheadingrpt40e"))
        {
            msg.latlonheadingrpt40e = from_json_ApollocanbusLatLonHeadingRpt40e(obj["latlonheadingrpt40e"]);
        }
        if(obj.contains("yawraterpt40d"))
        {
            msg.yawraterpt40d = from_json_ApollocanbusYawRateRpt40d(obj["yawraterpt40d"]);
        }
        if(obj.contains("datetimerpt40f"))
        {
            msg.datetimerpt40f = from_json_ApollocanbusDateTimeRpt40f(obj["datetimerpt40f"]);
        }
        if(obj.contains("vinrpt414"))
        {
            msg.vinrpt414 = from_json_ApollocanbusVinRpt414(obj["vinrpt414"]);
        }
        if(obj.contains("occupancyrpt415"))
        {
            msg.occupancyrpt415 = from_json_ApollocanbusOccupancyRpt415(obj["occupancyrpt415"]);
        }
        if(obj.contains("interiorlightsrpt416"))
        {
            msg.interiorlightsrpt416 = from_json_ApollocanbusInteriorLightsRpt416(obj["interiorlightsrpt416"]);
        }
        if(obj.contains("turncmd130"))
        {
            msg.turncmd130 = from_json_ApollocanbusTurnCmd130(obj["turncmd130"]);
        }
        if(obj.contains("detectedobjectrpt411"))
        {
            msg.detectedobjectrpt411 = from_json_ApollocanbusDetectedObjectRpt411(obj["detectedobjectrpt411"]);
        }
        if(obj.contains("vehspecificrpt1412"))
        {
            msg.vehspecificrpt1412 = from_json_ApollocanbusVehSpecificRpt1412(obj["vehspecificrpt1412"]);
        }
        if(obj.contains("vehdynamicsrpt413"))
        {
            msg.vehdynamicsrpt413 = from_json_ApollocanbusVehDynamicsRpt413(obj["vehdynamicsrpt413"]);
        }
        if(obj.contains("rearlightsrpt418"))
        {
            msg.rearlightsrpt418 = from_json_ApollocanbusRearLightsRpt418(obj["rearlightsrpt418"]);
        }
        return msg;
    }
    template <>
    ApollocanbusLexus from_json<ApollocanbusLexus>(nlohmann::json obj){
        return from_json_ApollocanbusLexus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLexus &dt)
    {
        dt=from_json_ApollocanbusLexus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLexus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLexus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
