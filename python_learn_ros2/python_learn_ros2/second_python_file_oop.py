#!/usr/bin/env python3

import rclpy
from rclpy.node import Node



class MyNode(Node):

    def __init__(self):
        super().__init__("second_py_node")
        self.counter_ = 0
        self.get_logger().info("Hello! This is Subham with OOP...")
        self.create_timer(0.5, self.timer_callback)


    def timer_callback(self):
        self.counter_ += 1
        self.get_logger().info("This is callback function.." + str(self.counter_))






def main(args = None):
    rclpy.init(args=args)
    node =MyNode()
    rclpy.spin(node)



    rclpy.shutdown()




if __name__ == "__main__":
    main()