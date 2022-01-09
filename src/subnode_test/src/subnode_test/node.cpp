#include <chrono>
#include <memory>
#include <string>

#include "subnode_test/node.hpp"

#include "rclcpp/rclcpp.hpp"
#include "subnode_test/foo/foo_node.hpp"
#include "subnode_test/bar/bar_node.hpp"

using namespace std::chrono_literals;

Node::Node(const std::string & node_name)
: rclcpp::Node(node_name)
{
  foo_node = std::make_shared<FooNode>(this->create_subnode("foo"));

  bar_node = std::make_shared<BarNode>(this->create_subnode("bar"));

  node_tiemr = this->create_wall_timer(
    8ms,
    [this] () {
      foo_node->publish();
      bar_node->publish();
    }
  )
}
