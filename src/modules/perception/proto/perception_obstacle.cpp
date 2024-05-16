#include "modules/perception/proto/perception_obstacle_name.pb.h"
#include <string>
#define CASE(e) case e: return #e;
namespace apollo::perception::V2XInformation
{
    std::string V2XType_Name(V2XType val)
    {
        switch (val)
        {
        case NONE:
            return "NONE";
        case ZOMBIES_CAR:
            return "ZOMBIES_CAR";
        case BLIND_ZONE:
            return "BLIND_ZONE";
        }
        return "?";
    };
}
namespace apollo::perception::PerceptionObstacle
{
    std::string Type_Name(Type val)
    {
        switch(val)
        {
            CASE(UNKNOWN);
            CASE(UNKNOWN_MOVABLE);
            CASE(UNKNOWN_UNMOVABLE);
            CASE(PEDESTRIAN);     // Pedestrian, usually determined by moving behavior.
            CASE(BICYCLE);        // bike, motor bike
            CASE(VEHICLE);        // Passenger car or truck.
        }
        return "?";
    }
}
namespace apollo::perception::PerceptionObstacle
{
    std::string ConfidenceType_Name(ConfidenceType val)
    {
        switch(val)
        {
            CASE(CONFIDENCE_UNKNOWN);
            CASE(CONFIDENCE_CNN);
            CASE(CONFIDENCE_RADAR);
        }
        return "?";
    }
}
namespace apollo::perception::PerceptionObstacle
{
    std::string SubType_Name(SubType val)
    {
        switch(val)
        {
            CASE(ST_UNKNOWN);
            CASE(ST_UNKNOWN_MOVABLE);
            CASE(ST_UNKNOWN_UNMOVABLE);
            CASE(ST_CAR);
            CASE(ST_VAN);
            CASE(ST_TRUCK);
            CASE(ST_BUS);
            CASE(ST_CYCLIST);
            CASE(ST_MOTORCYCLIST);
            CASE(ST_TRICYCLIST);
            CASE(ST_PEDESTRIAN);
            CASE(ST_TRAFFICCONE);
        }
        return "?";
    }
}
namespace apollo::perception::PerceptionObstacle
{
    std::string Source_Name(Source val)
    {
        switch(val)
        {
            CASE(HOST_VEHICLE);
            CASE(V2X);
        }
        return "?";
    }
}
