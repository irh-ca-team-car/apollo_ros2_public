#include "adapter/serialization/apollo_msgs/apollocanbus_occupancy_rpt415.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusOccupancyRpt415 &msg) {
        nlohmann::json obj;
        obj["rearseatbeltbuckledisvalid"] = (msg.rearseatbeltbuckledisvalid);
        obj["passseatbeltbuckledisvalid"] = (msg.passseatbeltbuckledisvalid);
        obj["driverseatbeltbuckledisvalid"] = (msg.driverseatbeltbuckledisvalid);
        obj["rearseatoccupiedisvalid"] = (msg.rearseatoccupiedisvalid);
        obj["passseatoccupiedisvalid"] = (msg.passseatoccupiedisvalid);
        obj["driverseatoccupiedisvalid"] = (msg.driverseatoccupiedisvalid);
        obj["rearseatbeltbuckled"] = (msg.rearseatbeltbuckled);
        obj["passseatbeltbuckled"] = (msg.passseatbeltbuckled);
        obj["driverseatbeltbuckled"] = (msg.driverseatbeltbuckled);
        obj["rearseatoccupied"] = (msg.rearseatoccupied);
        obj["passseatoccupied"] = (msg.passseatoccupied);
        obj["driverseatoccupied"] = (msg.driverseatoccupied);
        return obj;
    }
    ApollocanbusOccupancyRpt415 from_json_ApollocanbusOccupancyRpt415 (nlohmann::json obj) {
        ApollocanbusOccupancyRpt415 msg;
        if(obj.contains("rearseatbeltbuckledisvalid"))
        {
            msg.rearseatbeltbuckledisvalid = (obj["rearseatbeltbuckledisvalid"].is_string()?(bool)atoi(obj["rearseatbeltbuckledisvalid"].get<std::string>().c_str()):obj["rearseatbeltbuckledisvalid"].get<bool>());
        }
        if(obj.contains("passseatbeltbuckledisvalid"))
        {
            msg.passseatbeltbuckledisvalid = (obj["passseatbeltbuckledisvalid"].is_string()?(bool)atoi(obj["passseatbeltbuckledisvalid"].get<std::string>().c_str()):obj["passseatbeltbuckledisvalid"].get<bool>());
        }
        if(obj.contains("driverseatbeltbuckledisvalid"))
        {
            msg.driverseatbeltbuckledisvalid = (obj["driverseatbeltbuckledisvalid"].is_string()?(bool)atoi(obj["driverseatbeltbuckledisvalid"].get<std::string>().c_str()):obj["driverseatbeltbuckledisvalid"].get<bool>());
        }
        if(obj.contains("rearseatoccupiedisvalid"))
        {
            msg.rearseatoccupiedisvalid = (obj["rearseatoccupiedisvalid"].is_string()?(bool)atoi(obj["rearseatoccupiedisvalid"].get<std::string>().c_str()):obj["rearseatoccupiedisvalid"].get<bool>());
        }
        if(obj.contains("passseatoccupiedisvalid"))
        {
            msg.passseatoccupiedisvalid = (obj["passseatoccupiedisvalid"].is_string()?(bool)atoi(obj["passseatoccupiedisvalid"].get<std::string>().c_str()):obj["passseatoccupiedisvalid"].get<bool>());
        }
        if(obj.contains("driverseatoccupiedisvalid"))
        {
            msg.driverseatoccupiedisvalid = (obj["driverseatoccupiedisvalid"].is_string()?(bool)atoi(obj["driverseatoccupiedisvalid"].get<std::string>().c_str()):obj["driverseatoccupiedisvalid"].get<bool>());
        }
        if(obj.contains("rearseatbeltbuckled"))
        {
            msg.rearseatbeltbuckled = (obj["rearseatbeltbuckled"].is_string()?(bool)atoi(obj["rearseatbeltbuckled"].get<std::string>().c_str()):obj["rearseatbeltbuckled"].get<bool>());
        }
        if(obj.contains("passseatbeltbuckled"))
        {
            msg.passseatbeltbuckled = (obj["passseatbeltbuckled"].is_string()?(bool)atoi(obj["passseatbeltbuckled"].get<std::string>().c_str()):obj["passseatbeltbuckled"].get<bool>());
        }
        if(obj.contains("driverseatbeltbuckled"))
        {
            msg.driverseatbeltbuckled = (obj["driverseatbeltbuckled"].is_string()?(bool)atoi(obj["driverseatbeltbuckled"].get<std::string>().c_str()):obj["driverseatbeltbuckled"].get<bool>());
        }
        if(obj.contains("rearseatoccupied"))
        {
            msg.rearseatoccupied = (obj["rearseatoccupied"].is_string()?(bool)atoi(obj["rearseatoccupied"].get<std::string>().c_str()):obj["rearseatoccupied"].get<bool>());
        }
        if(obj.contains("passseatoccupied"))
        {
            msg.passseatoccupied = (obj["passseatoccupied"].is_string()?(bool)atoi(obj["passseatoccupied"].get<std::string>().c_str()):obj["passseatoccupied"].get<bool>());
        }
        if(obj.contains("driverseatoccupied"))
        {
            msg.driverseatoccupied = (obj["driverseatoccupied"].is_string()?(bool)atoi(obj["driverseatoccupied"].get<std::string>().c_str()):obj["driverseatoccupied"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusOccupancyRpt415 from_json<ApollocanbusOccupancyRpt415>(nlohmann::json obj){
        return from_json_ApollocanbusOccupancyRpt415(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusOccupancyRpt415 &dt)
    {
        dt=from_json_ApollocanbusOccupancyRpt415(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusOccupancyRpt415 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusOccupancyRpt415 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
