#include "adapter/serialization/apollo_msgs/apolloaudio_topic_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioTopicConf &msg) {
        nlohmann::json obj;
        obj["audiodatatopicname"] = (msg.audiodatatopicname);
        obj["audiodetectiontopicname"] = (msg.audiodetectiontopicname);
        obj["localizationtopicname"] = (msg.localizationtopicname);
        obj["audioeventtopicname"] = (msg.audioeventtopicname);
        obj["perceptiontopicname"] = (msg.perceptiontopicname);
        return obj;
    }
    ApolloaudioTopicConf from_json_ApolloaudioTopicConf (nlohmann::json obj) {
        ApolloaudioTopicConf msg;
        if(obj.contains("audiodatatopicname"))
        {
            msg.audiodatatopicname = (obj["audiodatatopicname"].is_string()?(obj["audiodatatopicname"].get<std::string>().c_str()):obj["audiodatatopicname"].get<std::string>());
        }
        if(obj.contains("audiodetectiontopicname"))
        {
            msg.audiodetectiontopicname = (obj["audiodetectiontopicname"].is_string()?(obj["audiodetectiontopicname"].get<std::string>().c_str()):obj["audiodetectiontopicname"].get<std::string>());
        }
        if(obj.contains("localizationtopicname"))
        {
            msg.localizationtopicname = (obj["localizationtopicname"].is_string()?(obj["localizationtopicname"].get<std::string>().c_str()):obj["localizationtopicname"].get<std::string>());
        }
        if(obj.contains("audioeventtopicname"))
        {
            msg.audioeventtopicname = (obj["audioeventtopicname"].is_string()?(obj["audioeventtopicname"].get<std::string>().c_str()):obj["audioeventtopicname"].get<std::string>());
        }
        if(obj.contains("perceptiontopicname"))
        {
            msg.perceptiontopicname = (obj["perceptiontopicname"].is_string()?(obj["perceptiontopicname"].get<std::string>().c_str()):obj["perceptiontopicname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloaudioTopicConf from_json<ApolloaudioTopicConf>(nlohmann::json obj){
        return from_json_ApolloaudioTopicConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioTopicConf &dt)
    {
        dt=from_json_ApolloaudioTopicConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloaudioTopicConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioTopicConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
