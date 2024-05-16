#include "adapter/serialization/apollo_msgs/apolloperception_debug_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionDebugMessage &msg) {
        nlohmann::json obj;
        nlohmann::json arr_trajectory;
        for (auto it = msg.trajectory.begin(); it != msg.trajectory.end(); ++it) {
            arr_trajectory.push_back(to_json(*it));
        }
        obj["trajectory"] = arr_trajectory;
        return obj;
    }
    ApolloperceptionDebugMessage from_json_ApolloperceptionDebugMessage (nlohmann::json obj) {
        ApolloperceptionDebugMessage msg;
        if(obj.contains("trajectory"))
        {
            if(obj["trajectory"].is_array())
            {
                for (auto& element : obj["trajectory"])
                {
                    msg.trajectory.push_back(from_json_ApolloperceptionTrajectory(element));
                }
            }
            else
            {
                msg.trajectory.push_back(from_json_ApolloperceptionTrajectory(obj["trajectory"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionDebugMessage from_json<ApolloperceptionDebugMessage>(nlohmann::json obj){
        return from_json_ApolloperceptionDebugMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionDebugMessage &dt)
    {
        dt=from_json_ApolloperceptionDebugMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionDebugMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionDebugMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
