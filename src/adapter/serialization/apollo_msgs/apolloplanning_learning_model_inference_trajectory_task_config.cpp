#include "adapter/serialization/apollo_msgs/apolloplanning_learning_model_inference_trajectory_task_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningModelInferenceTrajectoryTaskConfig &msg) {
        nlohmann::json obj;
        obj["minadcfuturetrajectorytimelength"] = (msg.minadcfuturetrajectorytimelength);
        return obj;
    }
    ApolloplanningLearningModelInferenceTrajectoryTaskConfig from_json_ApolloplanningLearningModelInferenceTrajectoryTaskConfig (nlohmann::json obj) {
        ApolloplanningLearningModelInferenceTrajectoryTaskConfig msg;
        if(obj.contains("minadcfuturetrajectorytimelength"))
        {
            msg.minadcfuturetrajectorytimelength = (obj["minadcfuturetrajectorytimelength"].is_string()?atof(obj["minadcfuturetrajectorytimelength"].get<std::string>().c_str()):obj["minadcfuturetrajectorytimelength"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningLearningModelInferenceTrajectoryTaskConfig from_json<ApolloplanningLearningModelInferenceTrajectoryTaskConfig>(nlohmann::json obj){
        return from_json_ApolloplanningLearningModelInferenceTrajectoryTaskConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningModelInferenceTrajectoryTaskConfig &dt)
    {
        dt=from_json_ApolloplanningLearningModelInferenceTrajectoryTaskConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningModelInferenceTrajectoryTaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningModelInferenceTrajectoryTaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
