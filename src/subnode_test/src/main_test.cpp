#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "subnode_test/node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = std::make_shared<rclcpp::Node>("kansei_node"); 
  auto kanesi_node = std::make_shared<Node>(node);

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
