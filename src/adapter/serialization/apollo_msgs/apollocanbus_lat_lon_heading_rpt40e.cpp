#include "adapter/serialization/apollo_msgs/apollocanbus_lat_lon_heading_rpt40e.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLatLonHeadingRpt40e &msg) {
        nlohmann::json obj;
        obj["heading"] = (msg.heading);
        obj["longitudeseconds"] = (msg.longitudeseconds);
        obj["longitudeminutes"] = (msg.longitudeminutes);
        obj["longitudedegrees"] = (msg.longitudedegrees);
        obj["latitudeseconds"] = (msg.latitudeseconds);
        obj["latitudeminutes"] = (msg.latitudeminutes);
        obj["latitudedegrees"] = (msg.latitudedegrees);
        return obj;
    }
    ApollocanbusLatLonHeadingRpt40e from_json_ApollocanbusLatLonHeadingRpt40e (nlohmann::json obj) {
        ApollocanbusLatLonHeadingRpt40e msg;
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("longitudeseconds"))
        {
            msg.longitudeseconds = (obj["longitudeseconds"].is_string()?atoi(obj["longitudeseconds"].get<std::string>().c_str()):obj["longitudeseconds"].get<int>());
        }
        if(obj.contains("longitudeminutes"))
        {
            msg.longitudeminutes = (obj["longitudeminutes"].is_string()?atoi(obj["longitudeminutes"].get<std::string>().c_str()):obj["longitudeminutes"].get<int>());
        }
        if(obj.contains("longitudedegrees"))
        {
            msg.longitudedegrees = (obj["longitudedegrees"].is_string()?atoi(obj["longitudedegrees"].get<std::string>().c_str()):obj["longitudedegrees"].get<int>());
        }
        if(obj.contains("latitudeseconds"))
        {
            msg.latitudeseconds = (obj["latitudeseconds"].is_string()?atoi(obj["latitudeseconds"].get<std::string>().c_str()):obj["latitudeseconds"].get<int>());
        }
        if(obj.contains("latitudeminutes"))
        {
            msg.latitudeminutes = (obj["latitudeminutes"].is_string()?atoi(obj["latitudeminutes"].get<std::string>().c_str()):obj["latitudeminutes"].get<int>());
        }
        if(obj.contains("latitudedegrees"))
        {
            msg.latitudedegrees = (obj["latitudedegrees"].is_string()?atoi(obj["latitudedegrees"].get<std::string>().c_str()):obj["latitudedegrees"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusLatLonHeadingRpt40e from_json<ApollocanbusLatLonHeadingRpt40e>(nlohmann::json obj){
        return from_json_ApollocanbusLatLonHeadingRpt40e(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLatLonHeadingRpt40e &dt)
    {
        dt=from_json_ApollocanbusLatLonHeadingRpt40e(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLatLonHeadingRpt40e & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLatLonHeadingRpt40e & dt)
    {
        os << to_json(dt);
        return os;
    }
}
