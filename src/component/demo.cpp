#include "component/demo.h"
#include "modules/common/util/json_util.h"
#include "adapter/serialization/yaml.hpp"
#include "modules/common/configs/config_gflags.h"
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>    // for STDOUT_FILENO
#include "cyber/reader.h"
#include "cyber/writer.h"
#include "modules/perception/base/hdmap_struct.h"
#include "adapter/serialization/apollo_msgs/apollocommon_polygon.hpp"
namespace apollo_msgs::msg
{
    nlohmann::json to_json(const D &msg)
    {
        return msg.to_json();
    }
    D from_json_D(nlohmann::json obj)
    {
        D d(0);
        d.v = obj.get<int>();
        return d;
    }
    template <>
    D from_json<D>(nlohmann::json obj)
    {
        return from_json_D(obj);
    }
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::Point;
    template <typename T>
    nlohmann::json to_json(const Point<T> &msg)
    {
        nlohmann::json j;

        j["x"] = msg.x;
        j["y"] = msg.y;
        j["z"] = msg.z;

        return j;
    }
    template <typename T>
    Point<T> from_json_Point(nlohmann::json obj)
    {
        Point<T> d;
        if (obj.contains("x"))
            d.x = obj["x"].get<T>();
        if (obj.contains("y"))
            d.x = obj["y"].get<T>();
        if (obj.contains("z"))
            d.x = obj["z"].get<T>();
        return d;
    }
    template <>
    Point<double> from_json<Point<double>>(nlohmann::json obj)
    {
        return from_json_Point<double>(obj);
    }
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::PointCloud;
    template <typename T>
    nlohmann::json to_json(const PointCloud<T> &msg)
    {
        nlohmann::json j;
        for (size_t i = 0; i < msg.size(); i++)
        {
            j[i] = to_json(msg[i]);
        }

        return j;
    }
    template <typename T>
    PointCloud<T> from_json_PointCloud(nlohmann::json obj)
    {
        PointCloud<T> d;

        for (auto &&i : obj)
        {
            d.push_back(from_json<T>(i));
        }

        return d;
    }
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::PointD;
    using apollo::perception::base::RoadBoundary;

    nlohmann::json to_json(const RoadBoundary &msg)
    {
        nlohmann::json j;
        j["left_boundary"] = to_json(msg.left_boundary);
        j["right_boundary"] = to_json(msg.right_boundary);
        return j;
    }
    RoadBoundary from_json_RoadBoundary(nlohmann::json obj)
    {
        RoadBoundary strct;
        if (obj.contains("left_boundary"))
            strct.left_boundary = from_json_PointCloud<PointD>(obj["left_boundary"]);
        if (obj.contains("right_boundary"))
            strct.right_boundary = from_json_PointCloud<PointD>(obj["right_boundary"]);
        return strct;
    }
    template <>
    RoadBoundary from_json<RoadBoundary>(nlohmann::json obj)
    {
        return from_json_RoadBoundary(obj);
    }
}
namespace apollo_msgs::msg
{
    template <typename T>
    nlohmann::json to_json(const EigenVector<T> &msg)
    {
        nlohmann::json j;
        for (size_t i = 0; i < msg.size(); i++)
        {
            j[i] = to_json(msg[i]);
        }

        return j;
    }
    template <typename T>
    EigenVector<T> from_json_EigenVector(nlohmann::json obj)
    {
        EigenVector<T> strct;
        for (auto &&i : obj)
        {
            strct.push_back(from_json<T>(i));
        }

        return strct;
    }
    template <typename T>
    EigenVector<PointCloud<T>> from_json_EigenVectorPC(nlohmann::json obj)
    {
        EigenVector<PointCloud<T>> strct;
        for (auto &&i : obj)
        {
            strct.push_back(from_json_PointCloud<T>(i));
        }

        return strct;
    }
}
namespace apollo_msgs::msg
{
    using apollo::perception::base::HdmapStruct;
    using apollo::perception::base::PointCloud;
    using apollo::perception::base::PointD;
    using apollo::perception::base::RoadBoundary;
    nlohmann::json to_json(const HdmapStruct &msg)
    {
        nlohmann::json j;
        j["road_boundary"] = to_json(msg.road_boundary);
        j["hole_polygons"] = to_json(msg.hole_polygons);
        j["junction_polygons"] = to_json(msg.junction_polygons);
        j["road_polygons"] = to_json(msg.road_polygons);
        return j;
    }
    HdmapStruct from_json_HdmapStruct(nlohmann::json obj)
    {
        HdmapStruct strct;
        if (obj.contains("road_boundary"))
            strct.road_boundary = from_json_EigenVector<RoadBoundary>(obj["road_boundary"]);
        if (obj.contains("hole_polygons"))
            strct.hole_polygons = from_json_EigenVectorPC<PointD>(obj["hole_polygons"]);
        if (obj.contains("junction_polygons"))
            strct.junction_polygons = from_json_EigenVectorPC<PointD>(obj["junction_polygons"]);
        if (obj.contains("road_polygons"))
            strct.road_polygons = from_json_EigenVectorPC<PointD>(obj["road_polygons"]);

        return strct;
    }
    template <>
    HdmapStruct from_json<HdmapStruct>(nlohmann::json obj)
    {
        return from_json_HdmapStruct(obj);
    }
}
std::shared_ptr<apollo::cyber::ReaderJson<D>> r3;
std::shared_ptr<apollo::cyber::WriterJson<D>> w3;
std::shared_ptr<apollo::cyber::WriterJson<apollo::perception::base::HdmapStruct>> writerj_;

#include <chrono>
class log_every2
{
public:
    static close_after_if_not_null get(std::string prefix, bool exit, long d)
    {
        static std::set<std::string> prefixes;
        bool print = prefixes.find(prefix) == prefixes.end();
        close_after_if_not_null ret_(exit, print);
        prefixes.emplace(prefix);

        if (print)
        {
            std::thread t([d, prefix]()
                          {
                            std::this_thread::sleep_for(std::chrono::milliseconds(d));
                            prefixes.erase(prefix); });
            t.detach();
        }
        return ret_;
    }
};
#undef AERROR_EVERY
#undef AINFO_EVERY
#undef ADEBUG_EVERY
#undef AWARN_EVERY
#undef AFATAL_EVERY
#define AERROR_EVERY(DELAY) (log_every2::get(std::string("[ERROR] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define AINFO_EVERY(DELAY) (log_every2::get(std::string("[INFO] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define ADEBUG_EVERY(DELAY) (log_every2::get(std::string("[DEBUG] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define AWARN_EVERY(DELAY) (log_every2::get(std::string("[WARN] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))
#define AFATAL_EVERY(DELAY) (log_every2::get(std::string("[FATAL] [") + __FILENAME__ + ":" + std::to_string(__LINE__) + ";" + __FUNCTION__ + "] ", false, DELAY))

bool DemoComponent::Init()
{
    HLINE;

    std::vector<double> b;
    b.push_back(5.14);

    std::cout << b[0] << std::endl;

    std::vector<unsigned char> b2((unsigned char *)&b[0], (unsigned char *)&b[1]);
    std::cout << (int)b2[0] << std::endl;
    b = std::vector<double>((double *)&b2[0], (double *)(&b2[0] + sizeof(double)));
    std::cout << b[0] << std::endl;

    HLINE;

    for (int i = 0; i < 30; i++)
    {
        AERROR_EVERY(1000) << "loop" << i;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    AERROR_EVERY(10) << "data";
    AERROR_EVERY(10) << "data";
    AERROR_EVERY(10) << "data";
    return false;

    // AINFO << "Setting gflags";
    // apollo::common::gflags::init_common(node_);
    // AINFO << "Gflags set";
    // apollo_msgs::msg::ApollocanbusWey str;
    // str.ads338e.brakelight = 100;
    // auto s = serialize_msg(str);
    // auto uns = deserialize_msg<apollo_msgs::msg::ApollocanbusWey>(s);

    // apollo_msgs::msg::ApollocommonPolygon poly;

    // AINFO << "Empty polygon " << poly;
    // poly = apollo_msgs::msg::from_json<apollo_msgs::msg::ApollocommonPolygon>(nlohmann::json::parse("{\"point\":[{\"x\":199}]}"));
    // AINFO << "Parsed polygon " << poly;
    // HLINE;
    // AINFO << uns;

    // HLINE;
    // AINFO << std::filesystem::current_path();
    // apollo::cyber::common::SetProtoToBinaryFile(str, "demo2.bin");
    // apollo::cyber::common::SetProtoToASCIIFile(str, "demo2.txt");
    // str.ads338e.brakelight = 101;
    // AINFO << uns.ads338e.brakelight;
    // uns.ads338e.brakelight = 102;
    // apollo::cyber::common::GetProtoFromBinaryFile("demo2.bin", &uns);
    // AINFO << uns.ads338e.brakelight;
    // uns.ads338e.brakelight = 103;
    // apollo::cyber::common::GetProtoFromASCIIFile("demo2.txt", &uns);
    // AINFO << uns.ads338e.brakelight;
    // uns.ads338e.brakelight = 104;
    // apollo::cyber::common::GetProtoFromFile("demo2.txt", &uns);
    // AINFO << uns.ads338e.brakelight;
    // auto node = apollo::cyber::CreateNode("nodeA");
    // auto w = node->CreateWriter<apollo_msgs::msg::ApollocanbusWey>("writer");
    // w->Write(uns);
    // w->Write(str);

    // HLINE;
    // auto yaml = to_yaml(uns);
    // AINFO << yaml;
    // AINFO << "to_yaml";

    // AINFO << "from_yaml";
    // auto un2 = apollo_msgs::msg::from_yaml<apollo_msgs::msg::ApollocanbusWey>(yaml);

    // HLINE;
    // AINFO << "un2";
    // AINFO << un2;

    // HLINE;
    // AINFO << "Deserialization from string(partial)";
    // AINFO << apollo_msgs::msg::from_json<apollo_msgs::msg::ApollocanbusWey>(nlohmann::json::parse("{\"ads1111\":{\"adsaebtaracce\":199}}"));

    // HLINE;
    // //auto w2 = node->CreateWriter_INTERNAL<D>("rd");
    // //auto r2 = node->CreateReader_INTERNAL<D>("rd", [](auto ptr) {
    // //    AINFO << "Received D=" << ptr->v << ";";
    // //});
    // //AINFO << "Sending D(3)";
    // //w2->Write(D(3));
    // //AINFO << "Sending D(4)";
    // //w2->Write(D(4));

    // //AINFO << "Last received D=" << r2->GetLatestObserved()->v << ";";

    // HLINE;
    // w3 = node->CreateWriterJson<D>("rd2");
    // r3 = node->CreateReaderJson<D>("rd2", [](auto ptr) {
    //     AINFO << "Received D=" << ptr->v << ";";
    // });
    // writerj_ = node_->CreateWriterJson<apollo::perception::base::HdmapStruct>("j");

    // AINFO << "Sending D(3)";
    // w3->Write(apollo_msgs::msg::to_json(D(3)));
    // AINFO << "Sending D(4)";
    // w3->Write(apollo_msgs::msg::to_json(D(4)));

    // //AINFO << "Last received D=" << r3->GetLatestObserved()->v << ";";
    // HLINE;

    // CHECK_EQ(uns, un2);
    // ACHECK(1 < 4) << "1 should be less than 4";
    // CHECK_LT(1, 3) << 1 << " should be lower than " << 3;

    // AINFO << "Node name::" << apollo::cyber::currentNode->get_name();

    // HLINE;

    // auto file_name = "tmp.txt";
    // std::ofstream output(file_name);
    // output << "demo" << std::endl;
    // output << "demo2" << std::endl;
    // output << "demo3" << std::endl;
    // output.close();

    // std::fstream input(file_name, std::ios::in);
    // std::istreambuf_iterator<char> eos;
    // std::string strtoe(std::istreambuf_iterator<char>(input), eos);
    // AINFO << "s[" << strtoe << "]";
    // input.close();

    return true;
}
