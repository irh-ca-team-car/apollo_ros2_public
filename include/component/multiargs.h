#include "cyber/cyber.h"
#include "std_msgs/msg/string.hpp"

using apollo::cyber::Reader;
using apollo::cyber::ReaderConfig;
using apollo::cyber::Writer;

class MultiArgsComponent : public apollo::cyber::Component
{
public:
  MultiArgsComponent() : Component("MultiArgsComponent") {}
  ~MultiArgsComponent(){};

  std::string Name() const;

  bool Init() override;

  void Proc(
      const std_msgs::msg::String::SharedPtr, const std_msgs::msg::String::SharedPtr);

private:
  std::shared_ptr<apollo::cyber::Reader<std_msgs::msg::String>> rd0;
  std::shared_ptr<apollo::cyber::Reader<std_msgs::msg::String>> rd1;

  apollo::cyber::adapter::Sync<std_msgs::msg::String, std_msgs::msg::String> sync_;
};