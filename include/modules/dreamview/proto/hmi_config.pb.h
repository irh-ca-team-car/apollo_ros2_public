#pragma once
#include "apollo_msgs/msg/apollodreamview_hmi_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_hmi_config.hpp"
#include "apollo_msgs/msg/apollodreamview_vehicle_data_data_file.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_vehicle_data_data_file.hpp"
namespace apollo::dreamview::VehicleData{
	typedef apollo_msgs::msg::ApollodreamviewVehicleDataDataFile DataFile;
}
#include "apollo_msgs/msg/apollodreamview_vehicle_data.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_vehicle_data.hpp"
namespace apollo::dreamview{
	enum HMIAction {
		// Simple HMI action without any parameter.
		NONE = 0,
		SETUP_MODE = 1,       // Setup current mode.
		RESET_MODE = 2,       // Reset current mode.
		ENTER_AUTO_MODE = 3,  // Enter into auto driving mode.
		DISENGAGE = 4,        // Disengage from auto driving mode.
		
		// HMI action with a value string parameter.
		CHANGE_MODE = 5,     // value = mode_name
		CHANGE_MAP = 6,      // value = map_name
		CHANGE_VEHICLE = 7,  // value = vehicle_name
		START_MODULE = 8,    // value = module_name
		STOP_MODULE = 9     // value = module_name
	};
}