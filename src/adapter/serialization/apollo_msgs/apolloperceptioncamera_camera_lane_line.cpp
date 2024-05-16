#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_camera_lane_line.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraCameraLaneLine &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["postype"] = (msg.postype);
        obj["curvecameracoord"] = to_json(msg.curvecameracoord);
        obj["curveimagecoord"] = to_json(msg.curveimagecoord);
        nlohmann::json arr_curvecamerapointset;
        for (auto it = msg.curvecamerapointset.begin(); it != msg.curvecamerapointset.end(); ++it) {
            arr_curvecamerapointset.push_back(to_json(*it));
        }
        obj["curvecamerapointset"] = arr_curvecamerapointset;
        nlohmann::json arr_curveimagepointset;
        for (auto it = msg.curveimagepointset.begin(); it != msg.curveimagepointset.end(); ++it) {
            arr_curveimagepointset.push_back(to_json(*it));
        }
        obj["curveimagepointset"] = arr_curveimagepointset;
        nlohmann::json arr_imageendpointset;
        for (auto it = msg.imageendpointset.begin(); it != msg.imageendpointset.end(); ++it) {
            arr_imageendpointset.push_back(to_json(*it));
        }
        obj["imageendpointset"] = arr_imageendpointset;
        obj["trackid"] = (msg.trackid);
        obj["confidence"] = (msg.confidence);
        obj["usetype"] = (msg.usetype);
        return obj;
    }
    ApolloperceptioncameraCameraLaneLine from_json_ApolloperceptioncameraCameraLaneLine (nlohmann::json obj) {
        ApolloperceptioncameraCameraLaneLine msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("postype"))
        {
            msg.postype = (obj["postype"].is_string()?atoi(obj["postype"].get<std::string>().c_str()):obj["postype"].get<int>());
        }
        if(obj.contains("curvecameracoord"))
        {
            msg.curvecameracoord = from_json_ApolloperceptioncameraLaneLineCubicCurve(obj["curvecameracoord"]);
        }
        if(obj.contains("curveimagecoord"))
        {
            msg.curveimagecoord = from_json_ApolloperceptioncameraLaneLineCubicCurve(obj["curveimagecoord"]);
        }
        if(obj.contains("curvecamerapointset"))
        {
            if(obj["curvecamerapointset"].is_array())
            {
                for (auto& element : obj["curvecamerapointset"])
                {
                    msg.curvecamerapointset.push_back(from_json_ApollocommonPoint3D(element));
                }
            }
            else
            {
                msg.curvecamerapointset.push_back(from_json_ApollocommonPoint3D(obj["curvecamerapointset"]));
            }
        }
        if(obj.contains("curveimagepointset"))
        {
            if(obj["curveimagepointset"].is_array())
            {
                for (auto& element : obj["curveimagepointset"])
                {
                    msg.curveimagepointset.push_back(from_json_ApollocommonPoint2D(element));
                }
            }
            else
            {
                msg.curveimagepointset.push_back(from_json_ApollocommonPoint2D(obj["curveimagepointset"]));
            }
        }
        if(obj.contains("imageendpointset"))
        {
            if(obj["imageendpointset"].is_array())
            {
                for (auto& element : obj["imageendpointset"])
                {
                    msg.imageendpointset.push_back(from_json_ApolloperceptioncameraEndPoints(element));
                }
            }
            else
            {
                msg.imageendpointset.push_back(from_json_ApolloperceptioncameraEndPoints(obj["imageendpointset"]));
            }
        }
        if(obj.contains("trackid"))
        {
            msg.trackid = (obj["trackid"].is_string()?atoi(obj["trackid"].get<std::string>().c_str()):obj["trackid"].get<int>());
        }
        if(obj.contains("confidence"))
        {
            msg.confidence = (obj["confidence"].is_string()?(float)atof(obj["confidence"].get<std::string>().c_str()):obj["confidence"].get<float>());
        }
        if(obj.contains("usetype"))
        {
            msg.usetype = (obj["usetype"].is_string()?atoi(obj["usetype"].get<std::string>().c_str()):obj["usetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraCameraLaneLine from_json<ApolloperceptioncameraCameraLaneLine>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraCameraLaneLine(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraCameraLaneLine &dt)
    {
        dt=from_json_ApolloperceptioncameraCameraLaneLine(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraCameraLaneLine & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraCameraLaneLine & dt)
    {
        os << to_json(dt);
        return os;
    }
}
