#include <chrono>
#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("publisher_node");
  auto publisher = node->create_publisher<std_msgs::msg::String>("/try/subs", 10);

  rclcpp::Rate rcl_rate(8ms);

  while (rclcpp::ok()) {
    rcl_rate.sleep();

    auto message = std_msgs::msg::String();

    publisher->publish(message);
  }

  return 0;
}
