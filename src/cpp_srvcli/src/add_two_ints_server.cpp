#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#include <memory>
#include <string>

class SimpleService : public rclcpp::Node
{
public:
  SimpleService(const std::string & node_name)
  : rclcpp::Node(node_name)
  {
    service = this->create_service<example_interfaces::srv::AddTwoInts>(
      "add_two_ints",
      [this](const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
            std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
      {
        response->sum = request->a + request->b;

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
          request->a, request->b);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);

        service = nullptr;
        rclcpp::shutdown();
      }
    );
  }

private:
  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleService>("add_two_ints_server"));
  rclcpp::shutdown();
}