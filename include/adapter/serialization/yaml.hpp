#include "yaml-cpp/yaml.h"

namespace apollo_msgs::msg
{
    template <typename T>
    YAML::Node to_yaml(T msg)
    {
        return to_yaml(to_json(msg));
    }
    template <>
    YAML::Node to_yaml<int>(int os)
    {
        return YAML::Node(os);
    }
    template <>
    YAML::Node to_yaml<long>(long os)
    {
        return YAML::Node(os);
    }
    template <>
    YAML::Node to_yaml<double>(double os)
    {
        return YAML::Node(os);
    }
    template <>
    YAML::Node to_yaml<bool>(bool os)
    {
        return YAML::Node(os);
    }
    template <>
    YAML::Node to_yaml<std::string>(std::string os)
    {
        return YAML::Node(os);
    }
    template <>
    YAML::Node to_yaml<nlohmann::json>(nlohmann::json os)
    {
        YAML::Node nd;

        if (os.is_array())
        {
            for (nlohmann::json::iterator it = os.begin(); it != os.end(); ++it)
            {
                nd.push_back(to_yaml(*it));
            }
        }
        else if (os.is_boolean())
        {
            nd = os.get<bool>();
        }
        else if (os.is_number())
        {
            nd = os.get<double>();
        }
        else if (os.is_string())
        {
            nd = os.get<std::string>();
        }
        else if (os.is_null())
        {
            nd = "nullptr";
        }
        else if (os.is_object())
        {
            for (nlohmann::json::iterator it = os.begin(); it != os.end(); ++it)
            {
                nd[it.key()] = to_yaml(it.value());
            }
        }

        return nd;
    }

    template <typename T>
    T from_yaml(YAML::Node os)
    {
        auto mid = from_yaml<nlohmann::json>(os);
        return from_json<T>(mid);
    }
    template <>
    int from_yaml<int>(YAML::Node os)
    {
        return os.as<int>(0);
    }
    template <>
    long from_yaml<long>(YAML::Node os)
    {
        return os.as<long>(0);
    }
    template <>
    double from_yaml<double>(YAML::Node os)
    {
        return os.as<double>(0);
    }
    template <>
    bool from_yaml<bool>(YAML::Node os)
    {
        return os.as<bool>(false);
    }
    template <>
    std::string from_yaml<std::string>(YAML::Node os)
    {
        return os.as<std::string>("");
    }
    template <>
    nlohmann::json from_yaml<nlohmann::json>(YAML::Node os)
    {
        nlohmann::json j;
        if (os.IsMap())
        {
            for (auto iter = os.begin(); iter != os.end(); ++iter)
            {
                j[iter->first.as<std::string>()] = from_yaml<nlohmann::json>(iter->second);
            }
        }
        else if (os.IsScalar())
        {
            j = os.as<std::string>();
        }
        else if (os.IsSequence())
        {
            for (unsigned i = 0; i < os.size(); i++)
            {
                j[i] = from_yaml<nlohmann::json>(os[i]);
            }
        }
        return j;
    }
}
