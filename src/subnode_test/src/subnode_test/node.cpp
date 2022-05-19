#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#include "subnode_test/node.hpp"

#include "more_interfaces/msg/address_book.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_srvs/srv/empty.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

Node::Node(rclcpp::Node::SharedPtr node)
: node(node), string("foo"), time(node->now().seconds()), prev_time(0.0), is_running(true)
{
  node_timer = node->create_wall_timer(
    8ms,
    [this] () {
      if (this->is_running) {
        std::cout << "run\n";
      }
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

  {
    using std_srvs::srv::Empty;

    server = node->create_service<Empty>(
      "empty", [this](const Empty::Request::SharedPtr request,
        const Empty::Response::SharedPtr response) {
          rclcpp::Rate rcl_rate(8ms);

          while (this->is_running && rclcpp::ok()) {
            rcl_rate.sleep();
            std::cout << "running\n";
          }
        }
    );
  }

  {
    using std_msgs::msg::Bool;

    bool_sub = node->create_subscription<Bool>(
      "bool", 10, [this](const Bool::SharedPtr message) {
          this->is_running = message->data;
        }
    );
  }
}
