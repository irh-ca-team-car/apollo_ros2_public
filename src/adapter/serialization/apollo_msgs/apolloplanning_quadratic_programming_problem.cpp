#include "adapter/serialization/apollo_msgs/apolloplanning_quadratic_programming_problem.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQuadraticProgrammingProblem &msg) {
        nlohmann::json obj;
        obj["paramsize"] = (msg.paramsize);
        obj["quadraticmatrix"] = to_json(msg.quadraticmatrix);
        nlohmann::json arr_bias;
        for (auto it = msg.bias.begin(); it != msg.bias.end(); ++it) {
            arr_bias.push_back((*it));
        }
        obj["bias"] = arr_bias;
        obj["equalitymatrix"] = to_json(msg.equalitymatrix);
        nlohmann::json arr_equalityvalue;
        for (auto it = msg.equalityvalue.begin(); it != msg.equalityvalue.end(); ++it) {
            arr_equalityvalue.push_back((*it));
        }
        obj["equalityvalue"] = arr_equalityvalue;
        obj["inequalitymatrix"] = to_json(msg.inequalitymatrix);
        nlohmann::json arr_inequalityvalue;
        for (auto it = msg.inequalityvalue.begin(); it != msg.inequalityvalue.end(); ++it) {
            arr_inequalityvalue.push_back((*it));
        }
        obj["inequalityvalue"] = arr_inequalityvalue;
        nlohmann::json arr_inputmarker;
        for (auto it = msg.inputmarker.begin(); it != msg.inputmarker.end(); ++it) {
            arr_inputmarker.push_back((*it));
        }
        obj["inputmarker"] = arr_inputmarker;
        nlohmann::json arr_optimalparam;
        for (auto it = msg.optimalparam.begin(); it != msg.optimalparam.end(); ++it) {
            arr_optimalparam.push_back((*it));
        }
        obj["optimalparam"] = arr_optimalparam;
        return obj;
    }
    ApolloplanningQuadraticProgrammingProblem from_json_ApolloplanningQuadraticProgrammingProblem (nlohmann::json obj) {
        ApolloplanningQuadraticProgrammingProblem msg;
        if(obj.contains("paramsize"))
        {
            msg.paramsize = (obj["paramsize"].is_string()?atoi(obj["paramsize"].get<std::string>().c_str()):obj["paramsize"].get<int>());
        }
        if(obj.contains("quadraticmatrix"))
        {
            msg.quadraticmatrix = from_json_ApolloplanningQPMatrix(obj["quadraticmatrix"]);
        }
        if(obj.contains("bias"))
        {
            if(obj["bias"].is_array())
            {
                for (auto& element : obj["bias"])
                {
                    msg.bias.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.bias.push_back((obj["bias"].is_string()?atof(obj["bias"].get<std::string>().c_str()):obj["bias"].get<double>()));
            }
        }
        if(obj.contains("equalitymatrix"))
        {
            msg.equalitymatrix = from_json_ApolloplanningQPMatrix(obj["equalitymatrix"]);
        }
        if(obj.contains("equalityvalue"))
        {
            if(obj["equalityvalue"].is_array())
            {
                for (auto& element : obj["equalityvalue"])
                {
                    msg.equalityvalue.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.equalityvalue.push_back((obj["equalityvalue"].is_string()?atof(obj["equalityvalue"].get<std::string>().c_str()):obj["equalityvalue"].get<double>()));
            }
        }
        if(obj.contains("inequalitymatrix"))
        {
            msg.inequalitymatrix = from_json_ApolloplanningQPMatrix(obj["inequalitymatrix"]);
        }
        if(obj.contains("inequalityvalue"))
        {
            if(obj["inequalityvalue"].is_array())
            {
                for (auto& element : obj["inequalityvalue"])
                {
                    msg.inequalityvalue.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.inequalityvalue.push_back((obj["inequalityvalue"].is_string()?atof(obj["inequalityvalue"].get<std::string>().c_str()):obj["inequalityvalue"].get<double>()));
            }
        }
        if(obj.contains("inputmarker"))
        {
            if(obj["inputmarker"].is_array())
            {
                for (auto& element : obj["inputmarker"])
                {
                    msg.inputmarker.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.inputmarker.push_back((obj["inputmarker"].is_string()?atof(obj["inputmarker"].get<std::string>().c_str()):obj["inputmarker"].get<double>()));
            }
        }
        if(obj.contains("optimalparam"))
        {
            if(obj["optimalparam"].is_array())
            {
                for (auto& element : obj["optimalparam"])
                {
                    msg.optimalparam.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.optimalparam.push_back((obj["optimalparam"].is_string()?atof(obj["optimalparam"].get<std::string>().c_str()):obj["optimalparam"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningQuadraticProgrammingProblem from_json<ApolloplanningQuadraticProgrammingProblem>(nlohmann::json obj){
        return from_json_ApolloplanningQuadraticProgrammingProblem(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQuadraticProgrammingProblem &dt)
    {
        dt=from_json_ApolloplanningQuadraticProgrammingProblem(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQuadraticProgrammingProblem & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQuadraticProgrammingProblem & dt)
    {
        os << to_json(dt);
        return os;
    }
}
