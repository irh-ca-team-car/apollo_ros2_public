#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle24f1.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle24f1 &msg) {
        nlohmann::json obj;
        obj["canrxvolvoshorttrackroc"] = (msg.canrxvolvoshorttrackroc);
        obj["canrxmronlytransmit"] = (msg.canrxmronlytransmit);
        obj["canrxlronlytransmit"] = (msg.canrxlronlytransmit);
        obj["canrxhighyawangle"] = (msg.canrxhighyawangle);
        obj["canrxclearfaults"] = (msg.canrxclearfaults);
        obj["canrxuseanglemisalignment"] = (msg.canrxuseanglemisalignment);
        obj["canrxturnsignalstatus"] = (msg.canrxturnsignalstatus);
        obj["canrxblockagedisable"] = (msg.canrxblockagedisable);
        obj["canrxvehiclespeedvalidity"] = (msg.canrxvehiclespeedvalidity);
        obj["canrxmmrupsidedown"] = (msg.canrxmmrupsidedown);
        obj["canrxwiperstatus"] = (msg.canrxwiperstatus);
        obj["canrxrawdataenable"] = (msg.canrxrawdataenable);
        obj["canrxradarcmdradiate"] = (msg.canrxradarcmdradiate);
        obj["canrxgroupingmode"] = (msg.canrxgroupingmode);
        obj["canrxmaximumtracks"] = (msg.canrxmaximumtracks);
        obj["canrxlateralmountingoffset"] = (msg.canrxlateralmountingoffset);
        obj["canrxanglemisalignment"] = (msg.canrxanglemisalignment);
        obj["canrxscanindexack"] = (msg.canrxscanindexack);
        return obj;
    }
    ApollodriversVehicle24f1 from_json_ApollodriversVehicle24f1 (nlohmann::json obj) {
        ApollodriversVehicle24f1 msg;
        if(obj.contains("canrxvolvoshorttrackroc"))
        {
            msg.canrxvolvoshorttrackroc = (obj["canrxvolvoshorttrackroc"].is_string()?atof(obj["canrxvolvoshorttrackroc"].get<std::string>().c_str()):obj["canrxvolvoshorttrackroc"].get<double>());
        }
        if(obj.contains("canrxmronlytransmit"))
        {
            msg.canrxmronlytransmit = (obj["canrxmronlytransmit"].is_string()?atoi(obj["canrxmronlytransmit"].get<std::string>().c_str()):obj["canrxmronlytransmit"].get<int>());
        }
        if(obj.contains("canrxlronlytransmit"))
        {
            msg.canrxlronlytransmit = (obj["canrxlronlytransmit"].is_string()?atoi(obj["canrxlronlytransmit"].get<std::string>().c_str()):obj["canrxlronlytransmit"].get<int>());
        }
        if(obj.contains("canrxhighyawangle"))
        {
            msg.canrxhighyawangle = (obj["canrxhighyawangle"].is_string()?atoi(obj["canrxhighyawangle"].get<std::string>().c_str()):obj["canrxhighyawangle"].get<int>());
        }
        if(obj.contains("canrxclearfaults"))
        {
            msg.canrxclearfaults = (obj["canrxclearfaults"].is_string()?atoi(obj["canrxclearfaults"].get<std::string>().c_str()):obj["canrxclearfaults"].get<int>());
        }
        if(obj.contains("canrxuseanglemisalignment"))
        {
            msg.canrxuseanglemisalignment = (obj["canrxuseanglemisalignment"].is_string()?atoi(obj["canrxuseanglemisalignment"].get<std::string>().c_str()):obj["canrxuseanglemisalignment"].get<int>());
        }
        if(obj.contains("canrxturnsignalstatus"))
        {
            msg.canrxturnsignalstatus = (obj["canrxturnsignalstatus"].is_string()?atoi(obj["canrxturnsignalstatus"].get<std::string>().c_str()):obj["canrxturnsignalstatus"].get<int>());
        }
        if(obj.contains("canrxblockagedisable"))
        {
            msg.canrxblockagedisable = (obj["canrxblockagedisable"].is_string()?atoi(obj["canrxblockagedisable"].get<std::string>().c_str()):obj["canrxblockagedisable"].get<int>());
        }
        if(obj.contains("canrxvehiclespeedvalidity"))
        {
            msg.canrxvehiclespeedvalidity = (obj["canrxvehiclespeedvalidity"].is_string()?atoi(obj["canrxvehiclespeedvalidity"].get<std::string>().c_str()):obj["canrxvehiclespeedvalidity"].get<int>());
        }
        if(obj.contains("canrxmmrupsidedown"))
        {
            msg.canrxmmrupsidedown = (obj["canrxmmrupsidedown"].is_string()?atoi(obj["canrxmmrupsidedown"].get<std::string>().c_str()):obj["canrxmmrupsidedown"].get<int>());
        }
        if(obj.contains("canrxwiperstatus"))
        {
            msg.canrxwiperstatus = (obj["canrxwiperstatus"].is_string()?atoi(obj["canrxwiperstatus"].get<std::string>().c_str()):obj["canrxwiperstatus"].get<int>());
        }
        if(obj.contains("canrxrawdataenable"))
        {
            msg.canrxrawdataenable = (obj["canrxrawdataenable"].is_string()?atoi(obj["canrxrawdataenable"].get<std::string>().c_str()):obj["canrxrawdataenable"].get<int>());
        }
        if(obj.contains("canrxradarcmdradiate"))
        {
            msg.canrxradarcmdradiate = (obj["canrxradarcmdradiate"].is_string()?atoi(obj["canrxradarcmdradiate"].get<std::string>().c_str()):obj["canrxradarcmdradiate"].get<int>());
        }
        if(obj.contains("canrxgroupingmode"))
        {
            msg.canrxgroupingmode = (obj["canrxgroupingmode"].is_string()?atoi(obj["canrxgroupingmode"].get<std::string>().c_str()):obj["canrxgroupingmode"].get<int>());
        }
        if(obj.contains("canrxmaximumtracks"))
        {
            msg.canrxmaximumtracks = (obj["canrxmaximumtracks"].is_string()?atoi(obj["canrxmaximumtracks"].get<std::string>().c_str()):obj["canrxmaximumtracks"].get<int>());
        }
        if(obj.contains("canrxlateralmountingoffset"))
        {
            msg.canrxlateralmountingoffset = (obj["canrxlateralmountingoffset"].is_string()?atof(obj["canrxlateralmountingoffset"].get<std::string>().c_str()):obj["canrxlateralmountingoffset"].get<double>());
        }
        if(obj.contains("canrxanglemisalignment"))
        {
            msg.canrxanglemisalignment = (obj["canrxanglemisalignment"].is_string()?atof(obj["canrxanglemisalignment"].get<std::string>().c_str()):obj["canrxanglemisalignment"].get<double>());
        }
        if(obj.contains("canrxscanindexack"))
        {
            msg.canrxscanindexack = (obj["canrxscanindexack"].is_string()?atoi(obj["canrxscanindexack"].get<std::string>().c_str()):obj["canrxscanindexack"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversVehicle24f1 from_json<ApollodriversVehicle24f1>(nlohmann::json obj){
        return from_json_ApollodriversVehicle24f1(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle24f1 &dt)
    {
        dt=from_json_ApollodriversVehicle24f1(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle24f1 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle24f1 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
