#include "adapter/serialization/apollo_msgs/apollomonitor_system_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorSystemStatus &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_hmimodules;
        for (auto it = msg.hmimodules.begin(); it != msg.hmimodules.end(); ++it) {
            arr_hmimodules.push_back(to_json(*it));
        }
        obj["hmimodules"] = arr_hmimodules;
        nlohmann::json arr_components;
        for (auto it = msg.components.begin(); it != msg.components.end(); ++it) {
            arr_components.push_back(to_json(*it));
        }
        obj["components"] = arr_components;
        obj["passengermsg"] = (msg.passengermsg);
        obj["safetymodetriggertime"] = (msg.safetymodetriggertime);
        obj["requireemergencystop"] = (msg.requireemergencystop);
        obj["isrealtimeinsimulation"] = (msg.isrealtimeinsimulation);
        nlohmann::json arr_othercomponents;
        for (auto it = msg.othercomponents.begin(); it != msg.othercomponents.end(); ++it) {
            arr_othercomponents.push_back(to_json(*it));
        }
        obj["othercomponents"] = arr_othercomponents;
        return obj;
    }
    ApollomonitorSystemStatus from_json_ApollomonitorSystemStatus (nlohmann::json obj) {
        ApollomonitorSystemStatus msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("hmimodules"))
        {
            if(obj["hmimodules"].is_array())
            {
                for (auto& element : obj["hmimodules"])
                {
                    msg.hmimodules.push_back(from_json_ApollomonitorSystemStatushmiModules(element));
                }
            }
            else
            {
                msg.hmimodules.push_back(from_json_ApollomonitorSystemStatushmiModules(obj["hmimodules"]));
            }
        }
        if(obj.contains("components"))
        {
            if(obj["components"].is_array())
            {
                for (auto& element : obj["components"])
                {
                    msg.components.push_back(from_json_ApollomonitorSystemStatuscomponents(element));
                }
            }
            else
            {
                msg.components.push_back(from_json_ApollomonitorSystemStatuscomponents(obj["components"]));
            }
        }
        if(obj.contains("passengermsg"))
        {
            msg.passengermsg = (obj["passengermsg"].is_string()?(obj["passengermsg"].get<std::string>().c_str()):obj["passengermsg"].get<std::string>());
        }
        if(obj.contains("safetymodetriggertime"))
        {
            msg.safetymodetriggertime = (obj["safetymodetriggertime"].is_string()?atof(obj["safetymodetriggertime"].get<std::string>().c_str()):obj["safetymodetriggertime"].get<double>());
        }
        if(obj.contains("requireemergencystop"))
        {
            msg.requireemergencystop = (obj["requireemergencystop"].is_string()?(bool)atoi(obj["requireemergencystop"].get<std::string>().c_str()):obj["requireemergencystop"].get<bool>());
        }
        if(obj.contains("isrealtimeinsimulation"))
        {
            msg.isrealtimeinsimulation = (obj["isrealtimeinsimulation"].is_string()?(bool)atoi(obj["isrealtimeinsimulation"].get<std::string>().c_str()):obj["isrealtimeinsimulation"].get<bool>());
        }
        if(obj.contains("othercomponents"))
        {
            if(obj["othercomponents"].is_array())
            {
                for (auto& element : obj["othercomponents"])
                {
                    msg.othercomponents.push_back(from_json_ApollomonitorSystemStatusotherComponents(element));
                }
            }
            else
            {
                msg.othercomponents.push_back(from_json_ApollomonitorSystemStatusotherComponents(obj["othercomponents"]));
            }
        }
        return msg;
    }
    template <>
    ApollomonitorSystemStatus from_json<ApollomonitorSystemStatus>(nlohmann::json obj){
        return from_json_ApollomonitorSystemStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorSystemStatus &dt)
    {
        dt=from_json_ApollomonitorSystemStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollomonitorSystemStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorSystemStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
