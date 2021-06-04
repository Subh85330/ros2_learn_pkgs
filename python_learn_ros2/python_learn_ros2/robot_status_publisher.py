#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from interfaces_learn_ros2.msg import RobotStatus


class RobotStatusPublisherNode(Node):
    
    def __init__(self):
        super().__init__("robot_status_publisher")
        self.get_logger().info("Hello! This is Robot Status Publisher...")
        self.publisher_ = self.create_publisher(RobotStatus, "robot_status_topic", 10)
        self.timer_ = self.create_timer(0.5, self.publish_status)
        self.get_logger().info("Robot Status Publisher has been started")


    def publish_status(self):
        msg = RobotStatus()
        msg.id = "robot1"
        msg.is_working = True
        msg.temperature = 32
        self.get_logger().info("Publishing Robot Status")
        self.publisher_.publish(msg)



def main(args = None):
    rclpy.init(args=args)
    node =RobotStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()