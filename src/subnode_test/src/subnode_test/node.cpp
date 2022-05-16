#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#include "subnode_test/node.hpp"

#include "more_interfaces/msg/address_book.hpp"
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

Node::Node(rclcpp::Node::SharedPtr node)
: node(node), string("foo"), time(node->now().seconds()), prev_time(0.0)
{
  node_timer = node->create_wall_timer(
    8ms,
    [this] () {
      // double now = this->node->now().seconds() - this->time;
      // std::cout << now << "\n";
      // std::cout << "delta: " << now - this->prev_time << "\n";
      // this->prev_time = now;
      // std::chrono::milliseconds sec = 8s;
      // std::cout << "timer: " << (this->node->now().nanoseconds() % 1000000000) / 1000000000.0 << std::endl;
    }
  );

  {
    using more_interfaces::msg::AddressBook;

    subscriber = node->create_subscription<AddressBook>(
      "address_book", 10,
      [this](AddressBook::SharedPtr message) {
        std::cout << "subscriber: " << message->dir << std::endl;
      });
  }
}
