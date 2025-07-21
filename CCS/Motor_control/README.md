 ## CCS开发的轮式小车驱动并调试程序
模块包含DL-20的zigbee通信、MG310电机连接TB-6612电机驱动模块的pid驱动，并集成串口通信（可读取电机当前速度）
### 串口引脚如下：<img width="1133" height="657" alt="33751f1acf1ab2e27591d87446b62ed9" src="https://github.com/user-attachments/assets/2ef6e8ed-9873-47d2-bac7-7e74abf17a57" />
### 电机引脚如下：
<img width="461" height="318" alt="37ebc6da83ce448f68b573c6ebf9a4b2" src="https://github.com/user-attachments/assets/18380a41-3391-42b3-b41b-5483e099733c" /><img width="450" height="300" alt="image" src="https://github.com/user-attachments/assets/c7d014ef-9a23-4d91-9e16-362b51c79e33" />




## Example Summary

Empty project using DriverLib.
This example shows a basic empty project using DriverLib with just main file
and SysConfig initialization.

## Peripherals & Pin Assignments

| Peripheral | Pin | Function |
| --- | --- | --- |
| SYSCTL |  |  |
| DEBUGSS | PA20 | Debug Clock |
| DEBUGSS | PA19 | Debug Data In Out |

## BoosterPacks, Board Resources & Jumper Settings

Visit [LP_MSPM0G3507](https://www.ti.com/tool/LP-MSPM0G3507) for LaunchPad information, including user guide and hardware files.

| Pin | Peripheral | Function | LaunchPad Pin | LaunchPad Settings |
| --- | --- | --- | --- | --- |
| PA20 | DEBUGSS | SWCLK | N/A | <ul><li>PA20 is used by SWD during debugging<br><ul><li>`J101 15:16 ON` Connect to XDS-110 SWCLK while debugging<br><li>`J101 15:16 OFF` Disconnect from XDS-110 SWCLK if using pin in application</ul></ul> |
| PA19 | DEBUGSS | SWDIO | N/A | <ul><li>PA19 is used by SWD during debugging<br><ul><li>`J101 13:14 ON` Connect to XDS-110 SWDIO while debugging<br><li>`J101 13:14 OFF` Disconnect from XDS-110 SWDIO if using pin in application</ul></ul> |

### Device Migration Recommendations
This project was developed for a superset device included in the LP_MSPM0G3507 LaunchPad. Please
visit the [CCS User's Guide](https://software-dl.ti.com/msp430/esd/MSPM0-SDK/latest/docs/english/tools/ccs_ide_guide/doc_guide/doc_guide-srcs/ccs_ide_guide.html#sysconfig-project-migration)
for information about migrating to other MSPM0 devices.

### Low-Power Recommendations
TI recommends to terminate unused pins by setting the corresponding functions to
GPIO and configure the pins to output low or input with internal
pullup/pulldown resistor.

SysConfig allows developers to easily configure unused pins by selecting **Board**→**Configure Unused Pins**.

For more information about jumper configuration to achieve low-power using the
MSPM0 LaunchPad, please visit the [LP-MSPM0G3507 User's Guide](https://www.ti.com/lit/slau873).

## Example Usage

Compile, load and run the example.
