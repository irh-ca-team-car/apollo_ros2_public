#include "adapter/serialization/apollo_msgs/apolloplanning_qp_matrix.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQPMatrix &msg) {
        nlohmann::json obj;
        obj["rowsize"] = (msg.rowsize);
        obj["colsize"] = (msg.colsize);
        nlohmann::json arr_element;
        for (auto it = msg.element.begin(); it != msg.element.end(); ++it) {
            arr_element.push_back((*it));
        }
        obj["element"] = arr_element;
        return obj;
    }
    ApolloplanningQPMatrix from_json_ApolloplanningQPMatrix (nlohmann::json obj) {
        ApolloplanningQPMatrix msg;
        if(obj.contains("rowsize"))
        {
            msg.rowsize = (obj["rowsize"].is_string()?atoi(obj["rowsize"].get<std::string>().c_str()):obj["rowsize"].get<int>());
        }
        if(obj.contains("colsize"))
        {
            msg.colsize = (obj["colsize"].is_string()?atoi(obj["colsize"].get<std::string>().c_str()):obj["colsize"].get<int>());
        }
        if(obj.contains("element"))
        {
            if(obj["element"].is_array())
            {
                for (auto& element : obj["element"])
                {
                    msg.element.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.element.push_back((obj["element"].is_string()?atof(obj["element"].get<std::string>().c_str()):obj["element"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningQPMatrix from_json<ApolloplanningQPMatrix>(nlohmann::json obj){
        return from_json_ApolloplanningQPMatrix(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQPMatrix &dt)
    {
        dt=from_json_ApolloplanningQPMatrix(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQPMatrix & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQPMatrix & dt)
    {
        os << to_json(dt);
        return os;
    }
}
