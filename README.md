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

Definícia Publisher
rclcpp::Publisher<typ premennej>::SharedPtr nazov premennej

Definícia Subscription
rclcpp::Subscription<typ premennej>::SharedPtr nazov premennej



-------
## Spustenie
```
ros2 run bpl_pub_sub publisher
```
```
ros2 run bpl_pub_sub subscriber
```
