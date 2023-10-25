# **    SmartHome Project Made by Mohamed Osama  **

## Hardware used :
 1. Atmega32
 2. LCD 16x2
 3. HC-05 Bluetooth Module
 4. SG90 Servo Motor
 5. AT24C32 EEPROM
 6. Buzzer
 7. Blue LED
 8. 28byj-48 Stepper Motor 
 9. ULN2003A Stepper Motor Driver
 10. UltraSonic Sensor HC-SR04
 11. RTC Module DS1307
 12. DS18B20 Tempertaure Sensor
 13. L298N DC-Motor Driver
 14. 5V FAN_DC_Motor
 
 ## Software used :
 ### MCAL LAYER :
 1. DIO DRIVER
 2. PORT DRIVER
 3. GPT DRIVER
 4. PWM DRIVER
 5. IRQH DRIVER
 6. ICU DRIVER
 7. UART DRIVER
 8. I2C DRIVER

### HAL LAYER :
1. LCD DRIVER
2. BUZZER DRIVER
3. LED DRIVER
4. BLUETOOTH MODULE DRIVER
5. AT24C32 EEPROM DRIVER
6. SERVO MOTOR DRIVER
7. STEPPER MOTOR DRIVER
8. ULTRASONIC DRIVER
9. DS18B20 TEMPERATURE SENSOR DRIVER
10. RTC MODULE DRIVER
11. FAN DRIVER

 ## Features :
 This SmartHome Project Consists of 5 Applications :
  1 - LockDoor System it's Features :
     1. can set a new pin but must enter old pin first
     2. the new pin will be saved in external EEPROM that communicates with I2C Protocol
     3. it check the current pin to open the door that is described by a stepper motor
     4. if you enter wrong pin 3 times buzzer will ring for 4 seconds and wrong pin message shown on LCD
     5. all inputs will be taken using Bluetooth module that communicates with UART Protocol
     6. if you enter the right pin stepper motor will move 90 degrees for 3 seconds then return 0 degrees
     7. if you enter the right pin a welcome home message will be shown on the LCD and Blue LED ON
   
 2 - Digital Clock it's Features :
    1. Shows The time by seconds,minutes,hours , Am or Pm it calcualtes time accurately using RTC
    2. Show the Date by day,month and year
    3. The Clock takes power from internal Lithium Battery that can be charged for a year so it keeps time if power is off

 3- Thermometer it's Features :
    Measures The Temperature Accurately Using DS18B20 and Shows it on The LCD

 4- Automatic Door it's Features :
    1. Show The Distance from The Door Using ultraSonic Sensor 
    2. if the Distance <20 cm the Servo Motor moves 90 degrees to open the door 
    3. if the Ditsance >= 20 cm the Servo Motor moves to 0 degree to close the Door
    4. The Distance and Door Status is Shown on The LCD
    5. if you close the application The Automatic Door will still move if you are close to it using Timer0 interrupt
   
 5- FanController it's Features : 
    Has 2 modes :
         1.AutoFanSpeed it' Features:
            1.if temp <=15 FanSpeed = 0
            2.if temp>15 && temp<=20 FanSpeed = 25
            3.if temp>20 && temp<=30 FanSpeed = 50
            4.if temp>30 && temp<=40 FanSpeed = 75
            5.if temp>40 FanSpeed = 90
            6. Temp and FanSpeed is shown on the LCD
            7. if you close the application after choosing automode the fan speed is still changed by temperature using timer0 Interrupt
        2.ManFanSpeed : user enters the fanspeed he wants using bluetooth application

Note : The project is made by CFGS for each pin you can change it as you wish