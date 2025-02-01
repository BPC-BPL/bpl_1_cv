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


### Tvorba konštruktora
V konštruktore je potrebné vytvoriť ROS2 publisher typu std_msgs::msg::Int32 ktorý bude publikovať na tému "bpl_number_topic"
a vytvoriť wall_timer, ktorý nám bude v určitom intervale pričítavať a vysielať

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

```
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Publisher>();
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
