#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("subscriber_node");
  auto suubscriber = node->create_subscription<std_msgs::msg::String>(
    "/foo_msg",
    10,
    [](const std_msgs::msg::String::SharedPtr foo_msg) {
      std::cout << foo_msg->data.c_str() << std::endl;
    }
  );

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
