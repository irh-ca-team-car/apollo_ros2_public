#include "adapter/serialization/apollo_msgs/apolloplanning_learning_model_inference_task_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningModelInferenceTaskConfig &msg) {
        nlohmann::json obj;
        obj["modeltype"] = (msg.modeltype);
        obj["cpumodelfile"] = (msg.cpumodelfile);
        obj["gpumodelfile"] = (msg.gpumodelfile);
        obj["usecuda"] = (msg.usecuda);
        obj["trajectorydeltat"] = (msg.trajectorydeltat);
        obj["allowemptylearningbaseddata"] = (msg.allowemptylearningbaseddata);
        obj["allowemptyoutputtrajectory"] = (msg.allowemptyoutputtrajectory);
        return obj;
    }
    ApolloplanningLearningModelInferenceTaskConfig from_json_ApolloplanningLearningModelInferenceTaskConfig (nlohmann::json obj) {
        ApolloplanningLearningModelInferenceTaskConfig msg;
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?atoi(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<int>());
        }
        if(obj.contains("cpumodelfile"))
        {
            msg.cpumodelfile = (obj["cpumodelfile"].is_string()?(obj["cpumodelfile"].get<std::string>().c_str()):obj["cpumodelfile"].get<std::string>());
        }
        if(obj.contains("gpumodelfile"))
        {
            msg.gpumodelfile = (obj["gpumodelfile"].is_string()?(obj["gpumodelfile"].get<std::string>().c_str()):obj["gpumodelfile"].get<std::string>());
        }
        if(obj.contains("usecuda"))
        {
            msg.usecuda = (obj["usecuda"].is_string()?(bool)atoi(obj["usecuda"].get<std::string>().c_str()):obj["usecuda"].get<bool>());
        }
        if(obj.contains("trajectorydeltat"))
        {
            msg.trajectorydeltat = (obj["trajectorydeltat"].is_string()?atof(obj["trajectorydeltat"].get<std::string>().c_str()):obj["trajectorydeltat"].get<double>());
        }
        if(obj.contains("allowemptylearningbaseddata"))
        {
            msg.allowemptylearningbaseddata = (obj["allowemptylearningbaseddata"].is_string()?(bool)atoi(obj["allowemptylearningbaseddata"].get<std::string>().c_str()):obj["allowemptylearningbaseddata"].get<bool>());
        }
        if(obj.contains("allowemptyoutputtrajectory"))
        {
            msg.allowemptyoutputtrajectory = (obj["allowemptyoutputtrajectory"].is_string()?(bool)atoi(obj["allowemptyoutputtrajectory"].get<std::string>().c_str()):obj["allowemptyoutputtrajectory"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningLearningModelInferenceTaskConfig from_json<ApolloplanningLearningModelInferenceTaskConfig>(nlohmann::json obj){
        return from_json_ApolloplanningLearningModelInferenceTaskConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningModelInferenceTaskConfig &dt)
    {
        dt=from_json_ApolloplanningLearningModelInferenceTaskConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningModelInferenceTaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningModelInferenceTaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
