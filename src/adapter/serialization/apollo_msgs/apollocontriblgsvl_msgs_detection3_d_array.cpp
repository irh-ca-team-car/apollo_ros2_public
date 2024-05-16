#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection3_d_array.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsDetection3DArray &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_detections;
        for (auto it = msg.detections.begin(); it != msg.detections.end(); ++it) {
            arr_detections.push_back(to_json(*it));
        }
        obj["detections"] = arr_detections;
        return obj;
    }
    ApollocontriblgsvlMsgsDetection3DArray from_json_ApollocontriblgsvlMsgsDetection3DArray (nlohmann::json obj) {
        ApollocontriblgsvlMsgsDetection3DArray msg;
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
                    msg.detections.push_back(from_json_ApollocontriblgsvlMsgsDetection3D(element));
                }
            }
            else
            {
                msg.detections.push_back(from_json_ApollocontriblgsvlMsgsDetection3D(obj["detections"]));
            }
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsDetection3DArray from_json<ApollocontriblgsvlMsgsDetection3DArray>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsDetection3DArray(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsDetection3DArray &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsDetection3DArray(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsDetection3DArray & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsDetection3DArray & dt)
    {
        os << to_json(dt);
        return os;
    }
}
