#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotSubscriber : public rclcpp::Node
{
public:
    RobotSubscriber() : Node("news_subscriber")
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("robot_news", 10,
        std::bind(&RobotSubscriber::callback_news, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Constructor Called! Reciving News");
    }

private:
    void callback_news(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }

    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;

};

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}