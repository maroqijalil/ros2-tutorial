#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "subnode_test/node.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = std::make_shared<rclcpp::Node>("kansei_node"); 
  auto kanesi_node = std::make_shared<Node>(node);

  rclcpp::Rate rcl_rate(2s);
  while (rclcpp::ok()) {
    rcl_rate.sleep();
    rclcpp::spin_some(node);
  }

  return 0;
}
