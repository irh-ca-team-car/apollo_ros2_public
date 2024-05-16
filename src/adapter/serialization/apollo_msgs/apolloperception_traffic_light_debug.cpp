#include "adapter/serialization/apollo_msgs/apolloperception_traffic_light_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLightDebug &msg) {
        nlohmann::json obj;
        obj["cropbox"] = to_json(msg.cropbox);
        nlohmann::json arr_box;
        for (auto it = msg.box.begin(); it != msg.box.end(); ++it) {
            arr_box.push_back(to_json(*it));
        }
        obj["box"] = arr_box;
        obj["signalnum"] = (msg.signalnum);
        obj["validpos"] = (msg.validpos);
        obj["tsdiffpos"] = (msg.tsdiffpos);
        obj["tsdiffsys"] = (msg.tsdiffsys);
        obj["projecterror"] = (msg.projecterror);
        obj["distancetostopline"] = (msg.distancetostopline);
        obj["cameraid"] = (msg.cameraid);
        nlohmann::json arr_croproi;
        for (auto it = msg.croproi.begin(); it != msg.croproi.end(); ++it) {
            arr_croproi.push_back(to_json(*it));
        }
        obj["croproi"] = arr_croproi;
        nlohmann::json arr_projectedroi;
        for (auto it = msg.projectedroi.begin(); it != msg.projectedroi.end(); ++it) {
            arr_projectedroi.push_back(to_json(*it));
        }
        obj["projectedroi"] = arr_projectedroi;
        nlohmann::json arr_rectifiedroi;
        for (auto it = msg.rectifiedroi.begin(); it != msg.rectifiedroi.end(); ++it) {
            arr_rectifiedroi.push_back(to_json(*it));
        }
        obj["rectifiedroi"] = arr_rectifiedroi;
        nlohmann::json arr_debugroi;
        for (auto it = msg.debugroi.begin(); it != msg.debugroi.end(); ++it) {
            arr_debugroi.push_back(to_json(*it));
        }
        obj["debugroi"] = arr_debugroi;
        return obj;
    }
    ApolloperceptionTrafficLightDebug from_json_ApolloperceptionTrafficLightDebug (nlohmann::json obj) {
        ApolloperceptionTrafficLightDebug msg;
        if(obj.contains("cropbox"))
        {
            msg.cropbox = from_json_ApolloperceptionTrafficLightBox(obj["cropbox"]);
        }
        if(obj.contains("box"))
        {
            if(obj["box"].is_array())
            {
                for (auto& element : obj["box"])
                {
                    msg.box.push_back(from_json_ApolloperceptionTrafficLightBox(element));
                }
            }
            else
            {
                msg.box.push_back(from_json_ApolloperceptionTrafficLightBox(obj["box"]));
            }
        }
        if(obj.contains("signalnum"))
        {
            msg.signalnum = (obj["signalnum"].is_string()?atoi(obj["signalnum"].get<std::string>().c_str()):obj["signalnum"].get<int>());
        }
        if(obj.contains("validpos"))
        {
            msg.validpos = (obj["validpos"].is_string()?atoi(obj["validpos"].get<std::string>().c_str()):obj["validpos"].get<int>());
        }
        if(obj.contains("tsdiffpos"))
        {
            msg.tsdiffpos = (obj["tsdiffpos"].is_string()?atof(obj["tsdiffpos"].get<std::string>().c_str()):obj["tsdiffpos"].get<double>());
        }
        if(obj.contains("tsdiffsys"))
        {
            msg.tsdiffsys = (obj["tsdiffsys"].is_string()?atof(obj["tsdiffsys"].get<std::string>().c_str()):obj["tsdiffsys"].get<double>());
        }
        if(obj.contains("projecterror"))
        {
            msg.projecterror = (obj["projecterror"].is_string()?atoi(obj["projecterror"].get<std::string>().c_str()):obj["projecterror"].get<int>());
        }
        if(obj.contains("distancetostopline"))
        {
            msg.distancetostopline = (obj["distancetostopline"].is_string()?atof(obj["distancetostopline"].get<std::string>().c_str()):obj["distancetostopline"].get<double>());
        }
        if(obj.contains("cameraid"))
        {
            msg.cameraid = (obj["cameraid"].is_string()?atoi(obj["cameraid"].get<std::string>().c_str()):obj["cameraid"].get<int>());
        }
        if(obj.contains("croproi"))
        {
            if(obj["croproi"].is_array())
            {
                for (auto& element : obj["croproi"])
                {
                    msg.croproi.push_back(from_json_ApolloperceptionTrafficLightBox(element));
                }
            }
            else
            {
                msg.croproi.push_back(from_json_ApolloperceptionTrafficLightBox(obj["croproi"]));
            }
        }
        if(obj.contains("projectedroi"))
        {
            if(obj["projectedroi"].is_array())
            {
                for (auto& element : obj["projectedroi"])
                {
                    msg.projectedroi.push_back(from_json_ApolloperceptionTrafficLightBox(element));
                }
            }
            else
            {
                msg.projectedroi.push_back(from_json_ApolloperceptionTrafficLightBox(obj["projectedroi"]));
            }
        }
        if(obj.contains("rectifiedroi"))
        {
            if(obj["rectifiedroi"].is_array())
            {
                for (auto& element : obj["rectifiedroi"])
                {
                    msg.rectifiedroi.push_back(from_json_ApolloperceptionTrafficLightBox(element));
                }
            }
            else
            {
                msg.rectifiedroi.push_back(from_json_ApolloperceptionTrafficLightBox(obj["rectifiedroi"]));
            }
        }
        if(obj.contains("debugroi"))
        {
            if(obj["debugroi"].is_array())
            {
                for (auto& element : obj["debugroi"])
                {
                    msg.debugroi.push_back(from_json_ApolloperceptionTrafficLightBox(element));
                }
            }
            else
            {
                msg.debugroi.push_back(from_json_ApolloperceptionTrafficLightBox(obj["debugroi"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionTrafficLightDebug from_json<ApolloperceptionTrafficLightDebug>(nlohmann::json obj){
        return from_json_ApolloperceptionTrafficLightDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLightDebug &dt)
    {
        dt=from_json_ApolloperceptionTrafficLightDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLightDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLightDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
