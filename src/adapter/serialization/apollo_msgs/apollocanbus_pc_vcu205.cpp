#include "adapter/serialization/apollo_msgs/apollocanbus_pc_vcu205.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusPcVcu205 &msg) {
        nlohmann::json obj;
        obj["pcaccpedreq"] = (msg.pcaccpedreq);
        obj["pcaccpedenable"] = (msg.pcaccpedenable);
        obj["pctorqreq"] = (msg.pctorqreq);
        obj["pctorqenable"] = (msg.pctorqenable);
        obj["pcgearreq"] = (msg.pcgearreq);
        obj["pcgearenable"] = (msg.pcgearenable);
        return obj;
    }
    ApollocanbusPcVcu205 from_json_ApollocanbusPcVcu205 (nlohmann::json obj) {
        ApollocanbusPcVcu205 msg;
        if(obj.contains("pcaccpedreq"))
        {
            msg.pcaccpedreq = (obj["pcaccpedreq"].is_string()?atof(obj["pcaccpedreq"].get<std::string>().c_str()):obj["pcaccpedreq"].get<double>());
        }
        if(obj.contains("pcaccpedenable"))
        {
            msg.pcaccpedenable = (obj["pcaccpedenable"].is_string()?atoi(obj["pcaccpedenable"].get<std::string>().c_str()):obj["pcaccpedenable"].get<int>());
        }
        if(obj.contains("pctorqreq"))
        {
            msg.pctorqreq = (obj["pctorqreq"].is_string()?atof(obj["pctorqreq"].get<std::string>().c_str()):obj["pctorqreq"].get<double>());
        }
        if(obj.contains("pctorqenable"))
        {
            msg.pctorqenable = (obj["pctorqenable"].is_string()?atoi(obj["pctorqenable"].get<std::string>().c_str()):obj["pctorqenable"].get<int>());
        }
        if(obj.contains("pcgearreq"))
        {
            msg.pcgearreq = (obj["pcgearreq"].is_string()?atoi(obj["pcgearreq"].get<std::string>().c_str()):obj["pcgearreq"].get<int>());
        }
        if(obj.contains("pcgearenable"))
        {
            msg.pcgearenable = (obj["pcgearenable"].is_string()?atoi(obj["pcgearenable"].get<std::string>().c_str()):obj["pcgearenable"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusPcVcu205 from_json<ApollocanbusPcVcu205>(nlohmann::json obj){
        return from_json_ApollocanbusPcVcu205(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusPcVcu205 &dt)
    {
        dt=from_json_ApollocanbusPcVcu205(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusPcVcu205 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusPcVcu205 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
