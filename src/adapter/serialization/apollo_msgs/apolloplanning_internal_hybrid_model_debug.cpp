#include "adapter/serialization/apollo_msgs/apolloplanning_internal_hybrid_model_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalHybridModelDebug &msg) {
        nlohmann::json obj;
        obj["usinglearningmodeloutput"] = (msg.usinglearningmodeloutput);
        obj["learningmodeloutputusageratio"] = (msg.learningmodeloutputusageratio);
        obj["learningmodeloutputfailreason"] = (msg.learningmodeloutputfailreason);
        obj["evaluatedpathreference"] = to_json(msg.evaluatedpathreference);
        return obj;
    }
    ApolloplanningInternalHybridModelDebug from_json_ApolloplanningInternalHybridModelDebug (nlohmann::json obj) {
        ApolloplanningInternalHybridModelDebug msg;
        if(obj.contains("usinglearningmodeloutput"))
        {
            msg.usinglearningmodeloutput = (obj["usinglearningmodeloutput"].is_string()?(bool)atoi(obj["usinglearningmodeloutput"].get<std::string>().c_str()):obj["usinglearningmodeloutput"].get<bool>());
        }
        if(obj.contains("learningmodeloutputusageratio"))
        {
            msg.learningmodeloutputusageratio = (obj["learningmodeloutputusageratio"].is_string()?atof(obj["learningmodeloutputusageratio"].get<std::string>().c_str()):obj["learningmodeloutputusageratio"].get<double>());
        }
        if(obj.contains("learningmodeloutputfailreason"))
        {
            msg.learningmodeloutputfailreason = (obj["learningmodeloutputfailreason"].is_string()?(obj["learningmodeloutputfailreason"].get<std::string>().c_str()):obj["learningmodeloutputfailreason"].get<std::string>());
        }
        if(obj.contains("evaluatedpathreference"))
        {
            msg.evaluatedpathreference = from_json_ApollocommonPath(obj["evaluatedpathreference"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalHybridModelDebug from_json<ApolloplanningInternalHybridModelDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalHybridModelDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalHybridModelDebug &dt)
    {
        dt=from_json_ApolloplanningInternalHybridModelDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalHybridModelDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalHybridModelDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
