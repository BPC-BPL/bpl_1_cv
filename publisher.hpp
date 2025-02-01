#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

class Publisher : public rclcpp::Node {
public:
    //vytvoriť konštruktor

private:
    //funkciu pre publish void publish();
    //definovať Publisher typu std_msgs::msg::Int32
    rclcpp::TimerBase::SharedPtr timer_;
    //internu premennu pre ukladanie celeho čisla
};