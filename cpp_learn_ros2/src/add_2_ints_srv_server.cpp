#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class Add2IntsSrvNode : public rclcpp::Node
{
public:
    Add2IntsSrvNode() : Node("add_2_ints_srv_server")
    {
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints_service", 
        std::bind(&Add2IntsSrvNode::callbackAdd2Ints, this, std::placeholders::_1, std::placeholders::_2));
        RCLCPP_INFO(this->get_logger(), "Service Server Started..........");
    }

private:
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;

    void callbackAdd2Ints(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                          const example_interfaces::srv::AddTwoInts::Response::SharedPtr response)
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "%d + %d = %d", request->a, request->b, response->sum);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Add2IntsSrvNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}