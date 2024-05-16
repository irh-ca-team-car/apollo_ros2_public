#include "modules/planning/proto/planning_config_name.pb.h"
namespace apollo::planning::TaskConfig
{
    std::string TaskType_Name(TaskType val)
    {
        switch (val)
        {
        // deciders
        case CREEP_DECIDER:
            return "CREEP_DECIDER";
        case LANE_CHANGE_DECIDER:
            return "LANE_CHANGE_DECIDER";
        case NAVI_OBSTACLE_DECIDER:
            return "NAVI_OBSTACLE_DECIDER";
        case NAVI_PATH_DECIDER:
            return "NAVI_PATH_DECIDER";
        case NAVI_SPEED_DECIDER:
            return "NAVI_SPEED_DECIDER";
        case OPEN_SPACE_FALLBACK_DECIDER:
            return "OPEN_SPACE_FALLBACK_DECIDER";
        case OPEN_SPACE_PRE_STOP_DECIDER:
            return "OPEN_SPACE_PRE_STOP_DECIDER";
        case OPEN_SPACE_ROI_DECIDER:
            return "OPEN_SPACE_ROI_DECIDER";
        case PATH_ASSESSMENT_DECIDER:
            return "PATH_ASSESSMENT_DECIDER";
        case PATH_BOUNDS_DECIDER:
            return "PATH_BOUNDS_DECIDER";
        case PATH_DECIDER:
            return "PATH_DECIDER";
        case PATH_LANE_BORROW_DECIDER:
            return "PATH_LANE_BORROW_DECIDER";
        case PATH_REFERENCE_DECIDER:
            return "PATH_REFERENCE_DECIDER";
        case PATH_REUSE_DECIDER:
            return "PATH_REUSE_DECIDER";
        case RSS_DECIDER:
            return "RSS_DECIDER";
        case RULE_BASED_STOP_DECIDER:
            return "RULE_BASED_STOP_DECIDER";
        case SPEED_BOUNDS_PRIORI_DECIDER:
            return "SPEED_BOUNDS_PRIORI_DECIDER";
        case SPEED_BOUNDS_FINAL_DECIDER:
            return "SPEED_BOUNDS_FINAL_DECIDER";
        case SPEED_DECIDER:
            return "SPEED_DECIDER";
        case ST_BOUNDS_DECIDER:
            return "ST_BOUNDS_DECIDER";
        // optimizers
        case OPEN_SPACE_TRAJECTORY_PARTITION:
            return "OPEN_SPACE_TRAJECTORY_PARTITION";
        case OPEN_SPACE_TRAJECTORY_PROVIDER:
            return "OPEN_SPACE_TRAJECTORY_PROVIDER";
        case PIECEWISE_JERK_NONLINEAR_SPEED_OPTIMIZER:
            return "PIECEWISE_JERK_NONLINEAR_SPEED_OPTIMIZER";
        case PIECEWISE_JERK_PATH_OPTIMIZER:
            return "PIECEWISE_JERK_PATH_OPTIMIZER";
        case PIECEWISE_JERK_SPEED_OPTIMIZER:
            return "PIECEWISE_JERK_SPEED_OPTIMIZER";
        case SPEED_HEURISTIC_OPTIMIZER:
            return "SPEED_HEURISTIC_OPTIMIZER";
        // other tasks
        case LEARNING_MODEL_INFERENCE_TASK:
            return "LEARNING_MODEL_INFERENCE_TASK";
        case LEARNING_MODEL_INFERENCE_TRAJECTORY_TASK:
            return "LEARNING_MODEL_INFERENCE_TRAJECTORY_TASK";
        }
        return "?";
    };
}
namespace apollo::planning::ScenarioConfig
{
    std::string ScenarioType_Name(ScenarioType val)
    {
        switch (val)
        {
        case LANE_FOLLOW:
            return "LANE_FOLLOW"; // default scenario

        // intersection involved
        case BARE_INTERSECTION_UNPROTECTED:
            return "BARE_INTERSECTION_UNPROTECTED";
        case STOP_SIGN_PROTECTED:
            return "STOP_SIGN_PROTECTED";
        case STOP_SIGN_UNPROTECTED:
            return "STOP_SIGN_UNPROTECTED";
        case TRAFFIC_LIGHT_PROTECTED:
            return "TRAFFIC_LIGHT_PROTECTED";
        case TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN:
            return "TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN";
        case TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN:
            return "TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN";
        case YIELD_SIGN:
            return "YIELD_SIGN";

        // parking
        case PULL_OVER:
            return "PULL_OVER";
        case VALET_PARKING:
            return "VALET_PARKING";

        case EMERGENCY_PULL_OVER:
            return "EMERGENCY_PULL_OVER";
        case EMERGENCY_STOP:
            return "EMERGENCY_STOP";

        // misc
        case NARROW_STREET_U_TURN:
            return "NARROW_STREET_U_TURN";
        case PARK_AND_GO:
            return "PARK_AND_GO";

        // learning model sample
        case LEARNING_MODEL_SAMPLE:
            return "LEARNING_MODEL_SAMPLE";
        }
        return "?";
    };
}
namespace apollo::planning::ScenarioConfig
{
    std::string StageType_Name(StageType val)
    {
        switch (val)
        {
        case NO_STAGE:
            return "NO_STAGE";

        case LANE_FOLLOW_DEFAULT_STAGE:
            return "LANE_FOLLOW_DEFAULT_STAGE";

        // bare_intersection_unprotected scenario
        case BARE_INTERSECTION_UNPROTECTED_APPROACH:
            return "BARE_INTERSECTION_UNPROTECTED_APPROACH";
        case BARE_INTERSECTION_UNPROTECTED_INTERSECTION_CRUISE:
            return "BARE_INTERSECTION_UNPROTECTED_INTERSECTION_CRUISE";

        // stop_sign_unprotected scenario
        case STOP_SIGN_UNPROTECTED_PRE_STOP:
            return "STOP_SIGN_UNPROTECTED_PRE_STOP";
        case STOP_SIGN_UNPROTECTED_STOP:
            return "STOP_SIGN_UNPROTECTED_STOP";
        case STOP_SIGN_UNPROTECTED_CREEP:
            return "STOP_SIGN_UNPROTECTED_CREEP";
        case STOP_SIGN_UNPROTECTED_INTERSECTION_CRUISE:
            return "STOP_SIGN_UNPROTECTED_INTERSECTION_CRUISE";

        // traffic_light_protected scenario
        case TRAFFIC_LIGHT_PROTECTED_APPROACH:
            return "TRAFFIC_LIGHT_PROTECTED_APPROACH";
        case TRAFFIC_LIGHT_PROTECTED_INTERSECTION_CRUISE:
            return "TRAFFIC_LIGHT_PROTECTED_INTERSECTION_CRUISE";

        // traffic_light_unprotected_left_turn scenario
        case TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_APPROACH:
            return "TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_APPROACH";
        case TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_CREEP:
            return "TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_CREEP";
        case TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_INTERSECTION_CRUISE:
            return "TRAFFIC_LIGHT_UNPROTECTED_LEFT_TURN_INTERSECTION_CRUISE";

        // traffic_light_unprotected_right_turn scenario
        case TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_STOP:
            return "TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_STOP";
        case TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_CREEP:
            return "TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_CREEP";
        case TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_INTERSECTION_CRUISE:
            return "TRAFFIC_LIGHT_UNPROTECTED_RIGHT_TURN_INTERSECTION_CRUISE";

        // pull_over scenario
        case PULL_OVER_APPROACH:
            return "PULL_OVER_APPROACH";
        case PULL_OVER_RETRY_APPROACH_PARKING:
            return "PULL_OVER_RETRY_APPROACH_PARKING";
        case PULL_OVER_RETRY_PARKING:
            return "PULL_OVER_RETRY_PARKING";

        // emergency_pull_over scenario
        case EMERGENCY_PULL_OVER_SLOW_DOWN:
            return "EMERGENCY_PULL_OVER_SLOW_DOWN";
        case EMERGENCY_PULL_OVER_APPROACH:
            return "EMERGENCY_PULL_OVER_APPROACH";
        case EMERGENCY_PULL_OVER_STANDBY:
            return "EMERGENCY_PULL_OVER_STANDBY";

        // emergency_pull_over scenario
        case EMERGENCY_STOP_APPROACH:
            return "EMERGENCY_STOP_APPROACH";
        case EMERGENCY_STOP_STANDBY:
            return "EMERGENCY_STOP_STANDBY";

        // valet parking scenario
        case VALET_PARKING_APPROACHING_PARKING_SPOT:
            return "VALET_PARKING_APPROACHING_PARKING_SPOT";
        case VALET_PARKING_PARKING:
            return "VALET_PARKING_PARKING";

        // park_and_go scenario
        case PARK_AND_GO_CHECK:
            return "PARK_AND_GO_CHECK";
        case PARK_AND_GO_CRUISE:
            return "PARK_AND_GO_CRUISE";
        case PARK_AND_GO_ADJUST:
            return "PARK_AND_GO_ADJUST";
        case PARK_AND_GO_PRE_CRUISE:
            return "PARK_AND_GO_PRE_CRUISE";

        // yield_sign scenario
        case YIELD_SIGN_APPROACH:
            return "YIELD_SIGN_APPROACH";
        case YIELD_SIGN_CREEP:
            return "YIELD_SIGN_CREEP";

        // learning_model_sample scenario
        case LEARNING_MODEL_RUN:
            return "LEARNING_MODEL_RUN";
        }
        return "?";
    };
}
namespace apollo::planning
{
    std::string PlannerType_Name(PlannerType val)
    {
        switch (val)
        {
        case RTK:
            return "RTK";
        case PUBLIC_ROAD:
            return "PUBLIC_ROAD"; // public road planner
        case NAVI:
            return "NAVI"; // navigation planner
        case LATTICE:
            return "LATTICE"; // lattice planner
        }
        return "?";
    };
}
namespace apollo::planning::PlanningConfig
{
    std::string PlanningLearningMode_Name(PlanningLearningMode val)
    {
        switch (val)
        {
        case NO_LEARNING:
            return "NO_LEARNING";
        case E2E:
            return "E2E";
        case HYBRID:
            return "HYBRID";
        case RL_TEST:
            return "RL_TEST";
        case E2E_TEST:
            return "E2E_TEST";
        case HYBRID_TEST:
            return "HYBRID_TEST";
        }
        return "?";
    };
}