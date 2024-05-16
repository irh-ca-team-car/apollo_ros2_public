#include "adapter/serialization/apollo_msgs/apolloprediction_topic_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionTopicConf &msg) {
        nlohmann::json obj;
        obj["adccontainertopicname"] = (msg.adccontainertopicname);
        obj["containertopicname"] = (msg.containertopicname);
        obj["evaluatortopicname"] = (msg.evaluatortopicname);
        obj["localizationtopic"] = (msg.localizationtopic);
        obj["perceptionobstacletopic"] = (msg.perceptionobstacletopic);
        obj["perceptionobstaclestopicname"] = (msg.perceptionobstaclestopicname);
        obj["planningtrajectorytopic"] = (msg.planningtrajectorytopic);
        obj["predictiontopic"] = (msg.predictiontopic);
        obj["storytellingtopic"] = (msg.storytellingtopic);
        return obj;
    }
    ApollopredictionTopicConf from_json_ApollopredictionTopicConf (nlohmann::json obj) {
        ApollopredictionTopicConf msg;
        if(obj.contains("adccontainertopicname"))
        {
            msg.adccontainertopicname = (obj["adccontainertopicname"].is_string()?(obj["adccontainertopicname"].get<std::string>().c_str()):obj["adccontainertopicname"].get<std::string>());
        }
        if(obj.contains("containertopicname"))
        {
            msg.containertopicname = (obj["containertopicname"].is_string()?(obj["containertopicname"].get<std::string>().c_str()):obj["containertopicname"].get<std::string>());
        }
        if(obj.contains("evaluatortopicname"))
        {
            msg.evaluatortopicname = (obj["evaluatortopicname"].is_string()?(obj["evaluatortopicname"].get<std::string>().c_str()):obj["evaluatortopicname"].get<std::string>());
        }
        if(obj.contains("localizationtopic"))
        {
            msg.localizationtopic = (obj["localizationtopic"].is_string()?(obj["localizationtopic"].get<std::string>().c_str()):obj["localizationtopic"].get<std::string>());
        }
        if(obj.contains("perceptionobstacletopic"))
        {
            msg.perceptionobstacletopic = (obj["perceptionobstacletopic"].is_string()?(obj["perceptionobstacletopic"].get<std::string>().c_str()):obj["perceptionobstacletopic"].get<std::string>());
        }
        if(obj.contains("perceptionobstaclestopicname"))
        {
            msg.perceptionobstaclestopicname = (obj["perceptionobstaclestopicname"].is_string()?(obj["perceptionobstaclestopicname"].get<std::string>().c_str()):obj["perceptionobstaclestopicname"].get<std::string>());
        }
        if(obj.contains("planningtrajectorytopic"))
        {
            msg.planningtrajectorytopic = (obj["planningtrajectorytopic"].is_string()?(obj["planningtrajectorytopic"].get<std::string>().c_str()):obj["planningtrajectorytopic"].get<std::string>());
        }
        if(obj.contains("predictiontopic"))
        {
            msg.predictiontopic = (obj["predictiontopic"].is_string()?(obj["predictiontopic"].get<std::string>().c_str()):obj["predictiontopic"].get<std::string>());
        }
        if(obj.contains("storytellingtopic"))
        {
            msg.storytellingtopic = (obj["storytellingtopic"].is_string()?(obj["storytellingtopic"].get<std::string>().c_str()):obj["storytellingtopic"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollopredictionTopicConf from_json<ApollopredictionTopicConf>(nlohmann::json obj){
        return from_json_ApollopredictionTopicConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionTopicConf &dt)
    {
        dt=from_json_ApollopredictionTopicConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionTopicConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionTopicConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
