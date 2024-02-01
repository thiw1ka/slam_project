#include "slam_sim/lidar_scan_modifier.hpp"
#include "rclcpp/rclcpp.hpp"
// #include <iostream.hpp>


int main (int argc, char * argv[]) {

    std::printf("[Main] main is executed. \n");
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LidarScanModifier>());
    rclcpp::shutdown();

    return 0;
}