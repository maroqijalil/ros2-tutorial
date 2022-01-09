#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class BarNode
{
public:
  BarNode(rclcpp::Node::SharedPtr node);

  void publish();

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr bar_publisher;
}
