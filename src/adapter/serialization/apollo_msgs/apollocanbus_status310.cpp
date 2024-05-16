#include "adapter/serialization/apollo_msgs/apollocanbus_status310.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusStatus310 &msg) {
        nlohmann::json obj;
        obj["longitudeaccvalid"] = (msg.longitudeaccvalid);
        obj["lateralaccevalid"] = (msg.lateralaccevalid);
        obj["vehdynyawratevalid"] = (msg.vehdynyawratevalid);
        obj["flwheelspdvalid"] = (msg.flwheelspdvalid);
        obj["frwheelspdvalid"] = (msg.frwheelspdvalid);
        obj["rlwheelspdvalid"] = (msg.rlwheelspdvalid);
        obj["rrwheelspdvalid"] = (msg.rrwheelspdvalid);
        obj["vehiclespdvalid"] = (msg.vehiclespdvalid);
        obj["longitudedrivingmode"] = (msg.longitudedrivingmode);
        obj["engspdvalid"] = (msg.engspdvalid);
        obj["accepedaloverride"] = (msg.accepedaloverride);
        obj["brakepedalstatus"] = (msg.brakepedalstatus);
        obj["espbrakelightsts"] = (msg.espbrakelightsts);
        obj["epbswtpositionvalid"] = (msg.epbswtpositionvalid);
        obj["epbsts"] = (msg.epbsts);
        obj["currentgearvalid"] = (msg.currentgearvalid);
        obj["epstrqsnsrsts"] = (msg.epstrqsnsrsts);
        obj["epsinterferdetdvalid"] = (msg.epsinterferdetdvalid);
        obj["epshandsdetnsts"] = (msg.epshandsdetnsts);
        obj["epshandsdetnstsvalid"] = (msg.epshandsdetnstsvalid);
        obj["steerwheelanglesign"] = (msg.steerwheelanglesign);
        obj["steerwheelspdsign"] = (msg.steerwheelspdsign);
        obj["driverdoorsts"] = (msg.driverdoorsts);
        obj["rldoorsts"] = (msg.rldoorsts);
        obj["passengerdoorsts"] = (msg.passengerdoorsts);
        obj["rrdoorsts"] = (msg.rrdoorsts);
        obj["frontfoglmpsts"] = (msg.frontfoglmpsts);
        obj["rearfoglmpsts"] = (msg.rearfoglmpsts);
        obj["lowbeamsts"] = (msg.lowbeamsts);
        obj["highbeamsts"] = (msg.highbeamsts);
        obj["leftturnlampsts"] = (msg.leftturnlampsts);
        obj["rightturnlampsts"] = (msg.rightturnlampsts);
        obj["bcmavailsts"] = (msg.bcmavailsts);
        obj["brakelmpsts"] = (msg.brakelmpsts);
        return obj;
    }
    ApollocanbusStatus310 from_json_ApollocanbusStatus310 (nlohmann::json obj) {
        ApollocanbusStatus310 msg;
        if(obj.contains("longitudeaccvalid"))
        {
            msg.longitudeaccvalid = (obj["longitudeaccvalid"].is_string()?atoi(obj["longitudeaccvalid"].get<std::string>().c_str()):obj["longitudeaccvalid"].get<int>());
        }
        if(obj.contains("lateralaccevalid"))
        {
            msg.lateralaccevalid = (obj["lateralaccevalid"].is_string()?atoi(obj["lateralaccevalid"].get<std::string>().c_str()):obj["lateralaccevalid"].get<int>());
        }
        if(obj.contains("vehdynyawratevalid"))
        {
            msg.vehdynyawratevalid = (obj["vehdynyawratevalid"].is_string()?atoi(obj["vehdynyawratevalid"].get<std::string>().c_str()):obj["vehdynyawratevalid"].get<int>());
        }
        if(obj.contains("flwheelspdvalid"))
        {
            msg.flwheelspdvalid = (obj["flwheelspdvalid"].is_string()?atoi(obj["flwheelspdvalid"].get<std::string>().c_str()):obj["flwheelspdvalid"].get<int>());
        }
        if(obj.contains("frwheelspdvalid"))
        {
            msg.frwheelspdvalid = (obj["frwheelspdvalid"].is_string()?atoi(obj["frwheelspdvalid"].get<std::string>().c_str()):obj["frwheelspdvalid"].get<int>());
        }
        if(obj.contains("rlwheelspdvalid"))
        {
            msg.rlwheelspdvalid = (obj["rlwheelspdvalid"].is_string()?atoi(obj["rlwheelspdvalid"].get<std::string>().c_str()):obj["rlwheelspdvalid"].get<int>());
        }
        if(obj.contains("rrwheelspdvalid"))
        {
            msg.rrwheelspdvalid = (obj["rrwheelspdvalid"].is_string()?atoi(obj["rrwheelspdvalid"].get<std::string>().c_str()):obj["rrwheelspdvalid"].get<int>());
        }
        if(obj.contains("vehiclespdvalid"))
        {
            msg.vehiclespdvalid = (obj["vehiclespdvalid"].is_string()?atoi(obj["vehiclespdvalid"].get<std::string>().c_str()):obj["vehiclespdvalid"].get<int>());
        }
        if(obj.contains("longitudedrivingmode"))
        {
            msg.longitudedrivingmode = (obj["longitudedrivingmode"].is_string()?atoi(obj["longitudedrivingmode"].get<std::string>().c_str()):obj["longitudedrivingmode"].get<int>());
        }
        if(obj.contains("engspdvalid"))
        {
            msg.engspdvalid = (obj["engspdvalid"].is_string()?atoi(obj["engspdvalid"].get<std::string>().c_str()):obj["engspdvalid"].get<int>());
        }
        if(obj.contains("accepedaloverride"))
        {
            msg.accepedaloverride = (obj["accepedaloverride"].is_string()?atoi(obj["accepedaloverride"].get<std::string>().c_str()):obj["accepedaloverride"].get<int>());
        }
        if(obj.contains("brakepedalstatus"))
        {
            msg.brakepedalstatus = (obj["brakepedalstatus"].is_string()?atoi(obj["brakepedalstatus"].get<std::string>().c_str()):obj["brakepedalstatus"].get<int>());
        }
        if(obj.contains("espbrakelightsts"))
        {
            msg.espbrakelightsts = (obj["espbrakelightsts"].is_string()?atoi(obj["espbrakelightsts"].get<std::string>().c_str()):obj["espbrakelightsts"].get<int>());
        }
        if(obj.contains("epbswtpositionvalid"))
        {
            msg.epbswtpositionvalid = (obj["epbswtpositionvalid"].is_string()?atoi(obj["epbswtpositionvalid"].get<std::string>().c_str()):obj["epbswtpositionvalid"].get<int>());
        }
        if(obj.contains("epbsts"))
        {
            msg.epbsts = (obj["epbsts"].is_string()?atoi(obj["epbsts"].get<std::string>().c_str()):obj["epbsts"].get<int>());
        }
        if(obj.contains("currentgearvalid"))
        {
            msg.currentgearvalid = (obj["currentgearvalid"].is_string()?atoi(obj["currentgearvalid"].get<std::string>().c_str()):obj["currentgearvalid"].get<int>());
        }
        if(obj.contains("epstrqsnsrsts"))
        {
            msg.epstrqsnsrsts = (obj["epstrqsnsrsts"].is_string()?atoi(obj["epstrqsnsrsts"].get<std::string>().c_str()):obj["epstrqsnsrsts"].get<int>());
        }
        if(obj.contains("epsinterferdetdvalid"))
        {
            msg.epsinterferdetdvalid = (obj["epsinterferdetdvalid"].is_string()?atoi(obj["epsinterferdetdvalid"].get<std::string>().c_str()):obj["epsinterferdetdvalid"].get<int>());
        }
        if(obj.contains("epshandsdetnsts"))
        {
            msg.epshandsdetnsts = (obj["epshandsdetnsts"].is_string()?atoi(obj["epshandsdetnsts"].get<std::string>().c_str()):obj["epshandsdetnsts"].get<int>());
        }
        if(obj.contains("epshandsdetnstsvalid"))
        {
            msg.epshandsdetnstsvalid = (obj["epshandsdetnstsvalid"].is_string()?atoi(obj["epshandsdetnstsvalid"].get<std::string>().c_str()):obj["epshandsdetnstsvalid"].get<int>());
        }
        if(obj.contains("steerwheelanglesign"))
        {
            msg.steerwheelanglesign = (obj["steerwheelanglesign"].is_string()?atoi(obj["steerwheelanglesign"].get<std::string>().c_str()):obj["steerwheelanglesign"].get<int>());
        }
        if(obj.contains("steerwheelspdsign"))
        {
            msg.steerwheelspdsign = (obj["steerwheelspdsign"].is_string()?atoi(obj["steerwheelspdsign"].get<std::string>().c_str()):obj["steerwheelspdsign"].get<int>());
        }
        if(obj.contains("driverdoorsts"))
        {
            msg.driverdoorsts = (obj["driverdoorsts"].is_string()?atoi(obj["driverdoorsts"].get<std::string>().c_str()):obj["driverdoorsts"].get<int>());
        }
        if(obj.contains("rldoorsts"))
        {
            msg.rldoorsts = (obj["rldoorsts"].is_string()?atoi(obj["rldoorsts"].get<std::string>().c_str()):obj["rldoorsts"].get<int>());
        }
        if(obj.contains("passengerdoorsts"))
        {
            msg.passengerdoorsts = (obj["passengerdoorsts"].is_string()?atoi(obj["passengerdoorsts"].get<std::string>().c_str()):obj["passengerdoorsts"].get<int>());
        }
        if(obj.contains("rrdoorsts"))
        {
            msg.rrdoorsts = (obj["rrdoorsts"].is_string()?atoi(obj["rrdoorsts"].get<std::string>().c_str()):obj["rrdoorsts"].get<int>());
        }
        if(obj.contains("frontfoglmpsts"))
        {
            msg.frontfoglmpsts = (obj["frontfoglmpsts"].is_string()?atoi(obj["frontfoglmpsts"].get<std::string>().c_str()):obj["frontfoglmpsts"].get<int>());
        }
        if(obj.contains("rearfoglmpsts"))
        {
            msg.rearfoglmpsts = (obj["rearfoglmpsts"].is_string()?atoi(obj["rearfoglmpsts"].get<std::string>().c_str()):obj["rearfoglmpsts"].get<int>());
        }
        if(obj.contains("lowbeamsts"))
        {
            msg.lowbeamsts = (obj["lowbeamsts"].is_string()?atoi(obj["lowbeamsts"].get<std::string>().c_str()):obj["lowbeamsts"].get<int>());
        }
        if(obj.contains("highbeamsts"))
        {
            msg.highbeamsts = (obj["highbeamsts"].is_string()?atoi(obj["highbeamsts"].get<std::string>().c_str()):obj["highbeamsts"].get<int>());
        }
        if(obj.contains("leftturnlampsts"))
        {
            msg.leftturnlampsts = (obj["leftturnlampsts"].is_string()?atoi(obj["leftturnlampsts"].get<std::string>().c_str()):obj["leftturnlampsts"].get<int>());
        }
        if(obj.contains("rightturnlampsts"))
        {
            msg.rightturnlampsts = (obj["rightturnlampsts"].is_string()?atoi(obj["rightturnlampsts"].get<std::string>().c_str()):obj["rightturnlampsts"].get<int>());
        }
        if(obj.contains("bcmavailsts"))
        {
            msg.bcmavailsts = (obj["bcmavailsts"].is_string()?atoi(obj["bcmavailsts"].get<std::string>().c_str()):obj["bcmavailsts"].get<int>());
        }
        if(obj.contains("brakelmpsts"))
        {
            msg.brakelmpsts = (obj["brakelmpsts"].is_string()?atoi(obj["brakelmpsts"].get<std::string>().c_str()):obj["brakelmpsts"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusStatus310 from_json<ApollocanbusStatus310>(nlohmann::json obj){
        return from_json_ApollocanbusStatus310(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusStatus310 &dt)
    {
        dt=from_json_ApollocanbusStatus310(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusStatus310 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusStatus310 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
