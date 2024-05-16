#include "adapter/serialization/apollo_msgs/apolloplanning_planning_learning_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningLearningData &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["learningdataframe"] = to_json(msg.learningdataframe);
        return obj;
    }
    ApolloplanningPlanningLearningData from_json_ApolloplanningPlanningLearningData (nlohmann::json obj) {
        ApolloplanningPlanningLearningData msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("learningdataframe"))
        {
            msg.learningdataframe = from_json_ApolloplanningLearningDataFrame(obj["learningdataframe"]);
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningLearningData from_json<ApolloplanningPlanningLearningData>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningLearningData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningLearningData &dt)
    {
        dt=from_json_ApolloplanningPlanningLearningData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningLearningData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningLearningData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
