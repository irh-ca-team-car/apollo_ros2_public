#include "adapter/serialization/apollo_msgs/apollodrivers_details738.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails738 &msg) {
        nlohmann::json obj;
        obj["numobstacles"] = (msg.numobstacles);
        obj["timestamp"] = (msg.timestamp);
        obj["applicationversion"] = (msg.applicationversion);
        obj["activeversionnumbersection"] = (msg.activeversionnumbersection);
        obj["leftcloserangcutin"] = (msg.leftcloserangcutin);
        obj["rightcloserangcutin"] = (msg.rightcloserangcutin);
        obj["go"] = (msg.go);
        obj["protocolversion"] = (msg.protocolversion);
        obj["closecar"] = (msg.closecar);
        obj["failsafe"] = (msg.failsafe);
        obj["reserved10"] = (msg.reserved10);
        return obj;
    }
    ApollodriversDetails738 from_json_ApollodriversDetails738 (nlohmann::json obj) {
        ApollodriversDetails738 msg;
        if(obj.contains("numobstacles"))
        {
            msg.numobstacles = (obj["numobstacles"].is_string()?atoi(obj["numobstacles"].get<std::string>().c_str()):obj["numobstacles"].get<int>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atoi(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<int>());
        }
        if(obj.contains("applicationversion"))
        {
            msg.applicationversion = (obj["applicationversion"].is_string()?atoi(obj["applicationversion"].get<std::string>().c_str()):obj["applicationversion"].get<int>());
        }
        if(obj.contains("activeversionnumbersection"))
        {
            msg.activeversionnumbersection = (obj["activeversionnumbersection"].is_string()?atoi(obj["activeversionnumbersection"].get<std::string>().c_str()):obj["activeversionnumbersection"].get<int>());
        }
        if(obj.contains("leftcloserangcutin"))
        {
            msg.leftcloserangcutin = (obj["leftcloserangcutin"].is_string()?(bool)atoi(obj["leftcloserangcutin"].get<std::string>().c_str()):obj["leftcloserangcutin"].get<bool>());
        }
        if(obj.contains("rightcloserangcutin"))
        {
            msg.rightcloserangcutin = (obj["rightcloserangcutin"].is_string()?(bool)atoi(obj["rightcloserangcutin"].get<std::string>().c_str()):obj["rightcloserangcutin"].get<bool>());
        }
        if(obj.contains("go"))
        {
            msg.go = (obj["go"].is_string()?atoi(obj["go"].get<std::string>().c_str()):obj["go"].get<int>());
        }
        if(obj.contains("protocolversion"))
        {
            msg.protocolversion = (obj["protocolversion"].is_string()?atoi(obj["protocolversion"].get<std::string>().c_str()):obj["protocolversion"].get<int>());
        }
        if(obj.contains("closecar"))
        {
            msg.closecar = (obj["closecar"].is_string()?(bool)atoi(obj["closecar"].get<std::string>().c_str()):obj["closecar"].get<bool>());
        }
        if(obj.contains("failsafe"))
        {
            msg.failsafe = (obj["failsafe"].is_string()?atoi(obj["failsafe"].get<std::string>().c_str()):obj["failsafe"].get<int>());
        }
        if(obj.contains("reserved10"))
        {
            msg.reserved10 = (obj["reserved10"].is_string()?atoi(obj["reserved10"].get<std::string>().c_str()):obj["reserved10"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversDetails738 from_json<ApollodriversDetails738>(nlohmann::json obj){
        return from_json_ApollodriversDetails738(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails738 &dt)
    {
        dt=from_json_ApollodriversDetails738(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails738 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails738 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
