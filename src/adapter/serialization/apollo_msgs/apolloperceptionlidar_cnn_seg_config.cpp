#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_cnn_seg_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarCNNSegConfig &msg) {
        nlohmann::json obj;
        obj["paramfile"] = (msg.paramfile);
        obj["protofile"] = (msg.protofile);
        obj["weightfile"] = (msg.weightfile);
        obj["enginefile"] = (msg.enginefile);
        return obj;
    }
    ApolloperceptionlidarCNNSegConfig from_json_ApolloperceptionlidarCNNSegConfig (nlohmann::json obj) {
        ApolloperceptionlidarCNNSegConfig msg;
        if(obj.contains("paramfile"))
        {
            msg.paramfile = (obj["paramfile"].is_string()?(obj["paramfile"].get<std::string>().c_str()):obj["paramfile"].get<std::string>());
        }
        if(obj.contains("protofile"))
        {
            msg.protofile = (obj["protofile"].is_string()?(obj["protofile"].get<std::string>().c_str()):obj["protofile"].get<std::string>());
        }
        if(obj.contains("weightfile"))
        {
            msg.weightfile = (obj["weightfile"].is_string()?(obj["weightfile"].get<std::string>().c_str()):obj["weightfile"].get<std::string>());
        }
        if(obj.contains("enginefile"))
        {
            msg.enginefile = (obj["enginefile"].is_string()?(obj["enginefile"].get<std::string>().c_str()):obj["enginefile"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarCNNSegConfig from_json<ApolloperceptionlidarCNNSegConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarCNNSegConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarCNNSegConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarCNNSegConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarCNNSegConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarCNNSegConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
