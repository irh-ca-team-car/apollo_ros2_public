#include "adapter/serialization/apollo_msgs/apollocanbus_surround.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSurround &msg) {
        nlohmann::json obj;
        obj["crosstrafficalertleft"] = (msg.crosstrafficalertleft);
        obj["crosstrafficalertleftenabled"] = (msg.crosstrafficalertleftenabled);
        obj["blindspotleftalert"] = (msg.blindspotleftalert);
        obj["blindspotleftalertenabled"] = (msg.blindspotleftalertenabled);
        obj["crosstrafficalertright"] = (msg.crosstrafficalertright);
        obj["crosstrafficalertrightenabled"] = (msg.crosstrafficalertrightenabled);
        obj["blindspotrightalert"] = (msg.blindspotrightalert);
        obj["blindspotrightalertenabled"] = (msg.blindspotrightalertenabled);
        obj["sonar00"] = (msg.sonar00);
        obj["sonar01"] = (msg.sonar01);
        obj["sonar02"] = (msg.sonar02);
        obj["sonar03"] = (msg.sonar03);
        obj["sonar04"] = (msg.sonar04);
        obj["sonar05"] = (msg.sonar05);
        obj["sonar06"] = (msg.sonar06);
        obj["sonar07"] = (msg.sonar07);
        obj["sonar08"] = (msg.sonar08);
        obj["sonar09"] = (msg.sonar09);
        obj["sonar10"] = (msg.sonar10);
        obj["sonar11"] = (msg.sonar11);
        obj["sonarenabled"] = (msg.sonarenabled);
        obj["sonarfault"] = (msg.sonarfault);
        nlohmann::json arr_sonarrange;
        for (auto it = msg.sonarrange.begin(); it != msg.sonarrange.end(); ++it) {
            arr_sonarrange.push_back((*it));
        }
        obj["sonarrange"] = arr_sonarrange;
        nlohmann::json arr_sonar;
        for (auto it = msg.sonar.begin(); it != msg.sonar.end(); ++it) {
            arr_sonar.push_back(to_json(*it));
        }
        obj["sonar"] = arr_sonar;
        return obj;
    }
    ApollocanbusSurround from_json_ApollocanbusSurround (nlohmann::json obj) {
        ApollocanbusSurround msg;
        if(obj.contains("crosstrafficalertleft"))
        {
            msg.crosstrafficalertleft = (obj["crosstrafficalertleft"].is_string()?(bool)atoi(obj["crosstrafficalertleft"].get<std::string>().c_str()):obj["crosstrafficalertleft"].get<bool>());
        }
        if(obj.contains("crosstrafficalertleftenabled"))
        {
            msg.crosstrafficalertleftenabled = (obj["crosstrafficalertleftenabled"].is_string()?(bool)atoi(obj["crosstrafficalertleftenabled"].get<std::string>().c_str()):obj["crosstrafficalertleftenabled"].get<bool>());
        }
        if(obj.contains("blindspotleftalert"))
        {
            msg.blindspotleftalert = (obj["blindspotleftalert"].is_string()?(bool)atoi(obj["blindspotleftalert"].get<std::string>().c_str()):obj["blindspotleftalert"].get<bool>());
        }
        if(obj.contains("blindspotleftalertenabled"))
        {
            msg.blindspotleftalertenabled = (obj["blindspotleftalertenabled"].is_string()?(bool)atoi(obj["blindspotleftalertenabled"].get<std::string>().c_str()):obj["blindspotleftalertenabled"].get<bool>());
        }
        if(obj.contains("crosstrafficalertright"))
        {
            msg.crosstrafficalertright = (obj["crosstrafficalertright"].is_string()?(bool)atoi(obj["crosstrafficalertright"].get<std::string>().c_str()):obj["crosstrafficalertright"].get<bool>());
        }
        if(obj.contains("crosstrafficalertrightenabled"))
        {
            msg.crosstrafficalertrightenabled = (obj["crosstrafficalertrightenabled"].is_string()?(bool)atoi(obj["crosstrafficalertrightenabled"].get<std::string>().c_str()):obj["crosstrafficalertrightenabled"].get<bool>());
        }
        if(obj.contains("blindspotrightalert"))
        {
            msg.blindspotrightalert = (obj["blindspotrightalert"].is_string()?(bool)atoi(obj["blindspotrightalert"].get<std::string>().c_str()):obj["blindspotrightalert"].get<bool>());
        }
        if(obj.contains("blindspotrightalertenabled"))
        {
            msg.blindspotrightalertenabled = (obj["blindspotrightalertenabled"].is_string()?(bool)atoi(obj["blindspotrightalertenabled"].get<std::string>().c_str()):obj["blindspotrightalertenabled"].get<bool>());
        }
        if(obj.contains("sonar00"))
        {
            msg.sonar00 = (obj["sonar00"].is_string()?atof(obj["sonar00"].get<std::string>().c_str()):obj["sonar00"].get<double>());
        }
        if(obj.contains("sonar01"))
        {
            msg.sonar01 = (obj["sonar01"].is_string()?atof(obj["sonar01"].get<std::string>().c_str()):obj["sonar01"].get<double>());
        }
        if(obj.contains("sonar02"))
        {
            msg.sonar02 = (obj["sonar02"].is_string()?atof(obj["sonar02"].get<std::string>().c_str()):obj["sonar02"].get<double>());
        }
        if(obj.contains("sonar03"))
        {
            msg.sonar03 = (obj["sonar03"].is_string()?atof(obj["sonar03"].get<std::string>().c_str()):obj["sonar03"].get<double>());
        }
        if(obj.contains("sonar04"))
        {
            msg.sonar04 = (obj["sonar04"].is_string()?atof(obj["sonar04"].get<std::string>().c_str()):obj["sonar04"].get<double>());
        }
        if(obj.contains("sonar05"))
        {
            msg.sonar05 = (obj["sonar05"].is_string()?atof(obj["sonar05"].get<std::string>().c_str()):obj["sonar05"].get<double>());
        }
        if(obj.contains("sonar06"))
        {
            msg.sonar06 = (obj["sonar06"].is_string()?atof(obj["sonar06"].get<std::string>().c_str()):obj["sonar06"].get<double>());
        }
        if(obj.contains("sonar07"))
        {
            msg.sonar07 = (obj["sonar07"].is_string()?atof(obj["sonar07"].get<std::string>().c_str()):obj["sonar07"].get<double>());
        }
        if(obj.contains("sonar08"))
        {
            msg.sonar08 = (obj["sonar08"].is_string()?atof(obj["sonar08"].get<std::string>().c_str()):obj["sonar08"].get<double>());
        }
        if(obj.contains("sonar09"))
        {
            msg.sonar09 = (obj["sonar09"].is_string()?atof(obj["sonar09"].get<std::string>().c_str()):obj["sonar09"].get<double>());
        }
        if(obj.contains("sonar10"))
        {
            msg.sonar10 = (obj["sonar10"].is_string()?atof(obj["sonar10"].get<std::string>().c_str()):obj["sonar10"].get<double>());
        }
        if(obj.contains("sonar11"))
        {
            msg.sonar11 = (obj["sonar11"].is_string()?atof(obj["sonar11"].get<std::string>().c_str()):obj["sonar11"].get<double>());
        }
        if(obj.contains("sonarenabled"))
        {
            msg.sonarenabled = (obj["sonarenabled"].is_string()?(bool)atoi(obj["sonarenabled"].get<std::string>().c_str()):obj["sonarenabled"].get<bool>());
        }
        if(obj.contains("sonarfault"))
        {
            msg.sonarfault = (obj["sonarfault"].is_string()?(bool)atoi(obj["sonarfault"].get<std::string>().c_str()):obj["sonarfault"].get<bool>());
        }
        if(obj.contains("sonarrange"))
        {
            if(obj["sonarrange"].is_array())
            {
                for (auto& element : obj["sonarrange"])
                {
                    msg.sonarrange.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.sonarrange.push_back((obj["sonarrange"].is_string()?atof(obj["sonarrange"].get<std::string>().c_str()):obj["sonarrange"].get<double>()));
            }
        }
        if(obj.contains("sonar"))
        {
            if(obj["sonar"].is_array())
            {
                for (auto& element : obj["sonar"])
                {
                    msg.sonar.push_back(from_json_ApollocanbusSonar(element));
                }
            }
            else
            {
                msg.sonar.push_back(from_json_ApollocanbusSonar(obj["sonar"]));
            }
        }
        return msg;
    }
    template <>
    ApollocanbusSurround from_json<ApollocanbusSurround>(nlohmann::json obj){
        return from_json_ApollocanbusSurround(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSurround &dt)
    {
        dt=from_json_ApollocanbusSurround(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSurround & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSurround & dt)
    {
        os << to_json(dt);
        return os;
    }
}
