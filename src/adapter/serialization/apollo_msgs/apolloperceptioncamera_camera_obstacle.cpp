#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraObstacle &msg) {
        nlohmann::json obj;
        obj["obstacle"] = to_json(msg.obstacle);
        obj["type"] = (msg.type);
        nlohmann::json arr_typeprobs;
        for (auto it = msg.typeprobs.begin(); it != msg.typeprobs.end(); ++it) {
            arr_typeprobs.push_back((*it));
        }
        obj["typeprobs"] = arr_typeprobs;
        obj["upperleft"] = to_json(msg.upperleft);
        obj["lowerright"] = to_json(msg.lowerright);
        nlohmann::json arr_keypoints;
        for (auto it = msg.keypoints.begin(); it != msg.keypoints.end(); ++it) {
            arr_keypoints.push_back(to_json(*it));
        }
        obj["keypoints"] = arr_keypoints;
        nlohmann::json arr_debugmessage;
        for (auto it = msg.debugmessage.begin(); it != msg.debugmessage.end(); ++it) {
            arr_debugmessage.push_back((*it));
        }
        obj["debugmessage"] = arr_debugmessage;
        return obj;
    }
    ApolloperceptioncameraCameraObstacle from_json_ApolloperceptioncameraCameraObstacle (nlohmann::json obj) {
        ApolloperceptioncameraCameraObstacle msg;
        if(obj.contains("obstacle"))
        {
            msg.obstacle = from_json_ApolloperceptionPerceptionObstacle(obj["obstacle"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("typeprobs"))
        {
            if(obj["typeprobs"].is_array())
            {
                for (auto& element : obj["typeprobs"])
                {
                    msg.typeprobs.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.typeprobs.push_back((obj["typeprobs"].is_string()?(float)atof(obj["typeprobs"].get<std::string>().c_str()):obj["typeprobs"].get<float>()));
            }
        }
        if(obj.contains("upperleft"))
        {
            msg.upperleft = from_json_ApollocommonPoint2D(obj["upperleft"]);
        }
        if(obj.contains("lowerright"))
        {
            msg.lowerright = from_json_ApollocommonPoint2D(obj["lowerright"]);
        }
        if(obj.contains("keypoints"))
        {
            if(obj["keypoints"].is_array())
            {
                for (auto& element : obj["keypoints"])
                {
                    msg.keypoints.push_back(from_json_ApollocommonPoint2D(element));
                }
            }
            else
            {
                msg.keypoints.push_back(from_json_ApollocommonPoint2D(obj["keypoints"]));
            }
        }
        if(obj.contains("debugmessage"))
        {
            if(obj["debugmessage"].is_array())
            {
                for (auto& element : obj["debugmessage"])
                {
                    msg.debugmessage.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.debugmessage.push_back((obj["debugmessage"].is_string()?(obj["debugmessage"].get<std::string>().c_str()):obj["debugmessage"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraCameraObstacle from_json<ApolloperceptioncameraCameraObstacle>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraCameraObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraObstacle &dt)
    {
        dt=from_json_ApolloperceptioncameraCameraObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
