#include "adapter/serialization/apollo_msgs/data_extraction_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const DataExtractionConfig &msg) {
        nlohmann::json obj;
        obj["ioconfig"] = to_json(msg.ioconfig);
        obj["channels"] = to_json(msg.channels);
        obj["records"] = to_json(msg.records);
        return obj;
    }
    DataExtractionConfig from_json_DataExtractionConfig (nlohmann::json obj) {
        DataExtractionConfig msg;
        if(obj.contains("ioconfig"))
        {
            msg.ioconfig = from_json_IoConfig(obj["ioconfig"]);
        }
        if(obj.contains("channels"))
        {
            msg.channels = from_json_Channels(obj["channels"]);
        }
        if(obj.contains("records"))
        {
            msg.records = from_json_Records(obj["records"]);
        }
        return msg;
    }
    template <>
    DataExtractionConfig from_json<DataExtractionConfig>(nlohmann::json obj){
        return from_json_DataExtractionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, DataExtractionConfig &dt)
    {
        dt=from_json_DataExtractionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const DataExtractionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const DataExtractionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
