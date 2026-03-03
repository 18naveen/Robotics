#include "hardware_interface/system_interface.hpp"
#include "rclcpp/rclcpp.hpp"

namespace aria_hardware {

class AriaSystemHardware : public hardware_interface::SystemInterface {
public:
  hardware_interface::CallbackReturn on_init(const hardware_interface::HardwareInfo & info) override {
    if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS) return CallbackReturn::ERROR;
    
     return CallbackReturn::SUCCESS;
  }

  std::vector<hardware_interface::StateInterface> export_state_interfaces() override {
    std::vector<hardware_interface::StateInterface> state_interfaces;
    for (size_t i = 0; i < info_.joints.size(); i++) {
      state_interfaces.emplace_back(info_.joints[i].name, "position", &hw_positions_[i]);
    }
    return state_interfaces;
  }

  hardware_interface::return_type write(const rclcpp::Time &, const rclcpp::Duration &) override {
  
    return hardware_interface::return_type::OK;
  }

private:
  std::vector<double> hw_commands_{0,0,0,0}, hw_positions_{0,0,0,0};
};
}