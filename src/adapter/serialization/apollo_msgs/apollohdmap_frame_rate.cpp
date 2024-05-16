#include "adapter/serialization/apollo_msgs/apollohdmap_frame_rate.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapFrameRate &msg) {
        nlohmann::json obj;
        obj["topic"] = (msg.topic);
        obj["expectedrate"] = (msg.expectedrate);
        obj["currentrate"] = (msg.currentrate);
        nlohmann::json arr_badrecordname;
        for (auto it = msg.badrecordname.begin(); it != msg.badrecordname.end(); ++it) {
            arr_badrecordname.push_back((*it));
        }
        obj["badrecordname"] = arr_badrecordname;
        return obj;
    }
    ApollohdmapFrameRate from_json_ApollohdmapFrameRate (nlohmann::json obj) {
        ApollohdmapFrameRate msg;
        if(obj.contains("topic"))
        {
            msg.topic = (obj["topic"].is_string()?(obj["topic"].get<std::string>().c_str()):obj["topic"].get<std::string>());
        }
        if(obj.contains("expectedrate"))
        {
            msg.expectedrate = (obj["expectedrate"].is_string()?atof(obj["expectedrate"].get<std::string>().c_str()):obj["expectedrate"].get<double>());
        }
        if(obj.contains("currentrate"))
        {
            msg.currentrate = (obj["currentrate"].is_string()?atof(obj["currentrate"].get<std::string>().c_str()):obj["currentrate"].get<double>());
        }
        if(obj.contains("badrecordname"))
        {
            if(obj["badrecordname"].is_array())
            {
                for (auto& element : obj["badrecordname"])
                {
                    msg.badrecordname.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.badrecordname.push_back((obj["badrecordname"].is_string()?(obj["badrecordname"].get<std::string>().c_str()):obj["badrecordname"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapFrameRate from_json<ApollohdmapFrameRate>(nlohmann::json obj){
        return from_json_ApollohdmapFrameRate(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapFrameRate &dt)
    {
        dt=from_json_ApollohdmapFrameRate(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapFrameRate & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapFrameRate & dt)
    {
        os << to_json(dt);
        return os;
    }
}
