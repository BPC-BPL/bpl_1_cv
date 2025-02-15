#pragma once

#include <rclcpp/rclcpp.hpp>
#include "sensor_msgs/msg/battery_state.hpp"
#include "rclcpp/qos.hpp"
#include <std_srvs/srv/trigger.hpp>

#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/battery_state.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include <mavros_msgs/srv/command_bool.hpp>
#include <mavros_msgs/srv/command_tol.hpp>
#include <mavros_msgs/srv/set_mode.hpp>
#include <mavros_msgs/msg/state.hpp>
#include <geographic_msgs/msg/geo_pose_stamped.hpp>

#include "bpl_interfaces/srv/position.hpp"
#include "bpl_uav_control/data_structures.hpp"

class DroneControl : public rclcpp::Node
{
public:
    DroneControl(const std::string &node_name, const std::string &connection_url, const rclcpp::NodeOptions &options);
    
private:
    rclcpp::CallbackGroup::SharedPtr _cb_group_subscribers;
    
    void battery_callback(const ::SharedPtr msg);
    void gps_callback(const ::SharedPtr msg);
    void state_callback(const ::SharedPtr msg);
    void imu_callback(const ::SharedPtr msg);

    // Subscribers
    //doplnit typ
    rclcpp::Subscription<>::SharedPtr _subBattery;
    rclcpp::Subscription<>::SharedPtr _subGps;
    rclcpp::Subscription<>::SharedPtr _subState;
    rclcpp::Subscription<>::SharedPtr _subImu;
};


