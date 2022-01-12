#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class FooNode
{
public:
  FooNode(rclcpp::Node::SharedPtr node);

  void publish();

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr foo_publisher;

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr bar_subscriber;
};
