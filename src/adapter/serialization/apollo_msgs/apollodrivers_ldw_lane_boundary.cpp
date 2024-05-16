#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lane_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwLaneBoundary &msg) {
        nlohmann::json obj;
        obj["degree"] = (msg.degree);
        obj["c0position"] = (msg.c0position);
        obj["c1headingangle"] = (msg.c1headingangle);
        obj["c2curvature"] = (msg.c2curvature);
        obj["c3curvaturederivative"] = (msg.c3curvaturederivative);
        return obj;
    }
    ApollodriversLdwLaneBoundary from_json_ApollodriversLdwLaneBoundary (nlohmann::json obj) {
        ApollodriversLdwLaneBoundary msg;
        if(obj.contains("degree"))
        {
            msg.degree = (obj["degree"].is_string()?atoi(obj["degree"].get<std::string>().c_str()):obj["degree"].get<int>());
        }
        if(obj.contains("c0position"))
        {
            msg.c0position = (obj["c0position"].is_string()?atof(obj["c0position"].get<std::string>().c_str()):obj["c0position"].get<double>());
        }
        if(obj.contains("c1headingangle"))
        {
            msg.c1headingangle = (obj["c1headingangle"].is_string()?atof(obj["c1headingangle"].get<std::string>().c_str()):obj["c1headingangle"].get<double>());
        }
        if(obj.contains("c2curvature"))
        {
            msg.c2curvature = (obj["c2curvature"].is_string()?atof(obj["c2curvature"].get<std::string>().c_str()):obj["c2curvature"].get<double>());
        }
        if(obj.contains("c3curvaturederivative"))
        {
            msg.c3curvaturederivative = (obj["c3curvaturederivative"].is_string()?atof(obj["c3curvaturederivative"].get<std::string>().c_str()):obj["c3curvaturederivative"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversLdwLaneBoundary from_json<ApollodriversLdwLaneBoundary>(nlohmann::json obj){
        return from_json_ApollodriversLdwLaneBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwLaneBoundary &dt)
    {
        dt=from_json_ApollodriversLdwLaneBoundary(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwLaneBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwLaneBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
}
