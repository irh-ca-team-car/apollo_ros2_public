#include "adapter/serialization/apollo_msgs/apolloplanning_topic_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTopicConfig &msg) {
        nlohmann::json obj;
        obj["chassistopic"] = (msg.chassistopic);
        obj["hmistatustopic"] = (msg.hmistatustopic);
        obj["localizationtopic"] = (msg.localizationtopic);
        obj["planningpadtopic"] = (msg.planningpadtopic);
        obj["planningtrajectorytopic"] = (msg.planningtrajectorytopic);
        obj["predictiontopic"] = (msg.predictiontopic);
        obj["relativemaptopic"] = (msg.relativemaptopic);
        obj["routingrequesttopic"] = (msg.routingrequesttopic);
        obj["routingresponsetopic"] = (msg.routingresponsetopic);
        obj["storytellingtopic"] = (msg.storytellingtopic);
        obj["trafficlightdetectiontopic"] = (msg.trafficlightdetectiontopic);
        obj["planninglearningdatatopic"] = (msg.planninglearningdatatopic);
        return obj;
    }
    ApolloplanningTopicConfig from_json_ApolloplanningTopicConfig (nlohmann::json obj) {
        ApolloplanningTopicConfig msg;
        if(obj.contains("chassistopic"))
        {
            msg.chassistopic = (obj["chassistopic"].is_string()?(obj["chassistopic"].get<std::string>().c_str()):obj["chassistopic"].get<std::string>());
        }
        if(obj.contains("hmistatustopic"))
        {
            msg.hmistatustopic = (obj["hmistatustopic"].is_string()?(obj["hmistatustopic"].get<std::string>().c_str()):obj["hmistatustopic"].get<std::string>());
        }
        if(obj.contains("localizationtopic"))
        {
            msg.localizationtopic = (obj["localizationtopic"].is_string()?(obj["localizationtopic"].get<std::string>().c_str()):obj["localizationtopic"].get<std::string>());
        }
        if(obj.contains("planningpadtopic"))
        {
            msg.planningpadtopic = (obj["planningpadtopic"].is_string()?(obj["planningpadtopic"].get<std::string>().c_str()):obj["planningpadtopic"].get<std::string>());
        }
        if(obj.contains("planningtrajectorytopic"))
        {
            msg.planningtrajectorytopic = (obj["planningtrajectorytopic"].is_string()?(obj["planningtrajectorytopic"].get<std::string>().c_str()):obj["planningtrajectorytopic"].get<std::string>());
        }
        if(obj.contains("predictiontopic"))
        {
            msg.predictiontopic = (obj["predictiontopic"].is_string()?(obj["predictiontopic"].get<std::string>().c_str()):obj["predictiontopic"].get<std::string>());
        }
        if(obj.contains("relativemaptopic"))
        {
            msg.relativemaptopic = (obj["relativemaptopic"].is_string()?(obj["relativemaptopic"].get<std::string>().c_str()):obj["relativemaptopic"].get<std::string>());
        }
        if(obj.contains("routingrequesttopic"))
        {
            msg.routingrequesttopic = (obj["routingrequesttopic"].is_string()?(obj["routingrequesttopic"].get<std::string>().c_str()):obj["routingrequesttopic"].get<std::string>());
        }
        if(obj.contains("routingresponsetopic"))
        {
            msg.routingresponsetopic = (obj["routingresponsetopic"].is_string()?(obj["routingresponsetopic"].get<std::string>().c_str()):obj["routingresponsetopic"].get<std::string>());
        }
        if(obj.contains("storytellingtopic"))
        {
            msg.storytellingtopic = (obj["storytellingtopic"].is_string()?(obj["storytellingtopic"].get<std::string>().c_str()):obj["storytellingtopic"].get<std::string>());
        }
        if(obj.contains("trafficlightdetectiontopic"))
        {
            msg.trafficlightdetectiontopic = (obj["trafficlightdetectiontopic"].is_string()?(obj["trafficlightdetectiontopic"].get<std::string>().c_str()):obj["trafficlightdetectiontopic"].get<std::string>());
        }
        if(obj.contains("planninglearningdatatopic"))
        {
            msg.planninglearningdatatopic = (obj["planninglearningdatatopic"].is_string()?(obj["planninglearningdatatopic"].get<std::string>().c_str()):obj["planninglearningdatatopic"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloplanningTopicConfig from_json<ApolloplanningTopicConfig>(nlohmann::json obj){
        return from_json_ApolloplanningTopicConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTopicConfig &dt)
    {
        dt=from_json_ApolloplanningTopicConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTopicConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
