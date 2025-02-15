#include "bpl_uav_control/drone_control.hpp"

DroneControl::DroneControl(const std::string &node_name, const std::string &connection_url, const rclcpp::NodeOptions &options)
    : Node(node_name, options)
{
    rclcpp::QoS qos(rclcpp::KeepLast(10)); // KeepLast(10) is often used for topics like battery status
        qos.reliability(rclcpp::ReliabilityPolicy::BestEffort); // Use BestEffort reliability
    
    //doplniť typ a nazov topicu aka_sprava::msg::typ_spravy
    _subBattery = this->create_subscription<typ>("", qos, std::bind(&DroneControl::battery_callback, this, std::placeholders::_1));
    _subGps = this->create_subscription<>("", qos, std::bind(&DroneControl::gps_callback, this, std::placeholders::_1));
    _subState = this->create_subscription<>("", qos, std::bind(&DroneControl::state_callback, this, std::placeholders::_1));
    _subImu = this->create_subscription<>("", qos, std::bind(&DroneControl::imu_callback, this, std::placeholders::_1));

}

void DroneControl::battery_callback(const ::SharedPtr msg)    {
    /*RCLCPP_INFO(this->get_logger(), "Battery Voltage: %.2f V", );
    RCLCPP_INFO(this->get_logger(), "Battery Current: %.2f A", );
    RCLCPP_INFO(this->get_logger(), "Battery Percentage: %.2f%%", );*/
}

void DroneControl::gps_callback(const ::SharedPtr msg)
{
    //altitude -20
    //RCLCPP_INFO(this->get_logger(), "GPS Position: [Lat: %.6f, Lon: %.6f, Alt: %.2f]", );
}   

void DroneControl::state_callback(const ::SharedPtr msg)
{
    //RCLCPP_INFO(this->get_logger(), "Flight Mode: %s",);
}

void DroneControl::imu_callback(const ::SharedPtr msg)
{
    //RCLCPP_INFO(this->get_logger(), "IMU Orientation: [x: %.2f, y: %.2f, z: %.2f, w: %.2f]", );
}


