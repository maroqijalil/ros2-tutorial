#include <chrono>
#include <memory>
#include <string>

#include "subnode_test/node.hpp"

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

Node::Node(const std::string & node_name)
: rclcpp::Node(node_name)
{
  foo_node = std::make_shared<FooNode>(this->create_sub_node("foo"));

  bar_node = std::make_shared<BarNode>(this->create_sub_node("bar"));

  node_timer = this->create_wall_timer(
    8ms,
    [this] () {
      foo_node->publish();
      bar_node->publish();
    }
  );
}
