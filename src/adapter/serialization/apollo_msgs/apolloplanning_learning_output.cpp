#include "adapter/serialization/apollo_msgs/apolloplanning_learning_output.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLearningOutput &msg) {
        nlohmann::json obj;
        nlohmann::json arr_adcfuturetrajectorypoint;
        for (auto it = msg.adcfuturetrajectorypoint.begin(); it != msg.adcfuturetrajectorypoint.end(); ++it) {
            arr_adcfuturetrajectorypoint.push_back(to_json(*it));
        }
        obj["adcfuturetrajectorypoint"] = arr_adcfuturetrajectorypoint;
        return obj;
    }
    ApolloplanningLearningOutput from_json_ApolloplanningLearningOutput (nlohmann::json obj) {
        ApolloplanningLearningOutput msg;
        if(obj.contains("adcfuturetrajectorypoint"))
        {
            if(obj["adcfuturetrajectorypoint"].is_array())
            {
                for (auto& element : obj["adcfuturetrajectorypoint"])
                {
                    msg.adcfuturetrajectorypoint.push_back(from_json_ApolloplanningTrajectoryPointFeature(element));
                }
            }
            else
            {
                msg.adcfuturetrajectorypoint.push_back(from_json_ApolloplanningTrajectoryPointFeature(obj["adcfuturetrajectorypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningLearningOutput from_json<ApolloplanningLearningOutput>(nlohmann::json obj){
        return from_json_ApolloplanningLearningOutput(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLearningOutput &dt)
    {
        dt=from_json_ApolloplanningLearningOutput(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLearningOutput & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLearningOutput & dt)
    {
        os << to_json(dt);
        return os;
    }
}
