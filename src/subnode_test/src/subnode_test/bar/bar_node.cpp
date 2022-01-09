#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "subnode_test/bar/bar_node.hpp"

BarNode::BarNode(rclcpp::Node::SharedPtr node)
{
  bar_publisher = node->create_publisher<std_msgs::msg::String>("bar_msg", 10);
}

void BarNode::publish()
{
  auto bar_msg = std_msgs::msg::String();
  bar_msg.data = "Hello from Bar!";
  bar_publisher->publish(bar_msg);
}
