#include "adapter/serialization/apollo_msgs/apolloperceptioncameradenseline_network_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameradenselineNetworkParam &msg) {
        nlohmann::json obj;
        obj["inblob"] = (msg.inblob);
        obj["outblob"] = (msg.outblob);
        nlohmann::json arr_internalblobint8;
        for (auto it = msg.internalblobint8.begin(); it != msg.internalblobint8.end(); ++it) {
            arr_internalblobint8.push_back((*it));
        }
        obj["internalblobint8"] = arr_internalblobint8;
        return obj;
    }
    ApolloperceptioncameradenselineNetworkParam from_json_ApolloperceptioncameradenselineNetworkParam (nlohmann::json obj) {
        ApolloperceptioncameradenselineNetworkParam msg;
        if(obj.contains("inblob"))
        {
            msg.inblob = (obj["inblob"].is_string()?(obj["inblob"].get<std::string>().c_str()):obj["inblob"].get<std::string>());
        }
        if(obj.contains("outblob"))
        {
            msg.outblob = (obj["outblob"].is_string()?(obj["outblob"].get<std::string>().c_str()):obj["outblob"].get<std::string>());
        }
        if(obj.contains("internalblobint8"))
        {
            if(obj["internalblobint8"].is_array())
            {
                for (auto& element : obj["internalblobint8"])
                {
                    msg.internalblobint8.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.internalblobint8.push_back((obj["internalblobint8"].is_string()?(obj["internalblobint8"].get<std::string>().c_str()):obj["internalblobint8"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioncameradenselineNetworkParam from_json<ApolloperceptioncameradenselineNetworkParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameradenselineNetworkParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameradenselineNetworkParam &dt)
    {
        dt=from_json_ApolloperceptioncameradenselineNetworkParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameradenselineNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameradenselineNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
