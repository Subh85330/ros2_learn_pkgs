#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

def main(args = None):
    rclpy.init(args=args)
    node = Node("first_python_node")
    node.get_logger().info("Hello! This is Subham....")
    rclpy.spin(node)



    rclpy.shutdown()




if __name__ == "__main__":
    main()