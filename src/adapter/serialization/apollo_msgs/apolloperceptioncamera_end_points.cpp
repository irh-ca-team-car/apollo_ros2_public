#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_end_points.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraEndPoints &msg) {
        nlohmann::json obj;
        obj["start"] = to_json(msg.start);
        obj["end"] = to_json(msg.end);
        return obj;
    }
    ApolloperceptioncameraEndPoints from_json_ApolloperceptioncameraEndPoints (nlohmann::json obj) {
        ApolloperceptioncameraEndPoints msg;
        if(obj.contains("start"))
        {
            msg.start = from_json_ApollocommonPoint2D(obj["start"]);
        }
        if(obj.contains("end"))
        {
            msg.end = from_json_ApollocommonPoint2D(obj["end"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraEndPoints from_json<ApolloperceptioncameraEndPoints>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraEndPoints(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraEndPoints &dt)
    {
        dt=from_json_ApolloperceptioncameraEndPoints(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraEndPoints & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraEndPoints & dt)
    {
        os << to_json(dt);
        return os;
    }
}
