#include "adapter/serialization/apollo_msgs/matrix.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Matrix &msg) {
        nlohmann::json obj;
        nlohmann::json arr_rows;
        for (auto it = msg.rows.begin(); it != msg.rows.end(); ++it) {
            arr_rows.push_back(to_json(*it));
        }
        obj["rows"] = arr_rows;
        return obj;
    }
    Matrix from_json_Matrix (nlohmann::json obj) {
        Matrix msg;
        if(obj.contains("rows"))
        {
            if(obj["rows"].is_array())
            {
                for (auto& element : obj["rows"])
                {
                    msg.rows.push_back(from_json_Vector(element));
                }
            }
            else
            {
                msg.rows.push_back(from_json_Vector(obj["rows"]));
            }
        }
        return msg;
    }
    template <>
    Matrix from_json<Matrix>(nlohmann::json obj){
        return from_json_Matrix(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Matrix &dt)
    {
        dt=from_json_Matrix(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Matrix & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Matrix & dt)
    {
        os << to_json(dt);
        return os;
    }
}
