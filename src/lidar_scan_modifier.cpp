#include "slam_sim/lidar_scan_modifier.hpp"


LidarScanModifier::LidarScanModifier () : Node("lidar_scan_modifier") {
    std::printf("[LidarScanModifier] initiating LidarScanModifier \n");

    Laser_scan_sub_ = this->create_subscription <sensor_msgs::msg::LaserScan> ("/scan", 10, std::bind(&LidarScanModifier::LaserScanSub, this, std::placeholders::_1));
}

void LidarScanModifier::LaserScanSub (const sensor_msgs::msg::LaserScan::SharedPtr msg) const{
    static int i = 0;
    std::printf("[LaserScanSub] (%i) received laser scan (%s) \n",++i, msg->header.frame_id.c_str());

}
