#include "adapter/serialization/apollo_msgs/io_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const IoConfig &msg) {
        nlohmann::json obj;
        obj["taskname"] = (msg.taskname);
        obj["outputpath"] = (msg.outputpath);
        obj["starttimestamp"] = (msg.starttimestamp);
        obj["endtimestamp"] = (msg.endtimestamp);
        obj["mainsensor"] = (msg.mainsensor);
        return obj;
    }
    IoConfig from_json_IoConfig (nlohmann::json obj) {
        IoConfig msg;
        if(obj.contains("taskname"))
        {
            msg.taskname = (obj["taskname"].is_string()?(obj["taskname"].get<std::string>().c_str()):obj["taskname"].get<std::string>());
        }
        if(obj.contains("outputpath"))
        {
            msg.outputpath = (obj["outputpath"].is_string()?(obj["outputpath"].get<std::string>().c_str()):obj["outputpath"].get<std::string>());
        }
        if(obj.contains("starttimestamp"))
        {
            msg.starttimestamp = (obj["starttimestamp"].is_string()?(obj["starttimestamp"].get<std::string>().c_str()):obj["starttimestamp"].get<std::string>());
        }
        if(obj.contains("endtimestamp"))
        {
            msg.endtimestamp = (obj["endtimestamp"].is_string()?(obj["endtimestamp"].get<std::string>().c_str()):obj["endtimestamp"].get<std::string>());
        }
        if(obj.contains("mainsensor"))
        {
            msg.mainsensor = (obj["mainsensor"].is_string()?(obj["mainsensor"].get<std::string>().c_str()):obj["mainsensor"].get<std::string>());
        }
        return msg;
    }
    template <>
    IoConfig from_json<IoConfig>(nlohmann::json obj){
        return from_json_IoConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, IoConfig &dt)
    {
        dt=from_json_IoConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const IoConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const IoConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
