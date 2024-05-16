import rclpy
import rclpy.serialization
from apollo_msgs.msg import *
import sys
print(1)
rclpy.init(args=sys.argv)
print(2)
node = rclpy.create_node('fake')
print(3)
ros_rate = node.create_rate(10)
print(4)

pub0x = node.create_publisher(ApollocanbusChassis,'/apollo/canbus/chassis',10)
pub1x = node.create_publisher(ApollolocalizationLocalizationEstimate,'/apollo/localization/pose',10)
print(5)

fake_chassis= ApollocanbusChassis()
local = ApollolocalizationLocalizationEstimate()
print(6)
while rclpy.ok():
    print(7)
    pub0x.publish(fake_chassis)
    pub1x.publish(local)
    print(8)
    rclpy.spin_once(node, timeout_sec=2)
    #ros_rate.sleep()
    print(fake_chassis)
    print(local)
  