 #include "component/microphone.h"
 int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<apollo::drivers::microphone::MicrophoneComponent>());
    rclcpp::shutdown();
    return 0;    
}