#include "adapter/serialization/apollo_msgs/apollodrivers_smartereye_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversSmartereyeObstacles &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["numobstacles"] = (msg.numobstacles);
        nlohmann::json arr_outputobstacles;
        for (auto it = msg.outputobstacles.begin(); it != msg.outputobstacles.end(); ++it) {
            arr_outputobstacles.push_back(to_json(*it));
        }
        obj["outputobstacles"] = arr_outputobstacles;
        return obj;
    }
    ApollodriversSmartereyeObstacles from_json_ApollodriversSmartereyeObstacles (nlohmann::json obj) {
        ApollodriversSmartereyeObstacles msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("numobstacles"))
        {
            msg.numobstacles = (obj["numobstacles"].is_string()?atoi(obj["numobstacles"].get<std::string>().c_str()):obj["numobstacles"].get<int>());
        }
        if(obj.contains("outputobstacles"))
        {
            if(obj["outputobstacles"].is_array())
            {
                for (auto& element : obj["outputobstacles"])
                {
                    msg.outputobstacles.push_back(from_json_ApollodriversSmartereyeObstaclesoutputObstacles(element));
                }
            }
            else
            {
                msg.outputobstacles.push_back(from_json_ApollodriversSmartereyeObstaclesoutputObstacles(obj["outputobstacles"]));
            }
        }
        return msg;
    }
    template <>
    ApollodriversSmartereyeObstacles from_json<ApollodriversSmartereyeObstacles>(nlohmann::json obj){
        return from_json_ApollodriversSmartereyeObstacles(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversSmartereyeObstacles &dt)
    {
        dt=from_json_ApollodriversSmartereyeObstacles(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversSmartereyeObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversSmartereyeObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
}
