#include "adapter/serialization/apollo_msgs/apollocontrol_preprocessor.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolPreprocessor &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["localview"] = to_json(msg.localview);
        obj["engageadvice"] = to_json(msg.engageadvice);
        obj["inputdebug"] = to_json(msg.inputdebug);
        obj["receivedpadmsg"] = (msg.receivedpadmsg);
        obj["estop"] = (msg.estop);
        obj["estopreason"] = (msg.estopreason);
        return obj;
    }
    ApollocontrolPreprocessor from_json_ApollocontrolPreprocessor (nlohmann::json obj) {
        ApollocontrolPreprocessor msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("localview"))
        {
            msg.localview = from_json_ApollocontrolLocalView(obj["localview"]);
        }
        if(obj.contains("engageadvice"))
        {
            msg.engageadvice = from_json_ApollocommonEngageAdvice(obj["engageadvice"]);
        }
        if(obj.contains("inputdebug"))
        {
            msg.inputdebug = from_json_ApollocontrolInputDebug(obj["inputdebug"]);
        }
        if(obj.contains("receivedpadmsg"))
        {
            msg.receivedpadmsg = (obj["receivedpadmsg"].is_string()?(bool)atoi(obj["receivedpadmsg"].get<std::string>().c_str()):obj["receivedpadmsg"].get<bool>());
        }
        if(obj.contains("estop"))
        {
            msg.estop = (obj["estop"].is_string()?(bool)atoi(obj["estop"].get<std::string>().c_str()):obj["estop"].get<bool>());
        }
        if(obj.contains("estopreason"))
        {
            msg.estopreason = (obj["estopreason"].is_string()?(obj["estopreason"].get<std::string>().c_str()):obj["estopreason"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocontrolPreprocessor from_json<ApollocontrolPreprocessor>(nlohmann::json obj){
        return from_json_ApollocontrolPreprocessor(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolPreprocessor &dt)
    {
        dt=from_json_ApollocontrolPreprocessor(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolPreprocessor & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolPreprocessor & dt)
    {
        os << to_json(dt);
        return os;
    }
}
