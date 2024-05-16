#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_dump_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloDumpParameter &msg) {
        nlohmann::json obj;
        obj["dumpdir"] = (msg.dumpdir);
        return obj;
    }
    ApolloperceptioninferenceYoloDumpParameter from_json_ApolloperceptioninferenceYoloDumpParameter (nlohmann::json obj) {
        ApolloperceptioninferenceYoloDumpParameter msg;
        if(obj.contains("dumpdir"))
        {
            msg.dumpdir = (obj["dumpdir"].is_string()?(obj["dumpdir"].get<std::string>().c_str()):obj["dumpdir"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceYoloDumpParameter from_json<ApolloperceptioninferenceYoloDumpParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceYoloDumpParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloDumpParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceYoloDumpParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloDumpParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloDumpParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
