#include "modules/map/proto/map_lane_name.pb.h"
#ifdef CASE
#undef CASE_BEGIN
#undef CASE
#undef CASE_END
#endif
#define CASE_BEGIN(val) switch (val) {
#define CASE(X) case X : return #X; 
#define CASE_END(val) \
    }                 \
    return "?";
namespace apollo::hdmap::LaneBoundaryType
{
    std::string Type_Name(Type val)
    {
        CASE_BEGIN(val)
        CASE(UNKNOWN)
        CASE(DOTTED_YELLOW)
        CASE(DOTTED_WHITE)
        CASE(SOLID_YELLOW)
        CASE(SOLID_WHITE)
        CASE(DOUBLE_YELLOW)
        CASE(CURB)
        CASE_END(val)
    }
}
namespace apollo::hdmap::Lane
{
    std::string LaneType_Name(LaneType val)
    {
        CASE_BEGIN(val)

        CASE(NONE)
        CASE(CITY_DRIVING)
        CASE(BIKING)
        CASE(SIDEWALK)
        CASE(PARKING)
        CASE(SHOULDER)

        CASE_END(val)
    }
}
namespace apollo::hdmap::Lane
{
    std::string LaneTurn_Name(LaneTurn val)
    {
        CASE_BEGIN(val)

        CASE(NO_TURN)
        CASE(LEFT_TURN)
        CASE(RIGHT_TURN)
        CASE(U_TURN)

        CASE_END(val)
    }
}
namespace apollo::hdmap::Lane
{
    std::string LaneDirection_Name(LaneDirection val)
    {
        CASE_BEGIN(val)

        CASE(FORWARD)
        CASE(BACKWARD)
        CASE(BIDIRECTION)

        CASE_END(val)
    }
}