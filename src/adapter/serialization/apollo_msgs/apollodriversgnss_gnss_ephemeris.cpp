#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss_ephemeris.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnssEphemeris &msg) {
        nlohmann::json obj;
        obj["gnsstype"] = (msg.gnsstype);
        obj["kepplerorbit"] = to_json(msg.kepplerorbit);
        obj["glonassorbit"] = to_json(msg.glonassorbit);
        return obj;
    }
    ApollodriversgnssGnssEphemeris from_json_ApollodriversgnssGnssEphemeris (nlohmann::json obj) {
        ApollodriversgnssGnssEphemeris msg;
        if(obj.contains("gnsstype"))
        {
            msg.gnsstype = (obj["gnsstype"].is_string()?atoi(obj["gnsstype"].get<std::string>().c_str()):obj["gnsstype"].get<int>());
        }
        if(obj.contains("kepplerorbit"))
        {
            msg.kepplerorbit = from_json_ApollodriversgnssKepplerOrbit(obj["kepplerorbit"]);
        }
        if(obj.contains("glonassorbit"))
        {
            msg.glonassorbit = from_json_ApollodriversgnssGlonassOrbit(obj["glonassorbit"]);
        }
        return msg;
    }
    template <>
    ApollodriversgnssGnssEphemeris from_json<ApollodriversgnssGnssEphemeris>(nlohmann::json obj){
        return from_json_ApollodriversgnssGnssEphemeris(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnssEphemeris &dt)
    {
        dt=from_json_ApollodriversgnssGnssEphemeris(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnssEphemeris & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnssEphemeris & dt)
    {
        os << to_json(dt);
        return os;
    }
}
