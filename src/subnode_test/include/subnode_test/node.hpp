#include <memory>
#include <string>

#include "more_interfaces/msg/address_book.hpp"
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

class Node
{
public:
  Node(rclcpp::Node::SharedPtr node);

private:
  rclcpp::Node::SharedPtr node;
  rclcpp::TimerBase::SharedPtr node_timer;

  std::string string;
  double time;
  double prev_time;

  rclcpp::Subscription<more_interfaces::msg::AddressBook>::SharedPtr subscriber;
};
