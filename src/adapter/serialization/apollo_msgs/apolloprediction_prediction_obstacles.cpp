#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionPredictionObstacles &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_predictionobstacle;
        for (auto it = msg.predictionobstacle.begin(); it != msg.predictionobstacle.end(); ++it) {
            arr_predictionobstacle.push_back(to_json(*it));
        }
        obj["predictionobstacle"] = arr_predictionobstacle;
        obj["perceptionerrorcode"] = (msg.perceptionerrorcode);
        obj["starttimestamp"] = (msg.starttimestamp);
        obj["endtimestamp"] = (msg.endtimestamp);
        obj["intent"] = to_json(msg.intent);
        obj["scenario"] = to_json(msg.scenario);
        return obj;
    }
    ApollopredictionPredictionObstacles from_json_ApollopredictionPredictionObstacles (nlohmann::json obj) {
        ApollopredictionPredictionObstacles msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("predictionobstacle"))
        {
            if(obj["predictionobstacle"].is_array())
            {
                for (auto& element : obj["predictionobstacle"])
                {
                    msg.predictionobstacle.push_back(from_json_ApollopredictionPredictionObstacle(element));
                }
            }
            else
            {
                msg.predictionobstacle.push_back(from_json_ApollopredictionPredictionObstacle(obj["predictionobstacle"]));
            }
        }
        if(obj.contains("perceptionerrorcode"))
        {
            msg.perceptionerrorcode = (obj["perceptionerrorcode"].is_string()?atoi(obj["perceptionerrorcode"].get<std::string>().c_str()):obj["perceptionerrorcode"].get<int>());
        }
        if(obj.contains("starttimestamp"))
        {
            msg.starttimestamp = (obj["starttimestamp"].is_string()?atof(obj["starttimestamp"].get<std::string>().c_str()):obj["starttimestamp"].get<double>());
        }
        if(obj.contains("endtimestamp"))
        {
            msg.endtimestamp = (obj["endtimestamp"].is_string()?atof(obj["endtimestamp"].get<std::string>().c_str()):obj["endtimestamp"].get<double>());
        }
        if(obj.contains("intent"))
        {
            msg.intent = from_json_ApollopredictionIntent(obj["intent"]);
        }
        if(obj.contains("scenario"))
        {
            msg.scenario = from_json_ApollopredictionScenario(obj["scenario"]);
        }
        return msg;
    }
    template <>
    ApollopredictionPredictionObstacles from_json<ApollopredictionPredictionObstacles>(nlohmann::json obj){
        return from_json_ApollopredictionPredictionObstacles(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionPredictionObstacles &dt)
    {
        dt=from_json_ApollopredictionPredictionObstacles(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionPredictionObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionPredictionObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
}
