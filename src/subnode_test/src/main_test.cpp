#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "subnode_test/node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Node>("subnode_test"));
  rclcpp::shutdown();

  return 0;
}
