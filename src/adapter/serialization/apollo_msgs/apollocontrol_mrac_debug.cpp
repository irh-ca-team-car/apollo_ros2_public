#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMracDebug &msg) {
        nlohmann::json obj;
        obj["mracmodelorder"] = (msg.mracmodelorder);
        nlohmann::json arr_mracreferencestate;
        for (auto it = msg.mracreferencestate.begin(); it != msg.mracreferencestate.end(); ++it) {
            arr_mracreferencestate.push_back((*it));
        }
        obj["mracreferencestate"] = arr_mracreferencestate;
        nlohmann::json arr_mracstateerror;
        for (auto it = msg.mracstateerror.begin(); it != msg.mracstateerror.end(); ++it) {
            arr_mracstateerror.push_back((*it));
        }
        obj["mracstateerror"] = arr_mracstateerror;
        obj["mracadaptivegain"] = to_json(msg.mracadaptivegain);
        obj["mracreferencesaturationstatus"] = (msg.mracreferencesaturationstatus);
        obj["mraccontrolsaturationstatus"] = (msg.mraccontrolsaturationstatus);
        return obj;
    }
    ApollocontrolMracDebug from_json_ApollocontrolMracDebug (nlohmann::json obj) {
        ApollocontrolMracDebug msg;
        if(obj.contains("mracmodelorder"))
        {
            msg.mracmodelorder = (obj["mracmodelorder"].is_string()?atoi(obj["mracmodelorder"].get<std::string>().c_str()):obj["mracmodelorder"].get<int>());
        }
        if(obj.contains("mracreferencestate"))
        {
            if(obj["mracreferencestate"].is_array())
            {
                for (auto& element : obj["mracreferencestate"])
                {
                    msg.mracreferencestate.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.mracreferencestate.push_back((obj["mracreferencestate"].is_string()?atof(obj["mracreferencestate"].get<std::string>().c_str()):obj["mracreferencestate"].get<double>()));
            }
        }
        if(obj.contains("mracstateerror"))
        {
            if(obj["mracstateerror"].is_array())
            {
                for (auto& element : obj["mracstateerror"])
                {
                    msg.mracstateerror.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.mracstateerror.push_back((obj["mracstateerror"].is_string()?atof(obj["mracstateerror"].get<std::string>().c_str()):obj["mracstateerror"].get<double>()));
            }
        }
        if(obj.contains("mracadaptivegain"))
        {
            msg.mracadaptivegain = from_json_ApollocontrolMracAdaptiveGain(obj["mracadaptivegain"]);
        }
        if(obj.contains("mracreferencesaturationstatus"))
        {
            msg.mracreferencesaturationstatus = (obj["mracreferencesaturationstatus"].is_string()?atoi(obj["mracreferencesaturationstatus"].get<std::string>().c_str()):obj["mracreferencesaturationstatus"].get<int>());
        }
        if(obj.contains("mraccontrolsaturationstatus"))
        {
            msg.mraccontrolsaturationstatus = (obj["mraccontrolsaturationstatus"].is_string()?atoi(obj["mraccontrolsaturationstatus"].get<std::string>().c_str()):obj["mraccontrolsaturationstatus"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocontrolMracDebug from_json<ApollocontrolMracDebug>(nlohmann::json obj){
        return from_json_ApollocontrolMracDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMracDebug &dt)
    {
        dt=from_json_ApollocontrolMracDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMracDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMracDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
