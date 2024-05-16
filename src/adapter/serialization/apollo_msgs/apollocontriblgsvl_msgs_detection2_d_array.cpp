#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection2_d_array.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsDetection2DArray &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_detections;
        for (auto it = msg.detections.begin(); it != msg.detections.end(); ++it) {
            arr_detections.push_back(to_json(*it));
        }
        obj["detections"] = arr_detections;
        return obj;
    }
    ApollocontriblgsvlMsgsDetection2DArray from_json_ApollocontriblgsvlMsgsDetection2DArray (nlohmann::json obj) {
        ApollocontriblgsvlMsgsDetection2DArray msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("detections"))
        {
            if(obj["detections"].is_array())
            {
                for (auto& element : obj["detections"])
                {
                    msg.detections.push_back(from_json_ApollocontriblgsvlMsgsDetection2D(element));
                }
            }
            else
            {
                msg.detections.push_back(from_json_ApollocontriblgsvlMsgsDetection2D(obj["detections"]));
            }
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsDetection2DArray from_json<ApollocontriblgsvlMsgsDetection2DArray>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsDetection2DArray(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsDetection2DArray &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsDetection2DArray(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsDetection2DArray & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsDetection2DArray & dt)
    {
        os << to_json(dt);
        return os;
    }
}
