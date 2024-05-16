#include "adapter/serialization/apollo_msgs/apollocontrol_mpc_controller_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMPCControllerConf &msg) {
        nlohmann::json obj;
        obj["ts"] = (msg.ts);
        obj["cf"] = (msg.cf);
        obj["cr"] = (msg.cr);
        obj["massfl"] = (msg.massfl);
        obj["massfr"] = (msg.massfr);
        obj["massrl"] = (msg.massrl);
        obj["massrr"] = (msg.massrr);
        obj["eps"] = (msg.eps);
        nlohmann::json arr_matrixq;
        for (auto it = msg.matrixq.begin(); it != msg.matrixq.end(); ++it) {
            arr_matrixq.push_back((*it));
        }
        obj["matrixq"] = arr_matrixq;
        nlohmann::json arr_matrixr;
        for (auto it = msg.matrixr.begin(); it != msg.matrixr.end(); ++it) {
            arr_matrixr.push_back((*it));
        }
        obj["matrixr"] = arr_matrixr;
        obj["cutofffreq"] = (msg.cutofffreq);
        obj["meanfilterwindowsize"] = (msg.meanfilterwindowsize);
        obj["maxiteration"] = (msg.maxiteration);
        obj["maxlateralacceleration"] = (msg.maxlateralacceleration);
        obj["standstillacceleration"] = (msg.standstillacceleration);
        obj["brakeminimumaction"] = (msg.brakeminimumaction);
        obj["throttleminimumaction"] = (msg.throttleminimumaction);
        obj["laterrgainscheduler"] = to_json(msg.laterrgainscheduler);
        obj["headingerrgainscheduler"] = to_json(msg.headingerrgainscheduler);
        obj["steerweightgainscheduler"] = to_json(msg.steerweightgainscheduler);
        obj["feedforwardtermgainscheduler"] = to_json(msg.feedforwardtermgainscheduler);
        obj["calibrationtable"] = to_json(msg.calibrationtable);
        obj["enablempcfeedforwardcompensation"] = (msg.enablempcfeedforwardcompensation);
        obj["unconstrainedcontroldifflimit"] = (msg.unconstrainedcontroldifflimit);
        return obj;
    }
    ApollocontrolMPCControllerConf from_json_ApollocontrolMPCControllerConf (nlohmann::json obj) {
        ApollocontrolMPCControllerConf msg;
        if(obj.contains("ts"))
        {
            msg.ts = (obj["ts"].is_string()?atof(obj["ts"].get<std::string>().c_str()):obj["ts"].get<double>());
        }
        if(obj.contains("cf"))
        {
            msg.cf = (obj["cf"].is_string()?atof(obj["cf"].get<std::string>().c_str()):obj["cf"].get<double>());
        }
        if(obj.contains("cr"))
        {
            msg.cr = (obj["cr"].is_string()?atof(obj["cr"].get<std::string>().c_str()):obj["cr"].get<double>());
        }
        if(obj.contains("massfl"))
        {
            msg.massfl = (obj["massfl"].is_string()?atoi(obj["massfl"].get<std::string>().c_str()):obj["massfl"].get<int>());
        }
        if(obj.contains("massfr"))
        {
            msg.massfr = (obj["massfr"].is_string()?atoi(obj["massfr"].get<std::string>().c_str()):obj["massfr"].get<int>());
        }
        if(obj.contains("massrl"))
        {
            msg.massrl = (obj["massrl"].is_string()?atoi(obj["massrl"].get<std::string>().c_str()):obj["massrl"].get<int>());
        }
        if(obj.contains("massrr"))
        {
            msg.massrr = (obj["massrr"].is_string()?atoi(obj["massrr"].get<std::string>().c_str()):obj["massrr"].get<int>());
        }
        if(obj.contains("eps"))
        {
            msg.eps = (obj["eps"].is_string()?atof(obj["eps"].get<std::string>().c_str()):obj["eps"].get<double>());
        }
        if(obj.contains("matrixq"))
        {
            if(obj["matrixq"].is_array())
            {
                for (auto& element : obj["matrixq"])
                {
                    msg.matrixq.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.matrixq.push_back((obj["matrixq"].is_string()?atof(obj["matrixq"].get<std::string>().c_str()):obj["matrixq"].get<double>()));
            }
        }
        if(obj.contains("matrixr"))
        {
            if(obj["matrixr"].is_array())
            {
                for (auto& element : obj["matrixr"])
                {
                    msg.matrixr.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.matrixr.push_back((obj["matrixr"].is_string()?atof(obj["matrixr"].get<std::string>().c_str()):obj["matrixr"].get<double>()));
            }
        }
        if(obj.contains("cutofffreq"))
        {
            msg.cutofffreq = (obj["cutofffreq"].is_string()?atoi(obj["cutofffreq"].get<std::string>().c_str()):obj["cutofffreq"].get<int>());
        }
        if(obj.contains("meanfilterwindowsize"))
        {
            msg.meanfilterwindowsize = (obj["meanfilterwindowsize"].is_string()?atoi(obj["meanfilterwindowsize"].get<std::string>().c_str()):obj["meanfilterwindowsize"].get<int>());
        }
        if(obj.contains("maxiteration"))
        {
            msg.maxiteration = (obj["maxiteration"].is_string()?atoi(obj["maxiteration"].get<std::string>().c_str()):obj["maxiteration"].get<int>());
        }
        if(obj.contains("maxlateralacceleration"))
        {
            msg.maxlateralacceleration = (obj["maxlateralacceleration"].is_string()?atof(obj["maxlateralacceleration"].get<std::string>().c_str()):obj["maxlateralacceleration"].get<double>());
        }
        if(obj.contains("standstillacceleration"))
        {
            msg.standstillacceleration = (obj["standstillacceleration"].is_string()?atof(obj["standstillacceleration"].get<std::string>().c_str()):obj["standstillacceleration"].get<double>());
        }
        if(obj.contains("brakeminimumaction"))
        {
            msg.brakeminimumaction = (obj["brakeminimumaction"].is_string()?atof(obj["brakeminimumaction"].get<std::string>().c_str()):obj["brakeminimumaction"].get<double>());
        }
        if(obj.contains("throttleminimumaction"))
        {
            msg.throttleminimumaction = (obj["throttleminimumaction"].is_string()?atof(obj["throttleminimumaction"].get<std::string>().c_str()):obj["throttleminimumaction"].get<double>());
        }
        if(obj.contains("laterrgainscheduler"))
        {
            msg.laterrgainscheduler = from_json_ApollocontrolGainScheduler(obj["laterrgainscheduler"]);
        }
        if(obj.contains("headingerrgainscheduler"))
        {
            msg.headingerrgainscheduler = from_json_ApollocontrolGainScheduler(obj["headingerrgainscheduler"]);
        }
        if(obj.contains("steerweightgainscheduler"))
        {
            msg.steerweightgainscheduler = from_json_ApollocontrolGainScheduler(obj["steerweightgainscheduler"]);
        }
        if(obj.contains("feedforwardtermgainscheduler"))
        {
            msg.feedforwardtermgainscheduler = from_json_ApollocontrolGainScheduler(obj["feedforwardtermgainscheduler"]);
        }
        if(obj.contains("calibrationtable"))
        {
            msg.calibrationtable = from_json_ApollocontrolcalibrationtableControlCalibrationTable(obj["calibrationtable"]);
        }
        if(obj.contains("enablempcfeedforwardcompensation"))
        {
            msg.enablempcfeedforwardcompensation = (obj["enablempcfeedforwardcompensation"].is_string()?(bool)atoi(obj["enablempcfeedforwardcompensation"].get<std::string>().c_str()):obj["enablempcfeedforwardcompensation"].get<bool>());
        }
        if(obj.contains("unconstrainedcontroldifflimit"))
        {
            msg.unconstrainedcontroldifflimit = (obj["unconstrainedcontroldifflimit"].is_string()?atof(obj["unconstrainedcontroldifflimit"].get<std::string>().c_str()):obj["unconstrainedcontroldifflimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolMPCControllerConf from_json<ApollocontrolMPCControllerConf>(nlohmann::json obj){
        return from_json_ApollocontrolMPCControllerConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMPCControllerConf &dt)
    {
        dt=from_json_ApollocontrolMPCControllerConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMPCControllerConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMPCControllerConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
