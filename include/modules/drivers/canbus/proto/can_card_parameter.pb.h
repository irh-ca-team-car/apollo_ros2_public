#pragma once
#include "apollo_msgs/msg/apollodriverscanbus_can_card_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo::drivers::canbus::CANCardParameter{
	enum CANCardBrand {
		FAKE_CAN = 0,
		ESD_CAN = 1,
		SOCKET_CAN_RAW = 2,
		HERMES_CAN = 3
	};
}
namespace apollo::drivers::canbus::CANCardParameter{
	enum CANCardType {
		PCI_CARD = 0,
		USB_CARD = 1
	};
}
namespace apollo::drivers::canbus::CANCardParameter{
	enum CANChannelId {
		CHANNEL_ID_ZERO = 0,
		CHANNEL_ID_ONE = 1,
		CHANNEL_ID_TWO = 2,
		CHANNEL_ID_THREE = 3,
		CHANNEL_ID_FOUR = 4,
		CHANNEL_ID_FIVE = 5,
		CHANNEL_ID_SIX = 6,
		CHANNEL_ID_SEVEN = 7
	};
}
namespace apollo::drivers::canbus::CANCardParameter{
	enum CANInterface {
		NATIVE = 0,
		VIRTUAL = 1,
		SLCAN = 2
	};
}