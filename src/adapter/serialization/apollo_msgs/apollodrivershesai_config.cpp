#include "adapter/serialization/apollo_msgs/apollodrivershesai_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodrivershesaiConfig &msg) {
        nlohmann::json obj;
        obj["model"] = (msg.model);
        obj["ip"] = (msg.ip);
        obj["lidarrecvport"] = (msg.lidarrecvport);
        obj["gpsrecvport"] = (msg.gpsrecvport);
        obj["startangle"] = (msg.startangle);
        obj["pointcloudchannel"] = (msg.pointcloudchannel);
        obj["timezone"] = (msg.timezone);
        obj["frameid"] = (msg.frameid);
        obj["scanchannel"] = (msg.scanchannel);
        obj["isonlinecalibration"] = (msg.isonlinecalibration);
        obj["calibrationfile"] = (msg.calibrationfile);
        obj["tcpcmdport"] = (msg.tcpcmdport);
        return obj;
    }
    ApollodrivershesaiConfig from_json_ApollodrivershesaiConfig (nlohmann::json obj) {
        ApollodrivershesaiConfig msg;
        if(obj.contains("model"))
        {
            msg.model = (obj["model"].is_string()?atoi(obj["model"].get<std::string>().c_str()):obj["model"].get<int>());
        }
        if(obj.contains("ip"))
        {
            msg.ip = (obj["ip"].is_string()?(obj["ip"].get<std::string>().c_str()):obj["ip"].get<std::string>());
        }
        if(obj.contains("lidarrecvport"))
        {
            msg.lidarrecvport = (obj["lidarrecvport"].is_string()?atoi(obj["lidarrecvport"].get<std::string>().c_str()):obj["lidarrecvport"].get<uint32_t>());
        }
        if(obj.contains("gpsrecvport"))
        {
            msg.gpsrecvport = (obj["gpsrecvport"].is_string()?atoi(obj["gpsrecvport"].get<std::string>().c_str()):obj["gpsrecvport"].get<uint32_t>());
        }
        if(obj.contains("startangle"))
        {
            msg.startangle = (obj["startangle"].is_string()?atoi(obj["startangle"].get<std::string>().c_str()):obj["startangle"].get<uint32_t>());
        }
        if(obj.contains("pointcloudchannel"))
        {
            msg.pointcloudchannel = (obj["pointcloudchannel"].is_string()?(obj["pointcloudchannel"].get<std::string>().c_str()):obj["pointcloudchannel"].get<std::string>());
        }
        if(obj.contains("timezone"))
        {
            msg.timezone = (obj["timezone"].is_string()?atoi(obj["timezone"].get<std::string>().c_str()):obj["timezone"].get<uint32_t>());
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("scanchannel"))
        {
            msg.scanchannel = (obj["scanchannel"].is_string()?(obj["scanchannel"].get<std::string>().c_str()):obj["scanchannel"].get<std::string>());
        }
        if(obj.contains("isonlinecalibration"))
        {
            msg.isonlinecalibration = (obj["isonlinecalibration"].is_string()?(bool)atoi(obj["isonlinecalibration"].get<std::string>().c_str()):obj["isonlinecalibration"].get<bool>());
        }
        if(obj.contains("calibrationfile"))
        {
            msg.calibrationfile = (obj["calibrationfile"].is_string()?(obj["calibrationfile"].get<std::string>().c_str()):obj["calibrationfile"].get<std::string>());
        }
        if(obj.contains("tcpcmdport"))
        {
            msg.tcpcmdport = (obj["tcpcmdport"].is_string()?atoi(obj["tcpcmdport"].get<std::string>().c_str()):obj["tcpcmdport"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodrivershesaiConfig from_json<ApollodrivershesaiConfig>(nlohmann::json obj){
        return from_json_ApollodrivershesaiConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodrivershesaiConfig &dt)
    {
        dt=from_json_ApollodrivershesaiConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodrivershesaiConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodrivershesaiConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
