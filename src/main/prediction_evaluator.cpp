#include "modules/prediction/submodules/evaluator_submodule.h"
#include "modules/prediction/submodules/predictor_submodule.h"
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node2 = std::make_shared<apollo::prediction::EvaluatorSubmodule>();

    rclcpp::spin(node2);

    rclcpp::shutdown();
    return 0;    
}