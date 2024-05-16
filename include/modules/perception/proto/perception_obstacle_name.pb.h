#pragma once
#include "modules/perception/proto/perception_obstacle.pb.h"
#include <string>

namespace apollo::perception::V2XInformation
{
    std::string V2XType_Name(V2XType val);
}
namespace apollo::perception::PerceptionObstacle
{
    std::string Type_Name(Type val);
}
namespace apollo::perception::PerceptionObstacle
{
    std::string ConfidenceType_Name(ConfidenceType val);
}
namespace apollo::perception::PerceptionObstacle
{
    std::string SubType_Name(SubType val);
}
namespace apollo::perception::PerceptionObstacle
{
    std::string Source_Name(Source val);
}