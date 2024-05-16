#include "adapter/serialization/apollo_msgs/apolloplanning_object_stop.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectStop &msg) {
        nlohmann::json obj;
        obj["reasoncode"] = (msg.reasoncode);
        obj["distances"] = (msg.distances);
        obj["stoppoint"] = to_json(msg.stoppoint);
        obj["stopheading"] = (msg.stopheading);
        nlohmann::json arr_waitforobstacle;
        for (auto it = msg.waitforobstacle.begin(); it != msg.waitforobstacle.end(); ++it) {
            arr_waitforobstacle.push_back((*it));
        }
        obj["waitforobstacle"] = arr_waitforobstacle;
        return obj;
    }
    ApolloplanningObjectStop from_json_ApolloplanningObjectStop (nlohmann::json obj) {
        ApolloplanningObjectStop msg;
        if(obj.contains("reasoncode"))
        {
            msg.reasoncode = (obj["reasoncode"].is_string()?atoi(obj["reasoncode"].get<std::string>().c_str()):obj["reasoncode"].get<int>());
        }
        if(obj.contains("distances"))
        {
            msg.distances = (obj["distances"].is_string()?atof(obj["distances"].get<std::string>().c_str()):obj["distances"].get<double>());
        }
        if(obj.contains("stoppoint"))
        {
            msg.stoppoint = from_json_ApollocommonPointENU(obj["stoppoint"]);
        }
        if(obj.contains("stopheading"))
        {
            msg.stopheading = (obj["stopheading"].is_string()?atof(obj["stopheading"].get<std::string>().c_str()):obj["stopheading"].get<double>());
        }
        if(obj.contains("waitforobstacle"))
        {
            if(obj["waitforobstacle"].is_array())
            {
                for (auto& element : obj["waitforobstacle"])
                {
                    msg.waitforobstacle.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.waitforobstacle.push_back((obj["waitforobstacle"].is_string()?(obj["waitforobstacle"].get<std::string>().c_str()):obj["waitforobstacle"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningObjectStop from_json<ApolloplanningObjectStop>(nlohmann::json obj){
        return from_json_ApolloplanningObjectStop(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectStop &dt)
    {
        dt=from_json_ApolloplanningObjectStop(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectStop & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectStop & dt)
    {
        os << to_json(dt);
        return os;
    }
}
