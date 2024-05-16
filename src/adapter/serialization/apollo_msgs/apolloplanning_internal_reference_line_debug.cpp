#include "adapter/serialization/apollo_msgs/apolloplanning_internal_reference_line_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalReferenceLineDebug &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["length"] = (msg.length);
        obj["cost"] = (msg.cost);
        obj["ischangelanepath"] = (msg.ischangelanepath);
        obj["isdrivable"] = (msg.isdrivable);
        obj["isprotected"] = (msg.isprotected);
        obj["isoffroad"] = (msg.isoffroad);
        obj["minimumboundary"] = (msg.minimumboundary);
        obj["averagekappa"] = (msg.averagekappa);
        obj["averagedkappa"] = (msg.averagedkappa);
        obj["kapparms"] = (msg.kapparms);
        obj["dkapparms"] = (msg.dkapparms);
        obj["kappamaxabs"] = (msg.kappamaxabs);
        obj["dkappamaxabs"] = (msg.dkappamaxabs);
        obj["averageoffset"] = (msg.averageoffset);
        return obj;
    }
    ApolloplanningInternalReferenceLineDebug from_json_ApolloplanningInternalReferenceLineDebug (nlohmann::json obj) {
        ApolloplanningInternalReferenceLineDebug msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("cost"))
        {
            msg.cost = (obj["cost"].is_string()?atof(obj["cost"].get<std::string>().c_str()):obj["cost"].get<double>());
        }
        if(obj.contains("ischangelanepath"))
        {
            msg.ischangelanepath = (obj["ischangelanepath"].is_string()?(bool)atoi(obj["ischangelanepath"].get<std::string>().c_str()):obj["ischangelanepath"].get<bool>());
        }
        if(obj.contains("isdrivable"))
        {
            msg.isdrivable = (obj["isdrivable"].is_string()?(bool)atoi(obj["isdrivable"].get<std::string>().c_str()):obj["isdrivable"].get<bool>());
        }
        if(obj.contains("isprotected"))
        {
            msg.isprotected = (obj["isprotected"].is_string()?(bool)atoi(obj["isprotected"].get<std::string>().c_str()):obj["isprotected"].get<bool>());
        }
        if(obj.contains("isoffroad"))
        {
            msg.isoffroad = (obj["isoffroad"].is_string()?(bool)atoi(obj["isoffroad"].get<std::string>().c_str()):obj["isoffroad"].get<bool>());
        }
        if(obj.contains("minimumboundary"))
        {
            msg.minimumboundary = (obj["minimumboundary"].is_string()?atof(obj["minimumboundary"].get<std::string>().c_str()):obj["minimumboundary"].get<double>());
        }
        if(obj.contains("averagekappa"))
        {
            msg.averagekappa = (obj["averagekappa"].is_string()?atof(obj["averagekappa"].get<std::string>().c_str()):obj["averagekappa"].get<double>());
        }
        if(obj.contains("averagedkappa"))
        {
            msg.averagedkappa = (obj["averagedkappa"].is_string()?atof(obj["averagedkappa"].get<std::string>().c_str()):obj["averagedkappa"].get<double>());
        }
        if(obj.contains("kapparms"))
        {
            msg.kapparms = (obj["kapparms"].is_string()?atof(obj["kapparms"].get<std::string>().c_str()):obj["kapparms"].get<double>());
        }
        if(obj.contains("dkapparms"))
        {
            msg.dkapparms = (obj["dkapparms"].is_string()?atof(obj["dkapparms"].get<std::string>().c_str()):obj["dkapparms"].get<double>());
        }
        if(obj.contains("kappamaxabs"))
        {
            msg.kappamaxabs = (obj["kappamaxabs"].is_string()?atof(obj["kappamaxabs"].get<std::string>().c_str()):obj["kappamaxabs"].get<double>());
        }
        if(obj.contains("dkappamaxabs"))
        {
            msg.dkappamaxabs = (obj["dkappamaxabs"].is_string()?atof(obj["dkappamaxabs"].get<std::string>().c_str()):obj["dkappamaxabs"].get<double>());
        }
        if(obj.contains("averageoffset"))
        {
            msg.averageoffset = (obj["averageoffset"].is_string()?atof(obj["averageoffset"].get<std::string>().c_str()):obj["averageoffset"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalReferenceLineDebug from_json<ApolloplanningInternalReferenceLineDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalReferenceLineDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalReferenceLineDebug &dt)
    {
        dt=from_json_ApolloplanningInternalReferenceLineDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalReferenceLineDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalReferenceLineDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
