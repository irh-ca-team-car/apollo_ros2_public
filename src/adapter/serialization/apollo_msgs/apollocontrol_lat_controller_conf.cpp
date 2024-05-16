#include "adapter/serialization/apollo_msgs/apollocontrol_lat_controller_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLatControllerConf &msg) {
        nlohmann::json obj;
        obj["ts"] = (msg.ts);
        obj["previewwindow"] = (msg.previewwindow);
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
        nlohmann::json arr_reversematrixq;
        for (auto it = msg.reversematrixq.begin(); it != msg.reversematrixq.end(); ++it) {
            arr_reversematrixq.push_back((*it));
        }
        obj["reversematrixq"] = arr_reversematrixq;
        obj["cutofffreq"] = (msg.cutofffreq);
        obj["meanfilterwindowsize"] = (msg.meanfilterwindowsize);
        obj["maxiteration"] = (msg.maxiteration);
        obj["maxlateralacceleration"] = (msg.maxlateralacceleration);
        obj["laterrgainscheduler"] = to_json(msg.laterrgainscheduler);
        obj["headingerrgainscheduler"] = to_json(msg.headingerrgainscheduler);
        obj["reverseleadlagconf"] = to_json(msg.reverseleadlagconf);
        obj["enablereverseleadlagcompensation"] = (msg.enablereverseleadlagcompensation);
        obj["enablelookaheadbackcontrol"] = (msg.enablelookaheadbackcontrol);
        obj["lookaheadstation"] = (msg.lookaheadstation);
        obj["lookbackstation"] = (msg.lookbackstation);
        obj["steermracconf"] = to_json(msg.steermracconf);
        obj["enablesteermraccontrol"] = (msg.enablesteermraccontrol);
        obj["lookaheadstationhighspeed"] = (msg.lookaheadstationhighspeed);
        obj["lookbackstationhighspeed"] = (msg.lookbackstationhighspeed);
        return obj;
    }
    ApollocontrolLatControllerConf from_json_ApollocontrolLatControllerConf (nlohmann::json obj) {
        ApollocontrolLatControllerConf msg;
        if(obj.contains("ts"))
        {
            msg.ts = (obj["ts"].is_string()?atof(obj["ts"].get<std::string>().c_str()):obj["ts"].get<double>());
        }
        if(obj.contains("previewwindow"))
        {
            msg.previewwindow = (obj["previewwindow"].is_string()?atoi(obj["previewwindow"].get<std::string>().c_str()):obj["previewwindow"].get<int>());
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
        if(obj.contains("reversematrixq"))
        {
            if(obj["reversematrixq"].is_array())
            {
                for (auto& element : obj["reversematrixq"])
                {
                    msg.reversematrixq.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.reversematrixq.push_back((obj["reversematrixq"].is_string()?atof(obj["reversematrixq"].get<std::string>().c_str()):obj["reversematrixq"].get<double>()));
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
        if(obj.contains("laterrgainscheduler"))
        {
            msg.laterrgainscheduler = from_json_ApollocontrolGainScheduler(obj["laterrgainscheduler"]);
        }
        if(obj.contains("headingerrgainscheduler"))
        {
            msg.headingerrgainscheduler = from_json_ApollocontrolGainScheduler(obj["headingerrgainscheduler"]);
        }
        if(obj.contains("reverseleadlagconf"))
        {
            msg.reverseleadlagconf = from_json_ApollocontrolLeadlagConf(obj["reverseleadlagconf"]);
        }
        if(obj.contains("enablereverseleadlagcompensation"))
        {
            msg.enablereverseleadlagcompensation = (obj["enablereverseleadlagcompensation"].is_string()?(bool)atoi(obj["enablereverseleadlagcompensation"].get<std::string>().c_str()):obj["enablereverseleadlagcompensation"].get<bool>());
        }
        if(obj.contains("enablelookaheadbackcontrol"))
        {
            msg.enablelookaheadbackcontrol = (obj["enablelookaheadbackcontrol"].is_string()?(bool)atoi(obj["enablelookaheadbackcontrol"].get<std::string>().c_str()):obj["enablelookaheadbackcontrol"].get<bool>());
        }
        if(obj.contains("lookaheadstation"))
        {
            msg.lookaheadstation = (obj["lookaheadstation"].is_string()?atof(obj["lookaheadstation"].get<std::string>().c_str()):obj["lookaheadstation"].get<double>());
        }
        if(obj.contains("lookbackstation"))
        {
            msg.lookbackstation = (obj["lookbackstation"].is_string()?atof(obj["lookbackstation"].get<std::string>().c_str()):obj["lookbackstation"].get<double>());
        }
        if(obj.contains("steermracconf"))
        {
            msg.steermracconf = from_json_ApollocontrolMracConf(obj["steermracconf"]);
        }
        if(obj.contains("enablesteermraccontrol"))
        {
            msg.enablesteermraccontrol = (obj["enablesteermraccontrol"].is_string()?(bool)atoi(obj["enablesteermraccontrol"].get<std::string>().c_str()):obj["enablesteermraccontrol"].get<bool>());
        }
        if(obj.contains("lookaheadstationhighspeed"))
        {
            msg.lookaheadstationhighspeed = (obj["lookaheadstationhighspeed"].is_string()?atof(obj["lookaheadstationhighspeed"].get<std::string>().c_str()):obj["lookaheadstationhighspeed"].get<double>());
        }
        if(obj.contains("lookbackstationhighspeed"))
        {
            msg.lookbackstationhighspeed = (obj["lookbackstationhighspeed"].is_string()?atof(obj["lookbackstationhighspeed"].get<std::string>().c_str()):obj["lookbackstationhighspeed"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolLatControllerConf from_json<ApollocontrolLatControllerConf>(nlohmann::json obj){
        return from_json_ApollocontrolLatControllerConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLatControllerConf &dt)
    {
        dt=from_json_ApollocontrolLatControllerConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLatControllerConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLatControllerConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
