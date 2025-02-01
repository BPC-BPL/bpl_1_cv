#include "bpl_pub_sub/subscriber.hpp"

Subscriber::Subscriber() : Node("bpl_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::Int32>("bpl_number_topic", 10,
    std::bind(&Subscriber::number_cb, this, std::placeholders::_1));
}

void Subscriber::number_cb(const std_msgs::msg::Int32::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "Received: %d", msg->data);
}

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Subscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}