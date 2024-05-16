#include "adapter/serialization/apollo_msgs/apolloplanning_internal_auto_tuning_training_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalAutoTuningTrainingData &msg) {
        nlohmann::json obj;
        obj["teachercomponent"] = to_json(msg.teachercomponent);
        obj["studentcomponent"] = to_json(msg.studentcomponent);
        return obj;
    }
    ApolloplanningInternalAutoTuningTrainingData from_json_ApolloplanningInternalAutoTuningTrainingData (nlohmann::json obj) {
        ApolloplanningInternalAutoTuningTrainingData msg;
        if(obj.contains("teachercomponent"))
        {
            msg.teachercomponent = from_json_ApolloplanningInternalCostComponents(obj["teachercomponent"]);
        }
        if(obj.contains("studentcomponent"))
        {
            msg.studentcomponent = from_json_ApolloplanningInternalCostComponents(obj["studentcomponent"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalAutoTuningTrainingData from_json<ApolloplanningInternalAutoTuningTrainingData>(nlohmann::json obj){
        return from_json_ApolloplanningInternalAutoTuningTrainingData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalAutoTuningTrainingData &dt)
    {
        dt=from_json_ApolloplanningInternalAutoTuningTrainingData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalAutoTuningTrainingData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalAutoTuningTrainingData & dt)
    {
        os << to_json(dt);
        return os;
    }
}
