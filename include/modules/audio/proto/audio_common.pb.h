#pragma once
namespace apollo::audio{
	enum MovingResult {
		UNKNOWN = 0,
		APPROACHING = 1,
		DEPARTING = 2,
		STATIONARY = 3
	};
}
namespace apollo::audio{
	enum AudioType {
		UNKNOWN_TYPE = 0,
		POLICE = 1,
		AMBULANCE = 2,
		FIRETRUCK = 3
	};
}
namespace apollo::audio{
	enum AudioDirection {
		UNKNOWN_DIRECTION = 0,
		FRONT = 1,
		LEFT = 2,
		BACK = 3,
		RIGHT = 4
	};
}