#include "adapter/serialization/apollo_msgs/apolloplanning_quadratic_programming_problem_set.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQuadraticProgrammingProblemSet &msg) {
        nlohmann::json obj;
        nlohmann::json arr_problem;
        for (auto it = msg.problem.begin(); it != msg.problem.end(); ++it) {
            arr_problem.push_back(to_json(*it));
        }
        obj["problem"] = arr_problem;
        return obj;
    }
    ApolloplanningQuadraticProgrammingProblemSet from_json_ApolloplanningQuadraticProgrammingProblemSet (nlohmann::json obj) {
        ApolloplanningQuadraticProgrammingProblemSet msg;
        if(obj.contains("problem"))
        {
            if(obj["problem"].is_array())
            {
                for (auto& element : obj["problem"])
                {
                    msg.problem.push_back(from_json_ApolloplanningQuadraticProgrammingProblem(element));
                }
            }
            else
            {
                msg.problem.push_back(from_json_ApolloplanningQuadraticProgrammingProblem(obj["problem"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningQuadraticProgrammingProblemSet from_json<ApolloplanningQuadraticProgrammingProblemSet>(nlohmann::json obj){
        return from_json_ApolloplanningQuadraticProgrammingProblemSet(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQuadraticProgrammingProblemSet &dt)
    {
        dt=from_json_ApolloplanningQuadraticProgrammingProblemSet(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQuadraticProgrammingProblemSet & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQuadraticProgrammingProblemSet & dt)
    {
        os << to_json(dt);
        return os;
    }
}
