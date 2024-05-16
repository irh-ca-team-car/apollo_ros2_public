#include "adapter/serialization/apollo_msgs/apollodata_record_segment_setting.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataRecordSegmentSetting &msg) {
        nlohmann::json obj;
        obj["sizesegment"] = (msg.sizesegment);
        obj["timesegment"] = (msg.timesegment);
        return obj;
    }
    ApollodataRecordSegmentSetting from_json_ApollodataRecordSegmentSetting (nlohmann::json obj) {
        ApollodataRecordSegmentSetting msg;
        if(obj.contains("sizesegment"))
        {
            msg.sizesegment = (obj["sizesegment"].is_string()?atoi(obj["sizesegment"].get<std::string>().c_str()):obj["sizesegment"].get<int>());
        }
        if(obj.contains("timesegment"))
        {
            msg.timesegment = (obj["timesegment"].is_string()?atoi(obj["timesegment"].get<std::string>().c_str()):obj["timesegment"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodataRecordSegmentSetting from_json<ApollodataRecordSegmentSetting>(nlohmann::json obj){
        return from_json_ApollodataRecordSegmentSetting(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataRecordSegmentSetting &dt)
    {
        dt=from_json_ApollodataRecordSegmentSetting(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataRecordSegmentSetting & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataRecordSegmentSetting & dt)
    {
        os << to_json(dt);
        return os;
    }
}
