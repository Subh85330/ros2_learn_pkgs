#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsNode : public rclcpp::Node
{
public:
    RobotNewsNode() : Node("robot_news_publisher")
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                         std::bind(&RobotNewsNode::publish_news, this));
        RCLCPP_INFO(this->get_logger(), "Costructor called! Robot Station has been started");
    }

private:
    void publish_news()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = "Hi This is Subham's Robot";
        publisher_->publish(msg);
    }

    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_; //declared publisher
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}