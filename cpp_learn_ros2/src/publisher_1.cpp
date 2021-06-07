#include "rclcpp/rclcpp.hpp"
// #include<iostream>
// using namespace std;

int main(int argc, char **argv){

    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_test");
    RCLCPP_INFO(node->get_logger(), "hello! This is Subham with Cpp node");
    rclcpp::spin(node);

    rclcpp::shutdown();
    // cout<<"working";
    return 0;
}