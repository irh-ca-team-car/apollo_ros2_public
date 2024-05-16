#pragma once
#include "apollo_msgs/msg/apollodreamview_process_monitor_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_process_monitor_config.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewProcessMonitorConfig ProcessMonitorConfig;
}
#include "apollo_msgs/msg/apollodreamview_module_monitor_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_module_monitor_config.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewModuleMonitorConfig ModuleMonitorConfig;
}
#include "apollo_msgs/msg/apollodreamview_channel_monitor_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_channel_monitor_config.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewChannelMonitorConfig ChannelMonitorConfig;
}
#include "apollo_msgs/msg/apollodreamview_resource_monitor_config_disk_space.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_resource_monitor_config_disk_space.hpp"
namespace apollo::dreamview::ResourceMonitorConfig{
	typedef apollo_msgs::msg::ApollodreamviewResourceMonitorConfigDiskSpace DiskSpace;
}
#include "apollo_msgs/msg/apollodreamview_resource_monitor_config_cpu_usage.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_resource_monitor_config_cpu_usage.hpp"
namespace apollo::dreamview::ResourceMonitorConfig{
	typedef apollo_msgs::msg::ApollodreamviewResourceMonitorConfigCPUUsage CPUUsage;
}
#include "apollo_msgs/msg/apollodreamview_resource_monitor_config_memory_usage.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_resource_monitor_config_memory_usage.hpp"
namespace apollo::dreamview::ResourceMonitorConfig{
	typedef apollo_msgs::msg::ApollodreamviewResourceMonitorConfigMemoryUsage MemoryUsage;
}
#include "apollo_msgs/msg/apollodreamview_resource_monitor_config_disk_load.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_resource_monitor_config_disk_load.hpp"
namespace apollo::dreamview::ResourceMonitorConfig{
	typedef apollo_msgs::msg::ApollodreamviewResourceMonitorConfigDiskLoad DiskLoad;
}
#include "apollo_msgs/msg/apollodreamview_resource_monitor_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_resource_monitor_config.hpp"
#include "apollo_msgs/msg/apollodreamview_monitored_component.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_monitored_component.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewMonitoredComponent MonitoredComponent;
}
#include "apollo_msgs/msg/apollodreamview_module.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_module.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewModule Module;
}
#include "apollo_msgs/msg/apollodreamview_cyber_module.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_cyber_module.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewCyberModule CyberModule;
}
#include "apollo_msgs/msg/apollodreamview_hmi_mode.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_hmi_mode.hpp"