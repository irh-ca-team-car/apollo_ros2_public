#include "adapter/serialization/apollo_msgs/apollocanbus_ch.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCh &msg) {
        nlohmann::json obj;
        obj["throttlecommand110"] = to_json(msg.throttlecommand110);
        obj["brakecommand111"] = to_json(msg.brakecommand111);
        obj["steercommand112"] = to_json(msg.steercommand112);
        obj["turnsignalcommand113"] = to_json(msg.turnsignalcommand113);
        obj["gearcommand114"] = to_json(msg.gearcommand114);
        obj["controlcommand115"] = to_json(msg.controlcommand115);
        obj["throttlestatus510"] = to_json(msg.throttlestatus510);
        obj["brakestatus511"] = to_json(msg.brakestatus511);
        obj["steerstatus512"] = to_json(msg.steerstatus512);
        obj["turnsignalstatus513"] = to_json(msg.turnsignalstatus513);
        obj["gearstatus514"] = to_json(msg.gearstatus514);
        obj["ecustatus1515"] = to_json(msg.ecustatus1515);
        obj["ecustatus2516"] = to_json(msg.ecustatus2516);
        obj["ecustatus3517"] = to_json(msg.ecustatus3517);
        return obj;
    }
    ApollocanbusCh from_json_ApollocanbusCh (nlohmann::json obj) {
        ApollocanbusCh msg;
        if(obj.contains("throttlecommand110"))
        {
            msg.throttlecommand110 = from_json_ApollocanbusThrottleCommand110(obj["throttlecommand110"]);
        }
        if(obj.contains("brakecommand111"))
        {
            msg.brakecommand111 = from_json_ApollocanbusBrakeCommand111(obj["brakecommand111"]);
        }
        if(obj.contains("steercommand112"))
        {
            msg.steercommand112 = from_json_ApollocanbusSteerCommand112(obj["steercommand112"]);
        }
        if(obj.contains("turnsignalcommand113"))
        {
            msg.turnsignalcommand113 = from_json_ApollocanbusTurnsignalCommand113(obj["turnsignalcommand113"]);
        }
        if(obj.contains("gearcommand114"))
        {
            msg.gearcommand114 = from_json_ApollocanbusGearCommand114(obj["gearcommand114"]);
        }
        if(obj.contains("controlcommand115"))
        {
            msg.controlcommand115 = from_json_ApollocanbusControlCommand115(obj["controlcommand115"]);
        }
        if(obj.contains("throttlestatus510"))
        {
            msg.throttlestatus510 = from_json_ApollocanbusThrottleStatus510(obj["throttlestatus510"]);
        }
        if(obj.contains("brakestatus511"))
        {
            msg.brakestatus511 = from_json_ApollocanbusBrakeStatus511(obj["brakestatus511"]);
        }
        if(obj.contains("steerstatus512"))
        {
            msg.steerstatus512 = from_json_ApollocanbusSteerStatus512(obj["steerstatus512"]);
        }
        if(obj.contains("turnsignalstatus513"))
        {
            msg.turnsignalstatus513 = from_json_ApollocanbusTurnsignalStatus513(obj["turnsignalstatus513"]);
        }
        if(obj.contains("gearstatus514"))
        {
            msg.gearstatus514 = from_json_ApollocanbusGearStatus514(obj["gearstatus514"]);
        }
        if(obj.contains("ecustatus1515"))
        {
            msg.ecustatus1515 = from_json_ApollocanbusEcuStatus1515(obj["ecustatus1515"]);
        }
        if(obj.contains("ecustatus2516"))
        {
            msg.ecustatus2516 = from_json_ApollocanbusEcuStatus2516(obj["ecustatus2516"]);
        }
        if(obj.contains("ecustatus3517"))
        {
            msg.ecustatus3517 = from_json_ApollocanbusEcuStatus3517(obj["ecustatus3517"]);
        }
        return msg;
    }
    template <>
    ApollocanbusCh from_json<ApollocanbusCh>(nlohmann::json obj){
        return from_json_ApollocanbusCh(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCh &dt)
    {
        dt=from_json_ApollocanbusCh(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCh & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCh & dt)
    {
        os << to_json(dt);
        return os;
    }
}
