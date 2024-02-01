#include <iostream>
// #include "rclcpp/rclcpp.hpp"
#include "rclcpp/node.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#ifndef LIDAR_SCAN_MODIFIER
#define LIDAR_SCAN_MODIFIER

class LidarScanModifier : public rclcpp::Node {

    public:

        /**
         * @brief default contructor for the class. it subcribes to the laser scan topic
         * 
         */
        LidarScanModifier();

    protected:

        /**
         * @brief subcriber variable decleration for laser scan modifier
         * 
         */
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr Laser_scan_sub_;

        /**
         * @brief laser scan copy
         * 
         */
        sensor_msgs::msg::LaserScan lsmsg;

        /**
         * @brief callback function for laser scan modifier subcriber
         * 
         * @param msg 
         */
        void LaserScanSub (const sensor_msgs::msg::LaserScan::SharedPtr msg) const;

    

};


#endif