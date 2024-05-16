#include "adapter/serialization/apollo_msgs/apollodata_smart_record_trigger.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataSmartRecordTrigger &msg) {
        nlohmann::json obj;
        obj["segmentsetting"] = to_json(msg.segmentsetting);
        nlohmann::json arr_triggers;
        for (auto it = msg.triggers.begin(); it != msg.triggers.end(); ++it) {
            arr_triggers.push_back(to_json(*it));
        }
        obj["triggers"] = arr_triggers;
        obj["maxbackwardtime"] = (msg.maxbackwardtime);
        obj["minrestorechunk"] = (msg.minrestorechunk);
        obj["triggerlogfilepath"] = (msg.triggerlogfilepath);
        return obj;
    }
    ApollodataSmartRecordTrigger from_json_ApollodataSmartRecordTrigger (nlohmann::json obj) {
        ApollodataSmartRecordTrigger msg;
        if(obj.contains("segmentsetting"))
        {
            msg.segmentsetting = from_json_ApollodataRecordSegmentSetting(obj["segmentsetting"]);
        }
        if(obj.contains("triggers"))
        {
            if(obj["triggers"].is_array())
            {
                for (auto& element : obj["triggers"])
                {
                    msg.triggers.push_back(from_json_ApollodataTrigger(element));
                }
            }
            else
            {
                msg.triggers.push_back(from_json_ApollodataTrigger(obj["triggers"]));
            }
        }
        if(obj.contains("maxbackwardtime"))
        {
            msg.maxbackwardtime = (obj["maxbackwardtime"].is_string()?atof(obj["maxbackwardtime"].get<std::string>().c_str()):obj["maxbackwardtime"].get<double>());
        }
        if(obj.contains("minrestorechunk"))
        {
            msg.minrestorechunk = (obj["minrestorechunk"].is_string()?atof(obj["minrestorechunk"].get<std::string>().c_str()):obj["minrestorechunk"].get<double>());
        }
        if(obj.contains("triggerlogfilepath"))
        {
            msg.triggerlogfilepath = (obj["triggerlogfilepath"].is_string()?(obj["triggerlogfilepath"].get<std::string>().c_str()):obj["triggerlogfilepath"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodataSmartRecordTrigger from_json<ApollodataSmartRecordTrigger>(nlohmann::json obj){
        return from_json_ApollodataSmartRecordTrigger(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataSmartRecordTrigger &dt)
    {
        dt=from_json_ApollodataSmartRecordTrigger(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataSmartRecordTrigger & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataSmartRecordTrigger & dt)
    {
        os << to_json(dt);
        return os;
    }
}
