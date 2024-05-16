#include "adapter/serialization/apollo_msgs/apollohdmap_loops_verify_request.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLoopsVerifyRequest &msg) {
        nlohmann::json obj;
        obj["cmd"] = (msg.cmd);
        obj["type"] = (msg.type);
        nlohmann::json arr_range;
        for (auto it = msg.range.begin(); it != msg.range.end(); ++it) {
            arr_range.push_back(to_json(*it));
        }
        obj["range"] = arr_range;
        return obj;
    }
    ApollohdmapLoopsVerifyRequest from_json_ApollohdmapLoopsVerifyRequest (nlohmann::json obj) {
        ApollohdmapLoopsVerifyRequest msg;
        if(obj.contains("cmd"))
        {
            msg.cmd = (obj["cmd"].is_string()?atoi(obj["cmd"].get<std::string>().c_str()):obj["cmd"].get<int>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("range"))
        {
            if(obj["range"].is_array())
            {
                for (auto& element : obj["range"])
                {
                    msg.range.push_back(from_json_ApollohdmapVerifyRange(element));
                }
            }
            else
            {
                msg.range.push_back(from_json_ApollohdmapVerifyRange(obj["range"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapLoopsVerifyRequest from_json<ApollohdmapLoopsVerifyRequest>(nlohmann::json obj){
        return from_json_ApollohdmapLoopsVerifyRequest(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLoopsVerifyRequest &dt)
    {
        dt=from_json_ApollohdmapLoopsVerifyRequest(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLoopsVerifyRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLoopsVerifyRequest & dt)
    {
        os << to_json(dt);
        return os;
    }
}
