#include "adapter/serialization/apollo_msgs/apolloprediction_list_frame_env.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionListFrameEnv &msg) {
        nlohmann::json obj;
        nlohmann::json arr_frameenv;
        for (auto it = msg.frameenv.begin(); it != msg.frameenv.end(); ++it) {
            arr_frameenv.push_back(to_json(*it));
        }
        obj["frameenv"] = arr_frameenv;
        return obj;
    }
    ApollopredictionListFrameEnv from_json_ApollopredictionListFrameEnv (nlohmann::json obj) {
        ApollopredictionListFrameEnv msg;
        if(obj.contains("frameenv"))
        {
            if(obj["frameenv"].is_array())
            {
                for (auto& element : obj["frameenv"])
                {
                    msg.frameenv.push_back(from_json_ApollopredictionFrameEnv(element));
                }
            }
            else
            {
                msg.frameenv.push_back(from_json_ApollopredictionFrameEnv(obj["frameenv"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionListFrameEnv from_json<ApollopredictionListFrameEnv>(nlohmann::json obj){
        return from_json_ApollopredictionListFrameEnv(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionListFrameEnv &dt)
    {
        dt=from_json_ApollopredictionListFrameEnv(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionListFrameEnv & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionListFrameEnv & dt)
    {
        os << to_json(dt);
        return os;
    }
}
