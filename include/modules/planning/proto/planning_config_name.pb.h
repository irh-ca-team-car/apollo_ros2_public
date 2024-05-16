#pragma once
#include "modules/planning/proto/planning_config.pb.h"
#include <string>
namespace apollo::planning::TaskConfig{
    std::string TaskType_Name(TaskType val);
}
namespace apollo::planning::ScenarioConfig{
    std::string ScenarioType_Name(ScenarioType val);
}
namespace apollo::planning::ScenarioConfig{
    std::string StageType_Name(StageType val);
}
namespace apollo::planning{
    std::string PlannerType_Name(PlannerType val);
}
namespace apollo::planning::PlanningConfig{
    std::string PlanningLearningMode_Name(PlanningLearningMode val);
}