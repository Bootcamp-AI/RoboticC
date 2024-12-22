#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "bai_ros2_pkg/srv/odd_even_check.hpp"

typedef bai_ros2_pkg::srv::OddEvenCheck OddEvenCheckSrv;

class OddEvenCheckCientNode : public rclcpp::Node
{
  public: 
    OddEvenCheckCientNode() : Node("odd_even_check_service_node") 
    {
      service_client = this->create_client<OddEvenCheckSrv>("odd_even_check");
    }

    void prompt_to_check_num_odd_even(int number_input)
    {
      auto request =  OddEvenCheckSrv::Request::SharedPtr();
      request->number = number_input;

      service_client->wait_for_service();


      auto result = service_client->async_send_request(request);

      // result.

      // while (!result.wait)

      // result.wait();
      
      // std::cout << result.get()->decision << std::endl;

      // //Wait for the result.
      // if (rclcpp::spin_until_future_complete(std::make_shared(this), result) == rclcpp::FutureReturnCode::SUCCESS)
      // {
      //   std::cout << result.get()->decision << std::endl;
      // } else {
      //   std::cout << "There was an error completing the request" << std::endl;
      // }

      
    }
  
  private:
    
    rclcpp::Client<OddEvenCheckSrv>::SharedPtr service_client;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // rclcpp::spin(std::make_shared<OddEvenCheckCientNode>());
  auto client_node = OddEvenCheckCientNode();
  client_node.prompt_to_check_num_odd_even(2);

  rclcpp::shutdown();
  
  return 0;
}