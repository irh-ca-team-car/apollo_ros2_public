#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_network_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNetworkParam &msg) {
        nlohmann::json obj;
        obj["instanceptblob"] = (msg.instanceptblob);
        obj["categoryptblob"] = (msg.categoryptblob);
        obj["confidenceptblob"] = (msg.confidenceptblob);
        obj["heightptblob"] = (msg.heightptblob);
        obj["classptblob"] = (msg.classptblob);
        obj["headingptblob"] = (msg.headingptblob);
        obj["featureblob"] = (msg.featureblob);
        return obj;
    }
    ApolloperceptionlidarNetworkParam from_json_ApolloperceptionlidarNetworkParam (nlohmann::json obj) {
        ApolloperceptionlidarNetworkParam msg;
        if(obj.contains("instanceptblob"))
        {
            msg.instanceptblob = (obj["instanceptblob"].is_string()?(obj["instanceptblob"].get<std::string>().c_str()):obj["instanceptblob"].get<std::string>());
        }
        if(obj.contains("categoryptblob"))
        {
            msg.categoryptblob = (obj["categoryptblob"].is_string()?(obj["categoryptblob"].get<std::string>().c_str()):obj["categoryptblob"].get<std::string>());
        }
        if(obj.contains("confidenceptblob"))
        {
            msg.confidenceptblob = (obj["confidenceptblob"].is_string()?(obj["confidenceptblob"].get<std::string>().c_str()):obj["confidenceptblob"].get<std::string>());
        }
        if(obj.contains("heightptblob"))
        {
            msg.heightptblob = (obj["heightptblob"].is_string()?(obj["heightptblob"].get<std::string>().c_str()):obj["heightptblob"].get<std::string>());
        }
        if(obj.contains("classptblob"))
        {
            msg.classptblob = (obj["classptblob"].is_string()?(obj["classptblob"].get<std::string>().c_str()):obj["classptblob"].get<std::string>());
        }
        if(obj.contains("headingptblob"))
        {
            msg.headingptblob = (obj["headingptblob"].is_string()?(obj["headingptblob"].get<std::string>().c_str()):obj["headingptblob"].get<std::string>());
        }
        if(obj.contains("featureblob"))
        {
            msg.featureblob = (obj["featureblob"].is_string()?(obj["featureblob"].get<std::string>().c_str()):obj["featureblob"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarNetworkParam from_json<ApolloperceptionlidarNetworkParam>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarNetworkParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNetworkParam &dt)
    {
        dt=from_json_ApolloperceptionlidarNetworkParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
