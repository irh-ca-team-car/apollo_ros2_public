#include "adapter/serialization/apollo_msgs/apolloplanning_spiral_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpiralSmootherConfig &msg) {
        nlohmann::json obj;
        obj["maxdeviation"] = (msg.maxdeviation);
        obj["piecewiselength"] = (msg.piecewiselength);
        obj["maxiteration"] = (msg.maxiteration);
        obj["opttol"] = (msg.opttol);
        obj["optacceptabletol"] = (msg.optacceptabletol);
        obj["optacceptableiteration"] = (msg.optacceptableiteration);
        obj["weightcurvelength"] = (msg.weightcurvelength);
        obj["weightkappa"] = (msg.weightkappa);
        obj["weightdkappa"] = (msg.weightdkappa);
        return obj;
    }
    ApolloplanningSpiralSmootherConfig from_json_ApolloplanningSpiralSmootherConfig (nlohmann::json obj) {
        ApolloplanningSpiralSmootherConfig msg;
        if(obj.contains("maxdeviation"))
        {
            msg.maxdeviation = (obj["maxdeviation"].is_string()?atof(obj["maxdeviation"].get<std::string>().c_str()):obj["maxdeviation"].get<double>());
        }
        if(obj.contains("piecewiselength"))
        {
            msg.piecewiselength = (obj["piecewiselength"].is_string()?atof(obj["piecewiselength"].get<std::string>().c_str()):obj["piecewiselength"].get<double>());
        }
        if(obj.contains("maxiteration"))
        {
            msg.maxiteration = (obj["maxiteration"].is_string()?atoi(obj["maxiteration"].get<std::string>().c_str()):obj["maxiteration"].get<uint32_t>());
        }
        if(obj.contains("opttol"))
        {
            msg.opttol = (obj["opttol"].is_string()?atof(obj["opttol"].get<std::string>().c_str()):obj["opttol"].get<double>());
        }
        if(obj.contains("optacceptabletol"))
        {
            msg.optacceptabletol = (obj["optacceptabletol"].is_string()?atof(obj["optacceptabletol"].get<std::string>().c_str()):obj["optacceptabletol"].get<double>());
        }
        if(obj.contains("optacceptableiteration"))
        {
            msg.optacceptableiteration = (obj["optacceptableiteration"].is_string()?atoi(obj["optacceptableiteration"].get<std::string>().c_str()):obj["optacceptableiteration"].get<uint32_t>());
        }
        if(obj.contains("weightcurvelength"))
        {
            msg.weightcurvelength = (obj["weightcurvelength"].is_string()?atof(obj["weightcurvelength"].get<std::string>().c_str()):obj["weightcurvelength"].get<double>());
        }
        if(obj.contains("weightkappa"))
        {
            msg.weightkappa = (obj["weightkappa"].is_string()?atof(obj["weightkappa"].get<std::string>().c_str()):obj["weightkappa"].get<double>());
        }
        if(obj.contains("weightdkappa"))
        {
            msg.weightdkappa = (obj["weightdkappa"].is_string()?atof(obj["weightdkappa"].get<std::string>().c_str()):obj["weightdkappa"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningSpiralSmootherConfig from_json<ApolloplanningSpiralSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningSpiralSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpiralSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningSpiralSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpiralSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpiralSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
