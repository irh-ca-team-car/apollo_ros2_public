#include "adapter/serialization/apollo_msgs/apollocommon_drive_event.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonDriveEvent &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["event"] = (msg.event);
        obj["location"] = to_json(msg.location);
        nlohmann::json arr_type;
        for (auto it = msg.type.begin(); it != msg.type.end(); ++it) {
            arr_type.push_back((*it));
        }
        obj["type"] = arr_type;
        obj["isreportable"] = (msg.isreportable);
        return obj;
    }
    ApollocommonDriveEvent from_json_ApollocommonDriveEvent (nlohmann::json obj) {
        ApollocommonDriveEvent msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("event"))
        {
            msg.event = (obj["event"].is_string()?(obj["event"].get<std::string>().c_str()):obj["event"].get<std::string>());
        }
        if(obj.contains("location"))
        {
            msg.location = from_json_ApollolocalizationPose(obj["location"]);
        }
        if(obj.contains("type"))
        {
            if(obj["type"].is_array())
            {
                for (auto& element : obj["type"])
                {
                    msg.type.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.type.push_back((obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>()));
            }
        }
        if(obj.contains("isreportable"))
        {
            msg.isreportable = (obj["isreportable"].is_string()?(bool)atoi(obj["isreportable"].get<std::string>().c_str()):obj["isreportable"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocommonDriveEvent from_json<ApollocommonDriveEvent>(nlohmann::json obj){
        return from_json_ApollocommonDriveEvent(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonDriveEvent &dt)
    {
        dt=from_json_ApollocommonDriveEvent(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonDriveEvent & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonDriveEvent & dt)
    {
        os << to_json(dt);
        return os;
    }
}
