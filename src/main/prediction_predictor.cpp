#include "component/prediction.h"
#include "modules/prediction/submodules/evaluator_submodule.h"
#include "modules/prediction/submodules/predictor_submodule.h"
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node3 = std::make_shared<apollo::prediction::PredictorSubmodule>();
 
    rclcpp::spin(node3);

    rclcpp::shutdown();
    return 0;    
}