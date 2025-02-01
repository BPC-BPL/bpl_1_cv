#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

class Subscriber : public rclcpp::Node {
public:
    //vytvoriť konštruktor

private:
    //definovať callback funkciu s vstupnou premennou const std_msgs::msg::Int32::SharedPtr msg
    //definovať Subscription typu std_msgs::msg::Int32
    rclcpp::Subscription<>::SharedPtr subscription_;
};