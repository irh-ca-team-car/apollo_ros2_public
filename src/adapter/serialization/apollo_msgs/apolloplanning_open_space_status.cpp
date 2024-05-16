#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceStatus &msg) {
        nlohmann::json obj;
        nlohmann::json arr_partitionedtrajectoriesindexhistory;
        for (auto it = msg.partitionedtrajectoriesindexhistory.begin(); it != msg.partitionedtrajectoriesindexhistory.end(); ++it) {
            arr_partitionedtrajectoriesindexhistory.push_back((*it));
        }
        obj["partitionedtrajectoriesindexhistory"] = arr_partitionedtrajectoriesindexhistory;
        obj["positioninit"] = (msg.positioninit);
        return obj;
    }
    ApolloplanningOpenSpaceStatus from_json_ApolloplanningOpenSpaceStatus (nlohmann::json obj) {
        ApolloplanningOpenSpaceStatus msg;
        if(obj.contains("partitionedtrajectoriesindexhistory"))
        {
            if(obj["partitionedtrajectoriesindexhistory"].is_array())
            {
                for (auto& element : obj["partitionedtrajectoriesindexhistory"])
                {
                    msg.partitionedtrajectoriesindexhistory.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.partitionedtrajectoriesindexhistory.push_back((obj["partitionedtrajectoriesindexhistory"].is_string()?(obj["partitionedtrajectoriesindexhistory"].get<std::string>().c_str()):obj["partitionedtrajectoriesindexhistory"].get<std::string>()));
            }
        }
        if(obj.contains("positioninit"))
        {
            msg.positioninit = (obj["positioninit"].is_string()?(bool)atoi(obj["positioninit"].get<std::string>().c_str()):obj["positioninit"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpaceStatus from_json<ApolloplanningOpenSpaceStatus>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpaceStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceStatus &dt)
    {
        dt=from_json_ApolloplanningOpenSpaceStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
