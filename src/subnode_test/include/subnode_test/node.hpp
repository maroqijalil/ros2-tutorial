#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "subnode_test/foo/foo_node.hpp"
#include "subnode_test/bar/bar_node.hpp"

class Node : public rclcpp::Node
{
public:
  Node(const std::string & node_name);

private:
  rclcpp::TimerBase::SharedPtr node_timer;

  std::shared_ptr<FooNode> foo_node;

  std::shared_ptr<BarNode> bar_node;
};
