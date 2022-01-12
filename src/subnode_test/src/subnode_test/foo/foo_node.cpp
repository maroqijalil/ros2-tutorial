#include <iostream>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "subnode_test/foo/foo_node.hpp"

FooNode::FooNode(rclcpp::Node::SharedPtr node)
{
  foo_publisher = node->create_publisher<std_msgs::msg::String>("foo_msg", 10);

  bar_subscriber = node->create_subscription<std_msgs::msg::String>(
    "/bar/bar_msg",
    10,
    [this](const std_msgs::msg::String::SharedPtr bar_msg) {
      std::cout << bar_msg->data.c_str() << std::endl;
    }
  );
}

void FooNode::publish()
{
  auto foo_msg = std_msgs::msg::String();
  foo_msg.data = "Hello from Foo!";
  foo_publisher->publish(foo_msg);
}
