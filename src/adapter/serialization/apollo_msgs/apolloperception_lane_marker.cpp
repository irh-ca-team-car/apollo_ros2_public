#include "adapter/serialization/apollo_msgs/apolloperception_lane_marker.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionLaneMarker &msg) {
        nlohmann::json obj;
        obj["lanetype"] = (msg.lanetype);
        obj["quality"] = (msg.quality);
        obj["modeldegree"] = (msg.modeldegree);
        obj["c0position"] = (msg.c0position);
        obj["c1headingangle"] = (msg.c1headingangle);
        obj["c2curvature"] = (msg.c2curvature);
        obj["c3curvaturederivative"] = (msg.c3curvaturederivative);
        obj["viewrange"] = (msg.viewrange);
        obj["longitudestart"] = (msg.longitudestart);
        obj["longitudeend"] = (msg.longitudeend);
        return obj;
    }
    ApolloperceptionLaneMarker from_json_ApolloperceptionLaneMarker (nlohmann::json obj) {
        ApolloperceptionLaneMarker msg;
        if(obj.contains("lanetype"))
        {
            msg.lanetype = (obj["lanetype"].is_string()?atoi(obj["lanetype"].get<std::string>().c_str()):obj["lanetype"].get<int>());
        }
        if(obj.contains("quality"))
        {
            msg.quality = (obj["quality"].is_string()?atof(obj["quality"].get<std::string>().c_str()):obj["quality"].get<double>());
        }
        if(obj.contains("modeldegree"))
        {
            msg.modeldegree = (obj["modeldegree"].is_string()?atoi(obj["modeldegree"].get<std::string>().c_str()):obj["modeldegree"].get<int>());
        }
        if(obj.contains("c0position"))
        {
            msg.c0position = (obj["c0position"].is_string()?atof(obj["c0position"].get<std::string>().c_str()):obj["c0position"].get<double>());
        }
        if(obj.contains("c1headingangle"))
        {
            msg.c1headingangle = (obj["c1headingangle"].is_string()?atof(obj["c1headingangle"].get<std::string>().c_str()):obj["c1headingangle"].get<double>());
        }
        if(obj.contains("c2curvature"))
        {
            msg.c2curvature = (obj["c2curvature"].is_string()?atof(obj["c2curvature"].get<std::string>().c_str()):obj["c2curvature"].get<double>());
        }
        if(obj.contains("c3curvaturederivative"))
        {
            msg.c3curvaturederivative = (obj["c3curvaturederivative"].is_string()?atof(obj["c3curvaturederivative"].get<std::string>().c_str()):obj["c3curvaturederivative"].get<double>());
        }
        if(obj.contains("viewrange"))
        {
            msg.viewrange = (obj["viewrange"].is_string()?atof(obj["viewrange"].get<std::string>().c_str()):obj["viewrange"].get<double>());
        }
        if(obj.contains("longitudestart"))
        {
            msg.longitudestart = (obj["longitudestart"].is_string()?atof(obj["longitudestart"].get<std::string>().c_str()):obj["longitudestart"].get<double>());
        }
        if(obj.contains("longitudeend"))
        {
            msg.longitudeend = (obj["longitudeend"].is_string()?atof(obj["longitudeend"].get<std::string>().c_str()):obj["longitudeend"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionLaneMarker from_json<ApolloperceptionLaneMarker>(nlohmann::json obj){
        return from_json_ApolloperceptionLaneMarker(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionLaneMarker &dt)
    {
        dt=from_json_ApolloperceptionLaneMarker(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionLaneMarker & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionLaneMarker & dt)
    {
        os << to_json(dt);
        return os;
    }
}
