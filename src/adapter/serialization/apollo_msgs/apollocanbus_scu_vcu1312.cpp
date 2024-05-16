#include "adapter/serialization/apollo_msgs/apollocanbus_scu_vcu1312.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuVcu1312 &msg) {
        nlohmann::json obj;
        obj["vcuelcsysfault"] = (msg.vcuelcsysfault);
        obj["vcubrkpedst"] = (msg.vcubrkpedst);
        obj["vcuintidx"] = (msg.vcuintidx);
        obj["vcugearintidx"] = (msg.vcugearintidx);
        obj["vcugeardrvmode"] = (msg.vcugeardrvmode);
        obj["vcuaccpedact"] = (msg.vcuaccpedact);
        obj["vcubrkpedpst"] = (msg.vcubrkpedpst);
        obj["vcuvehrng"] = (msg.vcuvehrng);
        obj["vcuaccpedpst"] = (msg.vcuaccpedpst);
        obj["vcuvehrdyst"] = (msg.vcuvehrdyst);
        obj["vcufaultst"] = (msg.vcufaultst);
        obj["vcudrvmode"] = (msg.vcudrvmode);
        obj["vcugearpst"] = (msg.vcugearpst);
        obj["vcugearfaultst"] = (msg.vcugearfaultst);
        obj["vcugearact"] = (msg.vcugearact);
        return obj;
    }
    ApollocanbusScuVcu1312 from_json_ApollocanbusScuVcu1312 (nlohmann::json obj) {
        ApollocanbusScuVcu1312 msg;
        if(obj.contains("vcuelcsysfault"))
        {
            msg.vcuelcsysfault = (obj["vcuelcsysfault"].is_string()?atoi(obj["vcuelcsysfault"].get<std::string>().c_str()):obj["vcuelcsysfault"].get<int>());
        }
        if(obj.contains("vcubrkpedst"))
        {
            msg.vcubrkpedst = (obj["vcubrkpedst"].is_string()?atoi(obj["vcubrkpedst"].get<std::string>().c_str()):obj["vcubrkpedst"].get<int>());
        }
        if(obj.contains("vcuintidx"))
        {
            msg.vcuintidx = (obj["vcuintidx"].is_string()?atoi(obj["vcuintidx"].get<std::string>().c_str()):obj["vcuintidx"].get<int>());
        }
        if(obj.contains("vcugearintidx"))
        {
            msg.vcugearintidx = (obj["vcugearintidx"].is_string()?atoi(obj["vcugearintidx"].get<std::string>().c_str()):obj["vcugearintidx"].get<int>());
        }
        if(obj.contains("vcugeardrvmode"))
        {
            msg.vcugeardrvmode = (obj["vcugeardrvmode"].is_string()?atoi(obj["vcugeardrvmode"].get<std::string>().c_str()):obj["vcugeardrvmode"].get<int>());
        }
        if(obj.contains("vcuaccpedact"))
        {
            msg.vcuaccpedact = (obj["vcuaccpedact"].is_string()?atof(obj["vcuaccpedact"].get<std::string>().c_str()):obj["vcuaccpedact"].get<double>());
        }
        if(obj.contains("vcubrkpedpst"))
        {
            msg.vcubrkpedpst = (obj["vcubrkpedpst"].is_string()?atof(obj["vcubrkpedpst"].get<std::string>().c_str()):obj["vcubrkpedpst"].get<double>());
        }
        if(obj.contains("vcuvehrng"))
        {
            msg.vcuvehrng = (obj["vcuvehrng"].is_string()?atoi(obj["vcuvehrng"].get<std::string>().c_str()):obj["vcuvehrng"].get<int>());
        }
        if(obj.contains("vcuaccpedpst"))
        {
            msg.vcuaccpedpst = (obj["vcuaccpedpst"].is_string()?atof(obj["vcuaccpedpst"].get<std::string>().c_str()):obj["vcuaccpedpst"].get<double>());
        }
        if(obj.contains("vcuvehrdyst"))
        {
            msg.vcuvehrdyst = (obj["vcuvehrdyst"].is_string()?atoi(obj["vcuvehrdyst"].get<std::string>().c_str()):obj["vcuvehrdyst"].get<int>());
        }
        if(obj.contains("vcufaultst"))
        {
            msg.vcufaultst = (obj["vcufaultst"].is_string()?atoi(obj["vcufaultst"].get<std::string>().c_str()):obj["vcufaultst"].get<int>());
        }
        if(obj.contains("vcudrvmode"))
        {
            msg.vcudrvmode = (obj["vcudrvmode"].is_string()?atoi(obj["vcudrvmode"].get<std::string>().c_str()):obj["vcudrvmode"].get<int>());
        }
        if(obj.contains("vcugearpst"))
        {
            msg.vcugearpst = (obj["vcugearpst"].is_string()?atoi(obj["vcugearpst"].get<std::string>().c_str()):obj["vcugearpst"].get<int>());
        }
        if(obj.contains("vcugearfaultst"))
        {
            msg.vcugearfaultst = (obj["vcugearfaultst"].is_string()?atoi(obj["vcugearfaultst"].get<std::string>().c_str()):obj["vcugearfaultst"].get<int>());
        }
        if(obj.contains("vcugearact"))
        {
            msg.vcugearact = (obj["vcugearact"].is_string()?atoi(obj["vcugearact"].get<std::string>().c_str()):obj["vcugearact"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuVcu1312 from_json<ApollocanbusScuVcu1312>(nlohmann::json obj){
        return from_json_ApollocanbusScuVcu1312(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuVcu1312 &dt)
    {
        dt=from_json_ApollocanbusScuVcu1312(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuVcu1312 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuVcu1312 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
