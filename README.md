# BPC-BPL 1. cvičenie
- doma vytvoriť github konto !!!
### Obsah cvičenia
- zoznámenie s systémom ROS 2
- demo ROS node, topic, service
- tvorba vlastného packagu
- vlasty publisher/subscriber

-------
### Spustenie demo publisheru
```
ros2 run demo_nodes_cpp talker
```

- zistite aký typ správy a akou frekvenciou vysiela publisher ?
```
ros2 topic
```

### Spustenie demo subscriberu
```
ros2 run demo_nodes_cpp listener
```

- pomocou rqt_graph vizualizujte prepojenie medzi demo nodes

### Spustenie demo node
spustenie demo node, ktory poskytuje servis pre scitanie dvoch čísiel
```
ros2 run demo_nodes_cpp add_two_ints_server
```
v druhej konzole si zavoláme servis pomocou
```
ros2 service call /add_two_ints example_interfaces/srv/AddTwoInts "{a: 5, b: 10}"
```

-------
## Tvorba vlastného packagu
ako prvé je potrebné vytvoriť pracovnú zložku
```
mkdir ros2_bpl
```
vstup do zložky
```
cd ros2_bpl
```
pomocou nasledujúceho príkazu je možné vytvoriť náš vlastný package
```
ros2 pkg create --build-type ament_cmake bpl_pub_sub
```

## Tvorba .hpp suborov
- stiahnite si základnú štruktúru z gitu
- súbory je potrebné umiestniť do zložky v includes 
- doplnte chýbajúce body

Deklarácia Publisher

rclcpp::Publisher<typ premennej>::SharedPtr nazov premennej

Deklarácia Subscription

rclcpp::Subscription<typ premennej>::SharedPtr nazov premennej

## Tvorba .cpp suborov
- stiahnite si základnú štruktúru z gitu
- súbory je potrebné umiestniť do zložky src 
- implementujte funckie

------
### Tvorba Publisheru
V konštruktore je potrebné vytvoriť ROS2 publisher typu std_msgs::msg::Int32 ktorý bude publikovať na tému "bpl_number_topic"
a vytvoriť wall_timer, ktorý nám bude v určitom intervale pričítavať a vysielať

#### Konštruktor

Inicialiácia premenných, ktoré sa doplnia k definícii konštruktora
```
: Node("bpl_publisher"), number_(0)
```

k vytvorenej premennej v .hpp, ktorá nám ukladá ukazovateľ na objekt, ktorý bude publikovať
```
this->create_publisher<std_msgs::msg::Int32>("bpl_number_topic", 10);
```

doplnenie wall_timer-u, ktorý nám bude každú sekundu volať funkciu
```
timer_ = this->create_wall_timer(std::chrono::seconds(1),std::bind(&Publisher::publish, this));
```

#### Funkcia pre publish
- inicializácia premennej message
```
auto message = std_msgs::msg::Int32();
```
- následne k premennej data, ktorá je súčasťou message, je potrebné priradiť inkrementované číslo
- pomocou RCLCPP_INFO si môžeme do konzole vypísať obsah správy
```
RCLCPP_INFO(this->get_logger(), "Publishing: %d", message.data);
```
- pomocou metody publish, môžeme pomocou vytvoreného ukazovatela na objekt rclcpp::Publisher<typ premennej>::SharedPtr
```
publish(message)
```

------
### Tvorba Subscriberu
Inicialiácia premenných, ktoré sa doplnia k definícii konštruktora
```
: Node("bpl_subscriber")
```
k vytvorenej premennej v .hpp, ktorá nám ukladá ukazovateľ na objekt, ktorý bude odoberať
```
subscription_ = this->create_subscription<std_msgs::msg::Int32>("bpl_number_topic", 10, std::bind(&Subscriber::number_cb, this, std::placeholders::_1));
```
v callback funkcii je potrebné prečítať data z message a vypísať do konzole

Pristup k datam:
```
msg->data
```

## Doplnenie CMakeListu a package.xml
CMakeLists.txt
```
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_executable(publisher src/publisher.cpp)
add_executable(subscriber src/subscriber.cpp)

ament_target_dependencies(publisher rclcpp std_msgs)
ament_target_dependencies(subscriber rclcpp std_msgs)

install(TARGETS
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME}
)
```
package.xml
```
<depend>rclcpp</depend>
<depend>std_msgs</depend>
```

Bude potrebné doplniť do publisher.cpp subscriber.cpp

Pridať do publisher.cpp
```
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Publisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```

Pridať do subscriber.cpp
```
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Subscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
-------
## Spustenie
```
ros2 run bpl_pub_sub publisher
```
```
ros2 run bpl_pub_sub subscriber
```
