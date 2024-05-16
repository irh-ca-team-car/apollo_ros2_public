#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_lane_line_cubic_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraLaneLineCubicCurve &msg) {
        nlohmann::json obj;
        obj["longitudemin"] = (msg.longitudemin);
        obj["longitudemax"] = (msg.longitudemax);
        obj["a"] = (msg.a);
        obj["b"] = (msg.b);
        obj["c"] = (msg.c);
        obj["d"] = (msg.d);
        return obj;
    }
    ApolloperceptioncameraLaneLineCubicCurve from_json_ApolloperceptioncameraLaneLineCubicCurve (nlohmann::json obj) {
        ApolloperceptioncameraLaneLineCubicCurve msg;
        if(obj.contains("longitudemin"))
        {
            msg.longitudemin = (obj["longitudemin"].is_string()?(float)atof(obj["longitudemin"].get<std::string>().c_str()):obj["longitudemin"].get<float>());
        }
        if(obj.contains("longitudemax"))
        {
            msg.longitudemax = (obj["longitudemax"].is_string()?(float)atof(obj["longitudemax"].get<std::string>().c_str()):obj["longitudemax"].get<float>());
        }
        if(obj.contains("a"))
        {
            msg.a = (obj["a"].is_string()?(float)atof(obj["a"].get<std::string>().c_str()):obj["a"].get<float>());
        }
        if(obj.contains("b"))
        {
            msg.b = (obj["b"].is_string()?(float)atof(obj["b"].get<std::string>().c_str()):obj["b"].get<float>());
        }
        if(obj.contains("c"))
        {
            msg.c = (obj["c"].is_string()?(float)atof(obj["c"].get<std::string>().c_str()):obj["c"].get<float>());
        }
        if(obj.contains("d"))
        {
            msg.d = (obj["d"].is_string()?(float)atof(obj["d"].get<std::string>().c_str()):obj["d"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraLaneLineCubicCurve from_json<ApolloperceptioncameraLaneLineCubicCurve>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraLaneLineCubicCurve(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraLaneLineCubicCurve &dt)
    {
        dt=from_json_ApolloperceptioncameraLaneLineCubicCurve(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraLaneLineCubicCurve & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraLaneLineCubicCurve & dt)
    {
        os << to_json(dt);
        return os;
    }
}
