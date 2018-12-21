# DroneGroundStation
Ground Control Station for drones developed with Qt 5.8 on Windows 7

### 主要模块

- 飞前设置——飞行前，参数加载及部件（主要是传感器）的校准，PID调参。详细的拆分解析见 [https://github.com/strawdiving/Calibration1](https://github.com/strawdiving/Calibration1)
- 飞行监控——飞行中，对飞机状态信息和飞行信息的实时监控。详细的拆分解析见 [https://github.com/strawdiving/FlightMonitor](https://github.com/strawdiving/FlightMonitor)
- log分析——飞行后，对log数据的回放和分析，详细的拆分解析见[https://github.com/strawdiving/LogDisplay](

### 运行效果图

飞前设置tab

![](https://raw.githubusercontent.com/strawdiving/DroneGroundStation/master/runImages/1.PNG)

飞前监控tab

![](https://raw.githubusercontent.com/strawdiving/DroneGroundStation/master/runImages/2.PNG)

log分析tab

![](https://raw.githubusercontent.com/strawdiving/DroneGroundStation/master/runImages/log.PNG)

### 如何运行

在Qt Creator中打开项目

在构建设置中，设置构建目录

运行（Ctrl+R）



