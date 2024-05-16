#include "adapter/serialization/apollo_msgs/apolloperception_motion_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMotionType &msg) {
        nlohmann::json obj;
        obj["m00"] = (msg.m00);
        obj["m01"] = (msg.m01);
        obj["m02"] = (msg.m02);
        obj["m03"] = (msg.m03);
        obj["m10"] = (msg.m10);
        obj["m11"] = (msg.m11);
        obj["m12"] = (msg.m12);
        obj["m13"] = (msg.m13);
        obj["m20"] = (msg.m20);
        obj["m21"] = (msg.m21);
        obj["m22"] = (msg.m22);
        obj["m23"] = (msg.m23);
        obj["m30"] = (msg.m30);
        obj["m31"] = (msg.m31);
        obj["m32"] = (msg.m32);
        obj["m33"] = (msg.m33);
        return obj;
    }
    ApolloperceptionMotionType from_json_ApolloperceptionMotionType (nlohmann::json obj) {
        ApolloperceptionMotionType msg;
        if(obj.contains("m00"))
        {
            msg.m00 = (obj["m00"].is_string()?(float)atof(obj["m00"].get<std::string>().c_str()):obj["m00"].get<float>());
        }
        if(obj.contains("m01"))
        {
            msg.m01 = (obj["m01"].is_string()?(float)atof(obj["m01"].get<std::string>().c_str()):obj["m01"].get<float>());
        }
        if(obj.contains("m02"))
        {
            msg.m02 = (obj["m02"].is_string()?(float)atof(obj["m02"].get<std::string>().c_str()):obj["m02"].get<float>());
        }
        if(obj.contains("m03"))
        {
            msg.m03 = (obj["m03"].is_string()?(float)atof(obj["m03"].get<std::string>().c_str()):obj["m03"].get<float>());
        }
        if(obj.contains("m10"))
        {
            msg.m10 = (obj["m10"].is_string()?(float)atof(obj["m10"].get<std::string>().c_str()):obj["m10"].get<float>());
        }
        if(obj.contains("m11"))
        {
            msg.m11 = (obj["m11"].is_string()?(float)atof(obj["m11"].get<std::string>().c_str()):obj["m11"].get<float>());
        }
        if(obj.contains("m12"))
        {
            msg.m12 = (obj["m12"].is_string()?(float)atof(obj["m12"].get<std::string>().c_str()):obj["m12"].get<float>());
        }
        if(obj.contains("m13"))
        {
            msg.m13 = (obj["m13"].is_string()?(float)atof(obj["m13"].get<std::string>().c_str()):obj["m13"].get<float>());
        }
        if(obj.contains("m20"))
        {
            msg.m20 = (obj["m20"].is_string()?(float)atof(obj["m20"].get<std::string>().c_str()):obj["m20"].get<float>());
        }
        if(obj.contains("m21"))
        {
            msg.m21 = (obj["m21"].is_string()?(float)atof(obj["m21"].get<std::string>().c_str()):obj["m21"].get<float>());
        }
        if(obj.contains("m22"))
        {
            msg.m22 = (obj["m22"].is_string()?(float)atof(obj["m22"].get<std::string>().c_str()):obj["m22"].get<float>());
        }
        if(obj.contains("m23"))
        {
            msg.m23 = (obj["m23"].is_string()?(float)atof(obj["m23"].get<std::string>().c_str()):obj["m23"].get<float>());
        }
        if(obj.contains("m30"))
        {
            msg.m30 = (obj["m30"].is_string()?(float)atof(obj["m30"].get<std::string>().c_str()):obj["m30"].get<float>());
        }
        if(obj.contains("m31"))
        {
            msg.m31 = (obj["m31"].is_string()?(float)atof(obj["m31"].get<std::string>().c_str()):obj["m31"].get<float>());
        }
        if(obj.contains("m32"))
        {
            msg.m32 = (obj["m32"].is_string()?(float)atof(obj["m32"].get<std::string>().c_str()):obj["m32"].get<float>());
        }
        if(obj.contains("m33"))
        {
            msg.m33 = (obj["m33"].is_string()?(float)atof(obj["m33"].get<std::string>().c_str()):obj["m33"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionMotionType from_json<ApolloperceptionMotionType>(nlohmann::json obj){
        return from_json_ApolloperceptionMotionType(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMotionType &dt)
    {
        dt=from_json_ApolloperceptionMotionType(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMotionType & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMotionType & dt)
    {
        os << to_json(dt);
        return os;
    }
}
