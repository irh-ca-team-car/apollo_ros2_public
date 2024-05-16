#include "modules/control/proto/control_conf.pb.h"

namespace apollo::control::ControlConf
{
    std::string ControllerType_Name(ControllerType val)
    {
    switch (val){
        case ControllerType::LAT_CONTROLLER:
        return "LAT_CONTROLLER";
    case ControllerType::LON_CONTROLLER:
        return "LON_CONTROLLER";
    case ControllerType::MPC_CONTROLLER:
        return "MPC_CONTROLLER";
        };
        return "?";
    }
}