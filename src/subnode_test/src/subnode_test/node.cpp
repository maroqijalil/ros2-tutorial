#include <chrono>
#include <memory>
#include <string>

#include "subnode_test/node.hpp"

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

Node::Node(rclcpp::Node::SharedPtr node)
: node(node)
{
  foo_node = std::make_shared<FooNode>(node);

  bar_node = std::make_shared<BarNode>(node->create_sub_node("bar"));

  node_timer = node->create_wall_timer(
    8ms,
    [this] () {
      foo_node->publish();
      bar_node->publish();
    }
  );
}
