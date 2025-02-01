#include "bpl_pub_sub/subscriber.hpp"

Subscriber::Subscriber() : Node("bpl_subscriber") {
    
}

void Subscriber::number_cb(const std_msgs::msg::Int32::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "Received: %d", msg->data);
}

