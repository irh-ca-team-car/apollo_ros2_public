#include "adapter/serialization/apollo_msgs/apolloperception_b_box2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionBBox2D &msg) {
        nlohmann::json obj;
        obj["xmin"] = (msg.xmin);
        obj["ymin"] = (msg.ymin);
        obj["xmax"] = (msg.xmax);
        obj["ymax"] = (msg.ymax);
        return obj;
    }
    ApolloperceptionBBox2D from_json_ApolloperceptionBBox2D (nlohmann::json obj) {
        ApolloperceptionBBox2D msg;
        if(obj.contains("xmin"))
        {
            msg.xmin = (obj["xmin"].is_string()?atof(obj["xmin"].get<std::string>().c_str()):obj["xmin"].get<double>());
        }
        if(obj.contains("ymin"))
        {
            msg.ymin = (obj["ymin"].is_string()?atof(obj["ymin"].get<std::string>().c_str()):obj["ymin"].get<double>());
        }
        if(obj.contains("xmax"))
        {
            msg.xmax = (obj["xmax"].is_string()?atof(obj["xmax"].get<std::string>().c_str()):obj["xmax"].get<double>());
        }
        if(obj.contains("ymax"))
        {
            msg.ymax = (obj["ymax"].is_string()?atof(obj["ymax"].get<std::string>().c_str()):obj["ymax"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionBBox2D from_json<ApolloperceptionBBox2D>(nlohmann::json obj){
        return from_json_ApolloperceptionBBox2D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionBBox2D &dt)
    {
        dt=from_json_ApolloperceptionBBox2D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionBBox2D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionBBox2D & dt)
    {
        os << to_json(dt);
        return os;
    }
}
