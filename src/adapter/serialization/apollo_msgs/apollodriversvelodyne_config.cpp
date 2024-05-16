#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneConfig &msg) {
        nlohmann::json obj;
        obj["frameid"] = (msg.frameid);
        obj["scanchannel"] = (msg.scanchannel);
        obj["rpm"] = (msg.rpm);
        obj["model"] = (msg.model);
        obj["mode"] = (msg.mode);
        obj["pcap"] = (msg.pcap);
        obj["prefixangle"] = (msg.prefixangle);
        obj["firingdataport"] = (msg.firingdataport);
        obj["positioningdataport"] = (msg.positioningdataport);
        obj["usesensorsync"] = (msg.usesensorsync);
        obj["maxrange"] = (msg.maxrange);
        obj["minrange"] = (msg.minrange);
        obj["maxangle"] = (msg.maxangle);
        obj["minangle"] = (msg.minangle);
        obj["viewdirection"] = (msg.viewdirection);
        obj["viewwidth"] = (msg.viewwidth);
        obj["calibrationonline"] = (msg.calibrationonline);
        obj["calibrationfile"] = (msg.calibrationfile);
        obj["organized"] = (msg.organized);
        obj["convertchannelname"] = (msg.convertchannelname);
        obj["npackets"] = (msg.npackets);
        obj["usegpstime"] = (msg.usegpstime);
        obj["usepollsync"] = (msg.usepollsync);
        obj["ismainframe"] = (msg.ismainframe);
        return obj;
    }
    ApollodriversvelodyneConfig from_json_ApollodriversvelodyneConfig (nlohmann::json obj) {
        ApollodriversvelodyneConfig msg;
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("scanchannel"))
        {
            msg.scanchannel = (obj["scanchannel"].is_string()?(obj["scanchannel"].get<std::string>().c_str()):obj["scanchannel"].get<std::string>());
        }
        if(obj.contains("rpm"))
        {
            msg.rpm = (obj["rpm"].is_string()?atof(obj["rpm"].get<std::string>().c_str()):obj["rpm"].get<double>());
        }
        if(obj.contains("model"))
        {
            msg.model = (obj["model"].is_string()?atoi(obj["model"].get<std::string>().c_str()):obj["model"].get<int>());
        }
        if(obj.contains("mode"))
        {
            msg.mode = (obj["mode"].is_string()?atoi(obj["mode"].get<std::string>().c_str()):obj["mode"].get<int>());
        }
        if(obj.contains("pcap"))
        {
            msg.pcap = (obj["pcap"].is_string()?(obj["pcap"].get<std::string>().c_str()):obj["pcap"].get<std::string>());
        }
        if(obj.contains("prefixangle"))
        {
            msg.prefixangle = (obj["prefixangle"].is_string()?atoi(obj["prefixangle"].get<std::string>().c_str()):obj["prefixangle"].get<int>());
        }
        if(obj.contains("firingdataport"))
        {
            msg.firingdataport = (obj["firingdataport"].is_string()?atoi(obj["firingdataport"].get<std::string>().c_str()):obj["firingdataport"].get<int>());
        }
        if(obj.contains("positioningdataport"))
        {
            msg.positioningdataport = (obj["positioningdataport"].is_string()?atoi(obj["positioningdataport"].get<std::string>().c_str()):obj["positioningdataport"].get<int>());
        }
        if(obj.contains("usesensorsync"))
        {
            msg.usesensorsync = (obj["usesensorsync"].is_string()?(bool)atoi(obj["usesensorsync"].get<std::string>().c_str()):obj["usesensorsync"].get<bool>());
        }
        if(obj.contains("maxrange"))
        {
            msg.maxrange = (obj["maxrange"].is_string()?atof(obj["maxrange"].get<std::string>().c_str()):obj["maxrange"].get<double>());
        }
        if(obj.contains("minrange"))
        {
            msg.minrange = (obj["minrange"].is_string()?atof(obj["minrange"].get<std::string>().c_str()):obj["minrange"].get<double>());
        }
        if(obj.contains("maxangle"))
        {
            msg.maxangle = (obj["maxangle"].is_string()?atof(obj["maxangle"].get<std::string>().c_str()):obj["maxangle"].get<double>());
        }
        if(obj.contains("minangle"))
        {
            msg.minangle = (obj["minangle"].is_string()?atof(obj["minangle"].get<std::string>().c_str()):obj["minangle"].get<double>());
        }
        if(obj.contains("viewdirection"))
        {
            msg.viewdirection = (obj["viewdirection"].is_string()?atof(obj["viewdirection"].get<std::string>().c_str()):obj["viewdirection"].get<double>());
        }
        if(obj.contains("viewwidth"))
        {
            msg.viewwidth = (obj["viewwidth"].is_string()?atof(obj["viewwidth"].get<std::string>().c_str()):obj["viewwidth"].get<double>());
        }
        if(obj.contains("calibrationonline"))
        {
            msg.calibrationonline = (obj["calibrationonline"].is_string()?(bool)atoi(obj["calibrationonline"].get<std::string>().c_str()):obj["calibrationonline"].get<bool>());
        }
        if(obj.contains("calibrationfile"))
        {
            msg.calibrationfile = (obj["calibrationfile"].is_string()?(obj["calibrationfile"].get<std::string>().c_str()):obj["calibrationfile"].get<std::string>());
        }
        if(obj.contains("organized"))
        {
            msg.organized = (obj["organized"].is_string()?(bool)atoi(obj["organized"].get<std::string>().c_str()):obj["organized"].get<bool>());
        }
        if(obj.contains("convertchannelname"))
        {
            msg.convertchannelname = (obj["convertchannelname"].is_string()?(obj["convertchannelname"].get<std::string>().c_str()):obj["convertchannelname"].get<std::string>());
        }
        if(obj.contains("npackets"))
        {
            msg.npackets = (obj["npackets"].is_string()?atoi(obj["npackets"].get<std::string>().c_str()):obj["npackets"].get<int>());
        }
        if(obj.contains("usegpstime"))
        {
            msg.usegpstime = (obj["usegpstime"].is_string()?(bool)atoi(obj["usegpstime"].get<std::string>().c_str()):obj["usegpstime"].get<bool>());
        }
        if(obj.contains("usepollsync"))
        {
            msg.usepollsync = (obj["usepollsync"].is_string()?(bool)atoi(obj["usepollsync"].get<std::string>().c_str()):obj["usepollsync"].get<bool>());
        }
        if(obj.contains("ismainframe"))
        {
            msg.ismainframe = (obj["ismainframe"].is_string()?(bool)atoi(obj["ismainframe"].get<std::string>().c_str()):obj["ismainframe"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversvelodyneConfig from_json<ApollodriversvelodyneConfig>(nlohmann::json obj){
        return from_json_ApollodriversvelodyneConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneConfig &dt)
    {
        dt=from_json_ApollodriversvelodyneConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
