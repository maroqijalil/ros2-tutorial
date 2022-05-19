#include <memory>
#include <string>

#include "more_interfaces/msg/address_book.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_srvs/srv/empty.hpp"
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

  bool is_running;

  rclcpp::Subscription<more_interfaces::msg::AddressBook>::SharedPtr subscriber;
  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr bool_sub;
  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr server;
};
