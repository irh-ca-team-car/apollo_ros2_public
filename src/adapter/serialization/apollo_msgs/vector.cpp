#include "adapter/serialization/apollo_msgs/vector.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Vector &msg) {
        nlohmann::json obj;
        nlohmann::json arr_columns;
        for (auto it = msg.columns.begin(); it != msg.columns.end(); ++it) {
            arr_columns.push_back((*it));
        }
        obj["columns"] = arr_columns;
        return obj;
    }
    Vector from_json_Vector (nlohmann::json obj) {
        Vector msg;
        if(obj.contains("columns"))
        {
            if(obj["columns"].is_array())
            {
                for (auto& element : obj["columns"])
                {
                    msg.columns.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.columns.push_back((obj["columns"].is_string()?atof(obj["columns"].get<std::string>().c_str()):obj["columns"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    Vector from_json<Vector>(nlohmann::json obj){
        return from_json_Vector(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Vector &dt)
    {
        dt=from_json_Vector(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Vector & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Vector & dt)
    {
        os << to_json(dt);
        return os;
    }
}
