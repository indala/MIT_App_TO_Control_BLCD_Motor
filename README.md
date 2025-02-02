# MIT_App_TO_Control_BLDC_Motor

MIT App to Control BLDC Motor using NodeMCU, where users can adjust motor speed via HTTP requests sent from a mobile app. The project leverages Wi-Fi or Bluetooth communication and PWM control to regulate the motor's speed.

## Features:
- **Wi-Fi Communication (NodeMCU)**: Control the motor speed using HTTP requests.
- **Bluetooth Communication (HC-05 with Arduino)**: Control the motor speed using Bluetooth signals.
- **Motor Speed Control**: Adjust the motor speed by sending speed values (0-10) through either Wi-Fi or Bluetooth.
- **PWM Control**: NodeMCU and Arduino use PWM (Pulse Width Modulation) to control the motor's speed.

## Wi-Fi Mode (NodeMCU):
1. Connect your mobile device to the NodeMCU's Wi-Fi hotspot (SSID: "Robot Wifi", Password: "87654321").
2. Open the MIT App Inventor app and enter the desired motor speed (0-10) in the app interface.
3. The app sends the speed command to the NodeMCU via HTTP. Example URL: `http://192.168.4.1/?State=5` for 50% motor speed.
4. The NodeMCU processes the command and adjusts the motor speed accordingly.

![Wi-Fi Mode](https://github.com/indala/MIT_App_TO_Control_BLCD_Motor/blob/main/images/wifi_mode.jpg)

## Bluetooth Mode (HC-05 with Arduino):wifi_mode.jpg
1. Pair your mobile device with the Arduino via Bluetooth (HC-05 module).
2. Open the app and select Bluetooth mode to control the motor speed.
3. Send the motor speed value via Bluetooth to the Arduino, and it will adjust the motor speed accordingly.
4. Bluetooth communication allows for wireless control within a limited range.

![Bluetooth Mode](https://github.com/indala/MIT_App_TO_Control_BLCD_Motor/blob/main/images/bluetooth_mode.png)

## Requirements:
- **Hardware**: NodeMCU (ESP8266) for Wi-Fi control, Arduino for Bluetooth control, BLDC motor, ESC (Electronic Speed Controller), HC-05 Bluetooth module.
- **Software**: MIT App Inventor, Arduino IDE for NodeMCU and Arduino programming.

## How to Run:
1. Upload the NodeMCU code to your device using Arduino IDE (for Wi-Fi control).
2. Upload the Arduino code for Bluetooth control (using HC-05) to your Arduino.
3. Import the `.aia` file into MIT App Inventor and build the APK.
4. Install the app on your mobile device.
5. Use either **Wi-Fi mode** or **Bluetooth mode** to control the motor speed.

## Repository Contents:
- **NodeMCU Code**: The Arduino code to control the BLDC motor via Wi-Fi.
- **Arduino Code**: The Arduino code to control the BLDC motor via Bluetooth using the HC-05 module.
- **MIT App Inventor Project (.aia)**: The app source file for the mobile app.
- **README.md**: This file.

## License:
This project is open-source. Feel free to modify, use, and share it.
