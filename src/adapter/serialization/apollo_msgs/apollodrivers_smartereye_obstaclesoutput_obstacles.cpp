#include "adapter/serialization/apollo_msgs/apollodrivers_smartereye_obstaclesoutput_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversSmartereyeObstaclesoutputObstacles &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversSmartereyeObstaclesoutputObstacles from_json_ApollodriversSmartereyeObstaclesoutputObstacles (nlohmann::json obj) {
        ApollodriversSmartereyeObstaclesoutputObstacles msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?atoi(obj["key"].get<std::string>().c_str()):obj["key"].get<uint32_t>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollodriversOutputObstacle(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollodriversSmartereyeObstaclesoutputObstacles from_json<ApollodriversSmartereyeObstaclesoutputObstacles>(nlohmann::json obj){
        return from_json_ApollodriversSmartereyeObstaclesoutputObstacles(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversSmartereyeObstaclesoutputObstacles &dt)
    {
        dt=from_json_ApollodriversSmartereyeObstaclesoutputObstacles(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversSmartereyeObstaclesoutputObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversSmartereyeObstaclesoutputObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
}
